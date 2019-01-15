#include <malloc.h>
#define RMAX 1000
#define TRUE 1
#define FALSE 0
#define MAXTBL 9973
#define WIDTH 300
#define HEIGHT 200

struct color {
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned int x;
  unsigned int y;
  struct color *prev;
  struct color *next;
};
struct gp{
  double x;
  double y;
};
// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
  #include "../fp15_target.h"
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
//--------------------------------------------------------------//
// 色データを上書きする処理
// @param unsigned char r
// @param unsigned char g
// @param unsigned char b
// @return struct coler *t
//--------------------------------------------------------------//
TEST_F(fixtureName, writecolor)
{
  // test01
  struct color *t = (struct color*)malloc(sizeof(struct color) * 1);
  // test01
  t = writecolor(t, 255, 255, 255);
  EXPECT_EQ(t->r, 255);
  EXPECT_EQ(t->g, 255);
  EXPECT_EQ(t->b, 255);
  // test02
  t = writecolor(t, 0, 0, 0);
  EXPECT_EQ(t->r, 0);
  EXPECT_EQ(t->g, 0);
  EXPECT_EQ(t->b, 0);
  // 領域開放
  free(t);
}

//--------------------------------------------------------------//
// 構造体を初期化する処理
// @return struct color *t
//--------------------------------------------------------------//
TEST_F(fixtureName, initialize)
{
  struct color *t = (struct color*)malloc(sizeof(struct color) * 1);
  // test01
  t = initialize(t);
  EXPECT_EQ(t->r, 255);
  EXPECT_EQ(t->g, 255);
  EXPECT_EQ(t->b, 255);
  EXPECT_EQ(t->x, 0);
  EXPECT_EQ(t->y, 0);
  EXPECT_EQ((unsigned long)t->prev, 0);
  EXPECT_EQ((unsigned long)t->next, 0);
  // 領域開放
  free(t);
}

//--------------------------------------------------------------//
// リストを初期化する処理
// int cnt
// return struct collor t
//--------------------------------------------------------------//
TEST_F(fixtureName, imgclear)
{
  struct color *start = imgclear();
  struct color *pos = NULL;
  // test01
  EXPECT_EQ(start->r, 255);
  EXPECT_EQ(start->g, 255);
  EXPECT_EQ(start->b, 255);
  //test02
  pos = eol_color(start);
  EXPECT_EQ(pos->r, 255);
  EXPECT_EQ(pos->g, 255);
  EXPECT_EQ(pos->b, 255);
  // 領域開放
  del_color_array(start);
  //free(pos);
}

//--------------------------------------------------------------//
// 先頭のアドレスを返す処理
// @param struct ent2 *pos
// @return struct ent2 *start
//--------------------------------------------------------------//
TEST_F(fixtureName, head_color)
{
  struct color *pos = NULL;
  struct color *start = imgclear();
  // test01
  pos = head_color(start);
  EXPECT_EQ((unsigned long)start, (unsigned long)pos);
  ASSERT_NE((unsigned long)start, 0);
  ASSERT_NE((unsigned long)pos, 0);
  // test02
  pos = eol_color(start);
  pos = head_color(pos);
  EXPECT_EQ((unsigned long)start, (unsigned long)pos);
  ASSERT_NE((unsigned long)start, 0);
  ASSERT_NE((unsigned long)pos, 0);
  // 領域開放
  del_color_array(start);
  //free(start);
}

//--------------------------------------------------------------//
// 構造体へ色情報を書き込む処理
// @param struct color *p
// @param int x
// @param int y
// @param unsigned char r
// @param unsigned char g
// @param unsigned char b
// @return struct color *p
//--------------------------------------------------------------//
TEST_F(fixtureName, imgputpixel)
{
  struct color *pos = NULL;
  struct color *start = imgclear();
  unsigned char r = 127;
  unsigned char g = 127;
  unsigned char b = 127;
  //test01
  pos = imgputpixel(start, 0, 0, r, g, b);
  EXPECT_EQ(start->r, 127);
  EXPECT_EQ(start->g, 127);
  EXPECT_EQ(start->b, 127);
  EXPECT_EQ(start->x, 0);
  EXPECT_EQ(start->y, 0);
  EXPECT_EQ(pos->r, 255);
  EXPECT_EQ(pos->g, 255);
  EXPECT_EQ(pos->b, 255);
  EXPECT_EQ((unsigned long)start, (unsigned long)pos->prev);
  EXPECT_EQ((unsigned long)start->next, (unsigned long)pos);
  // test02
  pos = imgputpixel(pos, 0, 1, r, g, b);
  EXPECT_EQ(pos->prev->r, 127);
  EXPECT_EQ(pos->prev->g, 127);
  EXPECT_EQ(pos->prev->b, 127);
  EXPECT_EQ(pos->prev->x, 0);
  EXPECT_EQ(pos->prev->y, 1);
  EXPECT_EQ(pos->r, 255);
  EXPECT_EQ(pos->g, 255);
  EXPECT_EQ(pos->b, 255);
  // 領域開放
  del_color_array(start);
}

//--------------------------------------------------------------//
// fwriteへ渡す配列を初期化する処理
// @return unsigned char *buf
//--------------------------------------------------------------//
TEST_F(fixtureName, create_buf)
{
  unsigned char *buf = create_buf();
  EXPECT_EQ(malloc_usable_size(buf), 180008);
  free(buf);
}

//--------------------------------------------------------------//
// リストに格納されたデータを画像ファイルへ書き出す処理
// @param struct color *p
// return bool
//--------------------------------------------------------------//
TEST_F(fixtureName, imgwrite)
{
  struct color *start = imgclear();
  /*unsigned char r = 127;
  unsigned char g = 127;
  unsigned char b = 127;*/
  EXPECT_TRUE(imgwrite(start, 0));
  // 領域開放
  del_color_array(start);
}
