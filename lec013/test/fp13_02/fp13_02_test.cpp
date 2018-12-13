#define RMAX 1000
#define TRUE 1
#define FALSE 0

// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
  #include "../fp13_target.h"
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
TEST_F(fixtureName, myatoi)
{
  char *s = (char *)malloc(10 * sizeof(char));
  // test01
  ASSERT_EQ(myatoi(s),0);
  // test02
  strcpy(s, "1234567890");
  ASSERT_EQ(myatoi(s),1234567890);
  // test03
  strcpy(s, "0xff");
  ASSERT_EQ(myatoi(s),0);
  // test04
  strcpy(s, "1");
  ASSERT_EQ(myatoi(s),1);

}
