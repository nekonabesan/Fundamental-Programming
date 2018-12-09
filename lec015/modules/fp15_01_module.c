#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH 300
#define HEIGHT 200
struct color {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

static unsigned char buf[HEIGHT][WIDTH][3];
static int filecnt = 0;
static char fname[100];

bool img_clear(void) {
  for(int j = 0; j < HEIGHT; j++) {
    for(int i = 0; i < WIDTH; i++) {
      buf[j][i][0] = buf[j][i][1] = buf[j][i][2] = 255;
    }
  }
  return true;
}

bool img_write(void) {
  sprintf(fname, "img%04d.ppm", filecnt++);
  FILE *f = fopen(fname, "wb");
  if(f == NULL) {
    fprintf(stderr, "can’t open %s\n", fname); exit(1);
    return false;
  }
  fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
  fwrite(buf, sizeof(buf), 1, f);
  fclose(f);
  return true;
}

bool img_putpixel(struct color c, int x, int y) {
  if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
    return false;
  }
  buf[HEIGHT-y-1][x][0] = c.r;
  buf[HEIGHT-y-1][x][1] = c.g;
  buf[HEIGHT-y-1][x][2] = c.b;
  return true;
}

bool img_fillcircle(struct color c, double x, double y, double r) {
  int imin = (int)(x - r - 1);
  int imax = (int)(x + r + 1);
  int jmin = (int)(y - r - 1);
  int jmax = (int)(y + r + 1);
  for(int j = jmin; j <= jmax; ++j) {
    for(int i = imin; i <= imax; ++i) {
      if((x-i)*(x-i) + (y-j)*(y-j) <= r*r) {
        img_putpixel(c, i, j);
      }
    }
  }
  return true;
}
