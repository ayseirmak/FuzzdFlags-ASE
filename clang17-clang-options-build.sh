# m510 setup 
# -------------------------------------------------------
# Step 0: Update & upgrade the system, install core tools
# -------------------------------------------------------
sudo useradd -m -d /users/user42 -s /bin/bash user42
sudo passwd user42
sudo usermod -aG sudo user42
sudo usermod -aG kclsystemfuzz-PG user42
sudo chown -R user42:kclsystemfuzz-PG /users/user42
sudo chmod 777 /users/user42
sudo chown -R user42:user42 /users/user42/
sudo chmod -R u+w /users/user42/

# -------------------------------------------------------
# Step 1: Update & upgrade the system, install core tools
# -------------------------------------------------------
sudo apt-get update && sudo apt-get upgrade -y

# Install a broad set of essential development packages
sudo apt-get install -y \
  software-properties-common \
  build-essential \
  apt-utils \
  wget \
  curl \
  git \
  vim \
  nano \
  zip \
  unzip \
  lsb-release \
  zlib1g \
  zlib1g-dev \
  libssl-dev \
  python3-dev \
  automake \
  cmake \
  flex \
  bison \
  libglib2.0-dev \
  libpixman-1-dev \
  python3-setuptools \
  cargo \
  libgtk-3-dev \
  ninja-build \
  gdb \
  coreutils \
  gcc-11-plugin-dev \
  libedit-dev \
  libpfm4-dev \
  valgrind \
  ocaml-nox \
  autoconf \
  libtool \
  pkg-config \
  libxml2-dev \
  ocaml \
  ocaml-findlib \
  libpthread-stubs0-dev \
  libtinfo-dev \
  libncurses5-dev \
  libz-dev \
  python3-pip \
  binutils-dev \
  libiberty-dev


# ------------------------------------------
# Step 2: Add Toolchain PPA & install GCC-11
# ------------------------------------------
sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
sudo apt-get update
sudo apt-get -y install gcc-11 g++-11 cpp-11

# --------------------------------------------------
# Step 3: Set GCC-11, G++-11, etc. as the system default
# --------------------------------------------------
sudo rm /usr/bin/cpp /usr/bin/gcc /usr/bin/g++ /usr/bin/gcov /usr/bin/c++ /usr/bin/cc 2>/dev/null

sudo ln -s /usr/bin/cpp-11  /usr/bin/cpp
sudo ln -s /usr/bin/gcc-11  /usr/bin/gcc
sudo ln -s /usr/bin/gcc-11  /usr/bin/cc
sudo ln -s /usr/bin/g++-11  /usr/bin/g++
sudo ln -s /usr/bin/g++-11  /usr/bin/c++
sudo ln -s /usr/bin/gcov-11 /usr/bin/gcov

# -------------------------------------------------------
# Step 4: Download & install LLVM 14 (for system clang)
# -------------------------------------------------------
sudo bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"
sudo apt-get install -y clang-14 lldb-14 lld-14
sudo ln -s /usr/bin/llvm-config-14 /usr/bin/llvm-config
su - user42
export LLVM_CONFIG=/usr/bin/llvm-config

# -------------------------------------------------------
# Step 5: setup AFL++ from source
# -------------------------------------------------------
wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/AFLplusplus-latest-mapsize22-m510.tar.gz
tar -zxvf AFLplusplus-latest-mapsize22-m510.tar.gz
cd AFLplusplus
sudo make install
cd ~

# -------------------------------------------------------
# Step 7: Get llvm-test-suite Single Source corpus (after Cmin)
# -------------------------------------------------------
wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/llvmSS-minimised-corpus.tar.gz
tar -zxvf llvmSS-minimised-corpus.tar.gz

# -------------------------------------------------------
# Step 8: Build clang17
# -------------------------------------------------------
cd ~
git clone https://github.com/llvm/llvm-project.git
cd llvm-project
git checkout release/17.x

cd /users/user42/llvm-project/clang/tools
mkdir -p clang-options && cd clang-options
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/clang-options/ClangOptions.cpp
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/clang-options/CMakeLists.txt
nano ../CMakeLists.txt # After add_clang_subdirectory(clang-scan-deps) Add add_clang_subdirectory(clang-options)

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

# -------------------------------------------------------
# Step 9: Build clang-options
# -------------------------------------------------------
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


tar -czvf clang17-build.tar.gz -C /users/user42/ build
tar -czvf clangOpt-build.tar.gz -C /users/user42/ build-clang-options
