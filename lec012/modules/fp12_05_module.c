#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int coin(int i, int *c) {
  return (i < 0) ? 0 : c[i];
}

int initialize(int *c, int *csel, int rmax) {
  if(c == NULL || csel == NULL || rmax == 0){
      return FALSE;
  }

  int sel = 0;
  int num = 0;
  int cnt = 0;
  c[0] = 0;
  for(int i = 1; i <= rmax; i++){
    num = 0;
    cnt = i;
    if(cnt / 25 >= 1){
      num += cnt / 25;
      cnt -= (cnt / 25) * 25;
      sel = 25;
    }
    if(cnt / 10 >= 1){
      num += cnt / 10;
      cnt -= (cnt / 10) * 10;
      sel = 10;
    }
    if(cnt / 5 >= 1){
      num += cnt / 5;
      cnt -= (cnt / 5) * 5;
      sel = 5;
    }
    if(cnt > 0){
      num += cnt;
      sel = 1;
    }
    c[i] = num;
    csel[i] = sel;
  }
  return TRUE;
}
