#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//============================================================================//
// 演習 2 上の例題を打ち込んで動かし、動作を確認しなさい。
// OK なら、以下のような配列入力プログラムを作りなさい。入力結果を表示すること。
//============================================================================//

//============================================================================//
// a. 最初に個数を指定してその数だけ入力する代わりに、順番に数値を入力して最後に 0 を
// 入れると終わり、入力した個数 (0 は含まない) を返す関数
// int riarrayz(int lim, int a[])。lim は最大個数で、
// それより多く入力してはいけない。動かすと次のようになる。
// 1> 21
// 2> 31
// 3> 0 → 21 と 31 が 0 番目と 1 番目に入り「2」を返す
//============================================================================//



//============================================================================//
// b. 上記と同様だが、上記では「0」が入れられないので、
// 終わりの印になる数をパラメタで渡すint riarrayz2(int lim, int a[], int endval)。
// たとえば-1を渡すと次のように。
// input integer (-1 for end) 1> 41
// input integer (-1 for end) 2> 0
// input integer (-1 for end) 3> -1 → 41 と 0 が入力され「2」を返す
//============================================================================//


//============================================================================//
// c. riarray、riarrayz、riarrayz2 の実数入力版。
//============================================================================//

//============================================================================//
// d. その他自分があったらいいと思う入力関数。
//============================================================================//

//============================================================================//
// e. その他ポインタやアドレスを使った面白いと思う関数。
//============================================================================//