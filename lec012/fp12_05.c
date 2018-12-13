#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "modules/fp12_05_module.c"

#define RMAX 31
#define TRUE 1
#define FALSE 0
//============================================================================//
// 演習 5 「釣り銭問題」も動的計画法が使える典型的な問題です。
// たとえば、米国だとコインの額面が「1¢」「5¢」「10¢」「25¢」の 4 種類なので、
// ある金額 (¢) を与えられたとき「何枚」コ14インがあれば済むかを決めるのはちょっと面倒です。
// これも、次のように考えると動的計画法で解けます (ただし coins(0) = 0 と定義します)。
//============================================================================//
int main(void){
  int n;
  int *c = (int *)malloc(RMAX * sizeof(int));
  int *csel = (int *)malloc(RMAX * sizeof(int));

  initialize(c, csel, RMAX);
  while(TRUE) {
    printf("input number (0 for end)> ");
    scanf("%d", &n);
    if(n == 0) {
      return 0;
    }
    if(n<0 || n >= RMAX-1) {
      printf("%d: invalid\\", n);
      continue;
    }
    printf("room price for %d => %d;", n, c[n]);
    while(n > 0) {
      printf(" %d", csel[n]); n -= csel[n];
    }
    printf("\n");
  }

  free(c);
  free(csel);
  return 0;
}
