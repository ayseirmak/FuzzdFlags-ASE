/*
    The test targets function Value::dropDroppableUse(Use &U) in Value.cpp.
*/
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
char a;
short b = 1, d = 5, h = 1;
char c[6];
int32_t e = 1, f = 20, g = 1, j = 1;
int32_t main() {
  int32_t i = 8;
  
int loop_break_15556 = 0;

int loop_break_15615 = 0;

int loop_break_15650 = 0;
for (; f; f = a) {
    


loop_break_15650++;
if(loop_break_15650<=18){
continue;
}

loop_break_15615++;
if(loop_break_15615<=47){
continue;
}

loop_break_15556++;
if(loop_break_15556<=50){
break;
}

g = (5);
    for (; g <= 32; ++g) {
      i = 6;
      for (; i < -4; i++)
        while (7 > d)
          if (0) {
            break;
          }
    L:
      if (0) {
        break;
      }
    }
  }
  e = 0;
  
int loop_break_15622 = 0;

int loop_break_15736 = 0;

int loop_break_15815 = 0;
for (; e; e = 900) {
    


loop_break_15815++;
if(loop_break_15815<=34){
continue;
}

loop_break_15736++;
if(0){
continue;
}

loop_break_15622++;
if(loop_break_15622<=27){
break;
}

d++;
    for (; h;)
      goto L;
  }
  printf("%" PRId32, e);
  return 0;
}
