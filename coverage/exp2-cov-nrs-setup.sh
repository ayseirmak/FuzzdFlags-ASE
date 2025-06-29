
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
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/41-cov-analysis-multirep.sh
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/5-cov-table.sh
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/51-inner-LH_file.sh
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/61-backend-cov-analysis.sh
wget https://raw.githubusercontent.com/ayseirmak/FuzzdFlags-ASE/refs/heads/main/coverage/62-middleend-cov-analysis.sh


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

mkdir -p /users/user42/nrs
mkdir -p /users/user42/nrs-semi-smart

wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp21-nrs-seeds.tar.gz
tar -zxvf exp21-nrs-seeds.tar.gz --strip-components=1 -C /users/user42/nrs
wget https://github.com/ayseirmak/FuzzdFlags-ASE/releases/download/v1.0.0-alpha.1/exp22-nrs-semi-smart-seeds.tar.gz
tar -zxvf exp22-nrs-semi-smart-seeds.tar.gz --strip-components=1 -C  /users/user42/nrs-semi-smart

# rm nrs/crash_flags.txt  nrs/hang_flags.txt nrs/summary_counters.txt
# rm nrs-semi-smart/crash_flags.txt  nrs-semi-smart/hang_flags.txt nrs-semi-smart/summary_counters.txt

mkdir -p coverage-measurement
cd coverage-measurement
mkdir -p nrs-cov/nrs nrs-cov/nrs-semi-smart
cd ~

cd /users/user42/coverage-measurement/nrs-cov/nrs
nohup /users/user42/32-gfauto-nrs-fuzzdflags.sh /users/user42/nrs /users/user42/coverage/llvm-clang-1 > exp21-nrs-cov.log 2>&1 &

cd /users/user42/coverage-measurement/nrs-cov/nrs-semi-smart
nohup /users/user42/32-gfauto-nrs-fuzzdflags.sh /users/user42/nrs-semi-smart /users/user42/coverage/llvm-clang-2 > exp22-nrs-semi-smart-cov.log 2>&1 &

cd ~
nohup /users/user42/41-cov-analysis-multirep.sh ~/coverage-measurement/nrs-cov/nrs /users/user42/coverage/llvm-clang-1 table_line_cov_nrs.csv > cov-mes-nrs.log 2>&1 &
nohup /users/user42/41-cov-analysis-multirep.sh ~/coverage-measurement/nrs-cov/nrs-semi-smart /users/user42/coverage/llvm-clang-2 table_line_cov_nrs-semi-smart.csv > cov-mes-nrs-semi-smart.log 2>&1 &

tar -czvf exp2-nrs-cov-analysis.tar.gz -C /users/user42/coverage-measurement/ nrs-cov
tar -czvf exp21-nrs-cov-result.tar.gz -C /users/user42/coverage/llvm-clang-1 coverage_processed coverage_gcda_files
tar -czvf exp22-nrs-semi-smart-cov-result.tar.gz -C /users/user42/coverage/llvm-clang-2 coverage_processed coverage_gcda_files
