#include "fp13_04_header.c"
#include "fp13_04_pars.c"
#include "fp13_04_naf.c"

struct pat naf[MAX];
//====================================================//
// NAFの配列を初期化する処理
// @return bool
//====================================================//
bool initialize(void){
  for(int i = 0; i < MAX; i++){
    for(int j = 0; j < 10; j++){
      naf[i].a[j] = 0x00;
    }
  }
  return true;
}

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
// 正規表現処理
// param  char *match
// param  char *pattern
// return int result
//====================================================//
int pattern_match(char match[], char pattern[]) {
  if(match == "" || pattern == "" || match == NULL || pattern == NULL){
    return -1;
  }

  bool flg = false;
  int result = -1;
  // 接頭語チェック
  bool prefix = chk_prefix(pattern);
  // 接尾語チェック
  bool suffix = chk_suffix(pattern);

  struct analysis *apars = (struct analysis*)malloc(sizeof(struct analysis) * 2);
  //struct pat *naf = (struct pat*)malloc(sizeof(struct pat) * 3);
  struct pat *anaf = naf;
  naf[0].a[0] = 0x00;
  naf[0].a[1] = 0x00;
  naf[0].a[2] = 0x00;

  // patternの構文解析
  if(!pars(apars, pattern)){
      return -1;
  }

/*int cc = 0;
while(1){
  printf("%c\n", apars[cc].c);
  cc++;
  if(apars[cc].c == 0x00){
    printf("%s", "\n");
    break;
  }
}*/

  // NAF配列初期化
  if(!initialize()){
    return -1;
  }
  // NAF変換
  if(!convnaf(apars, anaf, pattern, match)){
    return -1;
  }
  // CODE_ZERO_EXCEPTIONを取り除く処理
  if(!delete_cze(anaf)){
    return -1;
  }

  // NAF変換結果の格納された配列の要素数を数える処理
  int cnt = countnaf(anaf);

printf("last count naf : %d\n", cnt);

  for(int i = 0; i < cnt; i++){
    printf("last : %s\n",anaf[i].a);
  }

  // パターンマッチング
  for(int i = 0; i < cnt; i++){
    //printf("last : %s\n",anaf[i].a);
    if(normal_match(match, anaf[i].a)){
      result = 1;
      break;
    }
  }

  // 領域開放
  free(apars);

  return result;
}
