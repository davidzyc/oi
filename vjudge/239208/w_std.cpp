#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;

const ll GMOD = 9901;

ll a, b;
int pcnt = 0, pn[100] = {0};
ll p[100];

ll exgcd(ll a, ll b, ll &x, ll &y){
  if(b == 0){
    x = 1, y = 0;
    return a;
  }
  int ret = exgcd(b, a%b, x, y);
  ll t = x;
  x = y, y = t - (a/b) * y;
  return ret;
}

ll qpow(int x, int y, int m){
  ll tmul = x, ret = 1;
  for(;y;y>>=1, tmul*=tmul){
    if(y&1){
      ret *= tmul;
      ret %= m;
    }
  }
  return ret;
}

int main(){
  freopen("w.in", "r", stdin);
  freopen("w.ans", "w", stdout);

  scanf("%lld%lld", &a, &b);
  for(ll i=2; i*i<=a; i++){
    if(a % i) continue;
    p[pcnt] = i;
    while(a % i == 0){
      ++pn[pcnt];
      a /= i;
    }
    ++pcnt;
  }
  if(a > 1){
    p[pcnt] = a;
    pn[pcnt] = 1;
    ++pcnt;
  }
  ll gans = 1, tans, x, y, t;
  for(int i=0; i<pcnt; i++){
    tans = 1, t = 1;
    for(ll j=1; j<=pn[i]*b; j++){
      t *= p[i];
      t %= GMOD;
      tans += t;
      tans %= GMOD;
    }
    gans *= tans;
    gans %= GMOD;
    // cout << p[i] << " " << pn[i] << endl;
  }

  printf("%lld", gans);

  return 0;
}
