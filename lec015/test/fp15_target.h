// テスト対象関数のプロトタイプ宣言
#ifndef _TARGET_H_
#define _TARGET_H_

//=================================================//
// 以下に関数を宣言
// int coin(int i, int *c);
// int initialize(int *c, int *csel, int rmax);
//=================================================//
bool img_clear(void);
bool img_write(void);
bool img_putpixel(struct color c, int x, int y);
bool img_fillcircle(struct color c, double x, double y, double r);
bool img_triangle(struct color c, double x1, double y1, double x2, double y2, double x3, double y3);


#endif /* _TARGET_H_ */
