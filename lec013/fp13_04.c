#include "modules/fp13_04_module.c"

int main(void){
  char *match = (char *)malloc(10 * sizeof(char));
  char *pattern = (char *)malloc(10 * sizeof(char));
  strcpy(match, "string");
  strcpy(pattern, "s?");
  //strcpy(pattern, "rin");
  int flg = pattern_match(match, pattern);
  printf("ret flg : %d\n", flg);
  //printf("%d\n", pattern_match(match, pattern));
  free(match);
  free(pattern);
  return 0;
}
