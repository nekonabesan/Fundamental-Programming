#include "fp13_04_header.c"
struct analysis {
  char c;
  char seq;
};

//====================================================//
// 構文解釈の処理
// @param char *pattern
// @return bool
//====================================================//
bool pars(struct analysis apars[], char pattern[]){
  if(pattern == "" || pattern == NULL){
    return false;
  }

  // 字句解析
  // 構文解析処理
  // 構文木の作成
  for(int i = 1; i <= strlen(pattern); i++){
    if(!realloc(apars, 1)){
      return false;
    }
    // 現在位置の文字を判定しひとつ前の文字に対する処理を実行する
    switch (pattern[i]) {
      // a . 「+」(1 回以上の繰り返し)
      case ONE_OR_MORE_ITERATIONS:
        apars->c = pattern[i - 1];
        apars->seq = ONE_OR_MORE_ITERATIONS;
        i++;
        break;
      // に加えて「*」(0 回以上の繰り返し) も記述できるようにしてみなさい。
      case ZERO_OR_MORE_ITERATIONS:
        apars->c = pattern[i - 1];
        apars->seq = ZERO_OR_MORE_ITERATIONS;
        i++;
        break;
      // b. 「?」(直前の文字があってもなくてもよい) を実現してみなさい。
      case MAY_OR_MAY_NOT_BE_PRESENT:
        apars->c = pattern[i - 1];
        apars->seq = MAY_OR_MAY_NOT_BE_PRESENT;
        i++;
        break;
      // 実装しない
      //case START_MALTI_PATTERN:
        //break;
      default:
        apars->c = pattern[i - 1];
        apars->seq = 0x00;
        break;
    }
  }
  return true;
}
