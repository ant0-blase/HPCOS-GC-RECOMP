#ifndef STRIKERSRECOMP_HOST_HLE_PHYSICS_H
#define STRIKERSRECOMP_HOST_HLE_PHYSICS_H

#include "core/cpu.h"

extern bool g_physics_sor_failure_reported;
extern bool g_physics_set_failure_reported;

bool ball_state_log_enabled(void);
void hle_physics_init(void);

void notify_cBallUpdateOrientation(CPUState* cpu);
void notify_cBallPostPhysicsUpdate(CPUState* cpu);
void notify_PhysicsUpdate(CPUState* cpu);
void notify_PhysicsAIBallPostUpdate(CPUState* cpu);
void notify_PhysicsWorldUpdate(CPUState* cpu);
void notify_PhysicsWorldPreUpdate(CPUState* cpu);
void notify_dWorldQuickStep(CPUState* cpu);
void notify_dBodySetForce(CPUState* cpu);
void notify_dBodyAddForce(CPUState* cpu);
void notify_dBodySetAngularVel(CPUState* cpu);
void notify_dBodySetLinearVel(CPUState* cpu);
void notify_dBodySetRotation(CPUState* cpu);
void notify_dBodySetPosition(CPUState* cpu);
void notify_SorLcp(CPUState* cpu);
void notify_SorLcpReturn(CPUState* cpu);
void notify_dxStepBody(CPUState* cpu);

#ifdef STRIKERSRECOMP_AURORA
void notify_DrawableBallRender(CPUState* cpu);
#endif

#endif // STRIKERSRECOMP_HOST_HLE_PHYSICS_H
