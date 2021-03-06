#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "modules/fp12_03_module.c"
//============================================================================//
// 演習 3 実際に上に説明した方法で「0 番目から 30 番目までのフィボナッチ数列を打ち出す」
// プログラムを作りなさい。さらに、
// 「0～30 までのいずれかの番号を入力すると、その番号のフィボナッチ数列を出力する」
// プログラムも作れるとなおよい。
//============================================================================//
int main(void){
  int *f = (int *)malloc(31 * sizeof(int));
  fib(f, 30);
  for(int i = 0; i <= 30; i++){
    printf("%d ", f[i]);
  }
  printf("\n");
  free(f);
  return 1;
}
