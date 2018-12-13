#define RMAX 1000
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



// 成功するテストケース。細かい説明はGoogleTestのマニュアルを見てね。
// char mystrlen(char s[]);
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

TEST_F(fixtureName, mach1)
{
  char *match = (char *)malloc(10 * sizeof(char));
  char *pattern = (char *)malloc(10 * sizeof(char));
  // test01
  strcpy(match,"string");
  strcpy(pattern,"str");
  EXPECT_EQ(mach(match, pattern), 0);
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
  EXPECT_EQ(mach(match, pattern), -1);
  // test02
  strcpy(match,"string");
  strcpy(pattern,"");
  EXPECT_EQ(mach(match, pattern), -1);
  // test03
  match = NULL;
  strcpy(pattern,"str");
  EXPECT_EQ(mach(match, pattern), -1);
  // test04
  strcpy(match,"");
  strcpy(pattern,"str");
  EXPECT_EQ(mach(match, pattern), -1);
  // 領域開放
  free(match);
  free(pattern);
}
