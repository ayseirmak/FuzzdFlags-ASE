#!/usr/bin/env python3
import sys, subprocess, itertools, os, json

# Usage:
#   ./fddebug_min.py <clang_path|17|19|22> <test_no> <combo_sizes> <flags...>
# Outputs a JSON mapping of combo_size -> list of minimal crashing flag combinations.

# Constants (adjust paths if needed)
BASE_DIR = "/users/user42"
CORPUS_DIR = f"{BASE_DIR}/llvmSS-minimised-corpus"
INCLUDES_DIR = f"{BASE_DIR}/llvmSS-include"
COMP17 = f"{BASE_DIR}/build/bin/clang-17"
COMP19 = f"{BASE_DIR}/llvm-19-build/bin/clang-19"
COMP22 = f"{BASE_DIR}/llvm-latest-build/bin/clang-22"
COMPILE_TIMEOUT = 60
EXEC_TIMEOUT = 30

def is_crash(rc):
    return (rc < 0) or (rc >= 128) or (rc == 124)

# Parse args
if len(sys.argv) < 5:
    print("Usage: fddebug_min.py <clang_path|17|19|22> <test_no> <combo_sizes> <flags...>")
    sys.exit(1)
clang_arg = sys.argv[1]
if clang_arg == "17": clang = COMP17
elif clang_arg == "19": clang = COMP19
elif clang_arg == "22": clang = COMP22
else: clang = clang_arg

test_no = sys.argv[2]
test_file = os.path.join(CORPUS_DIR, f"test_{test_no}.c")
combo_sizes = sorted({int(x) for x in sys.argv[3].split(",") if x.isdigit()})
raw_flags = sys.argv[4:]

# Deduplicate flags, preserving last occurrence order
unique_flags = []
seen = set()
for f in raw_flags:
    if f in seen:
        unique_flags.remove(f)
    seen.add(f)
    unique_flags.append(f)

constant_flags = [
    "-std=gnu89", "-fpermissive", "-w",
    "-Wno-implicit-function-declaration", "-Wno-implicit-int",
    "-Wno-return-type", "-Wno-builtin-redeclared", "-Wno-int-conversion",
    "-march=native", "-I/usr/include", "-lm", f"-I{INCLUDES_DIR}" ]

# Container for minimal crashing combos
minimal = {size: [] for size in combo_sizes}
exe = "./_temp_fd.exe"

# Check each combination size in ascending order
for size in combo_sizes:
    crashing = []
    for combo in itertools.combinations(unique_flags, size):
        flags = list(combo)
        # compile
        cmd = ["timeout", str(COMPILE_TIMEOUT), clang] + constant_flags + flags + [test_file, "-o", exe]
        cp = subprocess.run(cmd, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        if cp.returncode != 0:
            if is_crash(cp.returncode):
                crashing.append(combo)
            continue
        # run
        rp = subprocess.run(["timeout", str(EXEC_TIMEOUT), exe], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        if is_crash(rp.returncode):
            crashing.append(combo)
    # Filter out supersets of any smaller minimal combo
    for combo in crashing:
        if any(set(sm).issubset(combo) for sz in combo_sizes for sm in minimal.get(sz, []) if sz < size):
            continue
        minimal[size].append(list(combo))
# Cleanup
if os.path.exists(exe): os.remove(exe)

# Output results
result = {"clang": clang_arg, "test": test_no, "min_flags": minimal}
print(json.dumps(result, indent=2))
