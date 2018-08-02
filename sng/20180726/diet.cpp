#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;

const int MAXG = 10;
const ll GMOD = 998244353;

struct Mat {

  int r, c;
  ll a[MAXG][MAXG];

  Mat (int r, int c){
    this->r = r;
    this->c = c;
    memset(a, 0, sizeof(a));
  }

  Mat operator * (const Mat &mb) const {
    Mat ret(this->r, mb.c);
    for(int i=1; i<=r; i++){
      for(int j=1; j<=c; j++){
        ret.a[i][j] = 0;
        for(int k=1; k<=c; k++){
          ret.a[i][j] += (this->a[i][k] * mb.a[k][j]) % GMOD;
          ret.a[i][j] %= GMOD;
        }
      }
    }
    return ret;
  }

};

ll n;
Mat a(1, 4);
Mat mul(4, 4);
Mat gmul(4, 4);

int main(){
  freopen("diet.in", "r", stdin);
  freopen("diet.out", "w", stdout);


  scanf("%d", &n);
  --n;
  for(int i=1; i<=4; i++) a.a[1][i] = 1;
  for(int i=1; i<=2; i++){
    for(int j=1; j<=4; j++){
      if(i == j) continue;
      mul.a[i][j] = 1;
    }
  }
  for(int i=3; i<=4; i++){
    for(int j=1; j<=4; j++){
      mul.a[i][j] = 1;
    }
  }
  for(int i=1; i<=4; i++) gmul.a[i][i] = 1;

  while(n > 0){
    if(n&1){
      gmul = gmul * mul;
    }
    mul = mul*mul;
    n >>= 1;
  }
  a = a * gmul;
  ll ans = 0;
  for(int i=1; i<=4; i++){
    ans += a.a[1][i];
    ans %= GMOD;
  }
  // for(int i=1; i<=4; i++){
  //   for(int j=1; j<=4; j++){
  //     cout << mul.a[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  printf("%lld", ans);

  // cout << a.r << " " << a.c ;

  return 0;
}
