#!/usr/bin/env bash
#
# This script:
#  1) Goes into directory/
#  2) Iterates rep1 through rep5
#  3) Runs the coverage table script (4-cov-table.sh)
#  4) Greps various paths from table__all_1_0.csv and sums up coverage
#  5) Logs everything (commands + outputs) to a log file
#  6) Can be run in the background via 'nohup' or '&'.

set -e          # Exit on any command failing
set -u          # Treat unset variables as an error
set -o pipefail # Catch errors in piped commands

# If you also want to see each command as it’s executed in the log, do:
set -x

# Decide where you want the log to go. You could also hardcode it, e.g.:
workdir=$1
llvm_file=$2
table_name=$3
LOGFILE="$workdir/coverage_analysis.log"

# Redirect *all* script output (stdout + stderr) into $LOGFILE.
# Using exec changes redirections for the entire script from this point forward.
exec >"$LOGFILE" 2>&1

echo "===== STARTING SCRIPT at $(date) ====="
# Move into m2 directory (if it exists)
cd "$workdir" || { echo "Could not cd to $workdir "; exit 1; }
mapfile -t coverage_dirs < <(find "$llvm_file/coverage_processed" -maxdepth 1 -mindepth 1 -type d | sort)

# Loop from 1 to 5
for i in 1 2 3 4 5; do
  covdir=${coverage_dirs[$i-1]}
  echo
  echo "===== PROCESSING rep$i at $(date) ====="
  rm -rf "$workdir/rep$i" || { echo "Could not remove $workdir/rep$i"; exit 1; }
  mkdir -p "$workdir/rep$i" || { echo "Could not create $workdir/rep$i"; exit 1; }
  cd "$workdir/rep$i" || { echo "Could not cd to $workdir/rep$i"; exit 1; }

  # 1) Run the coverage table script
  #    Adjust paths/names as needed:
  /users/user42/5-cov-table.sh \
    "${covdir}/line/cov.out" \
    "$table_name"

  # 2) Summation commands:

  echo "---- Linking & Execution ----"
  cat "$table_name" \
    | grep -e'llvm/lib/Linker/' -e'llvm/lib/LTO/' -e'llvm/lib/ExecutionEngine/' -e'llvm/lib/Object/' -e'llvm/lib/BinaryFormat/' -e'llvm/lib/ObjectYAML/' -e'llvm/include/llvm/Linker/' -e'llvm/include/llvm/LTO/' -e'llvm/include/llvm/ExecutionEngine/' -e'llvm/include/llvm/Object/' -e'llvm/include/llvm/BinaryFormat/' -e'llvm/include/llvm/ObjectYAML/' -e'llvm/lib/InterfaceStub/' -e'llvm/include/llvm/InterfaceStub/' \
    | awk -F, '
        # 1. NR==1 -> skip header 
        # 2. Foe each row 2nd col = total_lines; 3rd col  = covered_lines;
        NR > 1 {
          total += $2;
          covered += $3;
          pct       = ($3>0 ? ($3/$2*100) : 0);
          sum_pct  += pct;
          count++;
        }
        END {
          printf "Total Lines: %d\n", total;
          printf "Covered Lines: %d\n", covered;
        }'

  echo "---- Cross-Cutting Components ----"
  cat "$table_name" \
    | grep -e'llvm/lib/DebugInfo/' -e'llvm/lib/Support/' -e'llvm/include/llvm/DebugInfo/' -e'llvm/include/llvm/Support/' -e'llvm/lib/Option/' -e'llvm/include/llvm/Option/' -e'llvm/lib/Demangle/' -e'llvm/include/llvm/Demangle/' -e'llvm/lib/ProfileData/' -e'llvm/include/llvm/ProfileData/' -e'llvm/lib/Remarks/' -e'llvm/include/llvm/Remarks/' \
    | awk -F, '
        # 1. NR==1 -> skip header 
        # 2. Foe each row 2nd col = total_lines; 3rd col  = covered_lines;
        NR > 1 {
          total += $2;
          covered += $3;
          pct       = ($3>0 ? ($3/$2*100) : 0);
          sum_pct  += pct;
          count++;
        }
        END {
          printf "Total Lines: %d\n", total;
          printf "Covered Lines: %d\n", covered;
        }'


  echo "---- Tools & Utilities ----"
  cat "$table_name" \
    | grep -e'llvm/utils/TableGen/' -e'llvm/include/llvm/TableGen/' -e'llvm/tools/' -e'llvm/utils/' -e'llvm-build/' -e'/usr/include/' -e'llvm/lib/LineEditor/' -e'llvm/include/llvm/LineEditor/' \
    | awk -F, '
        # 1. NR==1 -> skip header 
        # 2. Foe each row 2nd col = total_lines; 3rd col  = covered_lines;
        NR > 1 {
          total += $2;
          covered += $3;
          pct       = ($3>0 ? ($3/$2*100) : 0);
          sum_pct  += pct;
          count++;
        }
        END {
          printf "Total Lines: %d\n", total;
          printf "Covered Lines: %d\n", covered;
        }'
  
  echo "---- Backend Analysis ----"
  cat "$table_name" \
    | grep -e'clang/lib/CodeGen/' -e'llvm/lib/CodeGen/' -e'llvm/lib/MC/'  -e'llvm/lib/MCA/' -e'llvm/lib/Target/' -e'clang/include/clang/CodeGen/' -e'llvm/include/llvm/CodeGen/' -e'llvm/include/llvm/Target/' -e'llvm/include/llvm/MC/' -e'llvm/include/llvm/MCA/'  \
    | awk -F, '
        # 1. NR==1 -> skip header 
        # 2. Foe each row 2nd col = total_lines; 3rd col  = covered_lines;
        NR > 1 {
          total += $2;
          covered += $3;
          pct       = ($3>0 ? ($3/$2*100) : 0);
          sum_pct  += pct;
          count++;
        }
        END {
          printf "Total Lines: %d\n", total;
          printf "Covered Lines: %d\n", covered;
        }'

  echo "---- Middle-end Analysis ----"
  cat "$table_name" \
    | grep -e'clang/lib/Analysis/' -e'llvm/lib/Analysis/' -e'llvm/lib/AsmParser/' -e'llvm/lib/Bitcode/'  -e'llvm/lib/IR/' -e'llvm/lib/IRReader/' -e'llvm/lib/Passes/' -e'llvm/lib/Transforms/' -e'llvm/include/llvm/Analysis/' -e'llvm/include/llvm/AsmParser/' -e'llvm/include/llvm/Bitcode/' -e'llvm/include/llvm/IR/' -e'llvm/include/llvm/IRReader/' -e'llvm/include/llvm/Passes/'  -e'llvm/include/llvm/Transforms/' -e'clang/include/clang/Analysis/'\
    | awk -F, '
        # 1. NR==1 -> skip header 
        # 2. Foe each row 2nd col = total_lines; 3rd col  = covered_lines;
        NR > 1 {
          total += $2;
          covered += $3;
          pct       = ($3>0 ? ($3/$2*100) : 0);
          sum_pct  += pct;
          count++;
        }
        END {
          printf "Total Lines: %d\n", total;
          printf "Covered Lines: %d\n", covered;
        }'

  echo "---- Frontend Analysis ----"
  cat "$table_name" \
    | grep -e'clang/lib/APINotes/' -e'clang/include/clang/APINotes/' -e'clang/lib/AST/' -e'clang/include/clang/AST/' -e'clang/lib/Basic/' -e'clang/include/clang/Basic/' -e'clang/lib/Driver/' -e'clang/include/clang/Driver/' -e'clang/lib/Edit/' -e'clang/include/clang/Edit/' -e'clang/lib/Format/' -e'clang/include/clang/Format/' -e'clang/lib/Frontend/' -e'clang/include/clang/Frontend/' -e'clang/lib/FrontendTool/' -e'clang/include/clang/FrontendTool/' -e'clang/lib/Index/' -e'clang/include/clang/Index/' -e'clang/lib/Lex/' -e'clang/include/clang/Lex/' -e'clang/lib/Parse/' -e'clang/include/clang/Parse/' -e'clang/lib/Rewrite/' -e'clang/include/clang/Rewrite/' -e'clang/lib/Sema/' -e'clang/include/clang/Sema/' -e'clang/lib/Serialization/' -e'clang/include/clang/Serialization/' -e'clang/lib/StaticAnalyzer/' -e'clang/include/clang/StaticAnalyzer/' -e'clang/lib/Tooling/' -e'clang/include/clang/Tooling/' \
    | awk -F, '
        # 1. NR==1 -> skip header 
        # 2. Foe each row 2nd col = total_lines; 3rd col  = covered_lines;
        NR > 1 {
          total += $2;
          covered += $3;
          pct       = ($3>0 ? ($3/$2*100) : 0);
          sum_pct  += pct;
          count++;
        }
        END {
          printf "Total Lines: %d\n", total;
          printf "Covered Lines: %d\n", covered;
        }'
    
    # Back up one directory to /users/a_irmak/m2
  /users/user42/61-backend-cov-analysis.sh "$workdir/rep$i" "$table_name"
  /users/user42/62-middleend-cov-analysis.sh "$workdir/rep$i" "$table_name"
  cd ..
done

echo "===== FINISHED SCRIPT at $(date) ====="

# End of script
