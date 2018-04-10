#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MATN = 11;
const int GMOD = 9973;

struct matrix {
  int row, col;
  int a[MATN][MATN];

  matrix(){
    memset(a, 0, sizeof(a));
  }

  matrix(int r, int c){
    row = r;
    col = c;
    memset(a, 0, sizeof(a));
  }

  matrix operator * (const matrix &m) const {
    matrix ansm(row, m.col);
    for(int i=0; i<row; i++){
      for(int j=0; j<m.col; j++){
        for(int k=0; k<col; k++){
          ansm.a[i][j] += (a[i][k] * m.a[k][j]) % GMOD;
          ansm.a[i][j] %= GMOD;
        }
      }
    }
    return ansm;
  }

  matrix operator ^ (const int mpow) const {
    matrix ansm(row, row);
    matrix tmul = *this;
    for(int i=0; i<row; i++){
      ansm.a[i][i] = 1;
    }
    int tpow = mpow;
    while(tpow > 0){
      if((tpow & 1) == 1){
        ansm = ansm * tmul;
      }
      tmul = tmul * tmul;
      tpow = tpow >> 1;
    }
    return ansm;
  }

  void print(){
    for(int i=0; i<row; i++){
      for(int j=0; j<col; j++){
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }
  }
};

int tset;
int n, k;
int outans;

int main(){
  int tin;
  scanf("%d", &tset);
  while(tset--){
    scanf("%d%d", &n, &k);
    matrix gans(n, n);
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        scanf("%d", &tin);
        gans.a[i][j] = tin;
      }
    }
    gans = gans ^ k;
    // gans.print();
    outans = 0;
    for(int i=0; i<n; i++){
      outans += gans.a[i][i];
      outans %= GMOD;
    }
    printf("%d\n", outans);
  }

  return 0;
}
