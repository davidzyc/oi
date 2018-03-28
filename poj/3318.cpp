#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

const int GMOD = 0x7f7f7f7f;
const int MATN = 505;

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
        // tsum.a[i][j] %= GMOD;
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
          // tmul.a[i][j] %= GMOD;
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
  bool operator == (const matrix &mp) const {
    for(int i=0; i<row; i++){
      for(int j=0; j<col; j++){
        if(a[i][j] != mp.a[i][j]){
          return false;
        }
      }
    }
    return true;
  }
};

matrix ma(501, 501);
matrix mb(501, 501);
matrix mc(501, 501);
matrix mr(501, 1);
matrix mtl(501, 1);
matrix mtr(501, 1);

int main(){
  int ncol;
  int t;
  scanf("%d", &ncol);
  for(int i=0; i<ncol; i++){
    for(int j=0; j<ncol; j++){
      scanf("%d", &t);
      ma.a[i][j] = t;
    }
  }
  for(int i=0; i<ncol; i++){
    for(int j=0; j<ncol; j++){
      scanf("%d", &t);
      mb.a[i][j] = t;
    }
  }
  for(int i=0; i<ncol; i++){
    for(int j=0; j<ncol; j++){
      scanf("%d", &t);
      mc.a[i][j] = t;
    }
  }
  srand(87368265);
  for(int i=0; i<ncol; i++){
    mr.a[i][0] = rand() % GMOD;
  }
  mtl = mb*mr;
  mtl = ma*mtl;
  mtr = mc*mr;
  if(mtl == mtr){
    printf("YES");
  }else{
    printf("NO");
  }

  return 0;
}
