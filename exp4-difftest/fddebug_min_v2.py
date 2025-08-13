#!/usr/bin/env python3
import sys, subprocess, os, json

# Usage:
#   ./fddebug_min.py <clang_path|17|19|22> <test_no> <flags...>
# Finds the smallest ordered prefix of flags that triggers a crash and stops immediately.

# Constants (adjust paths if needed)
BASE_DIR = "/users/user42"
CORPUS_DIR = f"{BASE_DIR}/llvmSS-minimised-corpus"
INCLUDES_DIR = f"{BASE_DIR}/llvmSS-include"
COMP17 = f"{BASE_DIR}/build/bin/clang-17"
COMP19 = f"{BASE_DIR}/llvm-19-build/bin/clang-19"
COMP22 = f"{BASE_DIR}/llvm-latest-build/bin/clang-22"
COMPILE_TIMEOUT = 60
EXEC_TIMEOUT = 30

def is_crash(rc: int) -> bool:
    # timeout(1) returns 124 on timeout; crashes typically return >=128 (signal + 128)
    return (rc < 0) or (rc >= 128) or (rc == 124)

def resolve_clang(arg: str) -> str:
    if arg == "17": return COMP17
    if arg == "19": return COMP19
    if arg == "22": return COMP22
    return arg

def dedupe_keep_last_order(raw_flags):
    """
    Keep only the last occurrence of each flag, preserving the final order.
    Example: [-O0, -O3, -O2, -O3] -> [-O0, -O2, -O3] (last -O3 kept, order preserved)
    """
    seen = set()
    result = []
    for f in raw_flags:
        if f in seen:
            # remove earlier kept occurrence to re-append at the end
            result.remove(f)
        else:
            seen.add(f)
        result.append(f)
    return result

def compile_with_flags(clang, constant_flags, flags, test_file, exe):
    # Ensure we don't accidentally run a stale binary if compilation fails
    if os.path.exists(exe):
        os.remove(exe)
    cmd = ["timeout", str(COMPILE_TIMEOUT), clang] + constant_flags + flags + [test_file, "-o", exe]
    cp = subprocess.run(cmd, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    return cp.returncode

def run_binary(exe):
    rp = subprocess.run(["timeout", str(EXEC_TIMEOUT), exe],
                        stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    return rp.returncode

def main():
    if len(sys.argv) < 4:
        print("Usage: fddebug_min.py <clang_path|17|19|22> <test_no> <flags...>")
        sys.exit(1)

    clang_arg = sys.argv[1]
    clang = resolve_clang(clang_arg)
    test_no = sys.argv[2]
    raw_flags = sys.argv[3:]

    test_file = os.path.join(CORPUS_DIR, f"test_{test_no}.c")
    exe = "./_temp_fd.exe"

    # Keep the last occurrence of each flag and preserve final order
    unique_flags = dedupe_keep_last_order(raw_flags)

    # Flags you always want to pass
    constant_flags = [
        "-std=gnu89", "-fpermissive", "-w",
        "-Wno-implicit-function-declaration", "-Wno-implicit-int",
        "-Wno-return-type", "-Wno-builtin-redeclared", "-Wno-int-conversion",
        "-march=native", "-I/usr/include", "-lm", f"-I{INCLUDES_DIR}"
    ]

    crash_info = None

    # Grow prefix 1, 2, 3, ... and stop on first crash
    for i in range(1, len(unique_flags) + 1):
        prefix = unique_flags[:i]

        # Compile
        c_rc = compile_with_flags(clang, constant_flags, prefix, test_file, exe)
        if c_rc != 0:
            if is_crash(c_rc):
                crash_info = {"stage": "compile", "rc": c_rc, "prefix_len": i, "flags": prefix}
                break
            # if it's just a normal compile error, keep growing the prefix
            continue

        # Run
        r_rc = run_binary(exe)
        if is_crash(r_rc):
            crash_info = {"stage": "exec", "rc": r_rc, "prefix_len": i, "flags": prefix}
            break

    # Cleanup
    if os.path.exists(exe):
        os.remove(exe)

    out = {
        "clang": clang_arg,
        "test": test_no,
        "strategy": "prefix-grow",
        "deduped_flags": unique_flags,
        "crash_found": bool(crash_info),
        "crash_stage": (crash_info["stage"] if crash_info else None),
        "crash_rc": (crash_info["rc"] if crash_info else None),
        "min_crash_prefix": (crash_info["flags"] if crash_info else []),
        "min_crash_prefix_len": (crash_info["prefix_len"] if crash_info else 0)
    }
    print(json.dumps(out, indent=2))

if __name__ == "__main__":
    main()
