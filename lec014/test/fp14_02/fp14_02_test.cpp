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
TEST_F(fixtureName, makedarker)
{
  struct color *p = (struct color *)malloc(1 * sizeof(struct color));
  p->r = 255;
  p->g = 255;
  p->b = 255;
  makedarker(p);
  EXPECT_EQ((short)p->r, 127);
  EXPECT_EQ((short)p->g, 127);
  EXPECT_EQ((short)p->b, 127);
  //
  free(p);
}

//============================================================================//
// a. 色を明るく変化させる関数 void makebrighter(struct color *p)。
//============================================================================//
TEST_F(fixtureName, makebrighter)
{
  struct color *p = (struct color *)malloc(1 * sizeof(struct color));
  // test01
  p->r = 0;
  p->g = 0;
  p->b = 0;
  makebrighter(p);
  EXPECT_EQ((short)p->r, 10);
  EXPECT_EQ((short)p->g, 10);
  EXPECT_EQ((short)p->b, 10);
  // test02
  makebrighter(p);
  EXPECT_EQ((short)p->r, 20);
  EXPECT_EQ((short)p->g, 20);
  EXPECT_EQ((short)p->b, 20);
  // test03
  p->r = 255;
  p->g = 255;
  p->b = 255;
  makebrighter(p);
  EXPECT_EQ((short)p->r, 255);
  EXPECT_EQ((short)p->g, 255);
  EXPECT_EQ((short)p->b, 255);
  // 領域開放
  free(p);
}

//============================================================================//
// b. 先の演習のreversecolorと同じ変化を施す関数void makereverse(struct color *p)。
//============================================================================//
TEST_F(fixtureName, makereverse)
{
}

//============================================================================//
// c. 先の演習のrot1color、rot2color と同様の変化をおこなう関数
// void makerot1(structcolor *p)、void makerot2(struct color *p)。
//============================================================================//
TEST_F(fixtureName, makerot2)
{
}

//============================================================================//
// d. RGB 値の増分 (マイナスでもよい) を受け取り、その分だけそれぞれの成分を増やす関数
// void addtocolor(struct color *p, int dr, int dg, int db)。
//============================================================================//
TEST_F(fixtureName, addtocolor)
{
}

//============================================================================//
// e. RGB 値それぞれに-10～10 の範囲のランダムな値を足すことで元とちょっとだけ違う色に
// する関数 void varcolor(struct color *p)。
//============================================================================//
TEST_F(fixtureName, varcolor)
{
}

//============================================================================//
// f. その他色の構造体のアドレスを受け取り、好きな変化を施す関数。
//============================================================================//
