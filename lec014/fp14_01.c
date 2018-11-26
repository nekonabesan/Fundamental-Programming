#inclide "modules/fp14_01_module.c"

int main(void) {
  struct color white = { 255, 255, 255 };
  struct color c1 = { 10, 100, 120 };
  showcolor(c1);
  showcolor(mixcolor(white, c1));
  return 0;
}
