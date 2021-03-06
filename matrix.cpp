#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int GMOD = 10000;
const int MATN = 11;

struct matrix {
  int col, row;
  int a[MATN][MATN];
  matrix() {
    memset(a, 0, sizeof(a));
  }
  matrix(int r, int c){
    row = r;
    col = c;
    memset(a, 0, sizeof(a));
  }
  matrix operator + (const matrix &m) const {
    matrix tsum(row, col);
    for(int i=0; i<row; i++){
      for(int j=0; j<col; j++){
        tsum.a[i][j] = a[i][j] + m.a[i][j];
        tsum.a[i][j] %= GMOD;
      }
    }
    return tsum;
  }
  matrix operator * (const matrix &m) const  {
    matrix tmul(row, m.col);
    for(int i=0; i<row; i++){
      for(int j=0; j<m.col; j++){
        for(int k=0; k<col; k++){
          tmul.a[i][j] += a[i][k] * m.a[k][j];
          tmul.a[i][j] %= GMOD;
        }
      }
    }
    return tmul;
  }
  matrix operator ^ (const int &mp) const {
    int tmp = mp;
    matrix tmul = *this;
    matrix ansm(row, row);
    for(int i=0; i<row; i++){
      ansm.a[i][i] = 1;
    }
    while(tmp > 0){
      if((tmp&1) == 1){
        ansm = ansm * tmul;
      }
      tmul = tmul * tmul;
      tmp = tmp >> 1;
    }
    return ansm;
  }
};

int main(){
  int nthfib;
  while(~scanf("%d", &nthfib)){
    if(nthfib == -1) return 0;
    matrix um(2, 2);
    matrix fib(2, 2);
    fib.a[0][0] = 0;
    fib.a[0][1] = 1;
    um.a[0][0] = 1;
    um.a[0][1] = 1;
    um.a[1][0] = 1;
    fib = fib * (um ^ nthfib);
    printf("%d\n", fib.a[0][0]);
  }

  return 0;
}
