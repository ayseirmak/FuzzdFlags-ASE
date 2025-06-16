# AFL_MAP_SIZE=4194304 AFL_USE_ASAN=0 AFL_SKIP_BIN_CHECK=1 AFL_NO_FORKSRV=1 AFL_SHUFFLE_QUEUE=1 AFL_NO_AFFINITY=1 AFL_SKIP_CPUFREQ=1 AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 \ 
# afl-fuzz -m none -t 500 -T 10 -i /users/user42/llvmSS-c-corpus -o /users/user42/output -- /users/user42/build-clang-options/bin/clang-option --filebin @@

# USE FULL PATHS
input=$1      # E.G. /users/user42/input-seeds
output=$2     # E.G. /users/user42/output-afl
resume=$3     # 0 - new run, 1 - resume
opt=$4        # E.G. -O0 ...
targetbin=$5  # E.G. /users/user42/build-clang-options/bin/clang-options

date
if [ $# -le 3 ]; then
    echo "Usage: $0 <input> <output> <resume_flag> <target>"
    exit 1
fi


if [ "$resume" -eq 1 ]; then
    # Resume fuzzing
    AFL_MAP_SIZE=4194304 AFL_USE_ASAN=0 AFL_SKIP_BIN_CHECK=1 AFL_NO_FORKSRV=1 AFL_SHUFFLE_QUEUE=1 AFL_NO_AFFINITY=1 \
AFL_SKIP_CPUFREQ=1 AFL_AUTORESUME=1 AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 \
afl-fuzz -m none -t 500 -T 10 -i $input -o $output -- $targetbin --filebin @@
else
    # Starts a new fuzzing
    AFL_MAP_SIZE=4194304 AFL_USE_ASAN=0 AFL_SKIP_BIN_CHECK=1 AFL_NO_FORKSRV=1 AFL_SHUFFLE_QUEUE=1 AFL_NO_AFFINITY=1 \
AFL_SKIP_CPUFREQ=1 AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 \
afl-fuzz -m none -t 500 -T 10 -i $input -o $output -- $targetbin --filebin @@ 
fi
echo "==End Fuzzing round, script run_AFL_conf_clangopt =="
date
echo "input=$1; output=$2; resume=$3; opt=-O0; targetbin=$5"
