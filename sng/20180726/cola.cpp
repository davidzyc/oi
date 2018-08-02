#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 15;

typedef long long ll;

const ll INF = 0x7f7f7f7f7f7f7f7f;

ll gcd(ll a, ll b){
  return b ? gcd(b, a%b) : a;
}

struct Frac {
  ll num, den;
  Frac(){
    this->num = 0;
    this->den = 1;
  }
  Frac(ll num, ll den){
    ll tgcd = gcd(this->num, this->den);
    this->num = num / tgcd;
    this->den = den / tgcd;
  }
  bool operator < (const Frac &a) const {
    ll dengcd = gcd(this->den, a.den);
    ll denlcm = a.den / dengcd * this->den;
    ll thisnum = this->num * (denlcm / this->den);
    ll anum = a.num * (denlcm / a.den);
    return thisnum < anum;
  }
};

void simplify(Frac &f){
  ll tgcd = gcd(f.num, f.den);
  f.num = f.num / tgcd;
  f.den = f.den / tgcd;
}

int n;
ll mp[MAXN][MAXN];
Frac a[MAXN][MAXN];

ll inabs(int x){
  return x > 0 ? x : -x;
}

int main(){
  freopen("cola.in", "r", stdin);
  freopen("cola.out", "w", stdout);
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      scanf("%lld", &mp[i][j]);
    }
  }
  // Frac ff;
  // ff.num = 100;
  // ff.den = 50;
  // simplify(ff);
  // cout << ff.num << "/ " << ff.den << endl;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(i == 1 && j == 1) continue;
      ll h;
      Frac t1, t2;
      int tu1 = 0, tu2 = 0;
      if(j > 1){
        h = inabs(mp[i][j] - mp[i][j-1]);
        t1.num = h*h+8*h+4;
        t1.den = h+1;
        simplify(t1);
        tu1 = 1;
        t1 = max(t1, a[i][j-1]);
      }
      if(i > 1){
        h = inabs(mp[i][j] - mp[i-1][j]);
        t2.num = h*h+8*h+4;
        t2.den = h+1;
        simplify(t2);
        tu2 = 1;
        t2 = max(t2, a[i-1][j]);
      }
      if(tu1 && tu2){
        a[i][j] = min(t1, t2);
      }else if(tu1){
        a[i][j] = t1;
      }else if(tu2){
        a[i][j] = t2;
      }else{
        a[i][j].num = INF;
        a[i][j].den = 1;
      }
      simplify(a[i][j]);
        // cout << i << ", " << j << " : " << a[i][j].num << "/" << a[i][j].den << endl;
    }
  }
  printf("%lld/%lld", a[n][n].num, a[n][n].den);
  // cout << a[n][n].num << "/" << a[n][n].den;

  return 0;
}
