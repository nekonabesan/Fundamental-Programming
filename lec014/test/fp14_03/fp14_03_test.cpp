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
//============================================================================//
// a. 登録できる値を整数 1 個から変更しなさい (整数 2 個とか文字列とか)。
// @param struct ent2* p
// @param char key
// @param char val
// @return struct ent2* t
//============================================================================//
TEST_F(fixtureName, add_struct)
{
  struct ent2 *p1 = NULL;
  struct ent2 *p2 = NULL;
  struct ent2 *p3 = NULL;
  char *k1 = (char *)malloc(10 * sizeof(char));
  char *k2 = (char *)malloc(10 * sizeof(char));
  char *k3 = (char *)malloc(10 * sizeof(char));
  char *v1 = (char *)malloc(10 * sizeof(char));
  char *v2 = (char *)malloc(10 * sizeof(char));
  char *v3 = (char *)malloc(10 * sizeof(char));
  // test01
  strcpy(k1, "key1");
  strcpy(k2, "key2");
  strcpy(k3, "key3");
  strcpy(v1, "val1");
  strcpy(v2, "val2");
  strcpy(v3, "val3");
  p1 = initialize(k1, v1);
  p2 = add_struct(p1, k2, v2);
  p3 = add_struct(p2, k3, v3);
  EXPECT_STREQ(p1->key, "key1");
  EXPECT_STREQ(p1->val, "val1");
  EXPECT_STREQ(p2->key, "key2");
  EXPECT_STREQ(p2->val, "val2");
  EXPECT_STREQ(p3->key, "key3");
  EXPECT_STREQ(p3->val, "val3");
  EXPECT_EQ((unsigned long)p1->prev, (unsigned long)NULL);
  EXPECT_EQ((unsigned long)p1->next, (unsigned long)p2);
  EXPECT_EQ((unsigned long)p2->prev, (unsigned long)p1);
  EXPECT_EQ((unsigned long)p2->next, (unsigned long)p3);
  EXPECT_EQ((unsigned long)p3->prev, (unsigned long)p2);
  EXPECT_EQ((unsigned long)p3->next, (unsigned long)NULL);
  // 領域開放
  free(k1);
  free(k2);
  free(k3);
  free(v1);
  free(v2);
  free(v3);
}

//============================================================================//
// b. 今は表は追加と書き換えしかできないが、削除機能をつけてみなさい。
// @param struct ent2 *p
// @return bool
//============================================================================//
TEST_F(fixtureName, del_struct01)
{
  struct ent2 *p1 = NULL;
  struct ent2 *p2 = NULL;
  struct ent2 *p3 = NULL;
  struct ent2 *pos = NULL;
  char *k1 = (char *)malloc(10 * sizeof(char));
  char *k2 = (char *)malloc(10 * sizeof(char));
  char *k3 = (char *)malloc(10 * sizeof(char));
  char *v1 = (char *)malloc(10 * sizeof(char));
  char *v2 = (char *)malloc(10 * sizeof(char));
  char *v3 = (char *)malloc(10 * sizeof(char));
  // test01
  strcpy(k1, "key1");
  strcpy(k2, "key2");
  strcpy(k3, "key3");
  strcpy(v1, "val1");
  strcpy(v2, "val2");
  strcpy(v3, "val3");
  p1 = initialize(k1, v1);
  p2 = add_struct(p1, k2, v2);
  p3 = add_struct(p2, k3, v3);
  // test01
  EXPECT_TRUE(del_struct(p3));
  EXPECT_STREQ(p1->key, "key1");
  EXPECT_STREQ(p1->val, "val1");
  EXPECT_STREQ(p2->key, "key2");
  EXPECT_STREQ(p2->val, "val2");

  EXPECT_EQ((unsigned long)p1->prev, (unsigned long)NULL);
  EXPECT_EQ((unsigned long)p1->next, (unsigned long)p2);
  EXPECT_EQ((unsigned long)p2->prev, (unsigned long)p1);
  EXPECT_EQ((unsigned long)p2->next, (unsigned long)NULL);
  // test02
  EXPECT_TRUE(del_struct(p2));
  EXPECT_STREQ(p1->key, "key1");
  EXPECT_STREQ(p1->val, "val1");
  EXPECT_EQ((unsigned long)p1->prev, (unsigned long)NULL);
  EXPECT_EQ((unsigned long)p1->next, (unsigned long)NULL);
  // test03
  EXPECT_TRUE(del_struct(p1));
  EXPECT_STRNE(p1->key, "key1");
  EXPECT_STRNE(p1->val, "val1");
  // 領域開放
}

//============================================================================//
// c. 表の中身を全部まとめて表示する機能をつけてみなさい。
// (ヒント: この機能そのものは tbllinear1.c の中に置くのが自然で、main からそれを呼び出す。
// どういう場合にこの機能が呼ばれることにするかは好きに決めてかまいません。)
// @param struct ent2 *p
// @return struct ent2 *p
//============================================================================//
TEST_F(fixtureName, show_structs)
{
}

//============================================================================//
// d. そのほか、面白いと思う機能をつけてみなさい。
// 構造体を初期化する処理
// @param char *key
// @param char *val
// @return char *ent2
//============================================================================//
TEST_F(fixtureName, initialize)
{
  struct ent2 *p1 = NULL;
  char *k1 = (char *)malloc(10 * sizeof(char));
  char *v1 = (char *)malloc(10 * sizeof(char));
  // test01
  strcpy(k1, "key1");
  strcpy(v1, "val1");
  p1 = initialize(k1, v1);
  EXPECT_STREQ(p1->key, "key1");
  EXPECT_STREQ(p1->val, "val1");
  EXPECT_EQ((unsigned long)p1->prev, (unsigned long)NULL);
  EXPECT_EQ((unsigned long)p1->next, (unsigned long)NULL);
  // 領域開放
  free(k1);
  free(v1);
}

//============================================================================//
// 先頭のアドレスを返す処理
// @param struct ent2 *pos
// @return struct ent2 *start
//============================================================================//
TEST_F(fixtureName, head_address)
{
  struct ent2 *p1 = NULL;
  struct ent2 *p2 = NULL;
  struct ent2 *p3 = NULL;
  struct ent2 *pos = NULL;
  char *k1 = (char *)malloc(10 * sizeof(char));
  char *k2 = (char *)malloc(10 * sizeof(char));
  char *k3 = (char *)malloc(10 * sizeof(char));
  char *v1 = (char *)malloc(10 * sizeof(char));
  char *v2 = (char *)malloc(10 * sizeof(char));
  char *v3 = (char *)malloc(10 * sizeof(char));
  // test01
  strcpy(k1, "key1");
  strcpy(k2, "key2");
  strcpy(k3, "key3");
  strcpy(v1, "val1");
  strcpy(v2, "val2");
  strcpy(v3, "val3");
  p1 = initialize(k1, v1);
  p2 = add_struct(p1, k2, v2);
  p3 = add_struct(p2, k3, v3);
  pos = head_address(p3);
  EXPECT_STREQ(pos->key, "key1");
  EXPECT_STREQ(pos->val, "val1");
  EXPECT_EQ((unsigned long)p1->prev, (unsigned long)NULL);
  EXPECT_EQ((unsigned long)p1->next, (unsigned long)p2);
  // 領域開放
  free(k1);
  free(k2);
  free(k3);
  free(v1);
  free(v2);
  free(v3);
}
