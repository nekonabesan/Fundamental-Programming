
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
// CODE_ZERO_EXCEPTIONを取り除く処理
// @param struct pat* anaf
// return bool
//====================================================//
bool delete_cze(struct pat anaf[]){
  int cnt = 0;
  int pos = 0;
  while(1){
    pos = strlen(anaf[cnt].a);
    if(anaf[cnt].a[0] == 0x00){
      break;
    }
    for(int i = 0; i < pos; i++){
      if(anaf[cnt].a[i] == CODE_ZERO_EXCEPTION){
        anaf[cnt].a[i] = 0x00;
        break;
      }
    }
    cnt++;
  }
  return true;
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
      if(anaf[cnt].a[k + 1] == 0x00) {
        anaf[cnt].a[k + 1] = c;
        anaf[cnt].a[k + 2] = 0x00;
        break;
      }
    }
    if(strlen(anaf[0].a) == 0){
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
  int eof = 0;
  int tmn = 0;
  // 置換用領域を初期化
  // NAFのデータを一時配列へ退避する
  for(int i = 0; i < cnt; i++){
    tmn = strlen(anaf[i].a);
    for(int j = 0; j < tmn; j++){
      tmp[i].a[j] = anaf[i].a[j];
      tmp[i].a[j + 1] = 0x00;
      tmp[i + 1].a[j] = 0x00;
    }
  }
  // NAFに格納された文字列の最後尾に1文字1追記
  //if(strlen(naf[0].a) == 0){
  if(tmp[0].a[0] == 0x00){
    // 初期化処理
    // NAFが空の場合先頭へ1文字追記
    anaf[0].a[0] = str;
    anaf[0].a[1] = 0x00;
    anaf[1].a[0] = CODE_ZERO_EXCEPTION;
    anaf[1].a[1] = 0x00;
    anaf[2].a[0] = 0x00;
    return true;
  } else {
    // 最後尾へ1文字追記
    for(int i = 0; i < cnt; i++){
      tmn = strlen(tmp[i].a) + 1;
      eof = tmn - 1;
      for(int j = 0; j < tmn; j++){
        // 0文字のパターンは上書き処理
        if(tmp[i].a[j] == CODE_ZERO_EXCEPTION){
          anaf[pos].a[j] = str;
          anaf[pos].a[j + 1] = 0x00;
          break;
        }
        if(j == eof){
          //printf("tmp : %s\n", tmp[i].a);
          //printf("tmn : %d\n", tmn);
          //printf("eof : %d\n", eof);
          anaf[pos].a[j] = str;
          anaf[pos].a[j + 1] = 0x00;
          break;
        } else if(j < eof) {
          anaf[pos].a[j] = tmp[i].a[j];
          anaf[pos].a[j + 1] = 0x00;
        }
      }
      //printf("pos : %d\n", pos);
      //printf("anaf : %s\n", anaf[pos].a);
      pos++;
    }
    // 配列anafへtmpの内容をコピーする
    // 最後尾へ0文字追記
    for(int i = 0; i <= cnt; i++){
      tmn = strlen(tmp[i].a) + 1;
      eof = tmn - 1;
      for(int j = 0; j < tmn; j++){
        // 0文字のパターンは最後尾にフラグを追記
        if(j == eof) {
          //printf("tmp : %s\n", tmp[i].a);
          //printf("tmn : %d\n", tmn);
          //printf("eof : %d\n", eof);
          anaf[pos].a[j] = CODE_ZERO_EXCEPTION;
          anaf[pos].a[j + 1] = 0x00;
          break;
        } else if(j < eof) {
          //printf("tmp : %s\n", tmp[i].a);
          anaf[pos].a[j] = tmp[i].a[j];
          anaf[pos].a[j + 1] = 0x00;
        }
      }
      //printf("pos : %d\n", pos);
      //printf("anaf : %s\n", anaf[pos].a);
      pos++;
    }

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
  int cnt = countnaf(anaf);
  int pos = 0;
  int num = 0;
  int eof = 0;
  int tmn = 0;
  // 置換用領域を初期化
  // NAFのデータを一時配列へ退避する
  for(int i = 0; i < cnt; i++){
    tmn = strlen(anaf[i].a);
    for(int j = 0; j < tmn; j++){
      tmp[i].a[j] = anaf[i].a[j];
      tmp[i].a[j + 1] = 0x00;
      tmp[i + 1].a[j] = 0x00;
    }
  }
  // NAFに格納された文字列の最後尾に1文字1追記
  //if(strlen(naf[0].a) == 0){
  if(tmp[0].a[0] == 0x00){
    // 初期化処理
    // NAFが空の場合先頭へN文字追記
    // 処理対象の文字がmatchの1文字目の場合
    // 初期化処理
    for(int i = 0; i < len; i++){
      for(int j = 0; j <= i; j++){
        anaf[i].a[j] = str;
        anaf[i].a[j + 1] = 0x00;
      }
      printf("%s\n", anaf[i].a);
    }
    anaf[len].a[0] = CODE_ZERO_EXCEPTION;
    anaf[len].a[1] = 0x00;
    // 一時配列初期化
    inittmp();
    return true;
  } else {
    // 配列anafへtmpの内容をコピーする
    for(int i = 0; i < cnt; i++){
      num = len - strlen(tmp[i].a);
      tmn = strlen(tmp[i].a);
      // len - strlen(tmp[i].a)こ配列を複製
      for(int j = 0; j < num; j++){
        for(int k = 0; k <= j; k++){
          if (k < tmn){
            anaf[pos].a[k] = tmp[i].a[k];
          }
          anaf[pos].a[k + tmn] = str;
          anaf[pos + 1].a[k] = 0x00;
        }
        // 要素数をカウントアップ
        pos++;
      }
    }

    // 配列anafへtmpの内容をコピーする
    // 最後尾へ0文字追記
    for(int i = 0; i < cnt; i++){
      tmn = strlen(tmp[i].a) + 1;
      eof = tmn - 1;
      for(int j = 0; j < tmn; j++){
        // 0文字のパターンは最後尾にフラグを追記
        if(j == eof) {
          anaf[pos].a[j] = CODE_ZERO_EXCEPTION;
          anaf[pos].a[j + 1] = 0x00;
          break;
        } else if(j < eof) {
          anaf[pos].a[j] = tmp[i].a[j];
          anaf[pos].a[j + 1] = 0x00;
        }
      }
      pos++;
    }
  }

  // 一時配列初期化
  inittmp();
  return true;
}

//====================================================//
// 大域変数nafに格納された構造体の変数aに1～N文字を追加した
// パターンの処理
// @param struct pat* anaf
// @param char str
// @param int len
// @param int flg
// @return bool
//====================================================//
bool one_to_n(struct pat anaf[], char str, int len, int flg){
  int cnt = countnaf(anaf);
  int pos = 0;
  int length = 0;
  int initial = 0;
  // NAFのデータを一時配列へ退避する
  // 参照用の配列を初期化
  for(int i = 0; i < cnt; i++){
    //printf("%s\n", anaf[i].a);
    for(int j = 0; j < strlen(anaf[i].a); j++){
      if(anaf[i].a[j] == CODE_ZERO_EXCEPTION){
        // 最後尾がCODE_ZERO_EXCEPTIONである場合0x00へ置換する
        tmp[i].a[j] = 0x00;
      } else {
        tmp[i].a[j] = anaf[i].a[j];
      }
      tmp[i + 1].a[j] = 0x00;
    }
  }
  // NAFに格納された文字列の最後尾に1文字1追記
  if(anaf[0].a[0] == 0x00){
    // 処理対象の文字がmatchの1文字目の場合
    // 初期化処理
    for(int i = 0; i < len; i++){
      for(int j = 0; j <= i; j++){
        anaf[i].a[j] = str;
        anaf[i].a[j + 1] = 0x00;
      }
    }
    return true;
  } else {
    // 元の文字列をlen - strlen(tmp[i].a)個複製する処理
    // tmp[i].a 毎に繰り返し処理
    pos = 0;
    for(int i = 0; i < cnt; i++){
      // tmp[i].aをlen - strlen(tmp[i].a)個複製する
      for(int j = 0; j < (len - strlen(tmp[i].a)); j++){
        for(int k = 0; k < strlen(tmp[i].a); k++){
          anaf[pos].a[k] = tmp[i].a[k];
          anaf[pos + 1].a[k] = 0x00;
        }
        // CODE_ZERO_EXCEPTION対応
        // 空文字を含むパターンを係数
        pos++;
      }
    }
    pos = 0;
    // 最後尾へ文字を追記する処理
    // len - strlen(tmp[i].a) * len - strlen(tmp[i].a) * i パターンの文字列を生成
    for(int i = 0; i < cnt; i++){
      length = len - strlen(tmp[i].a);
      // 上書きを避けるため格納されている文字数を取得する
      initial = strlen(tmp[i].a);
      // strlen(pattern) - strlen(anaf[ia]) 回繰り返す
      for(int k = 0; k < length; k++){
        for(int l = 0; l <= k; l++){
          // 最大strlen(pattern)文字
          //if(k < len){
            anaf[pos].a[initial + l] = str;
            anaf[pos].a[initial + l + 1] = 0x00;
          //}
        }
        pos++;
      }
    }
  }

  // 一時配列初期化
  inittmp();

  return true;
}


//====================================================//
// 大域変数nafに格納された構造体の変数aに1文字を追加した
// パターンと０文字追加したパターンを追加する処理
// @param pat *naf
// @param char str
// @param int len
// @param int flg
// @return bool
//====================================================//
bool raddpat(struct pat anaf[], char str, int len, int flg){
  switch (flg) {
    // 0または1文字のパターン
    case MAY_OR_MAY_NOT_BE_PRESENT:
      zero_or_one(anaf, str, len, flg);
      break;
    // 0またはN文字
    case ZERO_OR_MORE_ITERATIONS:
      zero_to_n(anaf, str, len, flg);
      break;
    // 1文字またはN文字
    case ONE_OR_MORE_ITERATIONS:
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
        raddpat(anaf, apars[i].c, l1, ONE_OR_MORE_ITERATIONS);
        break;
      // に加えて「*」(0 回以上の繰り返し) も記述できるようにしてみなさい。
      case ZERO_OR_MORE_ITERATIONS:
        // 0回のパターン
        // N回のパターン
        raddpat(anaf, apars[i].c, l1, ZERO_OR_MORE_ITERATIONS);
        break;
      // b. 「?」(直前の文字があってもなくてもよい) を実現してみなさい。
      case MAY_OR_MAY_NOT_BE_PRESENT:
        raddpat(anaf, apars[i].c, l1, MAY_OR_MAY_NOT_BE_PRESENT);
        break;
      // 実装しない
      //case START_MALTI_PATTERN:
        //break;
      default:
        // pattern配列の末尾に文字を追加する。
        addpat(anaf, apars[i].c, l1);
        break;
    }
    //printf("in functon convnaf :  %s\n", anaf[1].a);
  }

  return result;
}
