#define RMAX 1000
#define TRUE 1
#define FALSE 0
#define MAXTBL 9973
#define WIDTH 300
#define HEIGHT 200

struct color {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
  #include "../fp15_target.h"
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
// bool img_clear(void);
TEST_F(fixtureName, img_clear)
{
  // test01
  EXPECT_TRUE(img_clear());
}

// bool img_write(void);
TEST_F(fixtureName, img_write)
{
  // test01
  EXPECT_TRUE(img_write());
}

// bool img_putpixel(struct color c, int x, int y);
TEST_F(fixtureName, img_putpixel)
{
  // tets01 x境界値
  struct color c;
  c.r = 0;
  c.g = 127;
  c.b = 255;
  EXPECT_FALSE(img_putpixel(c,-1,1));
  EXPECT_TRUE(img_putpixel(c,0,1));
  EXPECT_TRUE(img_putpixel(c,1,1));
  EXPECT_TRUE(img_putpixel(c,299,1));
  EXPECT_FALSE(img_putpixel(c,300,1));
  // tets02 y境界値
  EXPECT_FALSE(img_putpixel(c,1,-1));
  EXPECT_TRUE(img_putpixel(c,1,0));
  EXPECT_TRUE(img_putpixel(c,1,1));
  EXPECT_TRUE(img_putpixel(c,1,199));
  EXPECT_FALSE(img_putpixel(c,1,200));
}

// bool img_fillcircle(struct color c, double x, double y, double r);
TEST_F(fixtureName, img_fillcircle)
{
  struct color c;
  c.r = 0;
  c.g = 127;
  c.b = 255;
  // test01
  EXPECT_TRUE(img_fillcircle(c,299,1,1));
  EXPECT_FALSE(img_fillcircle(c,300,1,1));
  // test02
  EXPECT_TRUE(img_fillcircle(c,1,199,1));
  EXPECT_FALSE(img_fillcircle(c,1,200,1));
  // test02
  EXPECT_FALSE(img_fillcircle(c,1,1,0));
  EXPECT_TRUE(img_fillcircle(c,1,1,1));
}

// bool img_triangle(struct color c, double x1, double y1, double x2, double y2, double x3, double y3)
TEST_F(fixtureName, img_triangle)
{
  struct color c;
  c.r = 0;
  c.g = 127;
  c.b = 255;
  // test01
  EXPECT_TRUE(img_triangle(c,299,1,1,1,1,1));
  EXPECT_FALSE(img_triangle(c,300,1,1,1,1,1));
}
