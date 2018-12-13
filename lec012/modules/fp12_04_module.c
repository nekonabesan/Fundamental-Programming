#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define RMAX 1000
#define TRUE 1
#define FALSE 0

//============================================================================//
// 演習 4 上の例題を打ち込んでそのまま動かしなさい
// (最初はトレースバック無しの簡単な方を動かし、
// 動いてからトレースバックを追加した方が楽だと思います)。
// 動いたら、「13 人部屋 3 万円」「17 人部屋 4 万円」の選択肢を追加して動かしてみなさい。
//============================================================================//
int room1(int i, int *roomprice) {
  return (i < 0) ? 0 : roomprice[i];
}

// 1 人部屋:5,000 円、3 人部屋:12,000 円、7 人部屋:20,000 円
// 動いたら、「13 人部屋 3 万円」
//「17 人部屋 4 万円」の選択肢を追加して動かしてみなさい。
int initialize(int *roomprice, int *roomsel, int rmax) {
    if(roomprice == NULL || roomsel == NULL || rmax == 0){
        return FALSE;
    }

    roomprice[0] = 0;
    for (int i = 1; i < rmax; i++) {
      int min = room1(i - 1, roomprice) + 5000, sel = 1;
      if(min > room1(i - 3, roomprice) + 12000) {
        min = room1(i - 3, roomprice) + 12000; sel = 3;
      }
      if(min > room1(i - 7, roomprice) + 20000) {
        min = room1(i - 7, roomprice) + 20000; sel = 7;
      }
      if(min > room1(i - 13, roomprice) + 30000) {
        min = room1(i - 13, roomprice) + 30000; sel = 13;
      }
      if(min > room1(i - 17, roomprice) + 40000) {
        min = room1(i - 17, roomprice) + 40000; sel = 17;
      }
      roomprice[i] = min;
      roomsel[i] = sel;
    }

    return TRUE;
}
