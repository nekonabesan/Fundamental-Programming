#include "modules/fp13_04_module.c"

int main(void){
  char *match = (char *)malloc(10 * sizeof(char));
  char *pattern = (char *)malloc(10 * sizeof(char));
  strcpy(match, "string");
  strcpy(pattern, "tri");
  int l1 = strlen(match);
  int flg = pattern_match(match, pattern);
  printf("%d\n", flg);
  //printf("%d\n", pattern_match(match, pattern));
  free(match);
  free(match);
  return 0;
}
