#include "fp13_04_header.c"
#include "fp13_04_pars.c"

struct pat {
  char a[MAX];
};

//============================================================================//
// 配列を複製する処理
// @param char Array c1
// @param char Array c2
// @result void
//============================================================================//
void cpary(char c1[], char c2[]){
  int l = strlen(c1);
  c2 = (char *)realloc(c2 ,sizeof(char) * l);
  for(int i = 0; i < l; i++){
    c2[i] = c1[i];
    c2[i + 1] = '\0';
  }
}

//============================================================================//
// 反転
// @param char Array
// @result void
//============================================================================//
void reversal(char c[]){
  int l = strlen(c);
  int j = l - 1;
  char *buf = (char *)malloc(l * sizeof(char));
  for(int i = 0; i < l; i++){
    buf[i] = c[j];
    buf[i + 1] = '\0';
    j--;
  }
  cpary(buf, c);
  free(buf);
}

//============================================================================//
// startからlen文字を削除する処理
// @param char Array c2[]
// @param int strat
// @param int len
// @result void
//============================================================================//
void concat_prefix(char c2[], int start, int len){
  int l = strlen(c2);
  char *buf = (char *)malloc(l * sizeof(char));
  int pos = 0;
  int j = 0;
  int end = start + len;
  for(int i = 0; i < l; i++){
    if(c2[pos] == '\0'){
      break;
    } else if(start <= i  && i < end){
      pos++;
    } else {
      buf[j] = c2[pos];
      buf[i + 1] = '\0';
      j++;
      pos++;
    }
  }
  c2 = (char *)realloc(c2 ,sizeof(char) * (l - len));
  for(int i = 0; i < strlen(c2); i++){
    c2[i] = buf[i];
  }
  c2[l - 1] = '\0';
  free(buf);
}

//============================================================================//
// c. ^(先頭に固定) を実現してみなさい。
//============================================================================//
bool chk_prefix(char c2[]){
  int l = strlen(c2);
  if(c2[0] == 0x5e){
    concat_prefix(c2, 0, 1);
    return true;
  } else if(c2[0] == 0x5c) {
    //========================================================================//
    // e. ここまでに出て来た特殊文字の機能をなくすエスケープ記号「\」を実現しなさい
    // (この文字に続いて特殊文字があった場合通常の文字として扱う)。
    //========================================================================//
    concat_prefix(c2, 0, 1);
    return false;
  }
  return false;
}
//============================================================================//
// c. $(末尾に固定) を実現してみなさい。
//============================================================================//
bool chk_suffix(char c2[]){
  int l = strlen(c2);
  if(c2[l - 2] == 0x5c){
    //========================================================================//
    // e. ここまでに出て来た特殊文字の機能をなくすエスケープ記号「\」を実現しなさい
    // (この文字に続いて特殊文字があった場合通常の文字として扱う)。
    //========================================================================//
    concat_prefix(c2, l - 2, 1);
    return false;
  } else if(c2[l - 1] == 0x24){
    concat_prefix(c2, (l - 1), 1);
    return true;
  }
  return false;
}

//====================================================//
// @pattern、pos文字目までのマッチング
// @param char *match
// @param char *pattern
// @param int pos
// @return bool result
//====================================================//
bool normal_match(char match[], char pattern[]){
  bool result = false;
  int l1 = strlen(match);
  int l2 = strlen(pattern);
  for(int i = 0; i < l1; i++){
    for(int j = 0; j < l2; j++){
      result = true;
      if(match[i + j] != pattern[j]){
        result = false;
        break;
      }
    }
    if(result == true || l1 <= (i + l2)){
      break;
    }
  }
  return result;
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
// param  char *pattern
// return bool
//====================================================//
int raddpat(struct pat naf[], char str, int len){
  int cnt = 0;
  while(1){
    if(naf[cnt].a[0] == 0x00){
      break;
    }
    cnt++;
  }
  if(str == 0x00){
    return cnt;
  }
  // tmpを初期化
  struct pat *tmp = (struct pat*)malloc(sizeof(struct pat)*(cnt + 1));
  // nafをtmpへcopy
  for(int i = 0; i < cnt; i++){
    tmp[i] = naf[i];
  }
  // nafへ格納されたpattern配列の末尾に文字を追加する。
  addpat(naf, str, len);
  // nafの末尾にtmpを追加する(0文字のパターン)
  if(!realloc(naf, cnt*2)){
    return false;
  }
  for(int i = 0; i < cnt; i++){
    naf[i + cnt] = tmp[i];
  }
  naf[cnt + 1].a[0] = 0x00;
  return cnt;
}

//====================================================//
// 正規表現処理
// param  char *match
// param  char *pattern
// return int result
//====================================================//
int pattern_match(char match[], char pattern[]) {
  if(match == "" || pattern == "" || match == NULL || pattern == NULL){
    return -1;
  }
  //
  // 接頭語チェック
  bool prefix = chk_prefix(pattern);
  // 接尾語チェック
  bool suffix = chk_suffix(pattern);

  struct analysis *apars = (struct analysis*)malloc(sizeof(struct analysis) * 2);
  struct pat *naf = (struct pat*)malloc(sizeof(struct pat) * 2);
  int cnt = 0;
  char *tmp;
  int l1 = strlen(match);
  int l2 = strlen(pattern);
  int pos = 0;
  int result = -1;
  bool flg = false;
  struct pat s;
  naf[0] = s;
  naf[0].a[0] = 0x00;
  naf[1] = s;
  naf[1].a[0] = 0x00;

  // patternの構文解析
  if(!pars(apars, pattern)){
      return -1;
  }

  // NAF変換
  while(1){
    if(pattern[pos] == '\0'){
      break;
    }
    switch (pattern[pos + 1]) {
      // a . 「+」(1 回以上の繰り返し)
      case ONE_OR_MORE_ITERATIONS:
        // N回のパターン
        for(int i = 0;  i < strlen(match); i++){
          // pattern配列の末尾に文字を追加する。
          cnt = raddpat(naf, pattern[pos], l1);
        }
        pos+=2;
        break;
      // に加えて「*」(0 回以上の繰り返し) も記述できるようにしてみなさい。
      case ZERO_OR_MORE_ITERATIONS:
        // 0回のパターン
        cnt = raddpat(naf, 0x00, l1);
        // N回のパターン
        for(int i = pos + 1; i < strlen(match); i++){
          cnt = raddpat(naf, pattern[pos], l1);
        }
        pos+=2;
        break;
      // b. 「?」(直前の文字があってもなくてもよい) を実現してみなさい。
      case MAY_OR_MAY_NOT_BE_PRESENT:
        cnt = raddpat(naf, pattern[pos], l1);
        pos+=2;
        break;
      // 実装しない
      //case START_MALTI_PATTERN:
        //break;
      default:
        // pattern配列の末尾に文字を追加する。
        cnt = addpat(naf, pattern[pos], l1);
        //printf("%s\n",naf[0].a[pos]);
        pos++;
        break;
    }
  }

  // match
  for(int i = 0; i <= cnt; i++){
    if(normal_match(match, naf[i].a)){
      result = 1;
      break;
    }
  }

  if(flg == true){
    result = 1;
  }
  free(naf);
  return result;
}
