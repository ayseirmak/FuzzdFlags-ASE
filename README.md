# FuzzdFlags: AFL++ Extension for Flag Mutations of C Compilers
FuzzdFlags is a fuzzing and compiler-testing tool designed to systematically explore compiler behaviours and uncover hidden bugs through efficient mutation of compiler flags and source file combinations.  

### Docker Image For Tool Reproducability
To quickly get started without manually following the Tool Setup & Installation Steps, you can use the pre-built Docker image that contains the full FuzzdFlags environment:
```
## Pulling the Docker image
docker pull ayseirmak/fuzzdflags-dev:latest
docker run -it ayseirmak/fuzzdflags-dev:latest /bin/sh
```
This image includes all required dependencies, compilers, AFL++, and the FuzzdFlags tool pre-installed, ensuring a consistent and reproducible environment.


## Abstract

FuzzdFlags extends [AFL++](https://github.com/AFLplusplus/AFLplusplus) with dynamic mutation of compiler flags, enabling deeper exploration of a compiler’s configuration space. Traditionally, fuzzing focuses on program inputs, but FuzzdFlags treats flag combinations as part of the fuzz input, thus broadening the search to reach untested paths in the compiler. This approach can reveal corner-case bugs triggered only by specific combinations of compiler flags (e.g., optimization levels, target architectures, warnings).

## General Architecture
### Primary Components

- **ClangOptions Wrapper Tool:** Converts AFL++ inputs into valid compiler invocations.  
- **Instrumented Clang Compiler:** Generates precise runtime coverage feedback.  
- **AFL++ Fuzzing Engine:** Executes grey-box fuzzing based on runtime coverage data.  

### Key Features:

- **Fuzzing Mode**: Fuzzes compiler flags, expanding the search to discover unique compiler paths activated by specific flag combinations. FuzzdFlags reads binary input files that indicate the combination of  selected C program and associated compiler flag-set. The tool decodes these binary inputs using a custom function called decodeByteToFlags(). Then, it dynamically generates compilation tasks managed by Clang’s Driver API. By quickly switching among various C programs and compiler flag-set combinations, it effectively explores compiler behaviours.  
- **Differential Testing Mode:** Compares behaviours between different compiler versions by using selected test cases captured during fuzzing.  
- **Flag Debugging Mode:** Isolates the minimal flag combination responsible for compiler crashes or miscompilation.  

###  Tool Architecture:
<img width="2424" height="1558" alt="fuzzdflag3" src="https://github.com/user-attachments/assets/95b603d9-42af-404f-9d78-825127e066ed" />

## System Requirements

- **Operating System**: A 64-bit Linux environment is recommended (the framework has been tested on Ubuntu LTS releases).
FuzzdFlags is likely to work on other Unix-like systems, but Linux is preferred for AFL++ and compiler toolchain support.
- **Hardware**: At least 8 cores and 64 GB of RAM are suggested to reproduce the experiments in a reasonable time. 
Fuzzing can be CPU-intensive, and more RAM may be useful to handle the compiler and multiple processes.
- **Storage:** Ensure you have at least 45 gigabytes of free disk space for the fuzzing output directories. AFL++ will store generated test cases and logs; if running for long durations, this can accumulate. Using an SSD or a RAM disk for the fuzzing output (AFL’s temp dir) can improve performance, but it’s optional.

## Tool Setup & Installation Steps

1. Corpus Integration
2. System Installations & Environment Configuration
3. Build & Install AFL++ Fuzzing Engine
4. Build Instrumented Clang & Custom ClangOptions Wrapper Tool
5. Build & Install Default Compilers for Differential Testing Mode of the Tool (GCC, Clang latest)
6. FuzzdFlags Runtime Components Setup

### 1. Corpus Integration
We constructed an input C program corpus from the [LLVM test suite’s single-file](https://github.com/llvm/llvm-test-suite/tree/main/SingleSource) . The initial corpus contains 2383 C programs. To retain the coverage of the original set while reducing redundancy, we minimised the corpus with `afl-cmin`. We ran `afl-cmin` with AFL++’s default timeout limits and 12 parallel threads, disabling its memory limits due to large SUT. The minimised corpus contains 1811 programs. We used this minimised corpus as or default C program corpus in our tool and experiments.

You can analyze how we generate default C corpus from,  [See corpus-setup script](https://github.com/ayseirmak/FuzzdFlags-ASE/blob/main/corpus-setup.sh)
  
> **Note on Cmin**: The corpus minimization step (afl-cmin) uses heuristics that may produce slightly different outputs each run. If you want to reproduce our exact minimized corpus, you can use the already minimized and reindexed corpus. Otherwise, re-running afl-cmin yourself might yield small differences.

- **Original LLVM test single SingleSource C program Corpus (2383 programs):**

```
wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/llvmSS-corpus-org.tar.gz
tar -zxvf llvmSS-corpus-org.tar.gz
```

- **Corpus Minimization with afl-cmin:**

```
AFL_DEBUG=1 AFL_USE_ASAN=0 AFL_PRINT_FILENAMES=1 AFL_DEBUG_CHILD_OUTPUT=1 \ 
afl-cmin -i /users/user42/llvmSS-c-corpus -o /users/user42/llvmSS-c-corpus-after-Cmin \
-m none -t 500 -T 12 -- /users/user42/build-clang17/bin/clang -x c -c -O3 -fpermissive \
-w -Wno-implicit-function-declaration -Wno-implicit-int -Wno-return-type -Wno-builtin-redeclared -Wno-int-conversion  \
-march=native -I/usr/include -I/users/user42/llvmSS-include @@  -o /dev/null > /users/user42/afl-cmin-errors.log 2>&1
```
- **Minimized Corpus (1811 programs):**
```
wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/llvmSS-minimised-corpus.tar.gz
tar -zxvf llvmSS-minimised-corpus.tar.gz
```

### 2. System Installation & Environment Configurations

Below are the core commands we used to set up the environment for FuzzdFlags Tool. 
We do not provide a single script; instead, you can copy & paste the relevant commands on your machine.

> **Important**: Some commands (like adding a user user42) are optional or can be adapted if you prefer using your own username. These instructions reflect what we did on a fresh Ubuntu 22.04 CloudLab machine

**Initial User Setup and Permissions**

```
sudo useradd -m -d /users/user42 -s /bin/bash user42
sudo passwd user42
sudo usermod -aG sudo user42
sudo usermod -aG kclsystemfuzz-PG user42
sudo chown -R user42:kclsystemfuzz-PG /users/user42
sudo chmod 777 /users/user42
sudo chown -R user42:user42 /users/user42/
```

**System Preparation**
Install required dependencies and core tools:

```
sudo apt-get update && sudo apt-get upgrade -y
sudo apt-get install -y software-properties-common build-essential wget curl git cmake flex bison python3-dev libssl-dev libgtk-3-dev ninja-build gdb gcc-11-plugin-dev valgrind ocaml-nox autoconf libtool python3-pip
```
**System Default Compiler and LLVM Setup**

- **Add Toolchain PPA & install GCC-11**

```
sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
sudo apt-get update
sudo apt-get -y install gcc-11 g++-11 cpp-11
sudo rm /usr/bin/cpp /usr/bin/gcc /usr/bin/g++ /usr/bin/gcov /usr/bin/c++ /usr/bin/cc 2>/dev/null
sudo ln -s /usr/bin/cpp-11  /usr/bin/cpp
sudo ln -s /usr/bin/gcc-11  /usr/bin/gcc
sudo ln -s /usr/bin/gcc-11  /usr/bin/cc
sudo ln -s /usr/bin/g++-11  /usr/bin/g++
sudo ln -s /usr/bin/g++-11  /usr/bin/c++
sudo ln -s /usr/bin/gcov-11 /usr/bin/gcov
```

- **Download & install LLVM 14 (for system clang)**
```
sudo bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"
sudo apt-get install -y clang-14 lldb-14 lld-14
sudo ln -s /usr/bin/llvm-config-14 /usr/bin/llvm-config
echo 'export LLVM_CONFIG=/usr/bin/llvm-config' >> ~/.bashrc
cd /users/user42
su user42
```

### 3. Build & Install AFL++ Fuzzing Engine
- **Setup AFL++ from source**
```
git clone https://github.com/AFLplusplus/AFLplusplus
cd AFLplusplus
sed -i 's/#define MAP_SIZE_POW2.*/#define MAP_SIZE_POW2 22/' include/config.h # MAP_SIZE_POW2=16 ~> MAP_SIZE_POW2=22 (4 MiB)
make distrib
sudo make install
```
### 4. Build Instrumented Clang & Custom ClangOptions Wrapper Tool
- **Build Instrumented LLVM-Clang-17**
```
cd ~
git clone https://github.com/llvm/llvm-project.git
cd llvm-project
git checkout release/17.x
cd /users/user42/llvm-project/clang/tools
mkdir -p clang-options && cd clang-options
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/clang-options/ClangOptions.cpp
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/clang-options/CMakeLists.txt
sed -i '/add_clang_subdirectory(clang-scan-deps)/a add_clang_subdirectory(clang-options)' ../CMakeLists.txt
export AFL_MAP_SIZE=4194304
mkdir ~/build
cd ~/build

# Configure LLVM build to use AFL's clang-fast
LD=/usr/local/bin/afl-clang-fast++ cmake -G Ninja -Wall ../llvm-project/llvm/ \
  -DLLVM_ENABLE_PROJECTS="clang" \
  -DLLVM_USE_SANITIZER=OFF \
  -DCMAKE_BUILD_TYPE="Release" \
  -DCMAKE_C_COMPILER=/usr/local/bin/afl-clang-fast \
  -DCMAKE_CXX_COMPILER=/usr/local/bin/afl-clang-fast++ \
  -DBUILD_SHARED_LIBS=OFF \
  -DLLVM_TARGETS_TO_BUILD="X86" \
  -DCMAKE_C_FLAGS="-pthread -L/usr/lib/x86_64-linux-gnu" \
  -DCMAKE_CXX_FLAGS="-pthread -L/usr/lib/x86_64-linux-gnu" \
  -DCMAKE_EXE_LINKER_FLAGS="-L/usr/lib/x86_64-linux-gnu" \
  -DLLVM_BUILD_DOCS="OFF"

# Build only clang 
ninja clang
```
- **Build custom ClangOptions wrapper tool**
```
mkdir ~/build-clang-options
cd ~/build-clang-options
cmake -G Ninja ../llvm-project/llvm \
  -DLLVM_ENABLE_PROJECTS="clang" \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_C_COMPILER=/usr/bin/clang-14 \
  -DCMAKE_CXX_COMPILER=/usr/bin/clang++-14 \
  -DLLVM_USE_SANITIZER=OFF \
  -DBUILD_SHARED_LIBS=OFF \
  -DLLVM_TARGETS_TO_BUILD="X86" \
  -DLLVM_BUILD_DOCS=OFF
ninja clang-options
cd ~
```
### 5. Build & Install Default Compilers for Differential Testing Mode of the Tool (GCC, Clang latest)
- **Build & Install GCC-14.2.0 as default one of the diff-test compiler**
```
mkdir -p /users/user42/difftest-compilers && cd /users/user42/difftest-compilers
wget https://github.com/gcc-mirror/gcc/archive/refs/tags/releases/gcc-14.2.0.tar.gz
tar -xvf gcc-14.2.0.tar.gz
cd gcc-releases-gcc-14.2.0
./contrib/download_prerequisites
cd ..  
mkdir gcc14-build && cd gcc14-build
../gcc-releases-gcc-14.2.0/configure --prefix=/opt/gcc-14 \
    --disable-multilib --disable-bootstrap \
    --enable-languages=c,c++,lto,objc,obj-c++ \
    --enable-targets=x86
make -j$(nproc)
sudo make install
```
- **Build & Install LLVM-Clang-19 as default one of the diff-test compiler**
```
cd /users/user42/difftest-compilers
git clone https://github.com/llvm/llvm-project.git
cd llvm-project
git checkout release/19.x
mkdir -p ../llvm-19-build && cd ../llvm-19-build
cmake -G Ninja ../llvm-project/llvm \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX=/opt/llvm-19 \
  -DLLVM_ENABLE_PROJECTS="clang;lld;clang-tools-extra" \
  -DCMAKE_C_COMPILER=gcc-11 \
  -DCMAKE_CXX_COMPILER=g++-11 \
  -DBUILD_SHARED_LIBS=OFF \
  -DLLVM_TARGETS_TO_BUILD=X86 \
  -DLLVM_BUILD_DOCS="OFF" \
  -DLLVM_BUILD_EXAMPLES="OFF"
ninja -j$(nproc)
sudo ninja install
```
- **Build & Install LLVM-Clang-Latest as a default TARGET compiler for diff-test**
```
cd /users/user42/difftest-compilers
cd llvm-project
git fetch origin
git checkout main
mkdir -p ../llvm-latest-build && cd ../llvm-latest-build
cmake -G Ninja ../llvm-project/llvm \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX=/opt/llvm-latest \
  -DLLVM_ENABLE_PROJECTS="clang;lld;clang-tools-extra" \
  -DCMAKE_C_COMPILER=gcc-11 \
  -DCMAKE_CXX_COMPILER=g++-11 \
  -DBUILD_SHARED_LIBS=OFF \
  -DLLVM_TARGETS_TO_BUILD=X86 \
  -DLLVM_BUILD_DOCS="OFF" \
  -DLLVM_BUILD_EXAMPLES="OFF"
ninja -j$(nproc)
sudo ninja install
```

### FuzzdFlags Runtime Components Setup
This step installs the FuzzdFlags executable, related runtime scripts, and an initial seed corpus (30 inputs) required to launch the fuzzing engine.

```
mkdir -p FuzzdFlags-project && cd FuzzdFlags-project
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/FuzzdFlags-tool/FuzzdFlags
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/FuzzdFlags-tool/custom_fuzz.sh
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/FuzzdFlags-tool/diff-test.sh
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/FuzzdFlags-tool/f_deltadebug.py
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/FuzzdFlags-tool/run_AFL_conf_default.sh
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/FuzzdFlags-tool/fuzz_report.py
```
```
# Download initial fuzzing seeds (30 inputs)
wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp3-input-seeds-30.tar.gz && \
tar -zxvf exp3-input-seeds-30.tar.gz
sudo chown -R user42:user42 /users/user42
sudo chmod -R 755 /users/user42
```

## Tool Usage & Functionality
FuzzdFlags provides a unified interface for conducting compiler fuzzing, differential testing, and flag-level delta debugging. The tool supports three primary modes, each triggered by a dedicated subcommand. Below is a breakdown of their purpose, behavior, and practical use.

### Displaying Tool `--help`
To view all available commands and options, run:
```
./FuzzdFlags --help
```
**Expected Output:**
```
 ./FuzzdFlags -fuzz <c-dir> <include-dir> <time-seconds>  [--no-cmin]
    * Minimizes c-files (afl-cmin) unless --no-cmin is given.
    * Reindexes them, then starts fuzzing for <time-seconds> with custom conf script.
    * Creates afl-cmin-output-<timestamp> and reindex-output-<timestamp> folders automatically.
    * Creates a fuzz-output-<timestamp> folder automatically.
___________________________________________________________________________________________________

   ./FuzzdFlags -difftest <fuzzed_queue/crash/hang_dir> <diff_out_dir> <target_name> <target_cmp_path>
    * Performs differential testing on the fuzzed queue, crashes, or hangs directories.
    * Creates a difftest-output-<timestamp> folder automatically.
    * By default, differential testing uses GCC-14, Clang-19, and a user-defined compiler (default: Clang-trunk).
    * Please export the following variables:
        INSTRUMENTED_CLANG_OPTIONS_PATH
        CFILES_DIR
        INCLUDES_DIR
___________________________________________________________________________________________________

   ./FuzzdFlags -f_ddebug <clang_path> <test_c_file> <combination_sizes> <flags...>
    * Performs flag-based delta debugging for a single .c file.
    * Generates log files as <test_c_basename>_<size>.log.
    * Please export:
        INCLUDES_DIR
___________________________________________________________________________________________________

Examples:
   ./FuzzdFlags -fuzz /abs_path/to/c-files /abs_path/to/include 3600
   ./FuzzdFlags -difftest /abs_path/to/fuzz-output/queue Clang-trunk /abs_path/to/target_cmp
   ./FuzzdFlags -f_ddebug /abs_path/to/target_cmp /abs/path/to/c-file "1,2,3" -O1 -O2 -fno-strict-return
```



### 1. Fuzzing Mode: `-fuzz`
This mode performs coverage-guided greybox fuzzing across combinations of C programs and compiler flags.

 **Features:**
- Optional corpus minimization using afl-cmin (default behavior).
- Automatic reindexing and environment setup.
- Full AFL++ fuzzing workflow with runtime feedback from the compiler.

**Usage:**
```
./FuzzdFlags -fuzz /path/to/Corpus /path/to/include 3600
# To skip corpus minimization:
./FuzzdFlags -fuzz /path/to/minimized-corpus /path/to/include 3600 --no-cmin
```

**Required Environment Variables:**
```
export INSTRUMENTED_CLANG_PATH=/abs/path/to/instrumented/clang
export INSTRUMENTED_CLANG_OPTIONS_PATH=/abs/path/to/instrumented/clang-options
```

**Example Usage**
```
export INSTRUMENTED_CLANG_PATH=/users/user42/build/bin/clang
export INSTRUMENTED_CLANG_OPTIONS_PATH=/users/user42/build-clang-options/bin/clang-options 
mkdir -p FuzzdFlags-output && cd FuzzdFlags-output
../FuzzdFlags -fuzz /users/user42/llvmSS-c-corpus-org /users/user42/llvmSS-include 360
../FuzzdFlags -fuzz /users/user42/llvmSS-minimised-corpus /users/user42/llvmSS-include 300 --no-cmin
```

**Expected Terminal Output:**
```
== Fuzz Mode ==
[*]C-files dir: /users/user42/llvmSS-c-corpus-org
[*]Include dir: /users/user42/llvmSS-include
[*]Fuzz time: 360 seconds
[*]Run conf script: /users/user42/FuzzdFlags-project/run_AFL_conf_default.sh
[*]INSTRUMENTED_CLANG_PATH is [/users/user42/build/bin/clang]
[*]INSTRUMENTED_CLANG_OPTIONS_PATH is [/users/user42/build-clang-options/bin/clang-options]
[*]Running afl-cmin to reduce corpus
...
Minimized corpus created at: .../afl-cmin-output-<timestamp>/after-Cmin-cfiles
== 3) Reindexing minimized .c files with absolute paths ==
...
== 4) Launch fuzzing ==
[*]Fuzzing output directory: .../fuzz-output-<timestamp>
```
**Output Folder Structure**
```
FuzzdFlags-output/
├── afl-cmin-output-<timestamp>/
│   └── after-Cmin-cfiles/
├── reindex-output-<timestamp>/
│   └── reindex-cfiles/
│   └── c_name_index_mapping.txt
├── fuzz-output-<timestamp>/
│   └── default/
│       ├── crashes/
│       ├── hangs/
│       └── queue/
│       ├── afl-default.log
│       └── fuzz_analysis_report_fuzz-output-<timestamp>
```

### 2. Differential Testing Mode: `-difftest`
This mode performs cross-version behavioral comparisons across multiple compilers on previously fuzzed test cases (from queue, crash, or hang directories).
**Features:**
- Runs each (program, flag-set) input on multiple compiler binaries.
- Detects and logs miscompilation, crashes, and behavioral divergence.
- Automatically creates structured reports.

**Usage:**
```
./FuzzdFlags -difftest <fuzzed_queue/crash/hang_dir> <diff_out_dir> <target_name> <target_cmp_path>
```
**Required Environment Variables:**
```
export INSTRUMENTED_CLANG_OPTIONS_PATH=/abs/path/to/clang-options
export CFILES_DIR=/abs/path/to/reindexed/cfiles
export INCLUDES_DIR=/abs/path/to/include-dir
```

**Example Usage**
```
export INSTRUMENTED_CLANG_PATH=/users/user42/build/bin/clang
export INSTRUMENTED_CLANG_OPTIONS_PATH=/users/user42/build-clang-options/bin/clang-options
export CFILES_DIR=/users/user42/llvmSS-minimised-corpus
export INCLUDES_DIR=/users/user42/llvmSS-include
mkdir -p FuzzdFlags-output && cd FuzzdFlags-output
../FuzzdFlags -difftest /users/user42/FuzzdFlags-project/FuzzdFlags-output/fuzz-output-20250721_182910/default/queue/ clang-latest /opt/llvm-latest/bin/clang-22
```

**Expected Terminal Output:**
```
== Differential Testing Mode ==
[*]Fuzzed queue/crash/hang directory: ...
[*]Diff test output directory: .../difftest-output-<timestamp>
[*]Target name: clang-latest
[*]Target compiler path: /opt/llvm-latest/bin/clang-22
[*]INSTRUMENTED_CLANG_OPTIONS_PATH is [..]
[*]CFILES_DIR is [..]
[*]INCLUDES_DIR is [..]
...
```

**Output Folder Structure**
```
difftest-output-<timestamp>/
├── Crashes/
│   ├── <case_id>/
│       ├── ...-clang-19.compile.log
│       ├── ...-clang-latest.compile.log
│       ├── ...-gcc-14.compile.log
│       └── mini-report.txt
├── Hangs/
├── MismatchLogs/
│   └── <case_id>/
│       ├── ...-clang-19.compile.log
│       ├── ...-clang-latest.compile.log
│       ├── ...-gcc-14.compile.log
│       └── mini-report.txt
├── diff_test_summary.txt
```
### 3. Flag-Based Delta Debugging Mode: `-f_ddebug`
This mode identifies the minimal flag combination required to trigger a bug (e.g., crash or miscompilation) on a given .c file.

**Features:**
- Iteratively tests combinations of 1, 2, and 3 flags (or any user-specified sizes).
- Logs compilation outcomes per combination.
- Ideal for isolating root causes of failures.

**Usage:**
```
./FuzzdFlags -f_ddebug /path/to/clang /path/to/test.c "1,2,3" -O1 -O2 -fno-stack-protector ...
```
**Required Environment Variables:**
```
export INCLUDES_DIR=/abs/path/to/llvm/include
```

**Example Usage**
```
export INCLUDES_DIR=/users/user42/llvmSS-include
mkdir -p FuzzdFlags-output && cd FuzzdFlags-output
../FuzzdFlags -f_ddebug /opt/llvm-latest/bin/clang-22 /users/user42/llvmSS-minimised-corpus/test_300.c "1,2,3" -march=x86-64-v2 -march=x86-64 -mavx -mavx2 -O0 -march=x86-64-v3 -funsigned-bitfields -flax-vector-conversions -fno-stack-protector -fstrict-float-cast-overflow -ffp-eval-method=extended
```

**Expected Terminal Output:**
```
== Flag-based Delta Debugging Mode ==
[*]Clang path: /opt/llvm-latest/bin/clang-22
[*]Test C file: /users/user42/llvmSS-minimised-corpus/test_300.c
[*]Combination sizes: 1,2,3
[*]Flags: -march=x86-64-v2 -O0 -fno-stack-protector
[*]Log Files found in directory: ...
[*]Always-used constant flags: -fpermissive -w ...
[*]Unique flags given: ...
[*]Now checking 1-flag combinations
[#1] Compiling (size=1) ...
...
[*]Delta debugging completed. Logs (like <test_c_basename>_<size>.log) are in: .../FuzzdFlags-output2
...
```

**Output Folder Structure**
```
FuzzdFlags-output/
├── test_300_1.log
├── test_300_2.log
└── test_300_3.log
```
## Experiment Setup and Reproducibility
FuzzdFlags experiments are fully reproducible using our provided shell scripts and container-based setup. This section details the procedure to replicate each experiment, including fuzzing and coverage measurement stages.

### Experiment Configurations
| Method | Fuzzing Strategy | Compiler Flags| Experiment Setup |
|-----|------------------|--------------|-----------------------|------------|
| **Baseline Compilation** | None (static compilation only)| `-O0`, `-O2`, `-O3` | - Compile each program at `-O0`, `-O2`, and `-O3`  <br> - Measure coverage on Clang 19 with `gcov`                            |
|  **AFL++ Vanilla**          | In-process fuzzing of each program with AFL++ | `-O2`, `-O3` | - Fuzz each program separately at `-O2` and `-O3`  <br> - 5 runs per optimization level  <br> - Compute average coverage with `gcov-11` |
| **FuzzdFlags Blackbox**    | Black-box random seed selection across programs and flags with implemented static, ruleset to filter out obviously incompatible flag combinations  | Dynamic range | - Use NRS-semi-smart generators to pick (program, flag-list) combos  <br> - 5 runs per generator  <br> - Compute average coverage with `gcov-11` |
| **FuzzdFlags Greybox**     | Our proposed method, fuzzing of program, flag-set combinations via AFL++ |  Dynamic range | - Fuzz (program, flag-set) combos with AFL++ and clangOptions, using  30 initial seeds  <br> - 5 runs per initial-seed setting  <br> - Compute average coverage with `gcov-11` |

### Machine Specification:
All experiments were conducted on a CloudLab m510 (X86) machine:
- **Hardware**: Intel Xeon D-1548 @ 2.0 GHz (8 cores, 2 threads/core), 8 GB swap size,64 GB RAM, 235 GB free disk space (we needed to extend default-64 GB free disk space).
- **OS**: Ubuntu 22.04.5 LTS (x86_64)

> Note: If you wish to replicate these experiments, we recommend an environment with at least 8 CPU cores and 16 GB RAM to achieve similar throughput, though smaller machines can still run them with reduced parallelism and use generated  [llvmSS-minimised-corpus](https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/llvmSS-minimised-corpus.tar.gz).
### Experiment Scripts
Each experiment is automated using a specific setup script.
| Experiment| Fuzzing Setup Script | Coverage Setup Script |
|-------------------------|---------------------------|--------------|
| **Baseline Compilation**    | N/A | [exp0‑cov‑baselines‑setup](https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/exp0-cov-baselines-setup.sh)                   |
| **AFL++ Vanilla**           | [fuzzing‑afl‑vanilla‑setup](https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/exp1-fuzz-afl-vanilla/setup-machine.sh) | [coverage‑afl‑vanilla‑setup](https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/exp1-cov-afl-vanilla-setup.sh)   |
| **FuzzdFlags Blackbox**     | [fuzzing‑FdF‑BlackBox‑setup](https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/exp2-nrs-options/setup-machine.sh)   | [coverage‑FdF‑BlackBox‑setup](https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/exp2-cov-nrs-setup.sh)             |
| **FuzzdFlags Greybox**      | [fuzzing‑FdF‑GreyBox‑setup](https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/exp3-fuzz-fuzzdflags-options/setup-machine.sh)   | [coverage‑FdF‑GreyBox‑setup](https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/exp3-cov-fuzzdflags-setup.sh)               |
### Dockerized Setup
Each fuzzing experiment runs within a Docker container, ensuring consistent and isolated environments:
AFL++ Vanilla uses **afl-vanilla-img**
FuzzdFlags Blackbox uses **nrs-img**
FuzzdFlags Greybox uses **afl-clang-opts-img**

To build and run these containers, execute the relevant script and adjust --cpuset-cpus bindings to your machine's core count. Scripts launch 5 containers per experiment for parallelism.

## Result Artifacts
You can directly download the output artifacts of each experiment
| Artifact                        | Download Link                  |
|---------------------------------|------------------------|
| **Baseline Coverage**           | [exp0‑baselines‑cov‑analysis.tar.gz](https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp0-baselines-cov-analysis.tar.gz) / [exp02-baseline-O2-cov-result.tar.gz](https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp02-baseline-O2-cov-result.tar.gz) / [exp03-baseline-O3-cov-result.tar.gz](https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp03-baseline-O3-cov-result.tar.gz)          |
| **AFL++ Vanilla (-O2)**          | [exp11-aflvan-O2-fuzz-results.tar.gz](https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp11-aflvan-O2-fuzz-results.tar.gz) / [exp11-afl-vanilla-O2-cov-result.tar.gz](https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp11-afl-vanilla-O2-cov-result.tar.gz) |
| **AFL++ Vanilla (-O3)**          | [exp12‑aflvan‑O3‑fuzz‑results.tar.gz](https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp12-aflvan-O3-fuzz-results.tar.gz) / [exp12-afl-vanilla-O3-cov-result.tar.gz](https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp12-afl-vanilla-O3-cov-result.tar.gz)|
| **FuzzdFlags Blackbox**  | [exp22‑nrs‑semi‑smart‑result.tar.gz](https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp22-nrs-semi-smart-result.tar.gz) / [exp22-nrs-semi-smart-cov-result.tar.gz](https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp22-nrs-semi-smart-cov-result.tar.gz) |
| All Coverage Analysis | [cov-analysis-all-exp-v2.tar.gz](https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/cov-analysis-all-exp-v2.tar.gz)|
| **FuzzdFlags Greybox**   | [exp32‑30seed‑fuzz‑results.tar.gz](https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp32-30seed-fuzz-results.tar.gz) / [exp32-fuzzdflags-30seed-cov-result.tar.gz](https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp32-fuzzdflags-30seed-cov-result.tar.gz)           |



