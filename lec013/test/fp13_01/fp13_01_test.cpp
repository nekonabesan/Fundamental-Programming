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
TEST_F(fixtureName, mystrlen)
{
  // 初期化
  char *s = (char *)malloc(10 * sizeof(char));
  ASSERT_EQ(mystrlen(s),0);
  //
  strcpy(s, "");
  ASSERT_EQ(mystrlen(s),0);
  //
  strcpy(s, "aaa");
  ASSERT_EQ(mystrlen(s),3);
  //
  strcpy(s, "000");
  ASSERT_EQ(mystrlen(s),3);
  //
  strcpy(s, "Google Test");
  ASSERT_EQ(mystrlen(s),11);
  free(s);
}

// void prchartriangletail(chars[]);
TEST_F(fixtureName, prchartriangletail)
{
  char *s = (char *)malloc(19 * sizeof(char));
  strcpy(s,"prchartriangletail");
  EXPECT_STREQ(s, "prchartriangletail");
  prchartriangletail(s);
  EXPECT_STREQ(s, "prchartriangletai");
  prchartriangletail(s);
  EXPECT_STREQ(s, "prchartriangleta");
  prchartriangletail(s);
  EXPECT_STREQ(s, "prchartrianglet");
  prchartriangletail(s);
  EXPECT_STREQ(s, "prchartriangle");
  prchartriangletail(s);
  EXPECT_STREQ(s, "prchartriangl");
  prchartriangletail(s);
  EXPECT_STREQ(s, "prchartriang");
  prchartriangletail(s);
  EXPECT_STREQ(s, "prchartrian");
  prchartriangletail(s);
  char *c1 = (char *)malloc(10 * sizeof(char));
  free(s);
}

// void mapchar(char s[], char c1, char c2);
TEST_F(fixtureName, mapchar)
{
  // 汎用レジスタ領域予約
  char *s = (char *)malloc(12 * sizeof(char));
  // test01
  char c1 = 0x20;// \s
  char c2 = 0x2a;// *
  strcpy(s, "Google Test");
  mapchar(s, c1, c2);
  EXPECT_STREQ(s, "Google*Test");
  // test01
  c1 = 0x47;
  c2 = 0x43;
  mapchar(s, c1, c2);
  EXPECT_STREQ(s, "Coogle*Test");
  // test02
  c1 = 0x6f;
  c2 = 0x30;
  mapchar(s, c1, c2);
  EXPECT_STREQ(s, "C00gle*Test");
  // 領域開放
  free(s);
}

// void deletechar(char s[],char c1);
TEST_F(fixtureName, deletechar)
{
  char *s = (char *)malloc(12 * sizeof(char));
  char c1 = 0x6f;
  strcpy(s, "Google Test");
  //test01
  deletechar(s, c1);
  EXPECT_STREQ(s, "Ggle Test");
  //test2
  c1 = 0x20;
  deletechar(s, c1);
  EXPECT_STREQ(s, "GgleTest");
  // 領域開放
  free(s);
}

// void reverse(char s[]);
TEST_F(fixtureName, reverse)
{
  char *s = (char *)malloc(12 * sizeof(char));
  strcpy(s, "Google Test");
  // test01
  reverse(s);
  EXPECT_STREQ(s, "tseT elgooG");
  free(s);
}

// void mystrcpy(char s1[], char s2[]);
TEST_F(fixtureName, mystrcpy)
{
  char *s1 = (char *)malloc(10 * sizeof(char));
  char *s2 = (char *)malloc(10 * sizeof(char));
  strcpy(s1, "Google Test");
  mystrcpy(s1, s2);
  EXPECT_STREQ(s2, "Google Test");
  free(s1);
  free(s2);
}

// void mystrcat(char s1[], char s2[]);
TEST_F(fixtureName, mystrcat)
{
  char *s1 = (char *)malloc(10 * sizeof(char));
  char *s2 = (char *)malloc(10 * sizeof(char));
  strcpy(s1,"Google Test");
  strcpy(s2, " Google Test");
  mystrcat(s1, s2);
  EXPECT_STREQ(s1, "Google Test Google Test");
  free(s1);
  free(s2);
}

// char mystrcmp(char s1[], char s2[]);
TEST_F(fixtureName, mystrcmp)
{
  char *s1 = (char *)malloc(10 * sizeof(char));
  char *s2 = (char *)malloc(10 * sizeof(char));
  free(s1);
  free(s2);
}


// あえて失敗するテストケースも書いておく。
/*TEST_F(fixtureName, sqrt03)
{

}*/
