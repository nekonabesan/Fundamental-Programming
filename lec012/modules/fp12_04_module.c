//============================================================================//
// 演習 4 上の例題を打ち込んでそのまま動かしなさい
// (最初はトレースバック無しの簡単な方を動かし、
// 動いてからトレースバックを追加した方が楽だと思います)。
// 動いたら、「13 人部屋 3 万円」「17 人部屋 4 万円」の選択肢を追加して動かしてみなさい。
//============================================================================//
int room1(int i, int *roomprice) {
  return (i < 0) ? 0 : roomprice[i];
}

void initialize(int *roomprice, int *roomsel, int rmax) {
  int i;
  for(i = 1; i < rmax; ++i) {
    int min = room1(i - 1, roomprice) + 5000, sel = 1;
    if(min > room1(i - 3, roomprice) + 12000) {
      min = room1(i - 3, roomprice) + 12000; sel = 3;
    }
    if(min > room1(i - 7, roomprice) + 20000) {
      min = room1(i - 7, roomprice) + 20000; sel = 7;
    }
    roomprice[i] = min;
    roomsel[i] = sel;
  }
}
