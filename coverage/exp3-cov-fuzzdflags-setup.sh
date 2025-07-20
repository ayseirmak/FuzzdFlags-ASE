
#!/bin/bash
# This script is for setting up a local environment for the input corpus coverage with -O2 flag.
sudo useradd -m -d /users/user42 -s /bin/bash user42
sudo passwd user42
sudo usermod -aG sudo user42
sudo usermod -aG kclsystemfuzz-PG user42
sudo chown -R user42:user42 /users/user42
sudo chmod 777 /users/user42
sudo apt-get update && sudo apt-get upgrade -y

cd /users/user42
su - user42
# wget default setup scripts
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/0-install-compilers-local.sh
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/1-clone-llvm.sh
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/2-llvm-cov-install.sh

# wget baseline coverage experiment scripts
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/32-gfauto-nrs-fuzzdflags.sh
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/41-cov-analysis-multirep-v2.sh
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/5-cov-table.sh
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/51-inner-LH_file.sh
# wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/61-backend-cov-analysis.sh
# wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/62-middleend-cov-analysis.sh


sudo chown -R user42:user42 /users/user42/
chmod 777 *.sh

./0-install-compilers-local.sh 
mkdir -p coverage
./1-clone-llvm.sh /users/user42/coverage 19
./2-llvm-cov-install.sh /users/user42/coverage <TMP_SOURCE_FOLDER> 1 > /tmp/llvm1-cov-install.log 2>&1 & 
./2-llvm-cov-install.sh /users/user42/coverage <TMP_SOURCE_FOLDER> 2 > /tmp/llvm2-cov-install.log 2>&1 &

git clone https://github.com/google/graphicsfuzz.git
cd graphicsfuzz/gfauto/
python3 --version # 3.10.2
vi dev_shell.sh.template
EDIT TO YOUR LOCAL VERSION of Python3: PYTHON=${PYTHON-python3.6} to PYTHON=${PYTHON-python3.10}
rm Pipfile.lock (if Python3.8 or above)
./dev_shell.sh.template
cd ../..

wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/llvmSS-minimised-corpus.tar.gz
tar -zxvf llvmSS-minimised-corpus.tar.gz

# mkdir -p /users/user42/fuzzdflags-1-seed
mkdir -p /users/user42/fuzzdflags-30-seed

# wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp31-1seed-fuzz-queue.tar.gz
# tar -zxvf exp31-1seed-fuzz-queue.tar.gz --strip-components=1 -C /users/user42/fuzzdflags-1-seed
wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp32-30seed-fuzz-queue.tar.gz
tar -zxvf exp32-30seed-fuzz-queue.tar.gz --strip-components=1 -C /users/user42/fuzzdflags-30-seed

mkdir -p coverage-measurement
cd coverage-measurement
# mkdir -p fuzzdflags-cov/fuzzdflags-1seed-cov 
mkdir -p fuzzdflags-cov/fuzzdflags-30seed-cov
cd ~

# cd /users/user42/coverage-measurement/fuzzdflags-cov/fuzzdflags-1seed-cov
# nohup /users/user42/32-gfauto-nrs-fuzzdflags.sh /users/user42/fuzzdflags-1-seed /users/user42/coverage/llvm-clang-1 > exp31-fuzzDflags-1seed-cov.log 2>&1 &

cd /users/user42/coverage-measurement/fuzzdflags-cov/fuzzdflags-30seed-cov
nohup /users/user42/32-gfauto-nrs-fuzzdflags.sh /users/user42/fuzzdflags-30-seed /users/user42/coverage/llvm-clang-2 > exp32-fuzzDflags-30seed-cov.log 2>&1 &

cd ~
# nohup /users/user42/41-cov-analysis-multirep.sh ~/coverage-measurement/fuzzdflags-cov/fuzzdflags-1seed-cov /users/user42/coverage/llvm-clang-1 table_line_cov_1seed.csv > cov-mes-fuzzdflag-1seed.log 2>&1 &
nohup /users/user42/41-cov-analysis-multirep-v2.sh ~/coverage-measurement/fuzzdflags-cov/fuzzdflags-30seed-cov /users/user42/coverage/llvm-clang-2 table_line_cov_30seed.csv  table_function_cov_30seed.csv > cov-mes-fuzzdflag-30seed.log 2>&1 &

# tar -czvf exp3-fuzzdflags-cov-analysis.tar.gz -C /users/user42/coverage-measurement/ fuzzdflags-cov
# tar -czvf exp31-fuzzdflags-1seed-cov-result.tar.gz -C /users/user42/coverage/llvm-clang-1 coverage_processed coverage_gcda_files
# tar -czvf exp32-fuzzdflags-30seed-cov-result.tar.gz -C /users/user42/coverage/llvm-clang-2 coverage_processed coverage_gcda_files
