#define RMAX 1000
#define TRUE 1
#define FALSE 0

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
TEST_F(fixtureName, initialize)
{
  //initialize では先のアルゴリズムによって roomprice を順に初期化しています
  int rmax = 11;
  int *roomprice = (int *)malloc(rmax * sizeof(int));
  int *roomsel = (int *)malloc(rmax * sizeof(int));
  int *null_num = NULL;
  EXPECT_TRUE(initialize(roomprice, roomsel, rmax));
  EXPECT_FALSE(initialize(null_num, roomsel, rmax));
  EXPECT_FALSE(initialize(roomprice, null_num, rmax));
  EXPECT_FALSE(initialize(roomprice, roomsel, 0));
  free(roomprice);
  free(roomsel);
}
TEST_F(fixtureName, room1)
{
  // 値を読み出す時には room1 という下請け関数を呼びます。
  // この関数は、人数 i が負のときは 0 を返し、それ以外はroomprice[i] を返します。
  int rmax = 11;
  int *roomprice = (int *)malloc(rmax * sizeof(int));
  int *roomsel = (int *)malloc(rmax * sizeof(int));
  EXPECT_TRUE(initialize(roomprice, roomsel, rmax));
  ASSERT_EQ(room1(-2, roomprice), 0);
  ASSERT_EQ(room1(-1, roomprice), 0);
  ASSERT_EQ(room1(0, roomprice), 0);
  ASSERT_EQ(room1(1, roomprice), 5000);
  ASSERT_EQ(room1(2, roomprice), 10000);
  ASSERT_EQ(room1(3, roomprice), 12000);
  ASSERT_EQ(room1(4, roomprice), 17000);
  ASSERT_EQ(room1(5, roomprice), 20000);
  ASSERT_EQ(room1(6, roomprice), 20000);
  ASSERT_EQ(room1(7, roomprice), 20000);
  ASSERT_EQ(room1(8, roomprice), 25000);
  ASSERT_EQ(room1(9, roomprice), 30000);
  ASSERT_EQ(room1(10, roomprice), 30000);
  free(roomprice);
  free(roomsel);
}

TEST_F(fixtureName, room2)
{
  int rmax = 21;
  int *roomprice = (int *)malloc(rmax * sizeof(int));
  int *roomsel = (int *)malloc(rmax * sizeof(int));
  EXPECT_TRUE(initialize(roomprice, roomsel, rmax));
  // 1 人部屋:5,000 円、3 人部屋:12,000 円、7 人部屋:20,000 円
  // 動いたら、「13 人部屋 3 万円」
  //「17 人部屋 4 万円」の選択肢を追加して動かしてみなさい。
  ASSERT_EQ(room1(-2, roomprice), 0);
  ASSERT_EQ(room1(-1, roomprice), 0);
  ASSERT_EQ(room1(0, roomprice), 0);
  ASSERT_EQ(room1(1, roomprice), 5000);
  ASSERT_EQ(room1(10, roomprice), 30000);
  ASSERT_EQ(room1(11, roomprice), 30000);
  ASSERT_EQ(room1(12, roomprice), 30000);
  ASSERT_EQ(room1(13, roomprice), 30000);
  ASSERT_EQ(room1(14, roomprice), 35000);
  ASSERT_EQ(room1(15, roomprice), 40000);
  ASSERT_EQ(room1(16, roomprice), 40000);
  ASSERT_EQ(room1(17, roomprice), 40000);
  ASSERT_EQ(room1(18, roomprice), 45000);
  ASSERT_EQ(room1(19, roomprice), 50000);
  ASSERT_EQ(room1(20, roomprice), 50000);
  free(roomprice);
  free(roomsel);
}

// あえて失敗するテストケースも書いておく。
/*TEST_F(fixtureName, sqrt03)
{

}*/
