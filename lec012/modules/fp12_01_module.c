#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const int TRUE = 1;
const int FALSE = 0;

//============================================================================//
// 演習 1 上の例題を打ち込んで実行せよ ( 一部を出力するところも追加して動かしてみること ) 。
// うまく動いたら、次のような関数を追加してみよ。
//============================================================================//
void sort2(double a, double b, double *p, double *q){
   if(a < b){
     *p = a;
     *q = b;
   }else{
     *p = b;
     *q = a;
   }
}

void piarray(int n, int a[]){
  for(int i = 0; i < n; i++){
    printf(" %2d", a[i]);
    if(i % 10 == 9 || i == n - 1){
      printf("\n");
    }
  }
}



//============================================================================//
// a. 整数配列を「後ろから順に」打ち出す関数 void piarrayrev(int n, int a[])。
//============================================================================//
void piarrayrev(int n, int a[]){
  for(int i = n; n > 0; i--){
    printf("%d", a[i]);
  }
}

//============================================================================//
// b. 整数配列と整数値を渡し、指定した整数値が配列の何番に入っているかを返す (入ってい
// なければ-1 を返す) 関数 int iindex(int n, int a[], int x)。
//============================================================================//
int iindex(int n, int a[], int x){
  unsigned int result = -1;
  for(int i = 0; n > i; i++){
    if(a[i] == x){
      result = i;
    }
  }
  return result;
}
//============================================================================//
// c. 整数配列の最大値を返す関数 int maxiarray(int n, int a[])。
//============================================================================//
int maxiarray(int n, int a[]){
  int max = a[0];
  for(int i = 0; n > i; i++){
    if(a[i] > max){
      max = a[i];
    }
  }
  return max;
}

//============================================================================//
// d. 整数配列の最小値を返す関数 int miniarray(int n, int a[])。
//============================================================================//
int miniarray(int n, int a[]){
  unsigned int min = a[0];
  for(int i = 0; n > i; i++){
    if(min > a[i]){
      min = a[i];
    }
  }
  return min;
}

//============================================================================//
// e. 整数配列の合計値を返す関数 int sumiarray(int n, int a[])。
//============================================================================//
int sumiarray(int n, int a[]){
  unsigned int result = 0;
  for(int i = 0; n > i; i++){
    result += a[i];
  }
  return result;
}

//============================================================================//
// f. 整数配列の平均値を返す関数 double avgiarray(int n, int a[])。
//============================================================================//
double avgiarray(int n, int a[]){
  unsigned int result = 0;
  for(int i = 0; n > i; i++){
    result += a[i];
  }
  return result / n;
}

//============================================================================//
// g. 実数配列の打ち出し/後ろから順に打ち出し/最大値/最小値/ 合計値/平均値を返す関数。
//============================================================================//
void g01(int n, double a[]){
  for(int i = 0; n > i; i++){
    printf("%s ", a[i]);
  }
}

void g02(int n, double a[]){
  for(int i = n; i > n; i--){
    printf("%s ", a[i]);
  }
}

double g03(int n, double a[]){
  double max = a[0];
  for(int i = 0; n > i; i++){
    if(a[i] > max){
      max = a[i];
    }
  }
  return max;
}

double g04(int n, double a[]){
  double min = a[0];
  for(int i = 0; n > i; i++){
    if(min > a[i]){
      min = a[i];
    }
  }
  return min;
}

double g05(int n, double a[]){
  double result = 0;
  for(int i = 0; n > i; i++){
    result += a[i];
  }
  return result;
}


double g06(int n, double a[]){
  double result = 0;
  for(int i = 0; n > i; i++){
    result += a[i];
  }
  return result / n;
}

//============================================================================//
// h. 好きな方法で整数配列を整列する関数。テスト用に乱数が必要なら付録を参照のこと。
//============================================================================//
int* h(int n, int a[]){
  int index = 0;
  int tmp = 0;
  for(int i = 0; n > i; i ++){
    for(int j = n - 1; j > i; j--){
        tmp = 0;
        if(a[j - 1] > a[j]){
          tmp = a[j];
          a[j] = a[j - 1];
          a[j - 1] = tmp;
        }
    }
  }
  return a;
}

//============================================================================//
// i. その他配列を受け取り好きな処理をする関数。
//============================================================================//
