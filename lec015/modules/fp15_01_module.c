#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 300
#define HEIGHT 200
struct color {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};
struct gp{
  double x;
  double y;
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
    fprintf(stderr, "can’t open %s\n", fname);
    exit(1);
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

// (参)http://www.ohshiro.tuis.ac.jp/~ohshiro/prog/game07_call_by_reference_pointer.html
// 座標(x, y) を，(xc, yc)を中心に θラジアン回転した座標は，次の式で計算できることが知られている。
// 回転した後のX座標 =  (x - xc) * cosθ - (y - yc) * sinθ + xc
// 回転した後のY座標 =  (x - xc) * sinθ + (y - yc) * cosθ + yc
//--------------------------------------------------------------//
// rd rad回転させたｘ座標を導出するメソッド
// @param double x
// @param double y
// @param double xc
// @param double yc
// @param double rd
// @return double
//--------------------------------------------------------------//
double rt_x(double x, double y, double xc, double yc, double rd){
  return (x - xc) * cos(rd) - (y - yc) * sin(rd) + xc;
}

//--------------------------------------------------------------//
//　rd rad回転させたｙ座標を導出するメソッド
// @param double x
// @param double y
// @param double xc
// @param double yc
// @param double rd
// @return double
//--------------------------------------------------------------//
double rt_y(double x, double y, double xc, double yc, double rd){
  // 数学座標と同じ様にするためにy座標値を反転
  // 正回転の場合コメントアウト？？
  //y = -y;
  //yc = -yc;
  return 1.0 * ((x - xc) * sin(rd) + (y - yc) * cos(rd) + yc);
}

//----------------------------------------------------------------------------//
// 三角形の重心を導出するメソッド
// @param x0
// @param y0
// @param x1
// @param y1
// @param x2
// @param y2
// @return struct gp
//----------------------------------------------------------------------------//
struct gp calc_gp(double x0, double y0, double x1, double y1, double x2, double y2){
  struct gp g;
  g.x = (x0 + x1 + x2) / 3;
  g.y = (y0 + y1 + y2) / 3;
  return g;
}
