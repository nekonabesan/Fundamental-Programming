// テスト対象関数のプロトタイプ宣言
#ifndef _TARGET_H_
#define _TARGET_H_
#define CODE_ZERO_EXCEPTION 0x01

//=================================================//
// 以下に関数を宣言
// int coin(int i, int *c);
// int initialize(int *c, int *csel, int rmax);
//=================================================//
// 演習1
int mystrlen(char s[]);
void prchartriangletail(char s[]);
void mapchar(char s[], char c1, char c2);
void deletechar(char s[],char c1);
void reverse(char s[]);
void mystrcpy(char s1[], char s2[]);
void mystrcat(char s1[], char s2[]);
int mystrcmp(char s1[], char s2[]);
// 演習2
// 演習3
//==================================================//
// 演習4
//==================================================//
// fp13_04_module.c
void cpary(char c1[], char c2[]);
void reversal(char c[]);
void concat_prefix(char c2[], int start = 0, int leng = 0);
bool chk_prefix(char c2[]);
bool chk_suffix(char c2[]);
bool normal_match(char match[], char pattern[]);
int pattern_match(char match[], char pattern[]);
// fp14_04_pars.c
bool pars(struct analysis apars[], char pattern[]);
// fp14_04_naf.c
int countapars(struct analysis apars[]);
int countnaf(struct pat naf[]);
int addpat(struct pat naf[], char c, int l1);
struct pat* zero_or_one(struct pat naf[], char str, int len, int flg);
struct pat* raddpat(struct pat naf[], char str, int len, int flg);
bool convnaf(struct analysis apars[], struct pat naf[], char pattern[], char match[]);

#endif /* _TARGET_H_ */
