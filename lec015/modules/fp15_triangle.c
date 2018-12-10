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
  if(x0 >= WIDTH || x1 >= WIDTH || x2 >= WIDTH || y0 >= HEIGHT || y1 >= HEIGHT || y2 >= HEIGHT){
    return false;
  }
  for(int y = 0; y < HEIGHT; y++){
    for(int x = 0; x < WIDTH; x++){
      if ((((x1 - x0) * (y - y0) - (y0 - y1) * (x - x0)) >= 0)
      && (((x2 - x0) * (y - y0) - (y0 - y2) * (x - x0)) <= 0)
      && (((x2 - x1) * (y - y1) - (y1 - y2) * (x - x1)) >= 0)) {
        img_putpixel(c, x, y);
      }
    }
  }
  return true;
}

//----------------------------------------------------------------------------//
// 上向きの三角形のを導出するメソッド
// @param struct color c
// @param x0
// @param y0
// @param x1
// @param y1
// @param x2
// @param y2
// @return bool true of false
//----------------------------------------------------------------------------//
bool img_rtriangle(struct color c, double x0, double y0, double x1, double y1, double x2, double y2){
  if(x0 >= WIDTH || x1 >= WIDTH || x2 >= WIDTH || y0 >= HEIGHT || y1 >= HEIGHT || y2 >= HEIGHT){
    return false;
  }
  for(int y = 0; y < HEIGHT; y++){
    for(int x = 0; x < WIDTH; x++){
      if ((((x1 - x0) * (y - y0) - (y1 - y0) * (x - x0)) <= 0)
      && (((x2 - x0) * (y - y0) - (y2 - y0) * (x - x0)) >= 0)
      && (((x2 - x1) * (y - y1) - (y2 - y1) * (x - x1)) <= 0)) {
        img_putpixel(c, x, y);
      }
    }
  }
  return true;
}

//----------------------------------------------------------------------------//
// 回転する図形を描画するメソッド
// @param struct color c
// @param x0
// @param y0
// @param x1
// @param y1
// @param x2
// @param y2
// @return bool true of false
//----------------------------------------------------------------------------//
bool rt_triangle(struct color c, double x0, double y0, double x1, double y1, double x2, double y2){
  double sx0;
  double sx1;
  double sx2;
  double sy0;
  double sy1;
  double sy2;
  double x;
  double y;
  double rd;
  struct gp g = calc_gp(x0, y0, x1, y1, x2, y2);
//int angle = 0;
  for(int angle = 0; angle < 360; angle+=5){
    rd = angle * PI / 180.0;
    sx0 = rt_x(x0, y0, g.x, g.y, rd);
    sy0 = rt_y(x0, y0, g.x, g.y, rd);
    sx1 = rt_x(x1, y1, g.x, g.y, rd);
    sy1 = rt_y(x1, y1, g.x, g.y, rd);
    sx2 = rt_x(x2, y2, g.x, g.y, rd);
    sy2 = rt_y(x2, y2, g.x, g.y, rd);
    img_clear();
    img_triangle(c, sx0, sy0, sx1, sy1, sx2, sy2);
    /*if(0 <= angle && angle < 90){
      img_triangle(c, sx0, sy0, sx1, sy1, sx2, sy2);
    } else if(90 <= angle && angle < 180) {
      img_triangle(c, sx1, sy1, sx2, sy2, sx0, sy0);
    } else if(180 <= angle && angle < 270) {
      img_rtriangle(c, sx0, sy0, sx2, sy2, sx1, sy1);
    } else if(270 <= angle && angle < 360) {
      img_triangle(c, sx2, sy2, sx0, sy0, sx1, sy1);
    }*/
    img_write();
  }

   return true;
}
