#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "modules/fp11_05_module.c"

int main(void) {
  // 演習 3
  printf("%s\n", "演習 5");
  printf("%.20f\n", 1.4142135623730951);
  printf("calc05(2.0, 1)        sqrt =>  %.20f\n", calc05(2.0, 1));
  printf("calc05(2.0, 2)        sqrt =>  %.20f\n", calc05(2.0, 2));
  printf("calc05(2.0, 3)        sqrt =>  %.20f\n", calc05(2.0, 3));
  printf("calc05(2.0, 4)        sqrt =>  %.20f\n", calc05(2.0, 4));
  printf("calc05(2.0, 5)        sqrt =>  %.20f\n", calc05(2.0, 5));
  printf("calc05(2.0, 10)       sqrt =>  %.20f\n", calc05(2.0, 10));
  printf("calc05(2.0, 100)      sqrt =>  %.20f\n", calc05(2.0, 100));
  printf("calc05(2.0, 1000)     sqrt =>  %.20f\n", calc05(2.0, 1000));
  printf("calc05(2.0, 10000)    sqrt =>  %.20f\n", calc05(2.0, 10000));
  printf("calc05(2.0, 100000)   sqrt =>  %.20f\n", calc05(2.0, 100000));
  printf("calc05(2.0, 1000000)  sqrt =>  %.20f\n", calc05(2.0, 1000000));
  printf("calc05(2.0, 10000000) sqrt =>  %.20f\n", calc05(2.0, 10000000));
  //--------------------------------------------------------------------//
  printf("%s\n", "//----------------------------------------------------//");
  printf("%.20f\n", 1.4142135623730951);
  printf("calc05(25.0, 1)       sqrt =>  %.20f\n", calc05(25.0, 1));
  printf("calc05(25.0, 2)       sqrt =>  %.20f\n", calc05(25.0, 2));
  printf("calc05(25.0, 3)       sqrt =>  %.20f\n", calc05(25.0, 3));
  printf("calc05(25.0, 4)       sqrt =>  %.20f\n", calc05(25.0, 4));
  printf("calc05(25.0, 5)       sqrt =>  %.20f\n", calc05(25.0, 5));
  printf("calc05(25.0, 10)      sqrt =>  %.20f\n", calc05(25.0, 10));
  printf("calc05(25.0, 100)     sqrt =>  %.20f\n", calc05(25.0, 100));
  printf("calc05(25.0, 1000)    sqrt =>  %.20f\n", calc05(25.0, 1000));
  //--------------------------------------------------------------------//
  printf("%s\n", "//----------------------------------------------------//");
  printf("%.20f\n", 1.4142135623730951);
  printf("calc05(36.0, 1)       sqrt =>  %.20f\n", calc05(36.0, 1));
  printf("calc05(36.0, 2)       sqrt =>  %.20f\n", calc05(36.0, 2));
  printf("calc05(36.0, 3)       sqrt =>  %.20f\n", calc05(36.0, 3));
  printf("calc05(36.0, 4)       sqrt =>  %.20f\n", calc05(36.0, 4));
  printf("calc05(36.0, 5)       sqrt =>  %.20f\n", calc05(36.0, 5));
  printf("calc05(36.0, 10)      sqrt =>  %.20f\n", calc05(36.0, 10));
  printf("calc05(36.0, 100)     sqrt =>  %.20f\n", calc05(36.0, 100));
  printf("calc05(36.0, 1000)    sqrt =>  %.20f\n", calc05(36.0, 1000));
  //--------------------------------------------------------------------//
  printf("%s\n", "//----------------------------------------------------//");
  printf("%.20f\n", 1.4142135623730951);
  printf("calc05(2,500,000,000.0, 1)       sqrt =>  %.20f\n", calc05(2500000000.0, 1));
  printf("calc05(2,500,000,000.0, 2)       sqrt =>  %.20f\n", calc05(2500000000.0, 2));
  printf("calc05(2,500,000,000.0, 3)       sqrt =>  %.20f\n", calc05(2500000000.0, 3));
  printf("calc05(2,500,000,000.0, 4)       sqrt =>  %.20f\n", calc05(2500000000.0, 4));
  printf("calc05(2,500,000,000.0, 5)       sqrt =>  %.20f\n", calc05(2500000000.0, 5));
  printf("calc05(2,500,000,000.0, 10)      sqrt =>  %.20f\n", calc05(2500000000.0, 10));
  printf("calc05(2,500,000,000.0, 20)      sqrt =>  %.20f\n", calc05(2500000000.0, 20));
  printf("calc05(2,500,000,000.0, 30)      sqrt =>  %.20f\n", calc05(2500000000.0, 30));
  printf("calc05(2,500,000,000.0, 100)     sqrt =>  %.20f\n", calc05(2500000000.0, 100));
  printf("calc05(2,500,000,000.0, 1000)    sqrt =>  %.20f\n", calc05(2500000000.0, 1000));
  return FALSE;
}
