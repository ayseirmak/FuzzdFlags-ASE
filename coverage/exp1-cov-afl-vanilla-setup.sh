
#!/bin/bash
# This script is for setting up a local environment for the input corpus coverage with -O2 flag.
sudo useradd -m -d /users/user42 -s /bin/bash user42
sudo passwd user42
sudo usermod -aG sudo user42
sudo usermod -aG kclsystemfuzz-PG user42
sudo chown -R user42:user42 /users/user42
sudo chmod 777 /users/user42
sudo apt-get update && sudo apt-get upgrade -y
sudo chown -R user42:user42 /users/user42/

cd /users/user42
su - user42
# wget default setup scripts
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/0-install-compilers-local.sh
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/1-clone-llvm.sh
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/2-llvm-cov-install.sh

# wget baseline coverage experiment scripts
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/31-gfauto-multirep.sh
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
./2-llvm-cov-install.sh /users/user42/coverage <TMP_SOURCE_FOLDER> 2 > /tmp/llvm2-cov-install.log 2>&1 
./2-llvm-cov-install.sh /users/user42/coverage <TMP_SOURCE_FOLDER> 3 > /tmp/llvm3-cov-install.log 2>&1 

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

mkdir -p /users/user42/afl-vanilla-fuzz-o2
mkdir -p /users/user42/afl-vanilla-fuzz-o3

wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp11-aflvan-O2-fuzz-results.tar.gz
tar -zxvf exp11-aflvan-O2-fuzz-results.tar.gz -C /users/user42/afl-vanilla-fuzz-o2
wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp12-aflvan-O3-fuzz-results.tar.gz
tar -zxvf exp12-aflvan-O3-fuzz-results.tar.gz -C /users/user42/afl-vanilla-fuzz-o3

mkdir -p coverage-measurement
cd coverage-measurement
mkdir -p afl-vanilla-cov/afl-vanilla-o2-cov afl-vanilla-cov/afl-vanilla-o3-cov
cd ~

cd /users/user42/coverage-measurement/afl-vanilla-cov/afl-vanilla-o2-cov 
nohup /users/user42/31-gfauto-multirep.sh  /users/user42/afl-vanilla-fuzz-o2 /users/user42/coverage/llvm-clang-2  -O2 > cov-llvm2-input.log 2>&1 &

cd /users/user42/coverage-measurement/afl-vanilla-cov/afl-vanilla-o3-cov 
nohup /users/user42/31-gfauto-multirep.sh  /users/user42/afl-vanilla-fuzz-o3 /users/user42/coverage/llvm-clang-3  -O3 > cov-llvm3-input.log 2>&1 &

cd ~
nohup /users/user42/41-cov-analysis-multirep-v2.sh ~/coverage-measurement/afl-vanilla-cov/afl-vanilla-o2-cov  /users/user42/coverage/llvm-clang-2 table_line_cov_afl_o2.csv table_function_cov_afl_o2.csv > cov-mes-afl-o2.log 2>&1 &
nohup /users/user42/41-cov-analysis-multirep-v2.sh ~/coverage-measurement/afl-vanilla-cov/afl-vanilla-o3-cov  /users/user42/coverage/llvm-clang-3 table_line_cov_afl_o3.csv table_function_cov_afl_o3.csv > cov-mes-afl-o3.log 2>&1 &

# tar -czvf afl-vanilla-cov-analysis.tar.gz -C /users/user42/coverage-measurement/ afl-vanilla-cov
# tar -czvf cov-afl-vanilla-o2-result.tar.gz -C /users/user42/coverage/llvm-clang-2 coverage_processed coverage_gcda_files
# tar -czvf cov-afl-vanilla-o3-result.tar.gz -C /users/user42/coverage/llvm-clang-3 coverage_processed coverage_gcda_files
