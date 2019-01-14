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
double rt_x(double x, double y, double xc, double yc, double rd);
double rt_y(double x, double y, double xc, double yc, double rd);
// fp15_triangle.c
struct gp calc_gp(double x0, double y0, double x1, double y1, double x2, double y2);
bool img_triangle(struct color c, double x1, double y1, double x2, double y2, double x3, double y3);
bool img_rtriangle(struct color c, double x0, double y0, double x1, double y1, double x2, double y2);
bool rt_triangle(struct color c, double x0, double y0, double x1, double y1, double x2, double y2);
// fp15_circle.c
bool img_fillcircle(struct color c, double x, double y, double r);
bool rt_circle(struct color c, double x0, double y0, double r);
// fp15_03fp15_01_module.c
struct color * writecolor(struct color *t, unsigned char r, unsigned char g, unsigned char b);
struct color * initialize(struct color *t);
struct color * imgclear(void);
struct color * head_color(struct color *pos);
struct color * eol_color(struct color *pos);
bool del_color_array(struct color *p);
bool imgwrite(struct color *p, int filecnt);
struct color * imgputpixel(struct color *p, int x, int y, unsigned char r, unsigned char g, unsigned char b);
// fp15_03fp15_03_module.c
unsigned char* create_buf(void);

#endif /* _TARGET_H_ */
