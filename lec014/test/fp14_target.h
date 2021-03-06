// テスト対象関数のプロトタイプ宣言
#ifndef _TARGET_H_
#define _TARGET_H_

//=================================================//
// 以下に関数を宣言
// int coin(int i, int *c);
// int initialize(int *c, int *csel, int rmax);
//=================================================//
#define MAXTBL 1000000
// 演習1
struct color {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};
// 演習2
struct ent {
  char *key;
  int val;
};
// 演習3
struct ent2 {
  char *key;
  char *val;
  struct ent *prev;
  struct ent *next;
};

struct ent tbl[MAXTBL];
struct ent2 tbl2[MAXTBL];
//int tblsize = 0;
//int tblsize2 = 0;

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
// 演習3
struct ent2 * add_struct(struct ent2* p, char key[], char val[]);
bool del_struct(struct ent2 *p);
bool del_array(struct ent2 *p);
struct ent2 * show_structs(struct ent2* p);
struct ent2 * initialize(char key[], char val[]);
struct ent2 * head_address(struct ent2 *pos);
// 演習5
static unsigned int hash(char *s);
static struct ent *lookup(struct ent *p, char *k);
int get1(struct ent *p, char *k);
static bool put1(struct ent **p, char *k, int v);
int tbl_get(char *k);
bool tbl_put(char *k, int v);

#endif /* _TARGET_H_ */
