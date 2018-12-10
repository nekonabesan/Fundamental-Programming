// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
  #include "fp11_05_target.h"
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
TEST_F(fixtureName, sqrt01)
{
  // 近似値
  EXPECT_NEAR(0.99, 1.0, calc05(1.0, 1));
  EXPECT_NEAR(0.99, 1.0, calc05(1.0, 2));
  EXPECT_NEAR(0.99, 1.0, calc05(1.0, 3));
  EXPECT_NEAR(0.99, 1.0, calc05(1.0, 4));
  EXPECT_NEAR(0.99, 1.0, calc05(1.0, 5));
  EXPECT_NEAR(0.99, 1.0, calc05(1.0, 10));
  EXPECT_NEAR(0.99, 1.0, calc05(1.0, 100));
  EXPECT_NEAR(0.99, 1.0, calc05(1.0, 1000));
  EXPECT_NEAR(0.99, 1.0, calc05(1.0, 10000));
  // EQ
  EXPECT_EQ(calc05(1.0, 1),1.0);
}
TEST_F(fixtureName, sqrt02)
{
  EXPECT_NEAR(1.414, 1.415, calc05(2.0, 1));
  EXPECT_NEAR(1.414, 1.415, calc05(2.0, 2));
  EXPECT_NEAR(1.414, 1.415, calc05(2.0, 3));
  EXPECT_NEAR(1.414, 1.415, calc05(2.0, 4));
  EXPECT_NEAR(1.414, 1.415, calc05(2.0, 5));
  EXPECT_NEAR(1.414, 1.415, calc05(2.0, 10));
  EXPECT_NEAR(1.414, 1.415, calc05(2.0, 100));
  EXPECT_NEAR(1.414, 1.415, calc05(2.0, 1000));
  EXPECT_NEAR(1.414, 1.415, calc05(2.0, 10000));
}
TEST_F(fixtureName, sqrt03)
{
  EXPECT_NEAR(1.72, 1.74, calc05(3.0, 10));
  EXPECT_NEAR(1.72, 1.74, calc05(3.0, 100));
  EXPECT_NEAR(1.72, 1.74, calc05(3.0, 1000));
  EXPECT_NEAR(1.72, 1.74, calc05(3.0, 10000));
}
TEST_F(fixtureName, sqrt25)
{
  // EQ
  EXPECT_EQ(calc05(25.0, 1),5.0);
}
TEST_F(fixtureName, sqrt36)
{
  // EQ
  EXPECT_EQ(calc05(36.0, 1),36.0);
}
// あえて失敗するテストケースも書いておく。
