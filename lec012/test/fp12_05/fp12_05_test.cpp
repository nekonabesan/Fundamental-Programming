#define RMAX 1000
#define TRUE 1
#define FALSE 0

// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
  #include "fp12_05_target.h"
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
TEST_F(fixtureName, initialize)
{
  //initialize では先のアルゴリズムによって roomprice を順に初期化しています
  int rmax = 11;
  int *c = (int *)malloc(rmax * sizeof(int));
  int *csel = (int *)malloc(rmax * sizeof(int));
  int *null_num = NULL;
  EXPECT_TRUE(initialize(c, csel, rmax));
  EXPECT_FALSE(initialize(null_num, csel, rmax));
  EXPECT_FALSE(initialize(c, null_num, rmax));
  EXPECT_FALSE(initialize(c, csel, 0));
  free(c);
  free(csel);
}
TEST_F(fixtureName, coin1)
{
  int rmax = 27;
  int *c = (int *)malloc(rmax * sizeof(int));
  int *csel = (int *)malloc(rmax * sizeof(int));
  EXPECT_TRUE(initialize(c, csel, rmax));
  ASSERT_EQ(coin(-2, c), 0);
  ASSERT_EQ(coin(-1, c), 0);
  ASSERT_EQ(coin(0, c), 0);
  ASSERT_EQ(coin(1, c), 1);
  ASSERT_EQ(coin(2, c), 2);
  ASSERT_EQ(coin(3, c), 3);
  ASSERT_EQ(coin(4, c), 4);
  ASSERT_EQ(coin(5, c), 1);
  ASSERT_EQ(coin(6, c), 2);
  ASSERT_EQ(coin(7, c), 3);
  ASSERT_EQ(coin(8, c), 4);
  ASSERT_EQ(coin(9, c), 5);
  ASSERT_EQ(coin(10, c), 1);
  ASSERT_EQ(coin(11, c), 2);
  ASSERT_EQ(coin(12, c), 3);
  ASSERT_EQ(coin(20, c), 2);
  ASSERT_EQ(coin(21, c), 3);
  ASSERT_EQ(coin(24, c), 6);
  ASSERT_EQ(coin(25, c), 1);
  ASSERT_EQ(coin(26, c), 2);
  free(c);
  free(csel);
}

TEST_F(fixtureName, coin2)
{
  int rmax = 21;
  int *c = (int *)malloc(rmax * sizeof(int));
  int *csel = (int *)malloc(rmax * sizeof(int));
  EXPECT_TRUE(initialize(c, csel, rmax));
//  ASSERT_EQ(coin(-2, roomprice), 0);
//  ASSERT_EQ(coin(-1, roomprice), 0);
/*  ASSERT_EQ(coin(0, roomprice), 0);
  ASSERT_EQ(coin(1, roomprice), 1);
  ASSERT_EQ(coin(10, roomprice), 1);
  ASSERT_EQ(coin(11, roomprice), 2);
  ASSERT_EQ(coin(12, roomprice), 3);
  ASSERT_EQ(coin(13, roomprice), 4);
  ASSERT_EQ(coin(14, roomprice), 5);
  ASSERT_EQ(coin(15, roomprice), 2);
  ASSERT_EQ(coin(16, roomprice), 3);
  ASSERT_EQ(coin(17, roomprice), 4);
  ASSERT_EQ(coin(18, roomprice), 5);
  ASSERT_EQ(coin(19, roomprice), 6);
  ASSERT_EQ(coin(20, roomprice), 2);*/
  free(c);
  free(csel);
}

// あえて失敗するテストケースも書いておく。
/*TEST_F(fixtureName, sqrt03)
{

}*/
