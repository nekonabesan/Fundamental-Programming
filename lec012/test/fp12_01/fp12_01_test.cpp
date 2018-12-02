#define RMAX 1000
#define TRUE 1
#define FALSE 0

// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
  #include "fp12_01_target.h"
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
  //int *roomprice = (int *)malloc(rmax * sizeof(int));
  //int *roomsel = (int *)malloc(rmax * sizeof(int));
}

//============================================================================//
// a. 整数配列を「後ろから順に」打ち出す関数 void piarrayrev(int n, int a[])。
//============================================================================//
TEST_F(fixtureName, sort2)
{
  // 値を読み出す時には room1 という下請け関数を呼びます。
  // この関数は、人数 i が負のときは 0 を返し、それ以外はroomprice[i] を返します。
}

//============================================================================//
// b. 整数配列と整数値を渡し、指定した整数値が配列の何番に入っているかを返す (入ってい
// なければ-1 を返す) 関数 int iindex(int n, int a[], int x)。
//============================================================================//
TEST_F(fixtureName, iindex)
{
  int a[] = {0,1,2,3,4,5,6,7,8,9};
  int n = sizeof(a) / sizeof(int);
  ASSERT_EQ(iindex(n,a,0),0);
  ASSERT_EQ(iindex(n,a,1),1);
  ASSERT_EQ(iindex(n,a,2),2);
  ASSERT_EQ(iindex(n,a,3),3);
  ASSERT_EQ(iindex(n,a,9),9);
  ASSERT_EQ(iindex(n,a,10),-1);
}

//============================================================================//
// c. 整数配列の最大値を返す関数 int maxiarray(int n, int a[])。
//============================================================================//
TEST_F(fixtureName, maxiarray)
{
  //test01
  int a1[] = {0,1,2,3,4,5,6,7,8,9};
  int n = sizeof(a1) / sizeof(int);
  ASSERT_EQ(maxiarray(n,a1),9);
  // test02
  int a2[] = {9,8,7,6,5,4,3,2,1,0};
  n = sizeof(a2) / sizeof(int);
  ASSERT_EQ(maxiarray(n,a2),9);
  // test02
  int a3[] = {-99,-1,0,5,100,999,-10,1};
  n = sizeof(a3) / sizeof(int);
  ASSERT_EQ(maxiarray(n,a3),999);
}

//============================================================================//
// d. 整数配列の最小値を返す関数 int miniarray(int n, int a[])。
//============================================================================//
TEST_F(fixtureName, miniarray)
{
  //test01
  int a1[] = {0,1,2,3,4,5,6,7,8,9};
  int n = sizeof(a1) / sizeof(int);
  ASSERT_EQ(miniarray(n,a1),0);
  // test02
  int a2[] = {9,8,7,6,5,4,3,2,1,0};
  n = sizeof(a2) / sizeof(int);
  ASSERT_EQ(miniarray(n,a2),0);
  // test02
  int a3[] = {-99,-1,0,5,100,999,-10,1};
  n = sizeof(a3) / sizeof(int);
  ASSERT_EQ(miniarray(n,a3),-99);
}

//============================================================================//
// e. 整数配列の合計値を返す関数 int sumiarray(int n, int a[])。
//============================================================================//
TEST_F(fixtureName, sumiarray)
{
  //test01
  int a1[] = {0,1,2,3,4,5,6,7,8,9};
  int n = sizeof(a1) / sizeof(int);
  ASSERT_EQ(sumiarray(n,a1),45);
  // test02
  int a2[] = {9,8,7,6,5,4,3,2,1,0};
  n = sizeof(a2) / sizeof(int);
  ASSERT_EQ(sumiarray(n,a2),45);
  // test02
  int a3[] = {-100,-10,-1,0,1,10,200};
  n = sizeof(a3) / sizeof(int);
  ASSERT_EQ(sumiarray(n,a3),100);
}

//============================================================================//
// f. 整数配列の平均値を返す関数 double avgiarray(int n, int a[])。
//============================================================================//
TEST_F(fixtureName, avgiarray)
{
  //test01
  int a1[] = {0,1,2,3,4,5,6,7,8,9};
  int n = sizeof(a1) / sizeof(int);
  ASSERT_EQ(avgiarray(n,a1),4.5);
  // test02
  int a2[] = {9,8,7,6,5,4,3,2,1,0};
  n = sizeof(a2) / sizeof(int);
  ASSERT_EQ(avgiarray(n,a2),4.5);
  // test02
  int a3[] = {-100,-10,-1,0,1,10,200};
  n = sizeof(a3) / sizeof(int);
  EXPECT_NEAR(avgiarray(n,a3),14.3,0.1);
}

//============================================================================//
// g. 実数配列の打ち出し/後ろから順に打ち出し/最大値/最小値/ 合計値/平均値を返す関数。
//============================================================================//
TEST_F(fixtureName, g01)
{
}

TEST_F(fixtureName, g02)
{
}

TEST_F(fixtureName, g03)
{
  // test01
  double a1[] = {0.0,1.0,2.0,3.0,4.0,5.0};
  double n = sizeof(a1)/sizeof(double);
  EXPECT_EQ(g03(n,a1),5.0);
  // test01
  double a2[] = {5.0,4.0,2.0,1,0,0.0};
  n = sizeof(a2)/sizeof(double);
  EXPECT_EQ(g03(n,a2),5.0);
  // test01
  double a3[] = {10000.1,0.0,1.0,-200.0,5.0,1.0};
  n = sizeof(a3)/sizeof(double);
  EXPECT_EQ(g03(n,a3),10000.1);
}

TEST_F(fixtureName, g04)
{
  // test01
  double a1[] = {0.0,1.0,2.0,3.0,4.0,5.0};
  double n = sizeof(a1)/sizeof(double);
  EXPECT_EQ(g04(n,a1),0.0);
  // test01
  double a2[] = {5.0,4.0,2.0,1,0,0.0};
  n = sizeof(a2)/sizeof(double);
  EXPECT_EQ(g04(n,a2),0.0);
  // test01
  double a3[] = {10000.1,0.0,1.0,-200.0,5.0,1.0};
  n = sizeof(a3)/sizeof(double);
  EXPECT_EQ(g04(n,a3),-200.0);
}

TEST_F(fixtureName, g05)
{
  // test01
  double a1[] = {0.0,1.0,2.0,3.0,4.0,5.0};
  double n = sizeof(a1)/sizeof(double);
  EXPECT_EQ(g05(n,a1),15.0);
  // test01
  double a2[] = {5.0,4.0,3.0,2.0,1,0,0.0};
  n = sizeof(a2)/sizeof(double);
  EXPECT_EQ(g05(n,a2),15.0);
  // test01
  double a3[] = {-5.5, -4.0, -3.3, -2.2, -1.1, 0.0, 1.1, 2.2, 3.3, 4.0, 5.5};
  n = sizeof(a3)/sizeof(double);
  EXPECT_EQ(g05(n,a3),0.0);
}

TEST_F(fixtureName, g06)
{
  //test01
  double a1[] = {0,1,2,3,4,5,6,7,8,9};
  int n = sizeof(a1) / sizeof(double);
  ASSERT_EQ(g06(n,a1),4.5);
  // test02
  double a2[] = {9,8,7,6,5,4,3,2,1,0};
  n = sizeof(a2) / sizeof(double);
  ASSERT_EQ(g06(n,a2),4.5);
  // test02
  double a3[] = {-100,-10,-1,0,1,10,200};
  n = sizeof(a3) / sizeof(double);
  EXPECT_NEAR(g06(n,a3),14.3,0.1);
}
// あえて失敗するテストケースも書いておく。
/*TEST_F(fixtureName, sqrt03)
{

}*/
