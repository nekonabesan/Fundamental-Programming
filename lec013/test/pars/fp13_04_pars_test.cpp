#define MAX 10000
#define TRUE 1
#define FALSE 0

// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
  //#include "../../modules/fp13_04_header.c"
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


// 成功するテストケース。細かい説明はGoogleTestのマニュアルを見てね。
//====================================================//
// 構文解釈の処理
// @param struct analysis *apars
// @param char *pattern
// @return bool
//====================================================//
TEST_F(fixtureName, pars01)
{
  struct analysis *apars = (struct analysis*)malloc(sizeof(struct analysis) * 2);
  char pattern[100];
  // test01
  strcpy(pattern, "string");
  EXPECT_TRUE(pars(apars, pattern));
  EXPECT_EQ(apars[0].c, 0x73);
  EXPECT_EQ(apars[0].seq, 0x00);
  EXPECT_EQ(apars[1].c, 0x74);
  EXPECT_EQ(apars[1].seq, 0x00);
  EXPECT_EQ(apars[2].c, 0x72);
  EXPECT_EQ(apars[2].seq, 0x00);
  EXPECT_EQ(apars[3].c, 0x69);
  EXPECT_EQ(apars[3].seq, 0x00);
  EXPECT_EQ(apars[4].c, 0x6e);
  EXPECT_EQ(apars[4].seq, 0x00);
  EXPECT_EQ(apars[5].c, 0x67);
  EXPECT_EQ(apars[5].seq, 0x00);
  // 領域開放
  free(apars);
}
// 制御文字あり
TEST_F(fixtureName, pars02)
{
  struct analysis *apars = (struct analysis*)malloc(sizeof(struct analysis) * 2);
  char pattern[100];
  // test02
  strcpy(pattern, "a+b?cde*fg");
  EXPECT_TRUE(pars(apars, pattern));
  EXPECT_EQ(apars[0].c, 0x61);
  EXPECT_EQ(apars[0].seq, 0x2b);
  EXPECT_EQ(apars[1].c, 0x62);
  EXPECT_EQ(apars[1].seq, 0x3f);
  EXPECT_EQ(apars[2].c, 0x63);
  EXPECT_EQ(apars[2].seq, 0x00);
  EXPECT_EQ(apars[3].c, 0x64);
  EXPECT_EQ(apars[3].seq, 0x00);
  EXPECT_EQ(apars[4].c, 0x65);
  EXPECT_EQ(apars[4].seq, 0x2a);
  EXPECT_EQ(apars[5].c, 0x66);
  EXPECT_EQ(apars[5].seq, 0x00);
  EXPECT_EQ(apars[6].c, 0x67);
  EXPECT_EQ(apars[6].seq, 0x00);
  // 領域開放
  free(apars);
}
// ESCAPE_SEQENCE
TEST_F(fixtureName, pars03)
{
  struct analysis *apars = (struct analysis*)malloc(sizeof(struct analysis) * 2);
  char pattern[100];
  // test03
  strcpy(pattern, "a\\+b\\?cde\\*fg");
  EXPECT_TRUE(pars(apars, pattern));
  EXPECT_EQ(apars[0].c, 0x61);
  EXPECT_EQ(apars[0].seq, 0x00);
  EXPECT_EQ(apars[1].c, 0x2b);
  EXPECT_EQ(apars[1].seq, 0x00);
  EXPECT_EQ(apars[2].c, 0x62);
  EXPECT_EQ(apars[2].seq, 0x00);
  EXPECT_EQ(apars[3].c, 0x3f);
  EXPECT_EQ(apars[3].seq, 0x00);
  EXPECT_EQ(apars[4].c, 0x63);
  EXPECT_EQ(apars[4].seq, 0x00);
  EXPECT_EQ(apars[5].c, 0x64);
  EXPECT_EQ(apars[5].seq, 0x00);
  EXPECT_EQ(apars[6].c, 0x65);
  EXPECT_EQ(apars[6].seq, 0x00);
  EXPECT_EQ(apars[7].c, 0x2a);
  EXPECT_EQ(apars[7].seq, 0x00);
  EXPECT_EQ(apars[8].c, 0x66);
  EXPECT_EQ(apars[8].seq, 0x00);
  EXPECT_EQ(apars[9].c, 0x67);
  EXPECT_EQ(apars[9].seq, 0x00);
  // 領域開放
  free(apars);
}
