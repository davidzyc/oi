#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;
const int MATN = 15;
// const ll GMOD = 10000007;
int kth;
int acoe[10];
int GMOD;

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

int main(){
  // freopen("e.txt", "r", stdin);
  while(scanf("%d%d", &kth, &GMOD) == 2){
    matrix matin(10, 10);
    matrix trans(10, 10);
    matrix gans(10, 10);
    for(int i=0; i<10; i++){
      scanf("%d", &acoe[i]);
    }
    if(kth < 10) printf("%d\n", kth);
    for(int i=0; i<10; i++){
      matin.a[0][i] = 9-i;
    }
    for(int i=0; i<10; i++){
      trans.a[i][0] = acoe[i];
    }
    for(int i=0; i<9; i++){
      trans.a[i][i+1] = 1;
    }
    gans = trans ^ (kth-9);
    gans = matin * gans;
    // trans.print();
    printf("%d\n", gans.a[0][0]);
  }
  return 0;
}
