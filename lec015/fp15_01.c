// animate1 --- create animation using img lib.
//#include "modules/fp15_01_module.c"
//#include "modules/fp15_triangle.c"
#include "modules/fp15_circle.c"

int main(void) {
  int x0 = 0;
  int x1 = 0;
  int x2 = 0;
  int y0 = 0;
  int y1 = 0;
  int y2 = 0;
  struct color c1;
  struct color c2;
  c1.r = 0;
  c1.g = 0;
  c1.b = 255;
  c2.r = 255;
  c2.g = 0;
  c2.b = 0;

  // 円
  /*for(int i = 0; i < 20; ++i) {
    img_clear();
    img_fillcircle(c1, 20+i*8, 100, 20);
    img_write();
  }
  for(int i = 0; i < 20; ++i) {
    img_clear();
    img_fillcircle(c2, 180, 100+i*5, 20-i);
    img_write();
  }*/

  // 三角形
  x0 = 150;
  x1 = 130;
  x2 = 170;
  y0 = 140;
  y1 = 80;
  y2 = 80;
  //for(int i = 0; i < 20; ++i) {
    //img_clear();
    /*x0 += 5;
    x1 += 5;
    x2 += 5;
    y0 += 0;
    y1 += 0;
    y2 += 0;
    img_triangle(c1, x0, y0, x1, y1, x2, y2);*/
    //rt_triangle(c1, x0, y0, x1, y1, x2, y2);
    //img_write();
  //}
  /*x1 = 0;
  x2 = 0;
  x3 = 0;
  y1 = 0;
  y2 = 0;
  y3 = 0;
  for(int i = 0; i < 20; ++i) {
    img_clear();
    x1 += 0;
    x2 += 0;
    x3 += 0;
    y1 += 0;
    y2 += 0;
    y3 += 0;
    img_triangle(c1, x1, y1, x2, y2, x3, y3);
    img_write();
  }*/
  rt_circle(c1, x0, y0, 10.0);
}
