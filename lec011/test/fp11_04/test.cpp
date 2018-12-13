// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
  #include "target.h"
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
    EXPECT_NEAR(0.9, 1.1, calc04(1.0, 10));
    EXPECT_NEAR(0.9, 1.1, calc04(1.0, 100));
    EXPECT_NEAR(0.9, 1.1, calc04(1.0, 1000));
    EXPECT_NEAR(0.9, 1.1, calc04(1.0, 10000));
}
TEST_F(fixtureName, sqrt02)
{
    EXPECT_NEAR(1.39, 1.42, calc04(2.0, 10));
    EXPECT_NEAR(1.39, 1.42, calc04(2.0, 100));
    EXPECT_NEAR(1.39, 1.42, calc04(2.0, 1000));
    EXPECT_NEAR(1.39, 1.42, calc04(2.0, 10000));
}
// あえて失敗するテストケースも書いておく。
TEST_F(fixtureName, sqrt03)
{
    EXPECT_NEAR(1.72, 1.74, calc04(3.0, 10));
    EXPECT_NEAR(1.72, 1.74, calc04(3.0, 100));
    EXPECT_NEAR(1.72, 1.74, calc04(3.0, 1000));
    EXPECT_NEAR(1.72, 1.74, calc04(3.0, 10000));
}
