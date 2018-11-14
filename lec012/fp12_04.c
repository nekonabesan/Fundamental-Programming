#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "modules/fp12_04_module.c"

#define RMAX 1000
#define TRUE 1
#define FALSE 0
//============================================================================//
// 演習 4 上の例題を打ち込んでそのまま動かしなさい
// (最初はトレースバック無しの簡単な方を動かし、
// 動いてからトレースバックを追加した方が楽だと思います)。
// 動いたら、「13 人部屋 3 万円」「17 人部屋 4 万円」の選択肢を追加して動かしてみなさい。
//============================================================================//
int main(void){
  int n;
  int *roomprice = (int *)malloc(RMAX * sizeof(int));
  int *roomsel = (int *)malloc(RMAX * sizeof(int));

  initialize(roomprice, roomsel, RMAX);
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
    printf("room price for %d => %d;", n, roomprice[n]);
    while(n > 0) {
      printf(" %d", roomsel[n]); n -= roomsel[n];
    }
    printf("\n");
  }

  free(roomprice);
  free(roomsel);
  return 1;
}
