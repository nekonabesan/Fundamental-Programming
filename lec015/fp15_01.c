// animate1 --- create animation using img lib.
#include "modules/fp15_01_module.c"

int main(void) {
  struct color c1;
  struct color c2;
  c1.r = 30;
  c1.g = 255;
  c1.b = 0;
  c2.r = 255;
  c2.g = 0;
  c2.b = 0;

  for(int i = 0; i < 20; ++i) {
    img_clear();
    img_fillcircle(c1, 20+i*8, 100, 20);
    img_write();
  }
  for(int i = 0; i < 20; ++i) {
    img_clear();
    img_fillcircle(c2, 180, 100+i*5, 20-i);
    img_write();
  }
}
