#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "modules/fp11_04_module.c"

int main(void) {
  // 演習 3
  printf("%s\n", "演習 4");
  printf("%.20f\n", 1.4142135623730951);
  printf("calc04(2.0, 10) sqrt =>  %.20f\n", calc04(2.0, 10));
  printf("calc04(2.0, 100) sqrt =>  %.20f\n", calc04(2.0, 100));
  printf("calc04(2.0, 1000) sqrt =>  %.20f\n", calc04(2.0, 1000));
  printf("calc04(2.0, 10000) sqrt =>  %.20f\n", calc04(2.0, 10000));
  printf("calc04(2.0, 100000) sqrt =>  %.20f\n", calc04(2.0, 100000));
  printf("calc04(2.0, 1000000) sqrt =>  %.20f\n", calc04(2.0, 1000000));
  printf("calc04(2.0, 10000000) sqrt =>  %.20f\n", calc04(2.0, 10000000));
  return FALSE;
}
