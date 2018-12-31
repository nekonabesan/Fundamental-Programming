
//#include "fp13_04_header.c"
struct pat {
  char a[MAX];
};
struct pat tmp[MAX];

//====================================================//
//
//
//====================================================//
bool inittmp(void){
  for(int i = 0; i < MAX; i++){
    for(int j = 0; j < 10; j++){
      tmp[i].a[j] = 0x00;
    }
  }
  return true;
}

//====================================================//
// 構文解釈の格納された配列の要素数を数える処理
// @param struct analysis apars[]
// @return int cnt
//====================================================//
int countapars(struct analysis apars[]){
  int cnt = 0;
  while(1){
    if(apars[cnt].c == 0x00){
      break;
    }
    cnt++;
  }
  return cnt;
}

//====================================================//
// NAF変換結果の格納された配列の要素数を数える処理
// @param struct analysis apars[]
// @return int cnt
//====================================================//
int countnaf(struct pat anaf[]){
  int cnt = 0;
  while(1){
    if(anaf[cnt].a[0] == 0x00){
      break;
    }
    cnt++;
  }
  return cnt;
}

//====================================================//
// 大域変数nafに格納された構造体の変数aに1文字を追加する処理
// @param  char *pattern
// @param char c
// @param int l1
// @return cnt
//====================================================//
int addpat(struct pat anaf[], char c, int l1){
  int cnt = 0;
  int k = 0;
  while(1){
    if(strlen(anaf[cnt].a) == l1){
      cnt++;
      continue;
    }
    for(k = 0; k < strlen(anaf[cnt].a); k++){
      if(anaf[cnt].a[k] == CODE_ZERO_EXCEPTION){
        anaf[cnt].a[k] = c;
        anaf[cnt].a[k + 1] = 0x00;
        break;
      }
      if (anaf[cnt].a[k + 1] == 0x00) {
        anaf[cnt].a[k + 1] = c;
        anaf[cnt].a[k + 2] = 0x00;
        break;
      }
    }
    if(strlen(anaf[cnt].a) == 0){
      anaf[cnt].a[0] = c;
      anaf[cnt].a[1] = 0x00;
    }
    if(anaf[cnt + 1].a[0] == 0x00){
      break;
    } else {
      cnt++;
    }
  }
  return cnt;
}

//====================================================//
// 大域変数nafに格納された構造体の変数aに0文字を追加した
// パターンと1文字追加したパターンを追加する処理
// @param struct pat* anaf
// @param char str
// @param int len
// @param int flg
// @return struct pat* naf
//====================================================//
bool zero_or_one(struct pat anaf[], char str, int len, int flg){
  int cnt = countnaf(anaf);
  int pos = 0;
  // 置換用領域を初期化
  // NAFのデータを一時配列へ退避する
  for(int i = 0; i < cnt; i++){
    for(int j = 0; j < strlen(anaf[i].a); j++){
      tmp[i].a[j] = anaf[i].a[j];
      tmp[i + 1].a[j] = 0x00;
    }
  }
  // NAFに格納された文字列の最後尾に1文字1追記
  //if(strlen(naf[0].a) == 0){
  if(anaf[0].a[0] == 0x00){
    // 初期化処理
    // NAFが空の場合先頭へ1文字追記
    anaf[0].a[0] = str;
    anaf[0].a[1] = 0x00;
    anaf[1].a[0] = CODE_ZERO_EXCEPTION;
    anaf[1].a[1] = 0x00;
    anaf[2].a[0] = 0x00;
    printf("%d\n", cnt);
    return true;
  } else {
    // 最後尾へ1文字追記
    for(int i = 0; i < cnt; i++){
      for(int j = 0; j < strlen(anaf[i].a); j++){
        // 0文字のパターンは上書き処理
        if(anaf[i].a[j] == CODE_ZERO_EXCEPTION){
          anaf[i].a[j] = str;
          anaf[i].a[j + 1] = 0x00;
          break;
        }
        if(j == (strlen(anaf[i].a)) - 1){
          anaf[i].a[j + 1] = str;
          anaf[i].a[j + 2] = 0x00;
          break;
        }
      }
    }
    // 終端文字追記
    anaf[cnt].a[0] = 0x00;
  }
  // 配列Marge
  for(int i = 0; i < cnt; i++){
    for(int j = 0; j <= strlen(anaf[i].a); j++){
      anaf[i + cnt].a[j] = tmp[i].a[j];
    }
    anaf[i + cnt + 1].a[0] = 0x00;
  }
  // 一時配列初期化
  inittmp();
  return true;
}

//====================================================//
// 大域変数nafに格納された構造体の変数aに0～N文字を追加した
// パターンの処理
// @param struct pat* naf
// @param char str
// @param int len
// @param int flg
// @return struct pat* naf
//====================================================//
bool zero_to_n(struct pat anaf[], char str, int len, int flg){
  return true;
}

//====================================================//
// 大域変数nafに格納された構造体の変数aに1～N文字を追加した
// パターンの処理
// @param struct pat* naf
// @param char str
// @param int len
// @param int flg
// @return struct pat* naf
//====================================================//
bool one_to_n(struct pat anaf[], char str, int len, int flg){
  return true;
}


//====================================================//
// 大域変数nafに格納された構造体の変数aに1文字を追加した
// パターンと０文字追加したパターンを追加する処理
// @param pat *naf
// @param char str
// @param int len
// @param int flg
// @return struct pat* naf
//====================================================//
bool raddpat(struct pat anaf[], char str, int len, int flg){
  switch (flg) {
    // 0または1文字のパターン
    case ZERO_OR_ONE:
      zero_or_one(anaf, str, len, flg);
      break;
    // 0またはN文字
    case ZERO_TO_N:
      zero_to_n(anaf, str, len, flg);
      break;
    // 1文字またはN文字
    case ONE_TO_N:
      one_to_n(anaf, str, len, flg);
      break;
  }

  return true;
}

//====================================================//
// 構文解釈の処理
// @param struct analysis *apars
// @param struct pat *anaf
// @param char *pattern
// @param char *match
// @return bool
//====================================================//
bool convnaf(struct analysis apars[], struct pat anaf[], char pattern[], char match[]){
  if(pattern == "" || pattern == NULL){
    return false;
  }
  int cnt_apars = countapars(apars);
  int l1 = strlen(match);
  int l2 = strlen(pattern);
  bool result = true;
  // 一時配列初期化
  inittmp();
  // NAF変換
  //printf("%d\n", cnt_apars);
  for(int i = 0; i < cnt_apars; i++){
    /*if(apars[i].c == 0x00){
      break;
    }*/
    //printf("%c", apars[i].c);
    switch (apars[i].seq) {
      // a . 「+」(1 回以上の繰り返し)
      case ONE_OR_MORE_ITERATIONS:
        // N回のパターン
        // pattern配列の末尾に文字を追加する。
        //naf = raddpat(naf, apars[i].c, l1, ONE_TO_N);
        break;
      // に加えて「*」(0 回以上の繰り返し) も記述できるようにしてみなさい。
      case ZERO_OR_MORE_ITERATIONS:
        // 0回のパターン
        // N回のパターン
        //naf = raddpat(naf, apars[i].c, l1, ZERO_TO_N);
        break;
      // b. 「?」(直前の文字があってもなくてもよい) を実現してみなさい。
      case MAY_OR_MAY_NOT_BE_PRESENT:
        raddpat(anaf, apars[i].c, l1, ZERO_OR_ONE);
        break;
      // 実装しない
      //case START_MALTI_PATTERN:
        //break;
      default:
        // pattern配列の末尾に文字を追加する。
        addpat(anaf, apars[i].c, l1);
        break;
    }
    printf("in functon convnaf :  %s\n", anaf[1].a);
  }

  return result;
}
