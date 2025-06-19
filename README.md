# FuzzdFlags: AFL++ Extension for Flag Mutations of C Compilers
FuzzdFlags is a fuzzing and compiler-testing tool designed to systematically explore compiler behaviours and uncover hidden bugs through efficient mutation of compiler flags and source file combinations.  
**Key Features**: Fuzzing Mode, Differential Testing Mode, Flag Debugging Mode

## Abstract

FuzzdFlags extends [AFL++](https://github.com/AFLplusplus/AFLplusplus) with dynamic mutation of compiler flags, enabling deeper exploration of a compiler’s configuration space. Traditionally, fuzzing focuses on program inputs, but FuzzdFlags treats flag sequences as part of the fuzz input, thus broadening the search to reach untested paths in the compiler. This approach can reveal corner-case bugs triggered only by specific combinations of compiler flags (e.g., optimization levels, target architectures, warnings).

## General Architecture
### How the Tool Works:
**(1) Fuzzing mode**: Fuzzes compiler flags, expanding the search to discover unique
compiler paths activated by specific flag combinations.
FuzzdFlags reads binary input files that indicate both the selected C program
and associated compiler flags. The tool decodes these binary inputs using a
custom function called decodeByteToFlags(). Then, it dynamically generates
compilation tasks managed by Clang’s Driver API. By quickly switching among
various C programs and compiler flag combinations, it effectively explores
compiler behaviours.  
**(2) Differential testing mode:** Compares behaviours between different compiler
versions by using selected test cases captured during fuzzing.  
**(3) Flag debugging mode:** Isolates the minimal flag combination responsible for
compiler crashes or miscompilation.  
###  Tool Architecture:
![fuzzdflag2](https://github.com/user-attachments/assets/c1b4f8aa-437a-44b9-8920-09bc65db9796)

## System Requirements
**Operating System**: A 64-bit Linux environment is recommended (the framework has been tested on Ubuntu LTS releases). FuzzdFlags is likely to work on other Unix-like systems, but Linux is preferred for AFL++ and compiler toolchain support.
**Hardware**: At least 8 cores and 64 GB of RAM are suggested to reproduce the experiments in a reasonable time. Fuzzing can be CPU-intensive, and more RAM may be useful to handle the compiler and multiple processes.
**Storage:** Ensure you have at least 45 gigabytes of free disk space for the fuzzing output directories. AFL++ will store generated test cases and logs; if running for long durations, this can accumulate. Using an SSD or a RAM disk for the fuzzing output (AFL’s temp dir) can improve performance, but it’s optional.

## Research Questions

We evaluate FuzzdFlags alongside ClangOptions to answer:

RQ1 (Coverage): To what extent does our flag mutator enhance AFL++’s efficacy in increasing code coverage?
RQ2 (Throughput): Does our flag mutation mechanism maintain an effective fuzzing throughput comparable to standard AFL++?

## Experiment Configurations
| Method | Fuzzing Strategy | Input Corpus | Compiler Flags| Experiment Setup |
|-----|------------------|--------------|-----------------------|------------|
| **Baseline** | None (static compilation only)| LLVM-SS      | `-O0`, `-O2`, `-O3` | - Compile each program at `-O0`, `-O2`, and `-O3`  <br> - Measure coverage on Clang 19 with `gcov`                            |
| **AFL++ (vanilla)**          | In-process fuzzing of each program with AFL++ | LLVM-SS      | `-O2`, `-O3` | - Fuzz each program separately at `-O2` and `-O3`  <br> - 5 runs per optimization level  <br> - Compute average coverage with `gcov` |
| **NRS on corpus & flags**    | Naive random seed selection across programs and flags | LLVM-SS | Dynamic range | - Use NRS and NRS-semi-smart generators to pick (program, flag-list) combos  <br> - 5 runs per generator  <br> - Compute average coverage with `gcov` |
| **AFL++ + flag fuzzing**     | Fuzzing of program–flag combinations via AFL++ | LLVM-SS  | Dynamic range | - Fuzz (program, flag-list) combos with AFL++ and clangOptions, using 1 and 30 initial seeds  <br> - 5 runs per initial-seed setting  <br> - Compute average coverage with `gcov` |


> **Note:** Each configuration was fuzzed for 24 hours, repeated 5 times, and both coverage and throughput were reported as the mean across those runs.  


## Experimental Setup

**Corpus**: We started with 2,113 single-file C programs from the [LLVM test suite](https://github.com/llvm/llvm-test-suite/tree/main/SingleSource) and minimized them with afl-cmin, reducing redundancy to 1,706 programs. This minimized corpus is used by FuzzdFlags (Configuration 1) and Vanilla AFL++ (Configuration 2).

### Machine Specification:

All experiments were conducted on a CloudLab m510 (X86) machine:

- **Hardware**: Intel Xeon D-1548 @ 2.0 GHz (8 cores, 2 threads/core), 64 GB RAM, 235 GB free disk space (we needed to extend default-64 GB free disk space).
- **OS**: Ubuntu 22.04 (x86_64)
- **Resources**: We disabled memory limits in AFL++ due to the large size of the system under test (SUT) and allowed up to 10 parallel fuzzing threads.

If you wish to replicate these experiments, we recommend an environment with at least 8 CPU cores and 16 GB RAM to achieve similar throughput, though smaller machines can still run them with reduced parallelism.

To replicate our experiments on a similar machine, follow the installation steps below, then run the provided commands for each experiment.

> **Note on Cmin**: The corpus minimization step (afl-cmin) uses heuristics that may produce slightly different outputs each run. If you want to reproduce our exact minimized corpus, you can use the already minimized and reindexed corpus from our Zenodo files. Otherwise, re-running afl-cmin yourself might yield small differences.

### Installation and Environment Configuration

Below are the core commands we used to set up the environment for both experiments (Vanilla AFL++ and FuzzdFlags). We do not provide a single script; instead, you can copy & paste the relevant commands on your machine.

Important: Some commands (like adding a user user42) are optional or can be adapted if you prefer using your own username. These instructions reflect what we did on a fresh Ubuntu 22.04 CloudLab machine
