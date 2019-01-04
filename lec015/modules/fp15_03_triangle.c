//============================================================================//
// !! -lmオプションを付けてビルド
// http://azsky2.html.xdomain.jp/note/paintprog/022_rotate.html
//============================================================================//
#include "fp15_03_module.c"

#define PI  3.141592

//----------------------------------------------------------------------------//
// 下向きの三角形のを導出するメソッド
// @param struct color *p
// @param x0
// @param y0
// @param x1
// @param y1
// @param x2
// @param y2
// @return bool true of false
//----------------------------------------------------------------------------//
struct color * imgtriangle(struct color *p, double x0, double y0, double x1, double y1, double x2, double y2, unsigned char r, unsigned char g, unsigned char b){
  struct color *c = p;
  for(int y = 0; y < HEIGHT; y++){
    for(int x = 0; x < WIDTH; x++){
      if((x1 - x0)*(y - y0) - (y1 - y0)*(x - x0) <= 0
      && (x2 - x0)*(y - y0) - (y2 - y0)*(x - x0) >= 0
      && (x2 - x1)*(y - y1) - (y2 - y1)*(x - x1) <= 0) {
        printf("%d\n", x);
        c = imgputpixel(c, x, y, r, g, b);
      } else {
        c = imgputpixel(c, x, y, 255, 255, 255);
      }
      //p->y = y;
      //p->x = x;
    }
  }
  return c;
}
