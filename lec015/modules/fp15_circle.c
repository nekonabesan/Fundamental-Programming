//============================================================================//
// !! -lmオプションを付けてビルド
// http://azsky2.html.xdomain.jp/note/paintprog/022_rotate.html
//============================================================================//
#include "fp15_01_module.c"

#define PI  3.141592

//----------------------------------------------------------------------------//
// 円を描画する処理
// @param struct color c
// @param double x
// @param double y
// @param double r
// @return bool true or false
//----------------------------------------------------------------------------//
bool img_fillcircle(struct color c, double x, double y, double r) {
  // 座標の境界値chk
  if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT || r < 1) {
    return false;
  }
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
bool rt_circle(struct color c, double x0, double y0, double r){
  double sx0;
  double sy0;
  double x;
  double y;
  double rd;
  //struct gp g = calc_gp(x0, y0, x1, y1, x2, y2);
  for(int angle = 0; angle < 360; angle+=1){
    rd = angle * PI / 180.0;
    sx0 = rt_x(x0, y0, 150, 100, rd);
    sy0 = rt_y(x0, y0, 150, 100, rd);
    img_clear();
    img_fillcircle(c, sx0, sy0, r);
    img_write();
  }

   return true;
}
