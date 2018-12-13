#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//============================================================================//
// 演習 4 上のコードを打ち込み、パターンが正しく処理されていることを確認しなさい。
// OK なら、次のことをやってみなさい。
//============================================================================//
//============================================================================//
// a . 「+」(1 回以上の繰り返し) に加えて「*」(0 回以上の繰り返し) も記述できるようにしてみなさい。
//============================================================================//
#define ONE_OR_MORE_ITERATIONS 0x2b
#define ZERO_OR_MORE_ITERATIONS 0x2a
//============================================================================//
// b. 「?」(直前の文字があってもなくてもよい) を実現してみなさい。
//============================================================================//
#define MAY_OR_MAY_NOT_BE_PRESENT 0x3f
//============================================================================//
// d. 文字クラス[...](...の文字のいずれかならあてはまる)を実現してみなさい。
// [^...](...のいずれでもなければ) も実現できるとなおよいです。
//============================================================================//
#define START_MALTI_PATTERN 0x5b
#define END_MALTI_PATTERN 0x5d
//============================================================================//
// e. ここまでに出て来た特殊文字の機能をなくすエスケープ記号「\」を実現しなさい
// (この文字に続いて特殊文字があった場合通常の文字として扱う)。
//============================================================================//
#define ESCAPE_SEQENCE 0x5c
//============================================================================//
// f. その他、パターンマッチにおいてあると面白いと思う好きな機能を選び実現しなさい
//============================================================================//


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
// pattern、pos文字目までのマッチング
// param char *match
// param char *pattern
// param int l1
// param int pos
// return int result
//====================================================//
bool normal_match(char match[], char pattern[], int l1, int pos){
  int result;
  int l2 = strlen(pattern);
  for(int i = 0; i < l1; i++){
    result = true;
    for(int j = 0; j <= pos; j++){
      if(pattern[j] != match[i + j]){
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
//
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

  //
  //char *mat = match;
  //char *pat = pattern;
  int l1 = strlen(match);
  int l2 = strlen(pattern);
  int pos = 0;
  int result = -1;
  bool flg = true;
  //

  while(1){
    switch (pattern[pos]) {
      /*case ONE_OR_MORE_ITERATIONS:
        break;
      case ZERO_OR_MORE_ITERATIONS:
        break;
      case MAY_OR_MAY_NOT_BE_PRESENT:
        break;
      case START_MALTI_PATTERN:
        break;*/
      default:
        /*if(normal_match(match, pattern, l1, pos) == false){
          flg = false;
        }*/
        flg = normal_match(match, pattern, l1, pos);
        break;
    }
    // 終了判定
    if(flg == false || (l2 - 1) == pos){
      // アンマッチ確定で処理中断
      if(pos == (l2 - 1) && flg == true){
        result = 1;
      }
      break;
    }
    //
    pos++;
  }
  return result;
}
