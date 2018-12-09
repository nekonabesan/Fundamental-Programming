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
  EXPECT_TRUE(img_clear());
}

// bool img_write(void);
TEST_F(fixtureName, img_write)
{
}

// bool img_putpixel(struct color c, int x, int y);
TEST_F(fixtureName, img_putpixel)
{
}

// bool img_fillcircle(struct color c, double x, double y, double r);
TEST_F(fixtureName, img_fillcircle)
{
}
