# Use Ubuntu 22.04 as the base image
FROM ubuntu:22.04

# Suppress debconf interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Switch to root for system-level installations
USER root

# Replace /bin/sh with bash, create new user "user42" and password "password"
RUN rm /bin/sh && ln -s /bin/bash /bin/sh && \
    useradd -m -d /users/user42 -s /bin/bash user42 && \
    echo "user42:123" | chpasswd && \
    usermod -aG sudo user42 && \
    chmod 755 /users/user42

# Update package lists, upgrade packages, and install basic utilities
RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y \
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

# Add the toolchain PPA and update package lists again
RUN add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
    apt-get update

# Install GCC 11 toolchain and reconfigure system symlinks
RUN apt-get -y install gcc-11 g++-11 cpp-11 && \
    rm /usr/bin/cpp /usr/bin/gcc /usr/bin/g++ /usr/bin/gcov /usr/bin/c++ /usr/bin/cc 2>/dev/null && \
    ln -s /usr/bin/cpp-11  /usr/bin/cpp && \
    ln -s /usr/bin/gcc-11  /usr/bin/gcc && \
    ln -s /usr/bin/gcc-11  /usr/bin/cc && \
    ln -s /usr/bin/g++-11  /usr/bin/g++ && \
    ln -s /usr/bin/g++-11  /usr/bin/c++ && \
    ln -s /usr/bin/gcov-11 /usr/bin/gcov

# Install LLVM/Clang 14 using the official script and set up llvm-config symlink
RUN bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)" && \
    apt-get install -y clang-14 lldb-14 lld-14 && \
    ln -s /usr/bin/llvm-config-14 /usr/bin/llvm-config
  
# Build GCC-14.2.0 for differential testing
WORKDIR /users/user42/difftest-compilers
RUN wget https://github.com/gcc-mirror/gcc/archive/refs/tags/releases/gcc-14.2.0.tar.gz && \
    tar -xvf gcc-14.2.0.tar.gz && \
    cd gcc-releases-gcc-14.2.0 && \
    ./contrib/download_prerequisites && \
    cd .. && \
    mkdir gcc14-build && cd gcc14-build && \
    ../gcc-releases-gcc-14.2.0/configure --prefix=/opt/gcc-14 \
       --disable-multilib --disable-bootstrap \
       --enable-languages=c,c++,lto,objc,obj-c++ \
       --enable-targets=x86 && \
    make -j$(nproc) && \
    make install && \
    rm -rf /users/user42/difftest-compilers/gcc-releases-gcc-14.2.0 \
           /users/user42/difftest-compilers/gcc14-build

# Build LLVM-Clang-19 for differential testing
WORKDIR /users/user42/difftest-compilers
RUN git clone https://github.com/llvm/llvm-project.git && \
    cd llvm-project && git checkout release/19.x && \
    mkdir -p ../llvm-19-build && cd ../llvm-19-build && \
    cmake -G Ninja ../llvm-project/llvm \
      -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_INSTALL_PREFIX=/opt/llvm-19 \
      -DLLVM_ENABLE_PROJECTS="clang;lld;clang-tools-extra" \
      -DCMAKE_C_COMPILER=gcc-11 \
      -DCMAKE_CXX_COMPILER=g++-11 \
      -DBUILD_SHARED_LIBS=OFF \
      -DLLVM_TARGETS_TO_BUILD="X86" \
      -DLLVM_BUILD_DOCS=OFF \
      -DLLVM_BUILD_EXAMPLES=OFF && \
    ninja -j$(nproc) && ninja install && \
    rm -rf /users/user42/difftest-compilers/llvm-19-build

# Build LLVM-Clang-Latest (main branch) for differential testing
WORKDIR /users/user42/difftest-compilers/llvm-project
RUN git fetch origin && git checkout main && \
    mkdir -p ../llvm-latest-build && cd ../llvm-latest-build && \
    cmake -G Ninja ../llvm-project/llvm \
      -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_INSTALL_PREFIX=/opt/llvm-latest \
      -DLLVM_ENABLE_PROJECTS="clang;lld;clang-tools-extra" \
      -DCMAKE_C_COMPILER=gcc-11 \
      -DCMAKE_CXX_COMPILER=g++-11 \
      -DBUILD_SHARED_LIBS=OFF \
      -DLLVM_TARGETS_TO_BUILD="X86" \
      -DLLVM_BUILD_DOCS=OFF \
      -DLLVM_BUILD_EXAMPLES=OFF && \
    ninja -j$(nproc) && ninja install && \
    rm -rf /users/user42/difftest-compilers/llvm-latest-build

# Switch to the non-root user "user42" and set the working directory
USER user42
WORKDIR /users/user42

# Set environment variable for LLVM_CONFIG
ENV LLVM_CONFIG=/usr/bin/llvm-config

# Download and install AFL++
RUN wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/AFLplusplus-latest-mapsize22-m510.tar.gz && \
    tar -zxvf AFLplusplus-latest-mapsize22-m510.tar.gz

USER root
RUN cd /users/user42/AFLplusplus && make install && cd ..
USER user42
WORKDIR /users/user42
         
# Download and extract C-programset-reindexed
RUN wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/llvmSS-minimised-corpus.tar.gz && \
    tar -zxvf llvmSS-minimised-corpus.tar.gz

  # Download and extract C corpus-original
RUN wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/llvmSS-corpus-org.tar.gz && \
    tar -zxvf llvmSS-corpus-org.tar.gz 
      
# Download and extract clang-options-build
RUN wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/build-clangOpt.tar.gz && \
    tar -zxvf build-clangOpt.tar.gz
      
# Install your tool scripts and set permissions
RUN mkdir -p FuzzdFlags-project && cd FuzzdFlags-project && \
    wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/FuzzdFlags-tool/FuzzdFlags && \
    wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/FuzzdFlags-tool/custom_fuzz.sh && \
    wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/FuzzdFlags-tool/diff-test.sh && \
    wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/FuzzdFlags-tool/f_deltadebug.py && \
    wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/FuzzdFlags-tool/run_AFL_conf_default.sh && \
    wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/FuzzdFlags-tool/fuzz_report.py && \
    wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp3-input-seeds-30.tar.gz && \
    chmod +x *.sh && \
    chmod +x FuzzdFlags && \
    chmod +x f_deltadebug.py && \
    chmod +x fuzz_report.py && \
    tar -zxvf exp3-input-seeds-30.tar.gz && \
    mv input-seeds-30 input-seeds && \
    rm -rf exp3-input-seeds-30.tar.gz

RUN rm -rf ~/llvmSS-minimised-corpus.tar.gz && \
    rm -rf ~/llvmSS-corpus-org.tar.gz && \
    rm -rf ~/build-clangOpt.tar.gz && \
    rm -rf ~/AFLplusplus-latest-mapsize22-m510.tar.gz

# Set proper ownership and writable permissions for /users/user42/
USER root
RUN chown -R user42:user42 /users/user42/ && chmod -R u+w /users/user42/
USER user42

WORKDIR /users/user42/FuzzdFlags-project
CMD ["/bin/bash"]
