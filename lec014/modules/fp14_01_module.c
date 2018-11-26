#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// color1.c --- handle color struct.
struct color {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};
//============================================================================//
// 演習 1 上の例題をそのまま打ち込んで実行しなさい。c1 の色は別のものにしてよいです。
// LMS 上に16 進 6 桁を入力してその色を表示するページを用意してあるので、
// それを利用してどんな色か確認すること。OK なら次のような関数を作ってみなさい。
//============================================================================//
struct color mixcolor(struct color c, struct color d) {
  struct color ret = {
    (c.r + d.r) / 2,
    (c.g + d.g) / 2,
    (c.b + d.b) / 2
  };
  return ret;
}

void showcolor(struct color c) {
  printf("%02x%02x%02x\n", c.r, c.g, c.b);
}

//============================================================================//
// a. 渡された色と白の平均を取って返す関数 struct color brighter(struct color c)。
//============================================================================//
struct color brighter(struct color c){
  struct color ret = {
    (c.r + 255) / 2,
    (c.g + 255) / 2,
    (c.b + 255) / 2
  };
  return ret;
}

//============================================================================//
// b. 渡された色と黒の平均を取って返す関数 struct color darker(struct color c)。
//============================================================================//
struct color darker(struct color c){
  short r = 0;
  short g = 0;
  short b = 0;
  struct color ret;
  if(0 < c.r){
    r = (c.r + 0) / 2;
  }
  if(0 < c.g){
    g = (c.g + 0) / 2;
  }
  if(0 < c.b){
    b = (c.b + 0) / 2;
  }
  ret.r = r;
  ret.g = g;
  ret.b = b;
  return ret;
}

//============================================================================//
// c. RGB 値は 0～255 なので、それぞれ「255 からその値を引く」と 0 は 255 に、255 は 0 になる。
// これを利用して、明るい色は暗く、暗い色は明るい色にして返す関数
// struct colorreversecolor(struct color c)。
//============================================================================//
struct color reversecolor(struct color c){
  struct color result;
  result.r = 255 - c.r;
  result.g = 255 - c.g;
  result.b = 255 - c.b;
  return result;
}

//============================================================================//
// d. R の値を G に、G の値を B に、B の値を R にコピーすることで、
// もとと明るさが同じくらいだけど色調が違う色ができるはずである。
// これをおこなう関数 struct color rot1color(struct color c)。
//============================================================================//
struct color rot1color(struct color c){
  struct color result;
  result.r = c.b;
  result.g = c.r;
  result.b = c.g;
  return result;
}
//============================================================================//
// ついでに R を B に、G を R に、B を G にコピーする関数
// struct color rot2color(struct color c) も作ってみるとよい。
//============================================================================//
struct color rot2color(struct color c){
  struct color result;
  result.r = c.g;
  result.g = c.b;
  result.b = c.r;
  return result;
}

//============================================================================//
// e. 2 つの色と 0.0～1.0 の値を渡すとその 2 色を指定した比率で混ぜた色を返す関数
// structcolor linearmix(struct color c, struct color d, double ratio)。
// ratio が 0.5のときは平均になるので mixcolor と同じになる。
//============================================================================//
struct color linearmix(struct color c, struct color d, double ratio){
  struct color result;
  result.r = (((short)c.r * ratio) + (d.r * (1 -ratio)));
  result.g = (((short)c.g * ratio) + (d.g * (1 -ratio)));;
  result.b = (((short)c.b * ratio) + (d.b * (1 -ratio)));;
  return result;
}

//============================================================================//
// f. パラメタは何も受け取らず、中で擬似乱数でランダムな色を生成し返す関数
// struct colorrandomcolor(void)(擬似乱数は#12 の付録参照)。
//============================================================================//
struct color randomcolor(void){

}

//============================================================================//
// g. その他、色を計算する何か面白い関数。
//============================================================================//
