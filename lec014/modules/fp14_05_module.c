#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "tbl.h"

#define MAXTBL 9973
//============================================================================//
// 演習 5 このハッシュ表の実装を入力し、先の計測プログラムと一緒にして計測してみなさい。
// 回数が多くなると O(1) でなくなりますが、その理由を検討し、
// その問題を解消するような変更を行ってみなさい。
// (ヒント: 多く登録しすぎるとそうなるので、
//   登録数を調べて一定以上」登録しようとしたら満杯ということにするのが方法の 1 つです。)
//============================================================================//
// tblchash --- table impl. with chained hash.
struct ent {
  char *key;
  int val;
  struct ent *next;
};
struct ent *tbl[MAXTBL];

static unsigned int hash(char *s) {
  unsigned int v = 1;
  while(*s){
    v *= 11 * (*s++) + 1;
  }
  return v % MAXTBL;
}

static struct ent *lookup(struct ent *p, char *k) {
  for( ; p != NULL; p = p->next) {
    if(strcmp(p->key, k) == 0) {
      return p;
    }
  }
  return NULL;
}

int get1(struct ent *p, char *k) {
  struct ent *q = lookup(p, k);
  return (q == NULL) ? -1 : q->val;
}

static bool put1(struct ent **p, char *k, int v) {
  struct ent *q = lookup(*p, k);
  if(q != NULL) {
    q->val = v;
    return true;
  }

  q = (struct ent*)malloc(sizeof(struct ent));
  if(q == NULL) {
    return false;
  }

  int len = strlen(k);

  q->key = (char*)malloc(len+1);
  if(q->key == NULL) {
    return false;
  }

  strcpy(q->key, k);
  q->val = v;
  q->next = *p;
  *p = q;
  return true;
}

int tbl_get(char *k) {
  return get1(tbl[hash(k)], k);
}

bool tbl_put(char *k, int v) {
  return put1(&tbl[hash(k)], k, v);
}
