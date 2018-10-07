const int TRUE = 1;
const int FALSE = 0;
//const int DENOMINATOR = 10000000;
//-----------------------------------------------------------------------------//
// 演習 4 区間 2 分法によって平方根を求める C プログラムを作成しなさい。
// 必要と思われる精度にしたとき、繰り返し回数がいくつになるか検討しなさい。
//-----------------------------------------------------------------------------//
double calc04(double x, int d){
  double a = 0;
  double b = x;
  double c = 0;
  double f = 0;
  int i = 0;
  while(1){
    c = (a + b)/2;
    f = pow(c, 2.0);
    if(f == x || i == d){
      break;
    }else if(f < x){
      a = c;
    }else{
      b = c;
    }
    i++;
  }
  return c;
}
