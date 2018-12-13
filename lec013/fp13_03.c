#include "modules/fp13_03_module.c"

int main(void){
  char *match = (char *)malloc(10 * sizeof(char));
  //test01
  /*strcpy(match, "^strrrrrr");
  printf("%s\n", match);
  concat_prefix(match, 0, 1);
  printf("%s\n", match);*/
  strcpy(match, "strrrrrr\\$");
  chk_suffix(match);
  printf("%s\n", match);
  /*bool prefix = (chk_prefix(match));
  printf("%s\n", match);
  printf("%d\n", prefix);*/
  return 0;
}
