#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;
const int MATN = 20;
const ll GMOD = 1000000007;
const int MAXN = 105;

int n;
ll k;
ll l[MAXN];
int h[MAXN];

struct matrix {
  int col, row;
  ll a[MATN][MATN];
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
        rtn.a[i][j] = (a[i][j] + m.a[i][j]) % GMOD;
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
          rtn.a[i][j] += (a[i][k] * m.a[k][j]) % GMOD;
          rtn.a[i][j] %= GMOD;
        }
      }
    }
    return rtn;
  }
  matrix operator ^ (const ll &mp) const {
    ll mpt = mp;
    matrix rtn(row, row);
    matrix tmul = *this;
    for(int i=0; i<row; i++){
      rtn.a[i][i] = 1;
    }
    while(mpt > 0){
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
  ll tf, tt;
  scanf("%d%lld", &n, &k);
  for(int i=0; i<n; i++){
    scanf("%lld%lld%d", &tf, &tt, &h[i]);
    tt = min(k, tt);
    l[i] = tt - tf;
  }
  matrix gans(18, 18);
  gans.a[0][0] = 1;
  for(int i=0; i<n; i++){
    matrix tmul(18, 18);
    for(int j=0; j<=h[i]; j++){
      if(j-1 >= 0){
        tmul.a[j][j-1] = 1;
      }
      tmul.a[j][j] = 1;
      if(j+1 <= h[i]){
        tmul.a[j][j+1] = 1;
      }
    }
    gans = gans * (tmul ^ l[i]);
    // printf("%d\n", gans.a[0][0]);
  }
  printf("%d\n", gans.a[0][0]);

  return 0;
}
