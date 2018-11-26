#include "../fp14_common.h"
//============================================================================//
// 演習 2 上の例題をそのまま動かし、暗い色ができることを確認しなさい。
// OK なら次のような関数を作ってみなさい。
//============================================================================//
void showcolor(struct color c) {
  printf("%02x%02x%02x\n", c.r, c.g, c.b);
}

struct color readcolor(void) {
  struct color result;
  printf("r(0-255)> ");
  scanf("%hhd", &result.r);
  printf("g(0-255)> ");
  scanf("%hhd", &result.g);
  printf("b(0-255)> ");
  scanf("%hhd", &result.b);
  return result;
}

void makedarker(struct color *p) {
  short r = p->r / 2;
  short g = p->g / 2;
  short b = p->b / 2;
  p->r = r;
  p->g = g;
  p->b = b;
}

//============================================================================//
// a. 色を明るく変化させる関数 void makebrighter(struct color *p)。
//============================================================================//
void makebrighter(struct color *p){
  short r = p->r + 10;
  short g = p->g + 10;
  short b = p->b + 10;
  if(255 < r){
    r = 255;
  }
  if(255 < g){
    g = 255;
  }
  if(255 < b){
    b = 255;
  }
  p->r = r;
  p->g = b;
  p->b = b;
}

//============================================================================//
// b. 先の演習のreversecolorと同じ変化を施す関数void makereverse(struct color *p)。
//============================================================================//
void makereverse(struct color *p){
  p->r = 255 - p->r;
  p->g = 255 - p->g;
  p->b = 255 - p->b;
}

//============================================================================//
// c. 先の演習のrot1color、rot2color と同様の変化をおこなう関数
// void makerot1(structcolor *p)、void makerot2(struct color *p)。
//============================================================================//
void makerot1(struct color *p){
  short r = p->b;
  short g = p->r;
  short b = p->g;
  p->r = r;
  p->g = g;
  p->b = b;
}

void makerot2(struct color *p){
  short r = p->g;
  short g = p->b;
  short b = p->r;
  p->r = r;
  p->g = g;
  p->b = b;
}

//============================================================================//
// d. RGB 値の増分 (マイナスでもよい) を受け取り、その分だけそれぞれの成分を増やす関数
// void addtocolor(struct color *p, int dr, int dg, int db)。
//============================================================================//
void addtocolor(struct color *p, int dr, int dg, int db){
  int r = (int)p->r;
  int g = (int)p->g;
  int b = (int)p->b;
  r += dr;
  g += dg;
  b += db;

  if(r < 0){
    r = 0;
  } else if(255 < r){
    r = 255;
  }
  if(g < 0){
    g = 0;
  } else if(255 < g){
    g = 255;
  }
  if(b < 0){
    b = 0;
  } else if(255 < b){
    b = 255;
  }
  p->r = (short)r;
  p->g = (short)g;
  p->b = (short)b;
}

//============================================================================//
// e. RGB 値それぞれに-10～10 の範囲のランダムな値を足すことで元とちょっとだけ違う色に
// する関数 void varcolor(struct color *p)。
//============================================================================//
void varcolor(struct color *p){

}

//============================================================================//
// f. その他色の構造体のアドレスを受け取り、好きな変化を施す関数。
//============================================================================//
