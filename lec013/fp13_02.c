#include "modules/fp13_02_module.c"

int main(void){
  char *s1 = (char *)malloc(20 * sizeof(char));
  strcpy(s1,"01");
  printf("%d\n", atoi(s1));
  free(s1);
}
