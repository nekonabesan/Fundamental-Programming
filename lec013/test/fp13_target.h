// テスト対象関数のプロトタイプ宣言
#ifndef _TARGET_H_
#define _TARGET_H_

#define MAX 10000
#define CODE_ZERO_EXCEPTION 0x01
//============================================================================//
// 演習 4 上のコードを打ち込み、パターンが正しく処理されていることを確認しなさい。
// OK なら、次のことをやってみなさい。
//============================================================================//
//============================================================================//
// a . 「+」(1 回以上の繰り返し) に加えて「*」(0 回以上の繰り返し) も記述できるようにしてみなさい。
//============================================================================//
#define ONE_OR_MORE_ITERATIONS 0x2b
#define ZERO_OR_MORE_ITERATIONS 0x2a
//============================================================================//
// b. 「?」(直前の文字があってもなくてもよい) を実現してみなさい。
//============================================================================//
#define MAY_OR_MAY_NOT_BE_PRESENT 0x3f
//============================================================================//
// d. 文字クラス[...](...の文字のいずれかならあてはまる)を実現してみなさい。
// [^...](...のいずれでもなければ) も実現できるとなおよいです。
//============================================================================//
#define START_MALTI_PATTERN 0x5b
#define END_MALTI_PATTERN 0x5d
//============================================================================//
// e. ここまでに出て来た特殊文字の機能をなくすエスケープ記号「\」を実現しなさい
// (この文字に続いて特殊文字があった場合通常の文字として扱う)。
//============================================================================//
#define ESCAPE_SEQENCE 0x5c
//============================================================================//
// f. その他、パターンマッチにおいてあると面白いと思う好きな機能を選び実現しなさい
//============================================================================//

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
bool zero_or_one(struct pat anaf[], char str, int len, int flg);
bool zero_to_n(struct pat anaf[], char str, int len, int flg);
bool one_to_n(struct pat anaf[], char str, int len, int flg);
bool raddpat(struct pat anaf[], char str, int len, int flg);
bool convnaf(struct analysis apars[], struct pat naf[], char pattern[], char match[]);

#endif /* _TARGET_H_ */
