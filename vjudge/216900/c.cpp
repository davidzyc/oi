#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;
const int MATN = 15;
const ll GMOD = 10000007;

struct matrix {
  int row, col;
  ll a[MATN][MATN];

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
  // freopen("c.txt", "r", stdin);
  int n, m;
  ll tin;
  while(scanf("%d%d", &n, &m) == 2){
    matrix matin(n+2, n+2);
    matrix trans(n+2, n+2);
    matrix gans(n+2, n+2);
    matin.a[0][0] = 23;
    for(int i=1; i<=n; i++){
      scanf("%lld", &tin);
      matin.a[0][i] = tin;
    }
    matin.a[0][n+1] = 3;
    for(int i=0; i<=n+1; i++){
      trans.a[0][i] = 10;
      trans.a[n+1][i] = 1;
    }
    trans.a[0][n+1] = 0;
    for(int i=1; i<=n; i++){
      for(int j=i; j<=n; j++){
        trans.a[i][j] = 1;
      }
    }
    // trans.print();
    gans = trans ^ m;
    gans = matin * gans;

    printf("%lld\n", gans.a[0][n]);
  }

  return 0;
}
