#define RMAX 1000
#define TRUE 1
#define FALSE 0

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
// char mystrlen(char s[]);
TEST_F(fixtureName, tbl_get)
{
    char *k1 = (char *)malloc(10 * sizeof(char));
    char *k2 = (char *)malloc(10 * sizeof(char));
    int result = 0;
    // test01
    strcpy(k1, "key1");
    strcpy(k2, "key2");
    EXPECT_TRUE(tbl_put(k1, 1));
    EXPECT_TRUE(tbl_put(k2, 2));
    result = tbl_get(k1);
    EXPECT_EQ(result, 1);
    EXPECT_EQ(tbl[0].val, 1);
    result = tbl_get(k2);
    EXPECT_EQ(result, 2);
    EXPECT_EQ(tbl[1].val, 2);
    // 領域開放
    free(k1);
    free(k2);
}

TEST_F(fixtureName, tbl_put)
{
  char *k1 = (char *)malloc(10 * sizeof(char));
  char *k2 = (char *)malloc(10 * sizeof(char));
  // test01
  strcpy(k1, "key1");
  strcpy(k2, "key2");
  EXPECT_TRUE(tbl_put(k1, 1));
  EXPECT_TRUE(tbl_put(k2, 2));
  // 領域開放
  free(k1);
  free(k2);
}

//============================================================================//
// a. 登録できる値を整数 1 個から変更しなさい (整数 2 個とか文字列とか)。
//============================================================================//
TEST_F(fixtureName, add_struct)
{
  char *k1 = (char *)malloc(10 * sizeof(char));
  char *k2 = (char *)malloc(10 * sizeof(char));
  char *v1 = (char *)malloc(10 * sizeof(char));
  char *v2 = (char *)malloc(10 * sizeof(char));
  // test01
  set_tableszize2(0);
  strcpy(k1, "key1");
  strcpy(k2, "key2");
  strcpy(v1, "value1");
  strcpy(v2, "value2");
  EXPECT_TRUE(add_struct(k1, v1));
  EXPECT_TRUE(add_struct(k2, v2));
  EXPECT_STREQ(tbl2[0].key, "key1");
  EXPECT_STREQ(tbl2[0].val, "value1");
  EXPECT_STREQ(tbl2[1].key, "key2");
  EXPECT_STREQ(tbl2[1].val, "value2");
  // 領域開放
  free(k1);
  free(k2);
  free(v1);
  free(v2);
}

TEST_F(fixtureName, del_struct)
{
  char *k1 = (char *)malloc(10 * sizeof(char));
  char *k2 = (char *)malloc(10 * sizeof(char));
  char *k3 = (char *)malloc(10 * sizeof(char));
  char *v1 = (char *)malloc(10 * sizeof(char));
  char *v2 = (char *)malloc(10 * sizeof(char));
  char *v3 = (char *)malloc(10 * sizeof(char));
  // test01
  set_tableszize2(0);
  strcpy(k1, "key1");
  strcpy(k2, "key2");
  strcpy(k3, "key3");
  strcpy(v1, "value1");
  strcpy(v2, "value2");
  strcpy(v3, "value3");
  EXPECT_TRUE(add_struct(k1, v1));
  EXPECT_TRUE(add_struct(k2, v2));
  EXPECT_TRUE(add_struct(k3, v3));
  EXPECT_TRUE(del_struct(k2));
  EXPECT_STREQ(tbl2[0].key, "key1");
  EXPECT_STREQ(tbl2[0].val, "value1");
  EXPECT_STREQ(tbl2[1].key, "key3");
  EXPECT_STREQ(tbl2[1].val, "value3");
  EXPECT_STREQ(tbl2[2].key, NULL);
  EXPECT_STREQ(tbl2[2].val, NULL);
  // 領域開放
  free(k1);
  free(k2);
  free(k3);
  free(v1);
  free(v2);
  free(v3);
}

TEST_F(fixtureName, show_structs)
{
}
