#include "../fp14_common.h"
//============================================================================//
// 演習 3 上の例題をそのまま打ち込んで動かしなさい。
// 動いたら次の変更をしてみなさい。
//============================================================================//
int tbl_get(char *k) {
  int i;
  for(i = 0; i < tblsize; ++i) {
    if(strcmp(tbl[i].key, k) == 0) {
      return tbl[i].val;
    }
  }
  return -1;
}

bool tbl_put(char *k, int v) {
  for(int i = 0; i < tblsize; ++i) {
    if(strcmp(tbl[i].key, k) == 0) {
      tbl[i].val = v;
      return true;
    }
  }

  if(tblsize+1 >= MAXTBL) {
    return false;
  }

  char *s = (char*)malloc(strlen(k) + 1);
  if(s == NULL) {
    return false;
  }

  strcpy(s, k);
  tbl[tblsize].key = s;
  tbl[tblsize].val = v;
  ++tblsize; return true;
}

void set_tableszize2(int val){
  tblsize2 = val;
}

//============================================================================//
// a. 登録できる値を整数 1 個から変更しなさい (整数 2 個とか文字列とか)。
//============================================================================//
bool add_struct(char key[], char val[]){
  if(tblsize+1 >= MAXTBL || key == NULL || val == NULL) {
    return false;
  }
  tbl2[tblsize2].key = key;
  tbl2[tblsize2].val = val;
  tblsize2 += 1;
  return true;
}

//============================================================================//
// b. 今は表は追加と書き換えしかできないが、削除機能をつけてみなさい。
//============================================================================//
bool del_struct(char key[]){
  if(key == NULL){
    return false;
  }
  for(int i = 0; i < tblsize2; i++) {
    if(strcmp(tbl2[i].key, key) == 0) {
      for(int j = i; j < tblsize2; j++){
        tbl2[j].key = tbl2[j + 1].key;
        tbl2[j].val = tbl2[j + 1].val;
        if(j == (tblsize2)){
          tbl2[j].key = NULL;
          tbl2[j].val = NULL;
        }
      }
      break;
    }
  }
  return true;
}

//============================================================================//
// c. 表の中身を全部まとめて表示する機能をつけてみなさい。
// (ヒント: この機能そのものは tbllinear1.c の中に置くのが自然で、main からそれを呼び出す。
// どういう場合にこの機能が呼ばれることにするかは好きに決めてかまいません。)
//============================================================================//
bool show_structs(void){
  for(int i = 0; i < tblsize2; i++){

  }
  return true;
}

//============================================================================//
// d. そのほか、面白いと思う機能をつけてみなさい。
//============================================================================//
