#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

const ll GMOD = 9901;

ll an, bn;
ll gans = 1;


ll exgcd(ll a, ll b, ll &x, ll &y){
  if(b == 0){
    x = 1, y = 0;
    return a;
  }
  ll tgcd = exgcd(b, a%b, x, y);
  ll z = x;
  x = y, y = z - (a/b) * y;
  return tgcd;
}

ll quickpow(ll a, ll b, ll m){
  ll ans = 1, mul = a;
  while(b > 0){
    if(b&1){
      ans *= mul;
      ans %= m;
    }
    mul = mul * mul;
    mul %= m;
    b >>= 1;
  }
  return ans;
}

ll process(ll i, ll p){
  ll tx, ty, ta;
  p = p * bn + 1;
  ta = quickpow(i, p, GMOD);
  ta = (ta - 1 + GMOD) % GMOD;
  if((i-1) % GMOD){
    exgcd(i-1, GMOD, tx, ty);
    tx = ((tx%GMOD)+GMOD)%GMOD;
    // tx = quickpow(i-1, GMOD-2, GMOD);
    ta = (ta * tx) % GMOD;
    // cout << i << " " << ta << endl;
  }else{
    ta = p;
  }
  return ta;
}

int main(){
  freopen("1845.in", "r", stdin);
  freopen("1845.out", "w", stdout);
  while(scanf("%lld%lld", &an, &bn) == 2){

    gans = 1;

    for(ll i=2; i<=(ll)sqrt(an*1.0); i++){
      if(an % i) continue;
      ll p = 0, ta;
      while(an % i == 0) ++p, an /= i;
      ta = process(i, p);
      gans = gans * ta;
      gans %= GMOD;
    }

    if(an > 1){
      ll ta = process(an, 1);
      gans = gans * ta;
      gans %= GMOD;
    }

    printf("%lld\n", gans);

  }

  return 0;
}
