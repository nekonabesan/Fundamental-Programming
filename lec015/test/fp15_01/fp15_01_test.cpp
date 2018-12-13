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
struct gp{
  double x;
  double y;
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
//double rt_x(double x, double y, double xc, double yc, double rd)
TEST_F(fixtureName, rt_x)
{
  // test01
  
}

//double rt_y(double x, double y, double xc, double yc, double rd)
TEST_F(fixtureName, rt_y)
{
}

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

// struct gp calc_gp(double x0, double y0, double x1, double y1, double x2, double y2)
TEST_F(fixtureName, calc_gp)
{
  // test01
  struct gp g = calc_gp(10,10,20,20,30,30);
  EXPECT_EQ(g.x,20);
  EXPECT_EQ(g.y,20);
  // test02
  g = calc_gp(0,30,-10,-15,10,-15);
  EXPECT_EQ(g.x,0);
  EXPECT_EQ(g.y,0);
  // test03
  g = calc_gp(1,4,-1,-2,3,-2);
  EXPECT_EQ(g.x,1);
  EXPECT_EQ(g.y,0);
  // test04
  g = calc_gp(1,2,3,4,5,6);
  EXPECT_EQ(g.x,3);
  EXPECT_EQ(g.y,4);
}
