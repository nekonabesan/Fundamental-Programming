//#include "modules/fp14_common.h"
#include "modules/fp14_03_module.c"

int main(void){
  /* code */
  char *key1 = (char *)malloc(10 * sizeof(char));
  char *val1 = (char *)malloc(10 * sizeof(char));
  char *key2 = (char *)malloc(10 * sizeof(char));
  char *val2 = (char *)malloc(10 * sizeof(char));
  char *key3 = (char *)malloc(10 * sizeof(char));
  char *val3 = (char *)malloc(10 * sizeof(char));
  strcpy(key1, "key1");
  strcpy(val1, "val1");
  strcpy(key2, "key2");
  strcpy(val2, "val2");
  strcpy(key3, "key3");
  strcpy(val3, "val3");
  struct ent2 *start = initialize(key1, val1);
  struct ent2 *pos = NULL;
  // リストを初期化(構造体単体)
  //show_structs(start);
  // 構造体削除
  if(!del_struct(start)){
    printf("%p\n", start);
  }
  // リストを初期化(双方向リスト)
  strcpy(key1, "key1");
  strcpy(val1, "val1");
  struct ent2 *start2 = initialize(key1, val1);
  // リストへ要素を追加
  pos =  add_struct(start2, key2, val2);
  pos =  add_struct(pos, key3, val3);
  pos = head_address(pos);
  show_structs(pos);
  // リストを初期化
  if(!del_array(start2)){
    printf("%s\n", start2->key);
  }
  // 領域開放
  free(key1);
  free(val1);
  free(key2);
  free(val2);
  free(key3);
  free(val3);
  return 0;
}
