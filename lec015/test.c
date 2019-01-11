#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define HEIGHT 3
#define WIDTH 5

int main(void){
  unsigned char *buf = (unsigned char*)calloc(HEIGHT * WIDTH * 3, sizeof(unsigned char));
  for (int i = 0; i < HEIGHT; i++){
    for (int j = 0; j < WIDTH; j++) {
      buf[i * WIDTH + j + 0 + (i * WIDTH)] = (unsigned char)j;
      buf[i * WIDTH + j + 1 + (i * WIDTH)] = (unsigned char)j;
      buf[i * WIDTH + j + 2 + (i * WIDTH)] = (unsigned char)j;
    }
  }
  for (int i = 0; i < HEIGHT; i++){
    for (int j = 0; j < WIDTH; j++) {
      printf("%d ",buf[i * WIDTH + j]);
    }
    printf("%s\n", "\n");
  }
  free(buf);
  return 0;
}
