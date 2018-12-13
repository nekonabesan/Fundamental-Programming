// animate1 --- create animation using img lib.
//#include "modules/fp15_01_module.c"
#include "modules/fp15_triangle.c"
//#include "modules/fp15_circle.c"

int main(void) {
  struct color c1;
  c1.r = 0;
  c1.g = 0;
  c1.b = 255;
  // 三角形
  double x0 = 150;
  double x1 = 130;
  double x2 = 170;
  double y0 = 120;
  double y1 = 80;
  double y2 = 80;
  double sx0;
  double sx1;
  double sx2;
  double sy0;
  double sy1;
  double sy2;
  double px0;
  double px1;
  double px2;
  double py0;
  double py1;
  double py2;
  double x;
  double y;
  double rd;
  struct gp g = calc_gp(x0, y0, x1, y1, x2, y2);
  for(int angle = 0; angle <= 360; angle+=30){
    rd = angle * PI / 180.0;
    sx0 = rt_x(x0, y0, g.x, g.y, rd);
    sy0 = rt_y(x0, y0, g.x, g.y, rd);
    sx1 = rt_x(x1, y1, g.x, g.y, rd);
    sy1 = rt_y(x1, y1, g.x, g.y, rd);
    sx2 = rt_x(x2, y2, g.x, g.y, rd);
    sy2 = rt_y(x2, y2, g.x, g.y, rd);
    printf("rad => %f\n", rd);
    printf("sx0 => %f\n", sx0);
    printf("sy0 => %f\n", sy0);
    printf("sx1 => %f\n", sx1);
    printf("sy1 => %f\n", sy1);
    printf("sx2 => %f\n", sx2);
    printf("sy2 => %f\n", sy2);
    printf("%s","----------------------------------\n");
    //
    if(sy0 > sy1 && sy0 > sy2){
      px0 = sx0;
      py0 = sy0;
      if(sx1 > sx2){
        px2 = sx1;
        py2 = sy1;
        px1 = sx2;
        py1 = sy2;
      }else if(sx2 > sx1){
        px2 = sx2;
        py2 = sy2;
        px1 = sx1;
        py1 = sy1;
      }
    }else if(sy1 > sy0 && sy1 > sy2){
      px0 = sx1;
      py0 = sy1;
      if(sx0 > sx2){
        px2 = sx0;
        py2 = sy0;
        px1 = sx2;
        py1 = sy2;
      }else if(sx2 > sx0){
        px2 = sx2;
        py2 = sy2;
        px1 = sx0;
        py1 = sy0;
      }
    }else if(sy2 > sy0 && sy2 > sy1){
      px0 = sx2;
      py0 = sy2;
      if(sx0 > sx1){
        px2 = sx0;
        py2 = sy0;
        px1 = sx1;
        py1 = sy1;
      }else if(sx1 > sx0){
        px2 = sx1;
        py2 = sy1;
        px1 = sx0;
        py1 = sy0;
      }
    }
    //
    img_clear();
    img_triangle(c1, px0, py0, px1, py1, px2, py2);
    img_write();
  }
}
