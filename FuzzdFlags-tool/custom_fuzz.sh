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
input=$1
output=$2
configuration=$3
target=$4
sleep_time=$5
mkdir -p object-folder
cd object-folder
# We see if 'configuration' is "run_AFL_conf_default.sh" or something else:
if [ "$(basename "$configuration")" == "run_AFL_conf_default.sh" ]; then
  # use the default conf
  echo "[custom_fuzz.sh] Using default run_AFL_conf_default.sh..."
  bash "$configuration" "$input" "${output}" 0 "$target" > ${output}/afl-default.log 2>&1 &
else
  # user provided a custom conf script
  echo "[custom_fuzz.sh] Using user conf script: $configuration"
  bash "$configuration" "$input" "${output}" 0 "$target" > ${output}/afl-custom.log 2>&1 &
fi

script_pid=$!

sleep $sleep_time

# then kill the script
kill_script $script_pid
