#!/usr/bin/env bash

# -------------------------------------------------------
# 0. Create/Configure a Non-Root User (Optional)
# -------------------------------------------------------
# Adjust group names, etc. according to your environment

sudo useradd -m -d /users/user42 -s /bin/bash user42
sudo passwd user42
sudo usermod -aG sudo user42
sudo usermod -aG kclsystemfuzz-PG user42

# Adjust ownership/permissions as desired:
sudo chown -R user42:user42 /users/user42
sudo chmod 777 /users/user42

# -------------------------------------------------------
# 1. Update & Upgrade the System
# -------------------------------------------------------
sudo apt-get update && sudo apt-get upgrade -y

# -------------------------------------------------------
# 2. Install Docker (Host Only)
# -------------------------------------------------------
sudo apt-get install -y \
  ca-certificates \
  curl \
  gnupg \
  lsb-release \
  wget \
  git

sudo mkdir -p /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/ubuntu/gpg \
  | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg

echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] \
  https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" \
  | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

sudo apt-get update
sudo apt-get install -y \
  docker-ce \
  docker-ce-cli \
  containerd.io \
  docker-buildx-plugin \
  docker-compose-plugin

# Optionally allow user42 to run docker without sudo:
sudo usermod -aG docker user42
# -------------------------------------------------------
# 3. Configure Core Dumps
# -------------------------------------------------------
echo "core" | sudo tee /proc/sys/kernel/core_pattern
# -------------------------------------------------------
# 4. Download Dockerfile & Helper Scripts & Build Fuzzing Image
# -------------------------------------------------------
su - user42
wget -----------------------exp3-nrs-dock.dockerfile

# Build Docker image from the local Dockerfile
docker build -f exp3-nrs-dock.dockerfile -t nrs-img .

# -------------------------------------------------------
# 5. Prepare Output Directories
# -------------------------------------------------------
mkdir -p rep01 rep02 rep03 rep04 rep05
chown -R user42:user42 rep01 rep02 rep03 rep04 rep05
chmod -R 777 rep01 rep02 rep03 rep04 rep05

# -------------------------------------------------------
# 61. Launch 5  Containers for nrs
# -------------------------------------------------------
# NOTE: Adjust --cpuset-cpus according to the actual cores on your m510 node.
# Give each container 3 cores:
# rep01 -> 0-2, rep02 -> 3-5, rep03 -> 6-8, rep04 -> 9-11, rep05 -> 12-14

docker run -d --name rep01 --cpuset-cpus="0-2" \
  -v /users/user42/rep01:/users/user42/output-nrs \
  nrs-img \
  python3 nrs.py

docker run -d --name rep02 --cpuset-cpus="3-5" \
  -v /users/user42/rep02:/users/user42/output-nrs \
  nrs-img \
  python3 nrs.py

docker run -d --name rep03 --cpuset-cpus="6-8" \
  -v /users/user42/rep03:/users/user42/output-nrs \
  nrs-img \
  python3 nrs.py

docker run -d --name rep04 --cpuset-cpus="9-11" \
  -v /users/user42/rep04:/users/user42/output-nrs \
  nrs-img \
  python3 nrs.py

docker run -d --name rep05 --cpuset-cpus="12-14" \
  -v /users/user42/rep05:/users/user42/output-nrs \
  nrs-img \
  python3 nrs.py

echo "All 5 containers started."
# -------------------------------------------------------

# -------------------------------------------------------
# 62. Launch 5  Containers for nrs-semi-smart
# -------------------------------------------------------
# NOTE: Adjust --cpuset-cpus according to the actual cores on your m510 node.
# Give each container 3 cores:
# rep01 -> 0-2, rep02 -> 3-5, rep03 -> 6-8, rep04 -> 9-11, rep05 -> 12-14

docker run -d --name rep01 --cpuset-cpus="0-2" \
  -v /users/user42/rep01:/users/user42/output-nrs \
  nrs-img \
  python3 nrs-semi-smart.py

docker run -d --name rep02 --cpuset-cpus="3-5" \
  -v /users/user42/rep02:/users/user42/output-nrs \
  nrs-img \
  python3 nrs-semi-smart.py

docker run -d --name rep03 --cpuset-cpus="6-8" \
  -v /users/user42/rep03:/users/user42/output-nrs \
  nrs-img \
  python3 nrs-semi-smart.py

docker run -d --name rep04 --cpuset-cpus="9-11" \
  -v /users/user42/rep04:/users/user42/output-nrs \
  nrs-img \
  python3 nrs-semi-smart.py

docker run -d --name rep05 --cpuset-cpus="12-14" \
  -v /users/user42/rep05:/users/user42/output-nrs \
  nrs-img \
  python3 nrs-semi-smart.py
  
# -------------------------------------------------------
# 71. After nrs generation, get results
# -------------------------------------------------------
tar -czvf exp21-nrs-result.tar.gz -C /users/user42/ rep01 rep02 rep03 rep04 rep05
tar -czvf exp21-nrs-result-rep1.tar.gz -C /users/user42/ rep01
tar -czvf exp21-nrs-result-rep2.tar.gz -C /users/user42/ rep02
tar -czvf exp21-nrs-result-rep3.tar.gz -C /users/user42/ rep03
tar -czvf exp21-nrs-result-rep4.tar.gz -C /users/user42/ rep04
tar -czvf exp21-nrs-result-rep5.tar.gz -C /users/user42/ rep05
# -------------------------------------------------------
# 72. After nrs-semi-smart generation, get results
# -------------------------------------------------------
tar -czvf exp22-nrs-semi-smart-result.tar.gz -C /users/user42/ rep01 rep02 rep03 rep04 rep05
tar -czvf exp22-nrs-semi-smart-result-rep1.tar.gz -C /users/user42/ rep01
tar -czvf exp22-nrs-semi-smart-result-rep2.tar.gz -C /users/user42/ rep02
tar -czvf exp22-nrs-semi-smart-result-rep3.tar.gz -C /users/user42/ rep03
tar -czvf exp22-nrs-semi-smart-result-rep4.tar.gz -C /users/user42/ rep04
tar -czvf exp22-nrs-semi-smart-result-rep5.tar.gz -C /users/user42/ rep05


