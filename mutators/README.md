sudo apt-get update && sudo apt-get upgrade -y \
sudo apt-get install -y build-essential python3-dev automake cmake git flex bison libglib2.0-dev libpixman-1-dev python3-setuptools cargo libgtk-3-dev \
sudo apt-get install -y lld-14 llvm-14 llvm-14-dev clang-14 || sudo apt-get install -y lld llvm llvm-dev clang \
sudo apt-get install -y gcc-$(gcc --version|head -n1|sed 's/\..*//'|sed 's/.* //')-plugin-dev libstdc++-$(gcc --version|head -n1|sed 's/\..*//'|sed 's/.* //')-dev \
sudo apt-get install -y ninja-build # for QEMU mode \
sudo apt-get install -y cpio libcapstone-dev # for Nyx mode \
sudo apt-get install -y wget curl # for Frida mode \
sudo apt-get install -y python3-pip # for Unicorn mode \
\
sudo wget -qO- https://apt.llvm.org/llvm.sh | sudo bash -s -- 17 \
cd mutators \
rm -rf build \
cmake -S . -B build -G Ninja -DLLVM_DIR=/usr/lib/llvm-17/lib/cmake/llvm   -DClang_DIR=/usr/lib/llvm-17/lib/cmake/clang \
cmake --build build -j \
./build/constant-mutator ../seed0.c -- 12345 \
