#define RMAX 1000
#define TRUE 1
#define FALSE 0
#define MAXTBL 9973

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
// static unsigned int hash(char *s);
TEST_F(fixtureName, hash)
{
}

// static struct ent *lookup(struct ent *p, char *k);
TEST_F(fixtureName, lookup)
{
}

// int get1(struct ent *p, char *k);
TEST_F(fixtureName, get1)
{
}

// static bool put1(struct ent **p, char *k, int v);
TEST_F(fixtureName, put1)
{
}

// int tbl_get(char *k);
TEST_F(fixtureName, tbl_get)
{
}

// bool tbl_put(char *k, int v);
TEST_F(fixtureName, tbl_put)
{
}
