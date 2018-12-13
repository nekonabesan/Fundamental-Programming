#include "modules/fp13_01_module.c"

int main(void){
  /*char *s = (char *)malloc(10 * sizeof(char));
  strcpy(s, "aaa");
  printf("%s\n", s);

  int len = mystrlen(s);
  printf("%d\n", len);
  free(s);*/
  /*char *s = (char *)malloc(12 * sizeof(char));
  strcpy(s, "Google Test");
  printf("%s\n", s);
  reverse(s);
  printf("%s\n", s);
  free(s);*/
  char *s1 = (char *)malloc(10 * sizeof(char));
  char *s2 = (char *)malloc(10 * sizeof(char));
  strcpy(s1,"Google Test");
  strcpy(s2, " Google Test");
  mystrcat(s1, s2);
  printf("%s\n", s1);
  return 0;
}
