# m510 setup 

sudo useradd -m -d /users/user42 -s /bin/bash user42
sudo passwd user42
sudo usermod -aG sudo user42
sudo usermod -aG kclsystemfuzz-PG user42
sudo chown -R user42:kclsystemfuzz-PG /users/user42
sudo chmod 777 /users/user42
sudo chown -R user42:user42 /users/user42/


sudo apt-get update && sudo apt-get upgrade -y
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

sudo bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"
sudo apt-get install -y clang-14 lldb-14 lld-14
sudo ln -s /usr/bin/llvm-config-14 /usr/bin/llvm-config
echo 'export LLVM_CONFIG=/usr/bin/llvm-config' >> ~/.bashrc
cd /users/user42
su user42

wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/AFLplusplus-latest-mapsize22-m510.tar.gz
tar -zxvf AFLplusplus-latest-mapsize22-m510.tar.gz
cd /users/user42/AFLplusplus && sudo make install
cd /users/user42

wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/llvmSS-minimised-corpus.tar.gz && \
tar -zxvf llvmSS-minimised-corpus.tar.gz

wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/build-clangOpt.tar.gz && \
tar -zxvf build-clangOpt.tar.gz

mkdir -p /users/user42/difftest-compilers && cd /users/user42/difftest-compilers
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
    


