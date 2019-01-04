// animate1 --- create animation using img lib.
//#include "modules/fp15_01_module.c"
#include "modules/fp15_03_triangle.c"
//#include "modules/fp15_circle.c"

int main(void) {
  unsigned char r = 0;
  unsigned char g = 0;
  unsigned char b = 255;
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
  struct gp gpos = calc_gp(x0, y0, x1, y1, x2, y2);
  struct color *p = NULL;
  for(int angle = 0; angle <= 360; angle+=1){
    rd = angle * PI / 180.0;
    sx0 = rt_x(x0, y0, gpos.x, gpos.y, rd);
    sy0 = rt_y(x0, y0, gpos.x, gpos.y, rd);
    sx1 = rt_x(x1, y1, gpos.x, gpos.y, rd);
    sy1 = rt_y(x1, y1, gpos.x, gpos.y, rd);
    sx2 = rt_x(x2, y2, gpos.x, gpos.y, rd);
    sy2 = rt_y(x2, y2, gpos.x, gpos.y, rd);
    /*printf("rad => %f\n", rd);
    printf("sx0 => %f\n", sx0);
    printf("sy0 => %f\n", sy0);
    printf("sx1 => %f\n", sx1);
    printf("sy1 => %f\n", sy1);
    printf("sx2 => %f\n", sx2);
    printf("sy2 => %f\n", sy2);
    printf("%s","----------------------------------\n");*/
    //
    if(sy0 > sy1 && sy0 > sy2){
      px0 = sx0;
      py0 = sy0;
      if(sx1 > sx2){
        px1 = sx1;
        py1 = sy1;
        px2 = sx2;
        py2 = sy2;
      }else if(sx2 >= sx1){
        px1 = sx2;
        py1 = sy2;
        px2 = sx1;
        py2 = sy1;
      }
    }else if(sy1 > sy0 && sy1 > sy2){
      px0 = sx1;
      py0 = sy1;
      if(sx0 > sx2){
        px1 = sx0;
        py1 = sy0;
        px2 = sx2;
        py2 = sy2;
      }else if(sx2 >= sx0){
        px1 = sx2;
        py1 = sy2;
        px2 = sx0;
        py2 = sy0;
      }
    }else if(sy2 > sy0 && sy2 > sy1){
      px0 = sx2;
      py0 = sy2;
      if(sx0 > sx1){
        px1 = sx0;
        py1 = sy0;
        px2 = sx1;
        py2 = sy1;
      }else if(sx1 >= sx0){
        px1 = sx1;
        py1 = sy1;
        px2 = sx0;
        py2 = sy0;
      }
    }
    //
    /*printf("px0 => %f\n", px0);
    printf("py0 => %f\n", py0);
    printf("px1 => %f\n", px1);
    printf("py1 => %f\n", py1);
    printf("px2 => %f\n", px2);
    printf("py2 => %f\n", py2);
    printf("%s","================================\n");*/
    // リストを初期化する処理
    p = imgclear();
    // リストへ三角形の画像情報を上書きする処理
    p = imgtriangle(p, px0, py0, px1, py1, px2, py2, r, g, b);
    // リストのポインタを先頭へ戻す処理
    //p = head_color(p);
    // 画像データをファイルへ出力する処理
    if(!imgwrite(head_color(p), angle)){
      return -1;
    }
    // リストの領域を解放する処理
    if(!del_color_array(head_color(p))){
      return -1;
    }
  }
}
