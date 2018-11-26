#define RMAX 1000
#define TRUE 1
#define FALSE 0

// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
  #include "../fp14_target.h"
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

TEST_F(fixtureName, mixcolor)
{
}

TEST_F(fixtureName, showcolor)
{
}

//============================================================================//
// a. 渡された色と白の平均を取って返す関数 struct color brighter(struct color c)。
//============================================================================//
TEST_F(fixtureName, brighter)
{
    struct color c;
    // test01
    c.r = 0;
    c.g = 0;
    c.b = 0;
    struct color d = brighter(c);
    EXPECT_EQ((short)d.r, 127);
    EXPECT_EQ((short)d.g, 127);
    EXPECT_EQ((short)d.b, 127);
    // test01
    c.r = 1;
    c.g = 1;
    c.b = 1;
    d = brighter(c);
    EXPECT_EQ((short)d.r, 128);
    EXPECT_EQ((short)d.g, 128);
    EXPECT_EQ((short)d.b, 128);
}

//============================================================================//
// b. 渡された色と黒の平均を取って返す関数 struct color darker(struct color c)。
//============================================================================//
TEST_F(fixtureName, darker)
{
  struct color c;
  // test01
  c.r = 0;
  c.g = 0;
  c.b = 0;
  struct color d = darker(c);
  EXPECT_EQ((short)d.r, 0);
  EXPECT_EQ((short)d.g, 0);
  EXPECT_EQ((short)d.b, 0);
  // test01
  c.r = 2;
  c.g = 2;
  c.b = 2;
  d = darker(c);
  EXPECT_EQ((short)d.r, 1);
  EXPECT_EQ((short)d.g, 1);
  EXPECT_EQ((short)d.b, 1);
}

//============================================================================//
// c. RGB 値は 0～255 なので、それぞれ「255 からその値を引く」と 0 は 255 に、255 は 0 になる。
// これを利用して、明るい色は暗く、暗い色は明るい色にして返す関数
// struct color reversecolor(struct color c)。
//============================================================================//
TEST_F(fixtureName, reversecolor)
{
  struct color c;
  // test01
  c.r = 0;
  c.g = 128;
  c.b = 255;
  struct color d = reversecolor(c);
  EXPECT_EQ((short)d.r, 255);
  EXPECT_EQ((short)d.g, 127);
  EXPECT_EQ((short)d.b, 0);
}

//============================================================================//
// d. R の値を G に、G の値を B に、B の値を R にコピーすることで、
// もとと明るさが同じくらいだけど色調が違う色ができるはずである。
// これをおこなう関数 struct color rot1color(struct color c)。
//============================================================================//
TEST_F(fixtureName, rot1color)
{
  struct color c;
  // test01
  c.r = 0;
  c.g = 128;
  c.b = 255;
  struct color d = rot1color(c);
  EXPECT_EQ((short)d.r, 255);
  EXPECT_EQ((short)d.g, 0);
  EXPECT_EQ((short)d.b, 128);
  // test02
  c = rot1color(d);
  EXPECT_EQ((short)c.r, 128);
  EXPECT_EQ((short)c.g, 255);
  EXPECT_EQ((short)c.b, 0);
}

//============================================================================//
// ついでに R を B に、G を R に、B を G にコピーする関数
// struct color rot2color(struct color c) も作ってみるとよい。
//============================================================================//
TEST_F(fixtureName, rot2color)
{
  struct color c;
  // test01
  c.r = 0;
  c.g = 128;
  c.b = 255;
  struct color d = rot2color(c);
  EXPECT_EQ((short)d.r, 128);
  EXPECT_EQ((short)d.g, 255);
  EXPECT_EQ((short)d.b, 0);
  // test02
  c = rot2color(d);
  EXPECT_EQ((short)c.r, 255);
  EXPECT_EQ((short)c.g, 0);
  EXPECT_EQ((short)c.b, 128);
}

//============================================================================//
// e. 2 つの色と 0.0～1.0 の値を渡すとその 2 色を指定した比率で混ぜた色を返す関数
// structcolor linearmix(struct color c, struct color d, double ratio)。
// ratio が 0.5のときは平均になるので mixcolor と同じになる。
//============================================================================//
TEST_F(fixtureName, linearmix)
{
  struct color c;
  struct color d;
  struct color e;
  // test01
  c.r = 255;
  c.g = 255;
  c.b = 255;
  d.r = 0;
  d.g = 0;
  d.b = 0;
  e = linearmix(c, d, 0.5);
  EXPECT_EQ((short)e.r, 127);
  EXPECT_EQ((short)e.g, 127);
  EXPECT_EQ((short)e.b, 127);
}

//============================================================================//
// f. パラメタは何も受け取らず、中で擬似乱数でランダムな色を生成し返す関数
// struct color randomcolor(void)(擬似乱数は#12 の付録参照)。
//============================================================================//
TEST_F(fixtureName, randomcolor)
{

}
