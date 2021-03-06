const int TRUE = 1;
const int FALSE = 0;
//const int DENOMINATOR = 10000000;
//-----------------------------------------------------------------------------//
// 演習 5 ニュートン法によって平方根を求める C プログラムを作成しなさい。
// 必要と思われる精度にしたとき、繰り返し回数がいくつになるか検討しなさい。
// (ヒント: 繰り返しごとに現在の近似値を書き出すのでもよいですね。)
//-----------------------------------------------------------------------------//
double calc05(double n, int d){
  double f = n;
  double dx = 2 * n;
  int cnt = 0;
  while(1){
    if(cnt > d){
      break;
    }
    dx = f;
    f = 0.5 * dx + 0.5 * n / dx;
    cnt++;
  }
  return f;
}
