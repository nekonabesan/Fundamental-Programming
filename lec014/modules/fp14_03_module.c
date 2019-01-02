#include "../fp14_common.h"
//============================================================================//
// 演習 3 上の例題をそのまま打ち込んで動かしなさい。
// 動いたら次の変更をしてみなさい。
//============================================================================//
/*int tbl_get(char *k) {
  int i;
  for(i = 0; i < tblsize; ++i) {
    if(strcmp(tbl[i].key, k) == 0) {
      return tbl[i].val;
    }
  }
  return -1;
}

bool tbl_put(char *k, int v) {
  /*for(int i = 0; i < tblsize; ++i) {
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
  tbl[tblsize + 1].key = 0x00;
  tbl[tblsize + 1].val = 0x00;
  ++tblsize; return true;
}

void set_tableszize2(int val){
  tblsize2 = val;
}*/

//============================================================================//
// a. 登録できる値を整数 1 個から変更しなさい (整数 2 個とか文字列とか)。
//============================================================================//
struct ent2 * add_struct(struct ent2* p, char key[], char val[]){
  if(key == NULL || val == NULL) {
    //return p;
  }
  struct ent2 *t = (struct ent2*)malloc(sizeof(struct ent2) * 1);
  t->key = key;
  t->val = val;
  t->prev = p;
  t->next = NULL;
  p->next = t;
  //printf("%s\n", t.key);
  tblsize2 += 1;
  return t;
}

//============================================================================//
// b. 今は表は追加と書き換えしかできないが、削除機能をつけてみなさい。
// @param struct ent2 *p
// @return bool
//============================================================================//
bool del_struct(struct ent2 *p){
  if(p == NULL){
    return false;
  }
  struct ent2 *prev = p->prev;
  struct ent2 *next = p->next;
  if(next){
    next->prev = prev;
  }
  if(prev){
    prev->next = next;
  }
  tblsize2 -= 1;
  //printf("%p\n", p);
  memset(p->key, 0x00 , sizeof(char) * strlen(p->key));
  memset(p->val, 0x00 , sizeof(char) * strlen(p->val));
  free(p);
  return true;
}
//============================================================================//
// リストを全て削除する処理
// @param struct ent2 *p
// @return bool
//============================================================================//
bool del_array(struct ent2 *p){
  if(p == NULL){
    return false;
  }
  struct ent2 *pos = p;
  struct ent2 *next = pos->next;
  while(next){
    pos = next;
    next = pos->next;
    //printf("%p\n", pos);
    memset(pos->key, 0x00 , sizeof(char) * strlen(pos->key));
    memset(pos->val, 0x00 , sizeof(char) * strlen(pos->val));
    free(pos);
    tblsize2 -= 1;
  }
  return true;
}

//============================================================================//
// c. 表の中身を全部まとめて表示する機能をつけてみなさい。
// (ヒント: この機能そのものは tbllinear1.c の中に置くのが自然で、main からそれを呼び出す。
// どういう場合にこの機能が呼ばれることにするかは好きに決めてかまいません。)
// @param struct ent2 *p
// @return struct ent2 *p
//============================================================================//
struct ent2 * show_structs(struct ent2* p){
  struct ent2 *pos = p;
  while(1){
    if(pos){
      printf("%s\n", pos->key);
      printf("%s\n", pos->val);
      //printf("%p\n", pos);
      pos = pos->next;
      continue;
    } else {
      break;
    }
  }
  return p;
}

//============================================================================//
// d. そのほか、面白いと思う機能をつけてみなさい。
// 構造体を初期化する処理
// @param char *key
// @param char *val
// @return char *ent2
//============================================================================//
struct ent2 * initialize(char key[], char val[]){
  if(tblsize+1 >= MAXTBL || key == NULL || val == NULL) {
    return false;
  }
  struct ent2 *t = (struct ent2*)malloc(sizeof(struct ent2) * 1);
  t->key = key;
  t->val = val;
  t->prev = NULL;
  t->next = NULL;
  tblsize2 += 1;
  return t;
}

//============================================================================//
// 先頭のアドレスを返す処理
// @param struct ent2 *pos
// @return struct ent2 *start
//============================================================================//
struct ent2 * head_address(struct ent2 *pos){
  struct ent2 *head = pos->prev;
  while(1){
    if(head->prev){
      head = head->prev;
    } else {
      break;
    }
  }
  return head;
}
