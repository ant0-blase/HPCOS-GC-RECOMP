#include "host/hle_physics.h"
#include "host/hle_offsets.h"
#include "gxruntime/hle_abi.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool g_physics_sor_failure_reported = false;
bool g_physics_set_failure_reported = false;

bool ball_state_log_enabled(void) {
    static int enabled = -1;
    if (enabled < 0)
        enabled = getenv("STRIKERS_BALL_STATE_LOG") != NULL ? 1 : 0;
    return enabled != 0;
}

typedef struct {
    u64 quick_step;
    unsigned position_sets;
    unsigned velocity_sets;
    bool quick_entry_finite;
    bool quick_entry_valid;
    bool first_failure_reported;
} BallPhysicsProbe;

static BallPhysicsProbe g_ball_physics_probe;

typedef struct {
    bool active;
    bool interesting;
    u64 quick_step;
    u32 m;
    u32 nb;
    u32 j;
    u32 jb;
    u32 bodies;
    u32 inv_i;
    u32 lambda;
    u32 cforce;
    u32 rhs;
    u32 lo;
    u32 hi;
    u32 cfm;
    u32 findex;
    s32 ball_body_index;
} BallSorProbe;

static BallSorProbe g_ball_sor_probe;

typedef struct {
    u32 body;
    bool finite_seen;
    bool failure_reported;
} PhysicsBodyProbeEntry;

#define PHYSICS_BODY_PROBE_CAPACITY 256u
static PhysicsBodyProbeEntry g_physics_body_probes[PHYSICS_BODY_PROBE_CAPACITY];
static unsigned g_physics_body_probe_count = 0;

static void report_ball_physics_failure(CPUState* cpu, const char* boundary);

static bool guest_ram_range_valid(const CPUState* cpu, u32 address, u32 size) {
    if (address < GC_RAM_BASE || size > cpu->ram_size)
        return false;
    return address - GC_RAM_BASE <= cpu->ram_size - size;
}

static bool guest_vec3_finite(CPUState* cpu, u32 address) {
    return isfinite(guest_read_f32(cpu, address)) &&
           isfinite(guest_read_f32(cpu, address + 4u)) &&
           isfinite(guest_read_f32(cpu, address + 8u));
}

static bool guest_vec4_finite(CPUState* cpu, u32 address) {
    return guest_vec3_finite(cpu, address) &&
           isfinite(guest_read_f32(cpu, address + 12u));
}

static bool physics_body_finite(CPUState* cpu, u32 body) {
    return guest_vec3_finite(cpu, body + 0x98u) &&
           guest_vec4_finite(cpu, body + 0xA8u) &&
           guest_vec3_finite(cpu, body + 0xB8u) &&
           guest_vec3_finite(cpu, body + 0xC8u) &&
           guest_vec3_finite(cpu, body + 0xD8u) &&
           guest_vec3_finite(cpu, body + 0xE8u) &&
           guest_vec3_finite(cpu, body + 0xF8u) &&
           guest_vec3_finite(cpu, body + 0x108u) &&
           guest_vec3_finite(cpu, body + 0x118u);
}

static void log_physics_body(CPUState* cpu, const char* phase, u32 body) {
    const u32 object = mem_read32(cpu, body + 0x0Cu);
    const u32 vtable = guest_ram_range_valid(cpu, object, 0x94u)
                           ? mem_read32(cpu, object)
                           : 0u;
    const u32 parent = guest_ram_range_valid(cpu, object, 0x94u)
                           ? mem_read32(cpu, object + 0x0Cu)
                           : 0u;
    const u32 ai_character =
        guest_ram_range_valid(cpu, object, 0x94u)
            ? mem_read32(cpu, object + 0x8Cu)
            : 0u;
    fprintf(stderr,
            "[physics-body-first-failure] phase=%s step=%llu "
            "guest-frame=%llu body=0x%08X object=0x%08X "
            "vtable=0x%08X parent=0x%08X ai=0x%08X flags=0x%08X "
            "joint=0x%08X pc=0x%08X lr=0x%08X\n"
            "  pos=% .7g,% .7g,% .7g q=% .7g,% .7g,% .7g,% .7g\n"
            "  vel=% .7g,% .7g,% .7g avel=% .7g,% .7g,% .7g "
            "force=% .7g,% .7g,% .7g torque=% .7g,% .7g,% .7g\n",
            phase, (unsigned long long)g_ball_physics_probe.quick_step,
            (unsigned long long)(cpu->timebase / 675000ull), body, object,
            vtable, parent, ai_character, mem_read32(cpu, body + 0x18u),
            mem_read32(cpu, body + 0x14u), cpu->pc, cpu->lr,
            (double)guest_read_f32(cpu, body + 0x98u),
            (double)guest_read_f32(cpu, body + 0x9Cu),
            (double)guest_read_f32(cpu, body + 0xA0u),
            (double)guest_read_f32(cpu, body + 0xA8u),
            (double)guest_read_f32(cpu, body + 0xACu),
            (double)guest_read_f32(cpu, body + 0xB0u),
            (double)guest_read_f32(cpu, body + 0xB4u),
            (double)guest_read_f32(cpu, body + 0xE8u),
            (double)guest_read_f32(cpu, body + 0xECu),
            (double)guest_read_f32(cpu, body + 0xF0u),
            (double)guest_read_f32(cpu, body + 0xF8u),
            (double)guest_read_f32(cpu, body + 0xFCu),
            (double)guest_read_f32(cpu, body + 0x100u),
            (double)guest_read_f32(cpu, body + 0x108u),
            (double)guest_read_f32(cpu, body + 0x10Cu),
            (double)guest_read_f32(cpu, body + 0x110u),
            (double)guest_read_f32(cpu, body + 0x118u),
            (double)guest_read_f32(cpu, body + 0x11Cu),
            (double)guest_read_f32(cpu, body + 0x120u));
}

static void observe_physics_body(CPUState* cpu, const char* phase, u32 body) {
    if (!ball_state_log_enabled() ||
        !guest_ram_range_valid(cpu, body, 0x128u))
        return;
    PhysicsBodyProbeEntry* entry = NULL;
    for (unsigned i = 0; i < g_physics_body_probe_count; ++i) {
        if (g_physics_body_probes[i].body == body) {
            entry = &g_physics_body_probes[i];
            break;
        }
    }
    if (entry == NULL &&
        g_physics_body_probe_count < PHYSICS_BODY_PROBE_CAPACITY) {
        entry = &g_physics_body_probes[g_physics_body_probe_count++];
        entry->body = body;
        entry->finite_seen = false;
        entry->failure_reported = false;
    }
    if (entry == NULL)
        return;
    const bool finite = physics_body_finite(cpu, body);
    if (finite) {
        entry->finite_seen = true;
        return;
    }
    if (!entry->failure_reported) {
        entry->failure_reported = true;
        log_physics_body(cpu, phase, body);
    }
}

static void observe_physics_world(CPUState* cpu, const char* phase, u32 world) {
    if (!ball_state_log_enabled() ||
        !guest_ram_range_valid(cpu, world, 4u))
        return;
    u32 body = mem_read32(cpu, world);
    for (unsigned count = 0; body != 0u && count < 1024u; ++count) {
        if (!guest_ram_range_valid(cpu, body, 0x128u))
            break;
        observe_physics_body(cpu, phase, body);
        body = mem_read32(cpu, body + 4u);
    }
}

static void log_nonfinite_body_set(CPUState* cpu, const char* kind, u32 body,
                                   f64 x, f64 y, f64 z) {
    if ((isfinite(x) && isfinite(y) && isfinite(z)) ||
        g_physics_set_failure_reported)
        return;
    g_physics_set_failure_reported = true;
    fprintf(stderr,
            "[physics-body-set-nonfinite] kind=%s step=%llu body=0x%08X "
            "object=0x%08X value=% .9g,% .9g,% .9g pc=0x%08X lr=0x%08X\n",
            kind, (unsigned long long)g_ball_physics_probe.quick_step, body,
            guest_ram_range_valid(cpu, body, 20u)
                ? mem_read32(cpu, body + 0x0Cu)
                : 0u,
            x, y, z, cpu->pc, cpu->lr);
}

static void log_character_force_write(CPUState* cpu, const char* kind) {
    if (!ball_state_log_enabled() ||
        g_ball_physics_probe.quick_step < 252u ||
        g_ball_physics_probe.quick_step > 256u ||
        !guest_ram_range_valid(cpu, cpu->gpr[3], 0x128u))
        return;
    const u32 body = cpu->gpr[3];
    const u32 object = mem_read32(cpu, body + 0x0Cu);
    if (!guest_ram_range_valid(cpu, object, 0x94u) ||
        mem_read32(cpu, object) != STRIKERS_BALL_VTABLE)
        return;
    fprintf(stderr,
            "[physics-force-write] kind=%s step=%llu body=0x%08X "
            "object=0x%08X ai=0x%08X value=% .9g,% .9g,% .9g "
            "before=% .9g,% .9g,% .9g lr=0x%08X\n",
            kind, (unsigned long long)g_ball_physics_probe.quick_step, body,
            object, mem_read32(cpu, object + 0x8Cu), cpu->fpr[1],
            cpu->fpr[2], cpu->fpr[3],
            (double)guest_read_f32(cpu, body + 0x108u),
            (double)guest_read_f32(cpu, body + 0x10Cu),
            (double)guest_read_f32(cpu, body + 0x110u), cpu->lr);
}

static bool ball_physics_addresses(CPUState* cpu, u32* ball_out,
                                   u32* physics_out, u32* body_out) {
    const u32 ball = mem_read32(cpu, STRIKERS_GBALL_GLOBAL); // g_pBall
    if (!guest_ram_range_valid(cpu, ball, 0xACu))
        return false;
    const u32 physics = mem_read32(cpu, ball + 0x38u);
    if (!guest_ram_range_valid(cpu, physics, 0x5Cu))
        return false;
    const u32 body = mem_read32(cpu, physics + 4u);
    if (!guest_ram_range_valid(cpu, body, 0x128u))
        return false;
    if (ball_out != NULL)
        *ball_out = ball;
    if (physics_out != NULL)
        *physics_out = physics;
    if (body_out != NULL)
        *body_out = body;
    return true;
}

static bool ball_physics_finite(CPUState* cpu, u32 ball, u32 physics,
                                u32 body) {
    return guest_vec3_finite(cpu, ball + 0x40u) &&
           guest_vec3_finite(cpu, physics + 0x14u) &&
           guest_vec3_finite(cpu, physics + 0x20u) &&
           guest_vec3_finite(cpu, body + 0x98u) &&
           guest_vec3_finite(cpu, body + 0xE8u) &&
           guest_vec3_finite(cpu, body + 0xF8u) &&
           guest_vec3_finite(cpu, body + 0x108u) &&
           guest_vec3_finite(cpu, body + 0x118u);
}

static bool log_ball_physics_probe(CPUState* cpu, const char* phase,
                                   bool periodic) {
    u32 ball;
    u32 physics;
    u32 body;
    if (!ball_state_log_enabled() ||
        !ball_physics_addresses(cpu, &ball, &physics, &body))
        return true;

    const bool finite = ball_physics_finite(cpu, ball, physics, body);
    if (!periodic && finite)
        return true;
    if (!periodic && g_ball_physics_probe.first_failure_reported)
        return false;

    fprintf(stderr,
            "[ball-physics] phase=%s step=%llu guest-frame=%llu pc=0x%08X "
            "lr=0x%08X finite=%u ball=0x%08X physics=0x%08X "
            "body=0x%08X owner=0x%08X damage=%u target=0x%08X "
            "body-flags=0x%08X joint=0x%08X\n"
            "  sim=% .7g,% .7g,% .7g cache-pos=% .7g,% .7g,% .7g "
            "cache-vel=% .7g,% .7g,% .7g\n"
            "  ode-pos=% .7g,% .7g,% .7g ode-vel=% .7g,% .7g,% .7g "
            "ode-avel=% .7g,% .7g,% .7g\n"
            "  force=% .7g,% .7g,% .7g torque=% .7g,% .7g,% .7g\n",
            phase, (unsigned long long)g_ball_physics_probe.quick_step,
            (unsigned long long)(cpu->timebase / 675000ull), cpu->pc, cpu->lr,
            finite ? 1u : 0u, ball, physics, body,
            mem_read32(cpu, ball + 0x24u),
            (unsigned)mem_read8(cpu, ball + 0xA6u),
            mem_read32(cpu, ball + 0xA8u), mem_read32(cpu, body + 0x18u),
            mem_read32(cpu, body + 0x14u),
            (double)guest_read_f32(cpu, ball + 0x40u),
            (double)guest_read_f32(cpu, ball + 0x44u),
            (double)guest_read_f32(cpu, ball + 0x48u),
            (double)guest_read_f32(cpu, physics + 0x14u),
            (double)guest_read_f32(cpu, physics + 0x18u),
            (double)guest_read_f32(cpu, physics + 0x1Cu),
            (double)guest_read_f32(cpu, physics + 0x20u),
            (double)guest_read_f32(cpu, physics + 0x24u),
            (double)guest_read_f32(cpu, physics + 0x28u),
            (double)guest_read_f32(cpu, body + 0x98u),
            (double)guest_read_f32(cpu, body + 0x9Cu),
            (double)guest_read_f32(cpu, body + 0xA0u),
            (double)guest_read_f32(cpu, body + 0xE8u),
            (double)guest_read_f32(cpu, body + 0xECu),
            (double)guest_read_f32(cpu, body + 0xF0u),
            (double)guest_read_f32(cpu, body + 0xF8u),
            (double)guest_read_f32(cpu, body + 0xFCu),
            (double)guest_read_f32(cpu, body + 0x100u),
            (double)guest_read_f32(cpu, body + 0x108u),
            (double)guest_read_f32(cpu, body + 0x10Cu),
            (double)guest_read_f32(cpu, body + 0x110u),
            (double)guest_read_f32(cpu, body + 0x118u),
            (double)guest_read_f32(cpu, body + 0x11Cu),
            (double)guest_read_f32(cpu, body + 0x120u));
    return finite;
}

static void log_ball_contact_joints(CPUState* cpu, const char* phase,
                                    u32 body) {
    u32 node = mem_read32(cpu, body + 0x14u);
    for (unsigned index = 0; index < 12u; ++index) {
        if (!guest_ram_range_valid(cpu, node, 12u))
            break;
        const u32 joint = mem_read32(cpu, node);
        const u32 other_body = mem_read32(cpu, node + 4u);
        const u32 next = mem_read32(cpu, node + 8u);
        if (!guest_ram_range_valid(cpu, joint, 0xBCu))
            break;
        const u32 vtable = mem_read32(cpu, joint + 0x14u);
        const u32 type = guest_ram_range_valid(cpu, vtable, 20u)
                             ? mem_read32(cpu, vtable + 0x10u)
                             : ~0u;
        const u32 other_object =
            guest_ram_range_valid(cpu, other_body, 20u)
                ? mem_read32(cpu, other_body + 0x0Cu)
                : 0u;
        fprintf(stderr,
                "[ball-contact] phase=%s step=%llu index=%u node=0x%08X "
                "joint=0x%08X type=%u flags=0x%08X other-body=0x%08X "
                "other-object=0x%08X next=0x%08X "
                "lambda=% .7g,% .7g,% .7g,% .7g,% .7g,% .7g\n",
                phase, (unsigned long long)g_ball_physics_probe.quick_step,
                index, node, joint, type, mem_read32(cpu, joint + 0x18u),
                other_body, other_object, next,
                (double)guest_read_f32(cpu, joint + 0x38u),
                (double)guest_read_f32(cpu, joint + 0x3Cu),
                (double)guest_read_f32(cpu, joint + 0x40u),
                (double)guest_read_f32(cpu, joint + 0x44u),
                (double)guest_read_f32(cpu, joint + 0x48u),
                (double)guest_read_f32(cpu, joint + 0x4Cu));
        if (type == 4u) {
            const u32 contact = joint + 0x54u;
            const u32 geom1 = mem_read32(cpu, contact + 0x50u);
            const u32 geom2 = mem_read32(cpu, contact + 0x54u);
            fprintf(stderr,
                    "  contact rows=%d mode=0x%08X mu=% .7g mu2=% .7g "
                    "bounce=% .7g bounce-vel=% .7g erp=% .7g cfm=% .7g "
                    "motion=% .7g,% .7g slip=% .7g,% .7g\n"
                    "  point=% .7g,% .7g,% .7g normal=% .7g,% .7g,% .7g "
                    "depth=% .7g geom=0x%08X(type=%u,data=0x%08X),"
                    "0x%08X(type=%u,data=0x%08X)\n",
                    (s32)mem_read32(cpu, joint + 0x50u),
                    mem_read32(cpu, contact),
                    (double)guest_read_f32(cpu, contact + 4u),
                    (double)guest_read_f32(cpu, contact + 8u),
                    (double)guest_read_f32(cpu, contact + 0x0Cu),
                    (double)guest_read_f32(cpu, contact + 0x10u),
                    (double)guest_read_f32(cpu, contact + 0x14u),
                    (double)guest_read_f32(cpu, contact + 0x18u),
                    (double)guest_read_f32(cpu, contact + 0x1Cu),
                    (double)guest_read_f32(cpu, contact + 0x20u),
                    (double)guest_read_f32(cpu, contact + 0x24u),
                    (double)guest_read_f32(cpu, contact + 0x28u),
                    (double)guest_read_f32(cpu, contact + 0x2Cu),
                    (double)guest_read_f32(cpu, contact + 0x30u),
                    (double)guest_read_f32(cpu, contact + 0x34u),
                    (double)guest_read_f32(cpu, contact + 0x3Cu),
                    (double)guest_read_f32(cpu, contact + 0x40u),
                    (double)guest_read_f32(cpu, contact + 0x44u),
                    (double)guest_read_f32(cpu, contact + 0x4Cu), geom1,
                    guest_ram_range_valid(cpu, geom1, 16u)
                        ? mem_read32(cpu, geom1)
                        : ~0u,
                    guest_ram_range_valid(cpu, geom1, 16u)
                        ? mem_read32(cpu, geom1 + 8u)
                        : 0u,
                    geom2,
                    guest_ram_range_valid(cpu, geom2, 16u)
                        ? mem_read32(cpu, geom2)
                        : ~0u,
                    guest_ram_range_valid(cpu, geom2, 16u)
                        ? mem_read32(cpu, geom2 + 8u)
                        : 0u);
        }
        node = next;
    }
}

static void log_ball_sor_rows(CPUState* cpu, const char* phase) {
    const BallSorProbe* probe = &g_ball_sor_probe;
    if (!probe->active || probe->ball_body_index < 0)
        return;
    fprintf(stderr,
            "[ball-sor] phase=%s step=%llu m=%u nb=%u ball-index=%d "
            "J=0x%08X jb=0x%08X lambda=0x%08X cforce=0x%08X\n",
            phase, (unsigned long long)probe->quick_step, probe->m, probe->nb,
            probe->ball_body_index, probe->j, probe->jb, probe->lambda,
            probe->cforce);
    for (u32 row = 0; row < probe->m; ++row) {
        const s32 b1 = (s32)mem_read32(cpu, probe->jb + row * 8u);
        const s32 b2 = (s32)mem_read32(cpu, probe->jb + row * 8u + 4u);
        if (b1 != probe->ball_body_index && b2 != probe->ball_body_index)
            continue;
        const u32 j = probe->j + row * 48u;
        fprintf(stderr,
                "  row=%u bodies=%d,%d rhs=% .7g lambda=% .7g "
                "lo=% .7g hi=% .7g cfm=% .7g findex=%d\n"
                "    J1=% .7g,% .7g,% .7g | % .7g,% .7g,% .7g\n"
                "    J2=% .7g,% .7g,% .7g | % .7g,% .7g,% .7g\n",
                row, b1, b2, (double)guest_read_f32(cpu, probe->rhs + row * 4u),
                (double)guest_read_f32(cpu, probe->lambda + row * 4u),
                (double)guest_read_f32(cpu, probe->lo + row * 4u),
                (double)guest_read_f32(cpu, probe->hi + row * 4u),
                (double)guest_read_f32(cpu, probe->cfm + row * 4u),
                (s32)mem_read32(cpu, probe->findex + row * 4u),
                (double)guest_read_f32(cpu, j),
                (double)guest_read_f32(cpu, j + 4u),
                (double)guest_read_f32(cpu, j + 8u),
                (double)guest_read_f32(cpu, j + 12u),
                (double)guest_read_f32(cpu, j + 16u),
                (double)guest_read_f32(cpu, j + 20u),
                (double)guest_read_f32(cpu, j + 24u),
                (double)guest_read_f32(cpu, j + 28u),
                (double)guest_read_f32(cpu, j + 32u),
                (double)guest_read_f32(cpu, j + 36u),
                (double)guest_read_f32(cpu, j + 40u),
                (double)guest_read_f32(cpu, j + 44u));
    }
    const u32 force =
        probe->cforce + (u32)probe->ball_body_index * 24u;
    fprintf(stderr,
            "  cforce=% .7g,% .7g,% .7g | % .7g,% .7g,% .7g\n",
            (double)guest_read_f32(cpu, force),
            (double)guest_read_f32(cpu, force + 4u),
            (double)guest_read_f32(cpu, force + 8u),
            (double)guest_read_f32(cpu, force + 12u),
            (double)guest_read_f32(cpu, force + 16u),
            (double)guest_read_f32(cpu, force + 20u));
}

static void report_ball_physics_failure(CPUState* cpu, const char* boundary) {
    if (g_ball_physics_probe.first_failure_reported)
        return;
    g_ball_physics_probe.first_failure_reported = true;
    fprintf(stderr,
            "[ball-physics-first-failure] boundary=%s step=%llu "
            "guest-frame=%llu pc=0x%08X lr=0x%08X\n",
            boundary, (unsigned long long)g_ball_physics_probe.quick_step,
            (unsigned long long)(cpu->timebase / 675000ull), cpu->pc, cpu->lr);
}

void notify_SorLcp(CPUState* cpu) {
    memset(&g_ball_sor_probe, 0, sizeof g_ball_sor_probe);
    if (!ball_state_log_enabled())
        return;
    u32 ball;
    u32 body;
    if (!ball_physics_addresses(cpu, &ball, NULL, &body))
        return;

    BallSorProbe* probe = &g_ball_sor_probe;
    probe->m = cpu->gpr[3];
    probe->nb = cpu->gpr[4];
    if (probe->m == 0u || probe->m > 4096u || probe->nb == 0u ||
        probe->nb > 1024u)
        return;
    probe->j = cpu->gpr[5];
    probe->jb = cpu->gpr[6];
    probe->bodies = cpu->gpr[7];
    probe->inv_i = cpu->gpr[8];
    probe->lambda = cpu->gpr[9];
    probe->cforce = cpu->gpr[10];
    probe->rhs = mem_read32(cpu, cpu->gpr[1] + 8u);
    probe->lo = mem_read32(cpu, cpu->gpr[1] + 12u);
    probe->hi = mem_read32(cpu, cpu->gpr[1] + 16u);
    probe->cfm = mem_read32(cpu, cpu->gpr[1] + 20u);
    probe->findex = mem_read32(cpu, cpu->gpr[1] + 24u);
    probe->ball_body_index = -1;
    for (u32 index = 0; index < probe->nb; ++index) {
        if (mem_read32(cpu, probe->bodies + index * 4u) == body) {
            probe->ball_body_index = (s32)index;
            break;
        }
    }
    probe->quick_step = g_ball_physics_probe.quick_step;
    probe->interesting =
        !g_ball_physics_probe.first_failure_reported &&
        probe->quick_step <= 260u &&
        isfinite(guest_read_f32(cpu, ball + 0x44u)) &&
        fabsf(guest_read_f32(cpu, ball + 0x44u)) >= 5.0f;
    probe->active = true;

    if (!g_physics_sor_failure_reported) {
        for (u32 row = 0; row < probe->m; ++row) {
            const u32 j = probe->j + row * 48u;
            bool finite = guest_vec4_finite(cpu, j) &&
                           guest_vec4_finite(cpu, j + 16u) &&
                           guest_vec4_finite(cpu, j + 32u) &&
                           isfinite(guest_read_f32(cpu,
                                                   probe->rhs + row * 4u)) &&
                           isfinite(guest_read_f32(cpu,
                                                   probe->cfm + row * 4u));
            if (finite)
                continue;
            g_physics_sor_failure_reported = true;
            const s32 b1 = (s32)mem_read32(cpu, probe->jb + row * 8u);
            const s32 b2 =
                (s32)mem_read32(cpu, probe->jb + row * 8u + 4u);
            fprintf(stderr,
                    "[physics-sor-invalid-input] step=%llu row=%u "
                    "bodies=%d,%d rhs=% .7g cfm=% .7g\n",
                    (unsigned long long)probe->quick_step, row, b1, b2,
                    (double)guest_read_f32(cpu, probe->rhs + row * 4u),
                    (double)guest_read_f32(cpu, probe->cfm + row * 4u));
            if (b1 >= 0 && (u32)b1 < probe->nb)
                log_physics_body(
                    cpu, "SOR-invalid-input-body-1",
                    mem_read32(cpu, probe->bodies + (u32)b1 * 4u));
            if (b2 >= 0 && (u32)b2 < probe->nb)
                log_physics_body(
                    cpu, "SOR-invalid-input-body-2",
                    mem_read32(cpu, probe->bodies + (u32)b2 * 4u));
            break;
        }
    }
    if (probe->active && probe->interesting)
        log_ball_sor_rows(cpu, "entry");
}

void notify_SorLcpReturn(CPUState* cpu) {
    if (!g_ball_sor_probe.active)
        return;
    bool ball_force_finite = true;
    if (g_ball_sor_probe.ball_body_index >= 0) {
        const u32 force =
            g_ball_sor_probe.cforce +
            (u32)g_ball_sor_probe.ball_body_index * 24u;
        ball_force_finite = guest_vec3_finite(cpu, force) &&
                            guest_vec3_finite(cpu, force + 12u);
    }
    if (g_ball_sor_probe.interesting || !ball_force_finite)
        log_ball_sor_rows(cpu, "return");
    if (!ball_force_finite)
        report_ball_physics_failure(cpu, "SOR-LCP");
    if (!g_physics_sor_failure_reported) {
        for (u32 index = 0; index < g_ball_sor_probe.nb; ++index) {
            const u32 force = g_ball_sor_probe.cforce + index * 24u;
            if (guest_vec3_finite(cpu, force) &&
                guest_vec3_finite(cpu, force + 12u))
                continue;
            g_physics_sor_failure_reported = true;
            fprintf(stderr,
                    "[physics-sor-invalid-output] step=%llu body-index=%u\n",
                    (unsigned long long)g_ball_sor_probe.quick_step, index);
            log_physics_body(
                cpu, "SOR-invalid-output",
                mem_read32(cpu, g_ball_sor_probe.bodies + index * 4u));
            break;
        }
    }
    g_ball_sor_probe.active = false;
}

void notify_dWorldQuickStep(CPUState* cpu) {
    if (!ball_state_log_enabled())
        return;
    ++g_ball_physics_probe.quick_step;
    observe_physics_world(cpu, "quick-step-entry", cpu->gpr[3]);
    const bool periodic = g_ball_physics_probe.quick_step <= 8u ||
                           (g_ball_physics_probe.quick_step % 60u) == 0u;
    g_ball_physics_probe.quick_entry_finite =
        log_ball_physics_probe(cpu, "quick-step-entry", periodic);
    g_ball_physics_probe.quick_entry_valid = true;
    u32 ball;
    u32 body;
    if (ball_physics_addresses(cpu, &ball, NULL, &body) &&
        isfinite(guest_read_f32(cpu, ball + 0x44u)) &&
        fabsf(guest_read_f32(cpu, ball + 0x44u)) >= 5.0f)
        log_ball_contact_joints(cpu, "quick-step-entry", body);
    if (!g_ball_physics_probe.quick_entry_finite)
        report_ball_physics_failure(cpu, "before-quick-step");
}

void notify_dxStepBody(CPUState* cpu) {
    observe_physics_body(cpu, "integrator-entry", cpu->gpr[3]);
    u32 body;
    if (!ball_state_log_enabled() ||
        !ball_physics_addresses(cpu, NULL, NULL, &body) ||
        cpu->gpr[3] != body)
        return;
    const bool finite = log_ball_physics_probe(cpu, "integrator-entry", false);
    if (!finite && g_ball_physics_probe.quick_entry_valid &&
        g_ball_physics_probe.quick_entry_finite) {
        log_ball_contact_joints(cpu, "integrator-entry", body);
        report_ball_physics_failure(cpu, "quick-step-solver");
    }
}

void notify_PhysicsAIBallPostUpdate(CPUState* cpu) {
    if (!ball_state_log_enabled())
        return;
    const bool finite = log_ball_physics_probe(cpu, "ode-post-update", false);
    if (!finite && g_ball_physics_probe.quick_entry_valid &&
        g_ball_physics_probe.quick_entry_finite)
        report_ball_physics_failure(cpu, "quick-step-integration");
}

void notify_cBallPostPhysicsUpdate(CPUState* cpu) {
    if (!ball_state_log_enabled())
        return;
    const bool finite =
        log_ball_physics_probe(cpu, "game-post-physics-entry", false);
    if (!finite)
        report_ball_physics_failure(cpu, "before-game-copy");
}

void notify_cBallUpdateOrientation(CPUState* cpu) {
    if (!ball_state_log_enabled())
        return;
    const bool finite =
        log_ball_physics_probe(cpu, "game-update-orientation", false);
    if (!finite)
        report_ball_physics_failure(cpu, "inside-game-copy");
}

void notify_dBodySetPosition(CPUState* cpu) {
    if (ball_state_log_enabled())
        log_nonfinite_body_set(cpu, "position", cpu->gpr[3], cpu->fpr[1],
                               cpu->fpr[2], cpu->fpr[3]);
    u32 body;
    if (!ball_state_log_enabled() ||
        !ball_physics_addresses(cpu, NULL, NULL, &body) ||
        cpu->gpr[3] != body)
        return;
    ++g_ball_physics_probe.position_sets;
    const bool finite = isfinite(cpu->fpr[1]) && isfinite(cpu->fpr[2]) &&
                        isfinite(cpu->fpr[3]);
    if (finite && g_ball_physics_probe.position_sets > 20u &&
        (g_ball_physics_probe.position_sets % 60u) != 0u)
        return;
    fprintf(stderr,
            "[ball-physics-set] kind=position count=%u step=%llu "
            "value=% .9g,% .9g,% .9g finite=%u lr=0x%08X\n",
            g_ball_physics_probe.position_sets,
            (unsigned long long)g_ball_physics_probe.quick_step,
            cpu->fpr[1], cpu->fpr[2], cpu->fpr[3], finite ? 1u : 0u, cpu->lr);
    if (!finite)
        report_ball_physics_failure(cpu, "dBodySetPosition");
}

void notify_dBodySetLinearVel(CPUState* cpu) {
    if (ball_state_log_enabled())
        log_nonfinite_body_set(cpu, "linear-velocity", cpu->gpr[3],
                               cpu->fpr[1], cpu->fpr[2], cpu->fpr[3]);
    u32 body;
    if (!ball_state_log_enabled() ||
        !ball_physics_addresses(cpu, NULL, NULL, &body) ||
        cpu->gpr[3] != body)
        return;
    ++g_ball_physics_probe.velocity_sets;
    const bool finite = isfinite(cpu->fpr[1]) && isfinite(cpu->fpr[2]) &&
                        isfinite(cpu->fpr[3]);
    if (finite && g_ball_physics_probe.velocity_sets > 20u &&
        (g_ball_physics_probe.velocity_sets % 60u) != 0u)
        return;
    fprintf(stderr,
            "[ball-physics-set] kind=velocity count=%u step=%llu "
            "value=% .9g,% .9g,% .9g finite=%u lr=0x%08X\n",
            g_ball_physics_probe.velocity_sets,
            (unsigned long long)g_ball_physics_probe.quick_step,
            cpu->fpr[1], cpu->fpr[2], cpu->fpr[3], finite ? 1u : 0u, cpu->lr);
    if (!finite)
        report_ball_physics_failure(cpu, "dBodySetLinearVel");
}

void notify_dBodySetAngularVel(CPUState* cpu) {
    if (ball_state_log_enabled())
        log_nonfinite_body_set(cpu, "angular-velocity", cpu->gpr[3],
                               cpu->fpr[1], cpu->fpr[2], cpu->fpr[3]);
}

void notify_dBodySetRotation(CPUState* cpu) {
    if (!ball_state_log_enabled() ||
        !guest_ram_range_valid(cpu, cpu->gpr[4], 44u))
        return;
    const u32 matrix = cpu->gpr[4];
    bool finite = true;
    for (u32 row = 0; row < 3u; ++row)
        finite = finite && guest_vec3_finite(cpu, matrix + row * 16u);
    if (!finite)
        fprintf(stderr,
                "[physics-body-set-nonfinite] kind=rotation step=%llu "
                "body=0x%08X object=0x%08X matrix=0x%08X "
                "pc=0x%08X lr=0x%08X\n",
                (unsigned long long)g_ball_physics_probe.quick_step,
                cpu->gpr[3],
                guest_ram_range_valid(cpu, cpu->gpr[3], 20u)
                    ? mem_read32(cpu, cpu->gpr[3] + 0x0Cu)
                    : 0u,
                matrix, cpu->pc, cpu->lr);
}

void notify_dBodySetForce(CPUState* cpu) {
    if (!ball_state_log_enabled())
        return;
    log_character_force_write(cpu, "set");
    log_nonfinite_body_set(cpu, "force", cpu->gpr[3], cpu->fpr[1],
                           cpu->fpr[2], cpu->fpr[3]);
}

void notify_dBodyAddForce(CPUState* cpu) {
    if (!ball_state_log_enabled())
        return;
    log_character_force_write(cpu, "add");
    log_nonfinite_body_set(cpu, "add-force", cpu->gpr[3], cpu->fpr[1],
                           cpu->fpr[2], cpu->fpr[3]);
}

void notify_PhysicsUpdate(CPUState* cpu) {
    if (guest_ram_range_valid(cpu, cpu->gpr[3], 4u))
        observe_physics_world(cpu, "physics-update-entry",
                              mem_read32(cpu, cpu->gpr[3]));
}

void notify_PhysicsWorldPreUpdate(CPUState* cpu) {
    if (guest_ram_range_valid(cpu, cpu->gpr[3], 4u))
        observe_physics_world(cpu, "world-pre-update-entry",
                              mem_read32(cpu, cpu->gpr[3]));
}

void notify_PhysicsWorldUpdate(CPUState* cpu) {
    if (guest_ram_range_valid(cpu, cpu->gpr[3], 4u))
        observe_physics_world(cpu, "world-update-entry",
                              mem_read32(cpu, cpu->gpr[3]));
}

#ifdef STRIKERSRECOMP_AURORA
void notify_DrawableBallRender(CPUState* cpu) {
    if (!ball_state_log_enabled())
        return;
    static unsigned render_count = 0;
    ++render_count;
    if (render_count > 20u && (render_count % 60u) != 0u)
        return;

    const u32 snapshot_ball = cpu->gpr[3];
    const u32 ball = mem_read32(cpu, STRIKERS_GBALL_GLOBAL); // g_pBall
    const u32 drawable = ball ? mem_read32(cpu, ball + 0x20u) : 0u;
    fprintf(stderr,
            "[ball-state] render=%u guest-frame=%llu snapshot=0x%08X "
            "visible=%u owner-index=%d pos=% .7g,% .7g,% .7g "
            "ball=0x%08X owner=0x%08X sim=% .7g,% .7g,% .7g "
            "drawable=0x%08X world=% .7g,% .7g,% .7g "
            "translation=% .7g,% .7g,% .7g\n",
            render_count,
            (unsigned long long)(cpu->timebase / 675000ull),
            snapshot_ball, (unsigned)mem_read8(cpu, snapshot_ball + 4u),
            (int)(s8)mem_read8(cpu, snapshot_ball + 6u),
            (double)guest_read_f32(cpu, snapshot_ball + 0x18u),
            (double)guest_read_f32(cpu, snapshot_ball + 0x1Cu),
            (double)guest_read_f32(cpu, snapshot_ball + 0x20u),
            ball, ball ? mem_read32(cpu, ball + 0x24u) : 0u,
            ball ? (double)guest_read_f32(cpu, ball + 0x40u) : 0.0,
            ball ? (double)guest_read_f32(cpu, ball + 0x44u) : 0.0,
            ball ? (double)guest_read_f32(cpu, ball + 0x48u) : 0.0,
            drawable,
            drawable ? (double)guest_read_f32(cpu, drawable + 0x34u) : 0.0,
            drawable ? (double)guest_read_f32(cpu, drawable + 0x38u) : 0.0,
            drawable ? (double)guest_read_f32(cpu, drawable + 0x3Cu) : 0.0,
            drawable ? (double)guest_read_f32(cpu, drawable + 0x58u) : 0.0,
            drawable ? (double)guest_read_f32(cpu, drawable + 0x5Cu) : 0.0,
            drawable ? (double)guest_read_f32(cpu, drawable + 0x60u) : 0.0);
}
#endif

void hle_physics_init(void) {
    memset(&g_ball_physics_probe, 0, sizeof g_ball_physics_probe);
    memset(&g_ball_sor_probe, 0, sizeof g_ball_sor_probe);
    memset(g_physics_body_probes, 0, sizeof g_physics_body_probes);
    g_physics_body_probe_count = 0;
    g_physics_sor_failure_reported = false;
    g_physics_set_failure_reported = false;
}
