#!/usr/bin/env python3
"""Full-SDK demand certificate extractor (game-agnostic method, G4QE01 first run).

Derives, purely statically, which SDK functions a game's own code can ever invoke:
  1. symbols.txt        -> addr/size/name for every guest function, lane-classified by SDK prefix
  2. generated chunks   -> cross-function edges: every `ctx->pc = 0xXXXXXXXXu;` constant,
                           attributed to the enclosing `void func_XXXXXXXX(CPUState*`
  3. address-taken set  -> function-start constants found in code (`0x8XXXXXXXu`) plus a scan of
                           main.dol data sections (vtables, callback tables) — extra reachability roots
Reachability = closure from __start + address-taken roots. Demand(lane) = SDK fns with >=1 caller
whose lane is 'game' (cross-boundary calls), separated from SDK-internal plumbing.
Output: JSON certificate + human summary on stdout.
"""
import json, re, struct, sys
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parents[2]
SYMBOLS = REPO / "smstrikers-decomp/config/G4QE01/symbols.txt"
CHUNKS = REPO / "StrikersRecomp/generated/chunks"
DOL = REPO / "StrikersRecomp/generated/main.dol"
OUT_JSON = REPO / "StrikersRecomp/tools/certificate_G4QE01.json"

LANES = [  # (lane, name-prefix regex) — first match wins; anchored, tolerant of 1-2 leading underscores
    ("gx", r"GX"), ("os", r"OS"), ("dvd", r"DVD"), ("card", r"CARD"), ("pad", r"PAD"),
    ("vi", r"VI"), ("ai", r"AI"), ("ar", r"AR"), ("arq", r"ARQ"), ("dsp", r"DSP"),
    ("si", r"SI"), ("exi", r"EXI"), ("musyx_api", r"(snd|s3d)"),
    ("musyx_int", r"(hw[A-Z]|sal[A-Z]|synth|seq[A-Z]|data[A-Z]|voice[A-Z]|stream[A-Z]|mcmd|macHandle|macMake|macSample|inpGet|vidGet)"),
    ("ax", r"AX"), ("mtx", r"(MTX|PS|C_MTX|VEC|QUAT)"), ("demo", r"DEMO"), ("db", r"DB"),
    ("gd", r"GD"), ("thp", r"THP"),
]
LANE_RE = [(lane, re.compile(r"^_{0,2}" + pat)) for lane, pat in LANES]

def lane_of(name: str) -> str:
    for lane, rx in LANE_RE:
        if rx.match(name):
            return lane
    return "game"

# ---- 1. symbols ----
sym_re = re.compile(r"^(\S+)\s*=\s*\.text:0x([0-9A-Fa-f]+);\s*//\s*type:function\s+size:0x([0-9A-Fa-f]+)")
funcs = []  # (addr, size, name, lane)
for line in SYMBOLS.read_text(errors="ignore").splitlines():
    m = sym_re.match(line)
    if m:
        name, addr, size = m.group(1), int(m.group(2), 16), int(m.group(3), 16)
        funcs.append((addr, size, name, lane_of(name)))
funcs.sort()
starts = [f[0] for f in funcs]
by_addr = {f[0]: f for f in funcs}

import bisect
def containing(addr: int):
    """function whose [start,start+size) contains addr, else None"""
    i = bisect.bisect_right(starts, addr) - 1
    if i >= 0:
        f = funcs[i]
        if f[0] <= addr < f[0] + f[1]:
            return f
    return None

# ---- 2. chunk scan: symbol-level edges via call-site PCs + fn-pointer constants ----
label_re = re.compile(r"^\s*label_([0-9A-Fa-f]{8}):")
lr_re = re.compile(r"ctx->lr = 0x([0-9A-Fa-f]{8})u;")
pc_re = re.compile(r"ctx->pc = 0x([0-9A-Fa-f]{8})u;")
gprconst_re = re.compile(r"ctx->gpr\[\d+\] = 0x(8[0-9A-Fa-f]{7})u")
edges = defaultdict(set)          # caller SYMBOL start -> {callee SYMBOL start}
gpr_consts = set()                # fn-pointer candidates materialized into registers
cur_pc = None                     # guest PC of the instruction being emitted
pending_lr = None                 # set by a bl's lr write; consumed by the next pc write
for cf in sorted(CHUNKS.glob("*.c")):
    for line in cf.open(errors="ignore"):
        m = label_re.match(line)
        if m:
            cur_pc = int(m.group(1), 16)
            continue
        m = lr_re.search(line)
        if m:
            pending_lr = int(m.group(1), 16)
        m = pc_re.search(line)
        if m:
            tgt = int(m.group(1), 16)
            callsite = (pending_lr - 4) if pending_lr is not None else cur_pc
            pending_lr = None
            cf_fn = containing(callsite) if callsite is not None else None
            tf = containing(tgt)
            if cf_fn and tf and cf_fn[0] != tf[0]:
                edges[cf_fn[0]].add(tf[0])
        for m in gprconst_re.finditer(line):
            gpr_consts.add(int(m.group(1), 16))

# ---- 3. address-taken: register-materialized fn ptrs + DOL data sections ----
addr_taken = {a for a in gpr_consts if a in by_addr}
dol = DOL.read_bytes()
hdr = struct.unpack(">18I18I18I", dol[0 : 0xD8])
offs, _addrs, sizes = hdr[0:18], hdr[18:36], hdr[36:54]
for i in range(7, 18):  # data sections only
    off, size = offs[i], sizes[i]
    if off == 0 or size == 0:
        continue
    sec = dol[off : off + size]
    for j in range(0, len(sec) - 3, 4):
        v = struct.unpack(">I", sec[j : j + 4])[0]
        if v in by_addr:
            addr_taken.add(v)

# ---- 4. reachability ----
roots = {a for a, s, n, l in funcs if n in ("__start", "__init_registers")} | addr_taken
if not roots:
    roots = {funcs[0][0]}
reach = set()
stack = list(roots)
while stack:
    a = stack.pop()
    if a in reach:
        continue
    reach.add(a)
    stack.extend(edges.get(a, ()))

# ---- 5. demand per lane ----
callers = defaultdict(set)  # callee -> {caller}
for c, tgts in edges.items():
    for t in tgts:
        callers[t].add(c)

cert = defaultdict(dict)
for addr, size, name, lane in funcs:
    if lane == "game":
        continue
    cs = callers.get(addr, set())
    rc = [by_addr[c] for c in cs]
    game_callers = sorted(f[2][:48] for f in rc if f[3] == "game")
    sdk_callers = sorted(f[2][:48] for f in rc if f[3] != "game")
    cert[lane][name] = {
        "addr": f"0x{addr:08X}",
        "reachable": addr in reach,
        "addr_taken": addr in addr_taken,
        "game_callers": len(game_callers),
        "game_caller_names": game_callers[:6],
        "sdk_callers": len(sdk_callers),
    }

meta = {
    "game": "G4QE01", "generated": "2026-07-06",
    "functions_total": len(funcs),
    "edges": sum(len(v) for v in edges.values()),
    "addr_taken_roots": len(addr_taken),
    "reachable_functions": len(reach),
    "unreachable_functions": len(funcs) - len(reach),
}
OUT_JSON.write_text(json.dumps({"meta": meta, "lanes": {k: cert[k] for k in sorted(cert)}}, indent=1))

print(json.dumps(meta, indent=1))
for lane in sorted(cert):
    entries = cert[lane]
    demanded = [n for n, e in entries.items() if e["game_callers"] > 0]
    reach_only = [n for n, e in entries.items() if e["game_callers"] == 0 and e["reachable"]]
    dead = [n for n, e in entries.items() if not e["reachable"]]
    print(f"\n== {lane.upper()}: {len(entries)} linked | {len(demanded)} game-demanded | "
          f"{len(reach_only)} sdk-internal/reachable | {len(dead)} unreachable ==")
    if lane in ("gx", "musyx_api", "ax", "dsp"):
        for n in sorted(demanded):
            e = entries[n]
            print(f"  DEMANDED {n} ({e['game_callers']} game callers: {', '.join(e['game_caller_names'][:3])})")
        if dead:
            print(f"  UNREACHABLE: {', '.join(sorted(dead))}")
