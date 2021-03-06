//#define MAX 10000
#define TRUE 1
#define FALSE 0

// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
  #include "../fp13_target.h"
}

// fixtureNameはテストケース群をまとめるグループ名と考えればよい、任意の文字列
// それ以外のclass～testing::Testまではおまじないと考える
class fixtureName : public ::testing::Test {
protected:
    // fixtureNameでグループ化されたテストケースはそれぞれのテストケース実行前に
    // この関数を呼ぶ。共通の初期化処理を入れておくとテストコードがすっきりする
    virtual void SetUp(){
    }
    // SetUpと同様にテストケース実行後に呼ばれる関数。共通後始末を記述する。
    virtual void TearDown(){
    }
};

struct analysis {
  char c;
  char seq;
};
struct pat {
  char a[MAX];
};

// 成功するテストケース。細かい説明はGoogleTestのマニュアルを見てね。
//====================================================//
// 構文解釈の格納された配列の要素数を数える処理
// @param struct analysis apars[]
// @return int cnt
//====================================================//
TEST_F(fixtureName, countapars01)
{
    struct analysis *apars = (struct analysis*)malloc(sizeof(struct analysis) * 2);
    char *pattern = (char *)malloc(10 * sizeof(char));
    // test01
    strcpy(pattern, "str");
    pars(apars, pattern);
    EXPECT_EQ(countapars(apars), 3);
    free(apars);
    free(pattern);
}
TEST_F(fixtureName, countapars02)
{
    struct analysis *apars = (struct analysis*)malloc(sizeof(struct analysis) * 2);
    char *pattern = (char *)malloc(10 * sizeof(char));
    // test01
    strcpy(pattern, "s?t+r*");
    pars(apars, pattern);
    EXPECT_EQ(countapars(apars), 3);
    free(apars);
    free(pattern);
}

//====================================================//
// NAF変換結果の格納された配列の要素数を数える処理
// @param struct analysis apars[]
// @return int cnt
//====================================================//
TEST_F(fixtureName, countnaf01)
{
  struct pat naf[3];
  struct pat *anaf = naf;
  // test01
  strcpy(anaf[0].a, "str");
  anaf[1].a[0] = 0x00;
  anaf[2].a[0] = 0x00;
  EXPECT_EQ(countnaf(anaf), 1);
  // test02
  naf[1].a[0] = CODE_ZERO_EXCEPTION;
  EXPECT_EQ(countnaf(anaf), 2);
}
TEST_F(fixtureName, countnaf02)
{
    struct pat *naf = (struct pat*)malloc(sizeof(struct pat) * 3);
    // test01
    naf[0].a[0] = 0x00;
    naf[1].a[0] = 0x00;
    naf[2].a[0] = 0x00;
    EXPECT_EQ(countnaf(naf), 0);
    free(naf);
}

//====================================================//
// 大域変数nafに格納された構造体の変数aに文字を追加する処理
// param  char *pattern
// return bool
//====================================================//
TEST_F(fixtureName, addpat)
{
  struct pat *naf = (struct pat*)malloc(sizeof(struct pat)*1);
  char *array = (char *)malloc(3 * sizeof(char));
  naf[1].a[0] = 0x00;
  strcpy(array, "str");
  EXPECT_EQ(addpat(naf, array[0], 3), 0);
  EXPECT_EQ(addpat(naf, array[1], 3), 0);
  EXPECT_EQ(addpat(naf, array[2], 3), 0);
  EXPECT_EQ(naf[0].a[0], 0x73);
  EXPECT_EQ(naf[0].a[1], 0x74);
  EXPECT_EQ(naf[0].a[2], 0x72);
  EXPECT_EQ(naf[0].a[3], 0x00);
  // 領域開放
  free(naf);
  free(array);
}

//====================================================//
// 大域変数nafに格納された構造体の変数aに0文字を追加した
// パターンと1文字追加したパターンを追加する処理
// @param struct pat* anaf
// @param char str
// @param int len
// @param int flg
// @return struct pat* naf
//====================================================//
TEST_F(fixtureName, zero_or_one01)
{
  struct pat naf[10];
  struct pat *anaf = naf;
  memset(anaf , 0x00 , sizeof(pat) * 10);
  anaf[1].a[0] = 0x00;
  strcpy(anaf[0].a, "str");
  char str = 0x69;
  int len = 6;
  int flg = MAY_OR_MAY_NOT_BE_PRESENT;
  // test01
  zero_or_one(anaf, str, len, flg);
  EXPECT_EQ(strlen(naf[0].a), 4);
  EXPECT_EQ(naf[0].a[0], 0x73);
  EXPECT_EQ(naf[0].a[1], 0x74);
  EXPECT_EQ(naf[0].a[2], 0x72);
  EXPECT_EQ(naf[0].a[3], 0x69);
  EXPECT_EQ(naf[0].a[4], 0x00);
  EXPECT_EQ(strlen(naf[1].a), 4);
  EXPECT_EQ(naf[1].a[0], 0x73);
  EXPECT_EQ(naf[1].a[1], 0x74);
  EXPECT_EQ(naf[1].a[2], 0x72);
  EXPECT_EQ(naf[1].a[3], 0x01);
  EXPECT_EQ(naf[0].a[4], 0x00);
  // 領域開放
  memset(anaf , 0x00 , sizeof(pat) * 10);
}
TEST_F(fixtureName, zero_or_one02)
{
  struct pat naf[10];
  struct pat *anaf = naf;
  memset(anaf , 0x00 , sizeof(pat) * 10);
  anaf[0].a[0] = 0x00;
  anaf[0].a[1] = 0x00;
  anaf[1].a[0] = 0x00;
  anaf[1].a[1] = 0x00;
  char str = 0x73;
  int len = 6;
  int flg = MAY_OR_MAY_NOT_BE_PRESENT;
  // test02
  zero_or_one(anaf, str, len, flg);
  EXPECT_EQ(strlen(naf[0].a), 1);
  EXPECT_EQ(naf[0].a[0], 0x73);
  EXPECT_EQ(naf[0].a[1], 0x00);
  EXPECT_EQ(strlen(naf[1].a), 1);
  EXPECT_EQ(naf[1].a[0], 0x01);
  EXPECT_EQ(naf[1].a[1], 0x00);
  // 領域開放
  memset(anaf , 0x00 , sizeof(pat) * 10);
}

//====================================================//
// 大域変数nafに格納された構造体の変数aに0～N文字を追加した
// パターンの処理
// @param struct pat* naf
// @param char str
// @param int len
// @param int flg
// @return struct pat* naf
//====================================================//
TEST_F(fixtureName, zero_to_n01)
{
  struct pat naf[10];
  struct pat *anaf = naf;
  memset(anaf , 0x00 , sizeof(pat) * 10);
  anaf[1].a[0] = 0x00;
  strcpy(anaf[0].a, "s");
  char str = 0x74;
  int len = 6;
  int flg = ZERO_OR_MORE_ITERATIONS;
  zero_to_n(anaf, str, len, flg);
  // 0
  EXPECT_EQ(naf[0].a[0], 0x73);
  EXPECT_EQ(naf[0].a[1], 0x74);
  EXPECT_EQ(naf[0].a[2], 0x00);
  // 1
  EXPECT_EQ(naf[1].a[0], 0x73);
  EXPECT_EQ(naf[1].a[1], 0x74);
  EXPECT_EQ(naf[1].a[2], 0x74);
  EXPECT_EQ(naf[1].a[3], 0x00);
  // 2
  EXPECT_EQ(naf[2].a[0], 0x73);
  EXPECT_EQ(naf[2].a[1], 0x74);
  EXPECT_EQ(naf[2].a[2], 0x74);
  EXPECT_EQ(naf[2].a[3], 0x74);
  EXPECT_EQ(naf[2].a[4], 0x00);
  // 3
  EXPECT_EQ(naf[3].a[0], 0x73);
  EXPECT_EQ(naf[3].a[1], 0x74);
  EXPECT_EQ(naf[3].a[2], 0x74);
  EXPECT_EQ(naf[3].a[3], 0x74);
  EXPECT_EQ(naf[3].a[4], 0x74);
  EXPECT_EQ(naf[3].a[5], 0x00);
  // 4
  EXPECT_EQ(naf[4].a[0], 0x73);
  EXPECT_EQ(naf[4].a[1], 0x74);
  EXPECT_EQ(naf[4].a[2], 0x74);
  EXPECT_EQ(naf[4].a[3], 0x74);
  EXPECT_EQ(naf[4].a[4], 0x74);
  EXPECT_EQ(naf[4].a[5], 0x74);
  EXPECT_EQ(naf[4].a[6], 0x00);
  // 5
  EXPECT_EQ(naf[5].a[0], 0x73);
  EXPECT_EQ(naf[5].a[1], 0x01);
  EXPECT_EQ(naf[5].a[2], 0x00);
  // 領域開放
  memset(anaf , 0x00 , sizeof(pat) * 10);
}
TEST_F(fixtureName, zero_to_n02)
{
  struct pat naf[10];
  struct pat *anaf = naf;
  memset(anaf , 0x00 , sizeof(pat) * 10);
  anaf[1].a[0] = 0x00;
  strcpy(anaf[0].a, "st");
  char str = 0x72;
  int len = 6;
  int flg = ZERO_OR_MORE_ITERATIONS;
  zero_to_n(anaf, str, len, flg);
  // 0
  EXPECT_EQ(naf[0].a[0], 0x73);
  EXPECT_EQ(naf[0].a[1], 0x74);
  EXPECT_EQ(naf[0].a[2], 0x72);
  EXPECT_EQ(naf[0].a[3], 0x00);
  // 1
  EXPECT_EQ(naf[1].a[0], 0x73);
  EXPECT_EQ(naf[1].a[1], 0x74);
  EXPECT_EQ(naf[1].a[2], 0x72);
  EXPECT_EQ(naf[1].a[3], 0x72);
  EXPECT_EQ(naf[1].a[4], 0x00);
  // 2
  EXPECT_EQ(naf[2].a[0], 0x73);
  EXPECT_EQ(naf[2].a[1], 0x74);
  EXPECT_EQ(naf[2].a[2], 0x72);
  EXPECT_EQ(naf[2].a[3], 0x72);
  EXPECT_EQ(naf[2].a[4], 0x72);
  EXPECT_EQ(naf[2].a[5], 0x00);
  // 3
  EXPECT_EQ(naf[3].a[0], 0x73);
  EXPECT_EQ(naf[3].a[1], 0x74);
  EXPECT_EQ(naf[3].a[2], 0x72);
  EXPECT_EQ(naf[3].a[3], 0x72);
  EXPECT_EQ(naf[3].a[4], 0x72);
  EXPECT_EQ(naf[3].a[5], 0x72);
  EXPECT_EQ(naf[3].a[6], 0x00);
  // 4
  EXPECT_EQ(naf[4].a[0], 0x73);
  EXPECT_EQ(naf[4].a[1], 0x74);
  EXPECT_EQ(naf[4].a[2], 0x01);
  EXPECT_EQ(naf[4].a[3], 0x00);
  // 領域開放
  memset(anaf , 0x00 , sizeof(pat) * 10);
}
TEST_F(fixtureName, zero_to_n03)
{
  struct pat naf[10];
  struct pat *anaf = naf;
  memset(anaf , 0x00 , sizeof(pat) * 10);
  anaf[1].a[0] = 0x00;
  char str = 0x73;
  int len = 6;
  int flg = ZERO_OR_MORE_ITERATIONS;
  zero_to_n(anaf, str, len, flg);
  // 0
  EXPECT_EQ(naf[0].a[0], 0x73);
  EXPECT_EQ(naf[0].a[1], 0x00);
  // 1
  EXPECT_EQ(naf[1].a[0], 0x73);
  EXPECT_EQ(naf[1].a[1], 0x73);
  EXPECT_EQ(naf[1].a[2], 0x00);
  // 2
  EXPECT_EQ(naf[2].a[0], 0x73);
  EXPECT_EQ(naf[2].a[1], 0x73);
  EXPECT_EQ(naf[2].a[2], 0x73);
  EXPECT_EQ(naf[2].a[3], 0x00);
  // 3
  EXPECT_EQ(naf[3].a[0], 0x73);
  EXPECT_EQ(naf[3].a[3], 0x73);
  EXPECT_EQ(naf[3].a[4], 0x00);
  // 4
  EXPECT_EQ(naf[4].a[0], 0x73);
  EXPECT_EQ(naf[4].a[4], 0x73);
  EXPECT_EQ(naf[4].a[5], 0x00);
  // 5
  EXPECT_EQ(naf[5].a[0], 0x73);
  EXPECT_EQ(naf[5].a[5], 0x73);
  EXPECT_EQ(naf[5].a[6], 0x00);
  // 0
  EXPECT_EQ(naf[6].a[0], 0x01);
  EXPECT_EQ(naf[6].a[1], 0x00);
  // 領域開放
  memset(anaf , 0x00 , sizeof(pat) * 10);
}

//====================================================//
// 大域変数nafに格納された構造体の変数aに1～N文字を追加した
// パターンの処理
// @param struct pat* anaf
// @param char str
// @param int len
// @param int flg
// @return bool
//====================================================//
TEST_F(fixtureName, one_to_n01)
{
  struct pat naf[10];
  struct pat *anaf = naf;
  memset(anaf , 0x00 , sizeof(pat) * 10);
  anaf[1].a[0] = 0x00;
  strcpy(anaf[0].a, "a");
  char str = 0x62;
  int len = 6;
  int flg = ONE_OR_MORE_ITERATIONS;
  zero_to_n(anaf, str, len, flg);
  // 0
  EXPECT_EQ(naf[0].a[0], 0x61);
  EXPECT_EQ(naf[0].a[1], 0x62);
  EXPECT_EQ(naf[0].a[2], 0x00);
  // 1
  EXPECT_EQ(naf[1].a[0], 0x61);
  EXPECT_EQ(naf[1].a[2], 0x62);
  EXPECT_EQ(naf[1].a[3], 0x00);
  // 2
  EXPECT_EQ(naf[2].a[0], 0x61);
  EXPECT_EQ(naf[2].a[3], 0x62);
  EXPECT_EQ(naf[2].a[4], 0x00);
  // 3
  EXPECT_EQ(naf[3].a[0], 0x61);
  EXPECT_EQ(naf[3].a[4], 0x62);
  EXPECT_EQ(naf[3].a[5], 0x00);
  // 4
  EXPECT_EQ(naf[4].a[0], 0x61);
  EXPECT_EQ(naf[4].a[5], 0x62);
  EXPECT_EQ(naf[4].a[6], 0x00);
  // 領域開放
  memset(anaf , 0x00 , sizeof(pat) * 10);
}
TEST_F(fixtureName, one_to_n02)
{
  struct pat naf[10];
  struct pat *anaf = naf;
  memset(anaf , 0x00 , sizeof(pat) * 10);
  anaf[1].a[0] = 0x00;
  strcpy(anaf[0].a, "ab");
  char str = 0x63;
  int len = 6;
  int flg = ONE_OR_MORE_ITERATIONS;
  zero_to_n(anaf, str, len, flg);
  // 0
  EXPECT_EQ(naf[0].a[0], 0x61);
  EXPECT_EQ(naf[0].a[1], 0x62);
  EXPECT_EQ(naf[0].a[2], 0x63);
  EXPECT_EQ(naf[0].a[3], 0x00);
  // 1
  EXPECT_EQ(naf[1].a[0], 0x61);
  EXPECT_EQ(naf[1].a[1], 0x62);
  EXPECT_EQ(naf[1].a[2], 0x63);
  EXPECT_EQ(naf[1].a[3], 0x63);
  EXPECT_EQ(naf[1].a[4], 0x00);
  // 2
  EXPECT_EQ(naf[2].a[0], 0x61);
  EXPECT_EQ(naf[2].a[1], 0x62);
  EXPECT_EQ(naf[2].a[2], 0x63);
  EXPECT_EQ(naf[2].a[3], 0x63);
  EXPECT_EQ(naf[2].a[4], 0x63);
  EXPECT_EQ(naf[2].a[5], 0x00);
  // 2
  EXPECT_EQ(naf[3].a[0], 0x61);
  EXPECT_EQ(naf[3].a[1], 0x62);
  EXPECT_EQ(naf[3].a[2], 0x63);
  EXPECT_EQ(naf[3].a[3], 0x63);
  EXPECT_EQ(naf[3].a[4], 0x63);
  EXPECT_EQ(naf[3].a[5], 0x63);
  EXPECT_EQ(naf[3].a[6], 0x00);
  //
  memset(anaf , 0x00 , sizeof(pat) * 10);
}
TEST_F(fixtureName, one_to_n03)
{
  struct pat naf[10];
  struct pat *anaf = naf;
  memset(anaf , 0x00 , sizeof(pat) * 10);
  anaf[1].a[0] = 0x00;
  char str = 0x61;
  int len = 6;
  int flg = ONE_OR_MORE_ITERATIONS;
  zero_to_n(anaf, str, len, flg);
  // 0
  EXPECT_EQ(naf[0].a[0], 0x61);
  EXPECT_EQ(naf[0].a[1], 0x00);
  // 1
  EXPECT_EQ(naf[1].a[0], 0x61);
  EXPECT_EQ(naf[1].a[1], 0x61);
  EXPECT_EQ(naf[1].a[2], 0x00);
  // 2
  EXPECT_EQ(naf[2].a[0], 0x61);
  EXPECT_EQ(naf[2].a[2], 0x61);
  EXPECT_EQ(naf[2].a[3], 0x00);
  // 3
  EXPECT_EQ(naf[3].a[0], 0x61);
  EXPECT_EQ(naf[3].a[3], 0x61);
  EXPECT_EQ(naf[3].a[4], 0x00);
  // 4
  EXPECT_EQ(naf[4].a[0], 0x61);
  EXPECT_EQ(naf[4].a[4], 0x61);
  EXPECT_EQ(naf[4].a[5], 0x00);
  // 4
  EXPECT_EQ(naf[5].a[0], 0x61);
  EXPECT_EQ(naf[5].a[5], 0x61);
  EXPECT_EQ(naf[5].a[6], 0x00);
  // 領域開放
  memset(anaf , 0x00 , sizeof(pat) * 10);
}


//====================================================//
// 大域変数nafに格納された構造体の変数aに1文字を追加した
// パターンと０文字追加したパターンを追加する処理
// @param pat *naf
// @param char str
// @param int len
// @param int flg
// @return bool
//====================================================//
TEST_F(fixtureName, raddpat_b)
{
  struct pat naf[10];
  struct pat *anaf = naf;
  char *array = (char *)malloc(3 * sizeof(char));
  anaf[1].a[0] = 0x00;
  strcpy(naf[0].a, "str");
  char str = 0x69;
  int len = 6;
  int flg = MAY_OR_MAY_NOT_BE_PRESENT;
  // b. 「?」(直前の文字があってもなくてもよい) を実現してみなさい。
  //EXPECT_TRUE(initialize());
  EXPECT_TRUE(raddpat(anaf, str, len, flg));
  EXPECT_EQ(strlen(anaf[0].a), 4);
  EXPECT_EQ(anaf[0].a[0], 0x73);
  EXPECT_EQ(anaf[0].a[3], 0x69);
  EXPECT_EQ(anaf[0].a[4], 0x00);
  EXPECT_EQ(strlen(anaf[1].a),4);
  EXPECT_EQ(anaf[1].a[0], 0x73);
  EXPECT_EQ(anaf[1].a[2], 0x72);
  EXPECT_EQ(anaf[1].a[3], 0x01);
  // 領域開放
  free(array);
}

//====================================================//
// 構文解釈の処理
// @param struct analysis *apars
// @param struct pat *naf
// @param char *pattern
// @param char *match
// @return bool
//====================================================//
TEST_F(fixtureName, convnaf01)
{
  struct analysis *apars = (struct analysis*)malloc(sizeof(struct analysis) * 2);
  struct pat *naf = (struct pat*)malloc(sizeof(struct pat) * 2);
  char *match = (char *)malloc(10 * sizeof(char));
  char *pattern = (char *)malloc(10 * sizeof(char));
  // test01
  strcpy(match, "string");
  strcpy(pattern, "str");
  EXPECT_TRUE(pars(apars, pattern));
  EXPECT_TRUE(convnaf(apars, naf, pattern, match));
  EXPECT_EQ(naf[0].a[0], 0x73);
  EXPECT_EQ(naf[0].a[1], 0x74);
  EXPECT_EQ(naf[0].a[2], 0x72);
  // 領域開放
  free(apars);
  free(naf);
  free(match);
  free(pattern);
}
TEST_F(fixtureName, convnaf02)
{
  struct analysis *apars = (struct analysis*)malloc(sizeof(struct analysis) * 2);
  struct pat *naf = (struct pat*)malloc(sizeof(struct pat) * 2);
  char *match = (char *)malloc(10 * sizeof(char));
  char *pattern = (char *)malloc(10 * sizeof(char));
  // test01
  strcpy(match, "string");
  strcpy(pattern, "s*t?r+");
  /*EXPECT_TRUE(pars(apars, pattern));
  EXPECT_TRUE(convnaf(apars, naf, pattern, match));
  EXPECT_EQ(naf[0].a[0], 0x73);
  EXPECT_EQ(naf[1].a[1], 0x73);
  EXPECT_EQ(naf[2].a[2], 0x73);*/
  // 領域開放
  free(apars);
  free(naf);
  free(match);
  free(pattern);
}


//============================================================================//
// 配列を複製する処理
// @param char Array c1 参照元の配列
// @param char Array c2
// @result void
//============================================================================//
TEST_F(fixtureName, cpary){
  char *c1 = (char *)malloc(7 * sizeof(char));
  char *c2 = (char *)malloc(2 * sizeof(char));
  strcpy(c1, "^str$");
  strcpy(c2, "aa");
  cpary(c1, c2);
  EXPECT_STREQ(c1, "^str$");
  EXPECT_STREQ(c2, "^str$");
  // 領域開放
  free(c1);
  free(c2);
}

//============================================================================//
// 反転
// @param char Array
// @result void
//============================================================================//
TEST_F(fixtureName, reversal){
  char *c1 = (char *)malloc(5 * sizeof(char));
  // test01
  strcpy(c1, "^str$");
  reversal(c1);
  EXPECT_STREQ(c1, "$rts^");
  // test02
  c1 = (char *)realloc(c1 ,sizeof(char) * 10);
  strcpy(c1, "\\^abcde$");
  reversal(c1);
  EXPECT_STREQ(c1, "$edcba^\\");
  free(c1);
}

//============================================================================//
// startからlen文字を削除する処理
// @param char Array c2[]
// @param int strat
// @param int len
// @result void
//============================================================================//
TEST_F(fixtureName, concat_prefix)
{
  char *match = (char *)malloc(10 * sizeof(char));
  //test01
  strcpy(match, "^str");
  concat_prefix(match, 0, 1);
  EXPECT_STREQ(match, "str");
  //test02
  strcpy(match, "\\^str");
  concat_prefix(match, 0, 1);
  EXPECT_STREQ(match, "^str");
  // 領域開放
  free(match);
}

//============================================================================//
// c. ^(先頭に固定) を実現してみなさい。
//============================================================================//
TEST_F(fixtureName, chk_prefix)
{
  char *match = (char *)malloc(10 * sizeof(char));
  //test01
  strcpy(match, "^str");
  EXPECT_TRUE(chk_prefix(match));
  EXPECT_STREQ(match, "str");
  // test02
  strcpy(match, "string");
  EXPECT_FALSE(chk_prefix(match));
  EXPECT_STREQ(match, "string");
  //test03
  strcpy(match, "\\^str");
  EXPECT_FALSE(chk_prefix(match));
  EXPECT_STREQ(match, "^str");
  // 領域開放
  free(match);
}

//============================================================================//
// c. $(末尾に固定) を実現してみなさい。
//============================================================================//
TEST_F(fixtureName, chk_suffix)
{
  char *match = (char *)malloc(10 * sizeof(char));
  //test01
  strcpy(match, "str$");
  EXPECT_TRUE(chk_suffix(match));
  EXPECT_STREQ(match, "str");
  // test02
  strcpy(match, "string");
  EXPECT_FALSE(chk_suffix(match));
  EXPECT_STREQ(match, "string");
  //test01
  strcpy(match, "str\\$");
  EXPECT_FALSE(chk_suffix(match));
  EXPECT_STREQ(match, "str$");
  // 領域開放
  free(match);
}

//====================================================//
// pattern、pos文字目までのマッチング
// param char *match
// param char *pattern
// param int l1
// param int pos
// return int result
//====================================================//
TEST_F(fixtureName, normal_match)
{
  char *match = (char *)malloc(10 * sizeof(char));
  char *pattern = (char *)malloc(10 * sizeof(char));
  // test01
  strcpy(match, "string");
  strcpy(pattern, "str");
  int result = normal_match(match, pattern);
  EXPECT_TRUE(result);
  strcpy(pattern, "tri");
  result = normal_match(match, pattern);
  EXPECT_TRUE(result);
  strcpy(pattern, "ing");
  result = normal_match(match, pattern);
  EXPECT_TRUE(result);
  // test02
  strcpy(pattern, "abc");
  result = normal_match(match, pattern);
  EXPECT_FALSE(result);
  strcpy(pattern, "stg");
  result = normal_match(match, pattern);
  EXPECT_FALSE(result);
  strcpy(pattern, "mng");
  result = normal_match(match, pattern);
  EXPECT_FALSE(result);
  // 領域開放
  free(match);
  free(pattern);
}

/*TEST_F(fixtureName, mach1)
{
  char *match = (char *)malloc(10 * sizeof(char));
  char *pattern = (char *)malloc(10 * sizeof(char));
  // test01
  strcpy(match,"string");
  strcpy(pattern,"str");
  EXPECT_EQ(pattern_match(match, pattern), 1);
  // test02
  strcpy(match,"string");
  strcpy(pattern,"tri");
  EXPECT_EQ(pattern_match(match, pattern), 1);
  // test02
  strcpy(match,"string");
  strcpy(pattern,"rin");
  EXPECT_EQ(pattern_match(match, pattern), 1);
  // test02
  strcpy(match,"string");
  strcpy(pattern,"ing");
  EXPECT_EQ(pattern_match(match, pattern), 1);
  // test02
  strcpy(match,"string");
  strcpy(pattern,"sti");
  EXPECT_EQ(pattern_match(match, pattern), -1);
  // test02
  strcpy(match,"string");
  strcpy(pattern,"ina");
  EXPECT_EQ(pattern_match(match, pattern), -1);
  // test02
  strcpy(match,"string");
  strcpy(pattern,"abc");
  EXPECT_EQ(pattern_match(match, pattern), -1);
  // test02
  strcpy(match,"string");
  strcpy(pattern,"asr");
  EXPECT_EQ(pattern_match(match, pattern), -1);
  // test02
  strcpy(match,"string");
  strcpy(pattern,"nga");
  EXPECT_EQ(pattern_match(match, pattern), -1);
  // 領域開放
  free(match);
  free(pattern);
}

// あえて失敗するテストケースも書いておく。
TEST_F(fixtureName, mach2)
{
  char *match = (char *)malloc(10 * sizeof(char));
  char *pattern = (char *)malloc(10 * sizeof(char));
  // test01
  strcpy(match,"string");
  pattern = NULL;
  EXPECT_EQ(pattern_match(match, pattern), -1);
  // test02
  strcpy(match,"string");
  strcpy(pattern,"");
  EXPECT_EQ(pattern_match(match, pattern), -1);
  // test03
  match = NULL;
  strcpy(pattern,"str");
  EXPECT_EQ(pattern_match(match, pattern), -1);
  // test04
  strcpy(match,"");
  strcpy(pattern,"str");
  EXPECT_EQ(pattern_match(match, pattern), -1);
  // 領域開放
  free(match);
  free(pattern);
}*/
