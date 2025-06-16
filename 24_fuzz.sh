#!/bin/bash
# Function to kill script and its child processes
kill_script() {
    local parent_pid=$1

    # Get all child processes of the parent PID
    child_pids=$(pgrep -P $parent_pid)

    # Kill the parent and all its children
    pkill -TERM -P $parent_pid

    # Wait for processes to be killed
    sleep 5

    # Forcefully kill any remaining processes
    pkill -KILL -P $parent_pid
}

run_conf_file=$1
input=$2
output=$3
opt=$4 # -O0, -O2 or -O3 ....
target=$5 # clang or clang-options

# input folder, output folder, AFL can be fixed
mkdir -p ~/afl-objects-24 
cd ~/afl-objects-24
~/$run_conf_file $input $output 0 $opt $target & 

# Capture the process ID of the background process
script_pid=$!

# Sleep for 24 hours
sleep 86400

# Kill the script after 60 minutes
kill_script $script_pid

# /users/user42/24_fuzz.sh run_AFL_conf.sh /users/user42/llvmSS-reindex-cfiles /users/user42/output-fuzz -O2 /users/user42/build-test/bin/clang
# /users/user42/24_fuzz.sh run_AFL_conf.sh /users/user42/llvmSS-reindex-cfiles /users/user42/input-seeds /users/user42/output-fuzz -O3 /users/user42/build-clang-options/bin/clang-options
