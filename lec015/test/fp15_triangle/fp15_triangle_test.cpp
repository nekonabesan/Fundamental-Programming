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
// img_triangle(struct color c, double x0, double y0, double x1, double y1, double x2, double y2)
TEST_F(fixtureName, img_triangle)
{
  struct color c;
  c.r = 0;
  c.g = 127;
  c.b = 255;
  EXPECT_TRUE(img_triangle(c,1,1,1,1,1,1));
}

// bool rt_triangle(struct color c, double x0, double y0, double x1, double y1, double x2, double y2);
TEST_F(fixtureName, img_rtriangle)
{
  struct color c;
  c.r = 0;
  c.g = 127;
  c.b = 255;
  // test01
  EXPECT_TRUE(rt_triangle(c,1,1,1,1,1,1));
}
