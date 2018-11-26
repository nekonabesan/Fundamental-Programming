// テスト対象関数のプロトタイプ宣言
#ifndef _TARGET_H_
#define _TARGET_H_

//=================================================//
// 以下に関数を宣言
// int coin(int i, int *c);
// int initialize(int *c, int *csel, int rmax);
//=================================================//
// 演習1
struct color {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};
struct color mixcolor(struct color c, struct color d);
void showcolor(struct color c);
struct color brighter(struct color c);
struct color darker(struct color c);
struct color reversecolor(struct color c);
struct color rot1color(struct color c);
struct color rot2color(struct color c);
struct color linearmix(struct color c, struct color d, double ratio);
struct color randomcolor(void);
// 演習2
struct color readcolor(void);
void makedarker(struct color *p);
void makebrighter(struct color *p);
void makereverse(struct color *p);
void makerot1(struct color *p);
void makerot2(struct color *p);
void addtocolor(struct color *p, int dr, int dg, int db);
void varcolor(struct color *p);

#endif /* _TARGET_H_ */