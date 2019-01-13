#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>

#define WIDTH 300
#define HEIGHT 200
struct color {
  unsigned char r;
  unsigned char g;
  unsigned char b;
  int x;
  int y;
  struct color *prev;
  struct color *next;
};
struct gp{
  double x;
  double y;
};

//--------------------------------------------------------------//
// 色データを上書きする処理
// @param unsigned char r
// @param unsigned char g
// @param unsigned char b
// @return struct color *t
//--------------------------------------------------------------//
struct color * writecolor(struct color* t, unsigned char r, unsigned char g, unsigned char b) {
  t->r = r;
  t->g = g;
  t->b = b;
  return t;
}

//--------------------------------------------------------------//
// 構造体を初期化する処理
// @return struct color *t
//--------------------------------------------------------------//
struct color * initialize(struct color *t) {
  unsigned char r = 255;
  unsigned char g = 255;
  unsigned char b = 255;
  t = writecolor(t, r, g, b);
  t->x = 0;
  t->y = 0;
  t->next = NULL;
  t->prev = NULL;
  return t;
}

//--------------------------------------------------------------//
// リストを初期化する処理
// int cnt
// return struct collor t
//--------------------------------------------------------------//
struct color * imgclear(void) {
  struct color *t = NULL;
  struct color *n =NULL;
  struct color *prev = NULL;
  struct color *start = NULL;
  for(int y = 0; y < HEIGHT; y++){
    for(int x = 0; x < WIDTH; x++) {
      t = (struct color*)malloc(sizeof(struct color) * 1);
      // リストの先頭要素を取得
      if(x == 0 && y == 0){
        start = t;
        t->prev = NULL;
      }
      t = initialize(t);
      if(prev){
        t->prev = prev;
        prev->next = t;
      }
      prev = t;
      t->y = y;
      t->x = x;
      t->next = NULL;
    }
  }
  return start;
}

//--------------------------------------------------------------//
// 先頭のアドレスを返す処理
// @param struct ent2 *pos
// @return struct ent2 *start
//--------------------------------------------------------------//
struct color * head_color(struct color *pos){
  if(pos->prev == NULL || pos == NULL){
    return pos;
  }
  struct color *head = pos->prev;
  while(1){
    if(head->prev){
      head = head->prev;
    } else {
      break;
    }
  }
  return head;
}

//--------------------------------------------------------------//
// 最後尾のアドレスを返す処理
// @param struct ent2 *pos
// @return struct ent2 *next
//--------------------------------------------------------------//
struct color * eol_color(struct color *pos){
  if(pos->next == NULL){
    return pos;
  }
  struct color *next = pos->next;
  while(1){
    if(next->next){
      next = next->next;
    } else {
      break;
    }
  }
  return next;
}

//============================================================================//
// リストを全て削除する処理
// @param struct color *p
// @return bool
//============================================================================//
bool del_color_array(struct color *p){
  if(p == NULL){
    return false;
  }
  struct color *pos = p;
  //struct color *next = NULL;
  while(pos->next){
    //pos->r = 0;
    //pos->g = 0;
    //pos->b = 0;
    pos = pos->next;
    free(pos->prev);
  }
  return true;
}

//--------------------------------------------------------------//
//--------------------------------------------------------------//
unsigned char* create_buf(void){
    //unsigned char *buf = (unsigned char *)calloc(HEIGHT * WIDTH * 3, sizeof(unsigned char));
    unsigned char *buf = (unsigned char *)malloc(HEIGHT * WIDTH * 3 * sizeof(unsigned char));
    return buf;
}

//--------------------------------------------------------------//
// リストに格納されたデータを画像ファイルへ書き出す処理
// @param struct color *p
// return bool
//--------------------------------------------------------------//
bool imgwrite(struct color *p, int filecnt) {
  char fname[100];
  struct color *c = head_color(p);
  //unsigned char buf[HEIGHT][WIDTH][3];
  unsigned char *buf = create_buf();
  //unsigned char buf[HEIGHT*WIDTH*3];
  //printf("%ld\n", malloc_usable_size(buf));
  while(p->next) {
    //buf[HEIGHT - p->y - 1][p->x][0] = p->r;
    //buf[HEIGHT - p->y - 1][p->x][1] = p->g;
    //buf[HEIGHT - p->y - 1][p->x][2] = p->b;
    buf[((p->x * 3) + 0) + ((HEIGHT - p->y - 1) * (WIDTH * 3))] = p->r;
    buf[((p->x * 3) + 1) + ((HEIGHT - p->y - 1) * (WIDTH * 3))] = p->g;
    buf[((p->x * 3) + 2) + ((HEIGHT - p->y - 1) * (WIDTH * 3))] = p->b;
    //printf("%d\n", ((p->x * 3) + 0) * (p->y + 1));
    p = p->next;
  }
  // ファイル名を取得する処理
  sprintf(fname, "img%04d.ppm", filecnt++);
  FILE *f = fopen(fname, "wb");
  if(f == NULL) {
    fprintf(stderr, "can’t open %s\n", fname);
    exit(1);
    return false;
  }
  fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
  fwrite(buf, malloc_usable_size(buf), 1, f);
  fclose(f);
  free(buf);
  return true;
}

//--------------------------------------------------------------//
// 構造体へ色情報を書き込む処理
// @param struct color *p
// @param int x
// @param int y
// @param unsigned char r
// @param unsigned char g
// @param unsigned char b
// @return struct color *p
//--------------------------------------------------------------//
struct color * imgputpixel(struct color *p, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
  if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
    //return false;
  }
  p->r = r;
  p->g = g;
  p->b = b;
  p->x = x;
  p->y = y;
  if(p->next){
    return p->next;
  } else {
    return p;
  }
}

//--------------------------------------------------------------//
// (参)http://www.ohshiro.tuis.ac.jp/~ohshiro/prog/game07_call_by_reference_pointer.html
// 座標(x, y) を，(xc, yc)を中心に θラジアン回転した座標は，次の式で計算できることが知られている。
// 回転した後のX座標 =  (x - xc) * cosθ - (y - yc) * sinθ + xc
// 回転した後のY座標 =  (x - xc) * sinθ + (y - yc) * cosθ + yc
//--------------------------------------------------------------//
// rd rad回転させたｘ座標を導出するメソッド
// @param double x
// @param double y
// @param double xc
// @param double yc
// @param double rd
// @return double
//--------------------------------------------------------------//
double rt_x(double x, double y, double xc, double yc, double rd){
  return (x - xc) * cos(rd) - (y - yc) * sin(rd) + xc;
}

//--------------------------------------------------------------//
//　rd rad回転させたｙ座標を導出するメソッド
// @param double x
// @param double y
// @param double xc
// @param double yc
// @param double rd
// @return double
//--------------------------------------------------------------//
double rt_y(double x, double y, double xc, double yc, double rd){
  // 数学座標と同じ様にするためにy座標値を反転
  // 正回転の場合コメントアウト？？
  //y = -y;
  //yc = -yc;
  return 1.0 * ((x - xc) * sin(rd) + (y - yc) * cos(rd) + yc);
}

//----------------------------------------------------------------------------//
// 三角形の重心を導出するメソッド
// @param x0
// @param y0
// @param x1
// @param y1
// @param x2
// @param y2
// @return struct gp
//----------------------------------------------------------------------------//
struct gp calc_gp(double x0, double y0, double x1, double y1, double x2, double y2){
  struct gp g;
  g.x = (x0 + x1 + x2) / 3;
  g.y = (y0 + y1 + y2) / 3;
  return g;
}
