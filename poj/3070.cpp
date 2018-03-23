#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MATN = 11;
const int GMOD = 10000;

struct matrix {
  int col, row;
  int a[MATN][MATN];
  matrix(){
    memset(a, 0, sizeof(a));
  }
  matrix(int r, int c){
    memset(a, 0, sizeof(a));
    row = r;
    col = c;
  }
  matrix operator + (const matrix &m) const {
    matrix rtn(row, col);
    for(int i=0; i<row; i++){
      for(int j=0; j<col; j++){
        rtn.a[i][j] = a[i][j] + m.a[i][j];
        rtn.a[i][j] %= GMOD;
      }
    }
    return rtn;
  }
  matrix operator * (const matrix &m) const {
    matrix rtn(row, m.col);
    for(int i=0; i<row; i++){
      for(int j=0; j<m.col; j++){
        for(int k=0; k<col; k++){
          rtn.a[i][j] += a[i][k] * m.a[k][j];
          rtn.a[i][j] %= GMOD;
        }
      }
    }
    return rtn;
  }
  matrix operator ^ (const int &mp) const {
    int mpt = mp;
    matrix rtn(row, row);
    matrix tmul = *this;
    for(int i=0; i<row; i++){
      rtn.a[i][i] = 1;
    }
    while(mpt){
      if((mpt & 1) == 1){
        rtn = rtn * tmul;
      }
      tmul = tmul * tmul;
      mpt = mpt >> 1;
    }
    return rtn;
  }
};

int main(){
  int ton;
  while(true){
    scanf("%d", &ton);
    if(ton == -1) return 0;
    matrix um(2, 2);
    um.a[0][0] = um.a[0][1] = um.a[1][0] = 1;
    matrix fibm(2, 2);
    fibm.a[0][0] = 0;
    fibm.a[0][1] = 1;
    matrix ansm(2, 2);
    ansm = fibm * (um ^ ton);
    printf("%d\n", ansm.a[0][0]);
  }

  return 0;
}
