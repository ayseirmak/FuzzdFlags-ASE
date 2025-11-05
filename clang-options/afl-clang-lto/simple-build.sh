sudo apt-get update && sudo apt-get upgrade -y
sudo apt-get install -y build-essential python3-dev automake cmake git flex bison libglib2.0-dev libpixman-1-dev python3-setuptools cargo libgtk-3-dev
sudo apt-get install -y lld-14 llvm-14 llvm-14-dev clang-14 || sudo apt-get install -y lld llvm llvm-dev clang
sudo apt-get install -y gcc-$(gcc --version|head -n1|sed 's/\..*//'|sed 's/.* //')-plugin-dev libstdc++-$(gcc --version|head -n1|sed 's/\..*//'|sed 's/.* //')-dev
sudo apt-get install -y ninja-build # for QEMU mode
sudo apt-get install -y cpio libcapstone-dev # for Nyx mode
sudo apt-get install -y wget curl # for Frida mode
sudo apt-get install -y python3-pip # for Unicorn mode

echo "[*] Installing base AFL++"
sudo mkdir -p /tmp/afl
sudo chown "$USER":"$USER" /tmp/afl
git clone https://github.com/AFLplusplus/AFLplusplus
cd AFLplusplus
make distrib
sudo make install

echo "[*] Setting governor to 'performance'..."
cd /sys/devices/system/cpu
echo performance | sudo tee cpu*/cpufreq/scaling_governor

echo "[*] Installing perf..."
sudo apt-get install linux-tools-common linux-tools-generic linux-tools-`uname -r`
echo "[*] Setting perf event paranoid to '-1'..."
echo "kernel.perf_event_paranoid=-1" | sudo tee -a /etc/sysctl.conf
sudo sysctl -p
cd ~

echo "[*] Installing latest CMake..."
sudo apt-get update
sudo apt-get install -y apt-transport-https ca-certificates gnupg wget
wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc | sudo apt-key add -
sudo apt-add-repository "deb https://apt.kitware.com/ubuntu/ $(lsb_release -cs) main"
sudo apt-get update
sudo apt-get install -y cmake
cmake --version

echo "[*] Installing utilities..."
sudo apt-get install screen
sudo apt-get install libtool
cd ~

echo "[*] Getting clang-17"
git clone https://github.com/llvm/llvm-project.git
cd llvm-project
git checkout release/17.x
cd /users/a_irmak/llvm-project/clang/tools
mkdir -p clang-options && cd clang-options
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/clang-options/afl-clang-lto/clang-options.cpp
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/clang-options/afl-clang-lto/CMakeLists.txt
sed -i '/add_clang_subdirectory(clang-scan-deps)/a add_clang_subdirectory(clang-options)' ../CMakeLists.txt
cd ~

echo "[*] Building build-stage0 tblgen files build without instrumentation to prevent segmentation fault bug"
mkdir ~/build-stage0 && cd ~/build-stage0
unset AFL_* ASAN_OPTIONS UBSAN_OPTIONS  # just to be safe
export CC=/usr/bin/clang-14
export CXX=/usr/bin/clang++-14
cmake -G Ninja ~/llvm-project/llvm   -DLLVM_ENABLE_PROJECTS="clang"   -DLLVM_TARGETS_TO_BUILD="X86"   -DCMAKE_BUILD_TYPE=Release   -DLLVM_ENABLE_ASSERTIONS=ON   -DLLVM_ENABLE_LLD=OFF   -DLLVM_OPTIMIZED_TABLEGEN=OFF
ninja llvm-tblgen clang-tblgen
cd ~

echo "[*] Building LTO instrumented clang-17 and clang-options "
mkdir -p build && cd build
export CC=afl-clang-lto
export CXX=afl-clang-lto++
export AR=/usr/lib/llvm-14/bin/llvm-ar
export RANLIB=/usr/lib/llvm-14/bin/llvm-ranlib
export AFL_MAP_SIZE=4194304
cmake -G Ninja ~/llvm-project/llvm \
  -DLLVM_ENABLE_PROJECTS="clang" \
  -DLLVM_TARGETS_TO_BUILD="X86" \
  -DCMAKE_BUILD_TYPE=Release \
  -DLLVM_ENABLE_ASSERTIONS=ON \
  -DLLVM_ENABLE_LLD=ON \
  -DLLVM_USE_HOST_TOOLS=ON \
  -DLLVM_TABLEGEN=/users/a_irmak/build-stage0/bin/llvm-tblgen \
  -DCLANG_TABLEGEN=/users/a_irmak/build-stage0/bin/clang-tblgen \
  -DLLVM_BUILD_LLVM_DYLIB=OFF \
  -DLLVM_LINK_LLVM_DYLIB=OFF \
  -DBUILD_SHARED_LIBS=OFF
ninja clang 
ninja clang-options
cd ~

echo "[*] Getting llvmSS Corpus and fuzzing scripts"
wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/llvmSS-minimised-corpus.tar.gz && \
tar -zxvf llvmSS-minimised-corpus.tar.gz
wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp3-input-seeds-30.tar.gz && \
tar -zxvf exp3-input-seeds-30.tar.gz

wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/24_fuzz.sh && \
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/exp3-fuzz-fuzzdflags-options/run_AFL_conf_clangopt.sh && \
chmod +x *.sh && \
rm *.tar.gz

echo "[*] Setup Fuzzing "
export CL_RESOURCE_DIR=$(/users/a_irmak/build/bin/clang -print-resource-dir)
export INSTRUMENTED_CLANG_PATH=/users/a_irmak/build/bin/clang
export CFILES_DIR=/users/a_irmak/llvmSS-minimised-corpus/
export FILE_COUNT=1811
export INCLUDES_DIR=/users/a_irmak/llvmSS-include/
# AFL_MAP_SIZE=4194304 afl-showmap -t 1000 -m none -o /tmp/map0 -- /users/a_irmak/build/bin/clang-options --filebin seed0.bin
# AFL_MAP_SIZE=4194304 afl-showmap -t 1000 -m none -o /tmp/map1 -- /users/a_irmak/build/bin/clang-options --filebin seed1.bin

nohup /users/a_irmak/24_fuzz.sh run_AFL_conf_clangopt.sh /users/a_irmak/input-seeds-30 \
/users/a_irmak/output-fuzz -O0 /users/a_irmak/build/bin/clang-options > exp1-fuzz-lto.log 2>&1 &

tmux new-session -d -s afl env AFL_MAP_SIZE=4194304 AFL_SKIP_BIN_CHECK=1 AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 afl-fuzz -m none -t 1000 -i /users/a_irmak/input-seeds-1 -o /users/a_irmak/output-fuzz-llvmSS-2 -- /users/a_irmak/build/bin/clang-options --filebin @@
tmux attach -t afl

echo "[*] Analysing the queue and hangs "
export INSTRUMENTED_CLANG_PATH=/users/a_irmak/build/bin/clang
export CFILES_DIR=/users/a_irmak/trial/
export FILE_COUNT=1811
export INCLUDES_DIR=/users/a_irmak/llvmSS-include/
./seed-decoder.sh ./output-fuzz/default/hangs/ llvmSS-lto-hangs

