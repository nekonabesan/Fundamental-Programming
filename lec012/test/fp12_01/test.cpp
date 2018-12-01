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
  int *roomprice = (int *)malloc(rmax * sizeof(int));
  int *roomsel = (int *)malloc(rmax * sizeof(int));
}

//============================================================================//
// a. 整数配列を「後ろから順に」打ち出す関数 void piarrayrev(int n, int a[])。
//============================================================================//
TEST_F(fixtureName, room1)
{
  // 値を読み出す時には room1 という下請け関数を呼びます。
  // この関数は、人数 i が負のときは 0 を返し、それ以外はroomprice[i] を返します。
}

//============================================================================//
// b. 整数配列と整数値を渡し、指定した整数値が配列の何番に入っているかを返す (入ってい
// なければ-1 を返す) 関数 int iindex(int n, int a[], int x)。
//============================================================================//
TEST_F(fixtureName, room2)
{
}

TEST_F(fixtureName, room2)
{
}

TEST_F(fixtureName, room2)
{
}

TEST_F(fixtureName, room2)
{
}


TEST_F(fixtureName, room2)
{
}



// あえて失敗するテストケースも書いておく。
/*TEST_F(fixtureName, sqrt03)
{

}*/
