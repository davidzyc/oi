#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long ll;

ll mpow(int b, int p){
  ll c = b, ans = 1;;
  for(int i=0; i<(int)log(p)+1; i++){
    if(((p>>i)&1)==1){
      ans *= c;
    }
    c *= c;
  }
  return ans;
}

struct matrix {
  const int MATRIXN = 11;
  int col, row;
  int a[MATRIXN][MATRIXN];
  matrix(){
    memset(a, 0, sizeof(a));
  }
  matrix(int y, int x){
    row = y;
    col = x;
  }
  matrix operator + (const matrix &b) const {
    matrix ans(row, col);
    for(int i=0; i<row; i++){
      for(int j=0; j<col; j++){
        ans.a[i][j] = a[i][j] + b.a[i][j];
      }
    }
    return ans;
  }
  matrix operator * (const matrix &b) const {
    matrix ans(row, b.col);
    for(int i=0; i<row; i++){
      for(int j=0; j<b.col; j++){
        for(int k=0; k<col; k++){
          ans.a[i][j] += a[i][k] + b.a[k][j];
        }
      }
    }
  }
};

int main(){



  return 0;
}
