//============================================================================//
// !! -lmオプションを付けてビルド
// http://azsky2.html.xdomain.jp/note/paintprog/022_rotate.html
//============================================================================//
#include "fp15_01_module.c"

#define PI  3.141592

//----------------------------------------------------------------------------//
// 下向きの三角形のを導出するメソッド
// @param struct color c
// @param x0
// @param y0
// @param x1
// @param y1
// @param x2
// @param y2
// @return bool true of false
//----------------------------------------------------------------------------//
bool img_triangle(struct color c, double x0, double y0, double x1, double y1, double x2, double y2){
  //if(x0 >= WIDTH || x1 >= WIDTH || x2 >= WIDTH || y0 >= HEIGHT || y1 >= HEIGHT || y2 >= HEIGHT){
  //  return false;
  //}
  for(int y = 0; y < HEIGHT; y++){
    for(int x = 0; x < WIDTH; x++){
      if((x1 - x0)*(y - y0) - (y1 - y0)*(x - x0) <= 0
      && (x2 - x0)*(y - y0) - (y2 - y0)*(x - x0) >= 0
      && (x2 - x1)*(y - y1) - (y2 - y1)*(x - x1) <= 0) {
        img_putpixel(c, x, y);
      }
    }
  }
  return true;
}
