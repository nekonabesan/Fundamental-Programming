
//#include "fp13_04_header.c"
struct pat {
  char a[MAX];
};

//====================================================//
// 構文解釈の格納された配列の要素数を数える処理
// @param struct analysis apars[]
// @return int cnt
//====================================================//
int countapars(struct analysis apars[]){
  int cnt = 0;
  while(1){
    cnt++;
    if(apars[cnt].c == 0x00){
      break;
    }
  }
  return cnt;
}

//====================================================//
// NAF変換結果の格納された配列の要素数を数える処理
// @param struct analysis apars[]
// @return int cnt
//====================================================//
int countnaf(struct pat naf[]){
  int cnt = 0;
  while(1){
    cnt++;
    if(naf[cnt].a[0] == 0x00){
      break;
    }
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
int addpat(struct pat naf[], char c, int l1){
  int cnt = 0;
  int k = 0;
  while(1){
    if(strlen(naf[cnt].a) == l1){
      cnt++;
      continue;
    }
    for(k = 0; k < strlen(naf[cnt].a); k++){
      if (naf[cnt].a[k + 1] == 0x00) {
        naf[cnt].a[k + 1] = c;
        naf[cnt].a[k + 2] = 0x00;
        break;
      }
    }
    if(strlen(naf[cnt].a) == 0){
      naf[cnt].a[0] = c;
      naf[cnt].a[1] = 0x00;
    }
    if(naf[cnt + 1].a[0] == 0x00){
      break;
    } else {
      cnt++;
    }
  }
  return cnt;
}

//====================================================//
// 大域変数nafに格納された構造体の変数aに1文字を追加した
// パターンと０文字追加したパターンを追加する処理
// @param pat *naf
// @param char str
// @param int len
// @return bool
//====================================================//
int raddpat(struct pat naf[], char str, int len){
  int cnt = countnaf(naf);
  int add = 0;

  if(str == 0x00){
    return cnt;
  }

  // tmpを初期化
  struct pat *tmp = (struct pat*)malloc(sizeof(struct pat)*(cnt + 1));
  // nafをtmpへcopy
  for(int i = 0; i < cnt; i++){
    for(int j = 0; j < strlen(naf[i].a); j++){
      tmp[i].a[j] = naf[i].a[j];
    }
    tmp[i + 1].a[0] = 0x00;
  }

  // nafへ格納されたpattern配列の末尾に文字を追加する。
  addpat(naf, str, len);
  add = countnaf(naf);
  // nafの領域を拡張する
  if(!(struct pat*)realloc(naf, countnaf(tmp))){
    return false;
  }

  // nafの末尾にtmpを追加する
  for(int i = 0; i < cnt; i++){
    for(int j = 0; j < strlen(tmp[i].a); j++){
      naf[1 + i + cnt].a[j] = tmp[i].a[j];
    }
    naf[i + 1].a[0] = 0x00;
  }

  // 要素数
  cnt += add;

  // 領域開放
  free(tmp);

  return cnt;
}

//====================================================//
// 構文解釈の処理
// @param struct analysis *apars
// @param struct pat *naf
// @param char *pattern
// @param char *match
// @return bool
//====================================================//
bool convnaf(struct analysis apars[], struct pat naf[], char pattern[], char match[]){
  if(pattern == "" || pattern == NULL){
    return false;
  }

  int cnt_apars = countapars(apars);
  int l1 = strlen(match);
  int l2 = strlen(pattern);
  int result = -1;
  struct pat s;
  naf[0].a[0] = 0x00;
  naf[1].a[0] = 0x00;

  // NAF変換
  for(int i = 0; i < cnt_apars; i++){
    if(apars[i].c == 0x00){
      break;
    }
    switch (apars[i].seq) {
      // a . 「+」(1 回以上の繰り返し)
      case ONE_OR_MORE_ITERATIONS:
        // N回のパターン
        for(int j = 0;  j < strlen(match); j++){
          // pattern配列の末尾に文字を追加する。
          raddpat(naf, apars[i].c, l1);
        }
        break;
      // に加えて「*」(0 回以上の繰り返し) も記述できるようにしてみなさい。
      case ZERO_OR_MORE_ITERATIONS:
        // 0回のパターン
        raddpat(naf, 0x00, l1);
        // N回のパターン
        for(int j = 0; j < strlen(match); j++){
          raddpat(naf, apars[i].c, l1);
        }
        break;
      // b. 「?」(直前の文字があってもなくてもよい) を実現してみなさい。
      case MAY_OR_MAY_NOT_BE_PRESENT:
        raddpat(naf, apars[i].c, l1);
        break;
      // 実装しない
      //case START_MALTI_PATTERN:
        //break;
      default:
        // pattern配列の末尾に文字を追加する。
        addpat(naf, apars[i].c, l1);
        break;
    }
  }

  return true;
}
