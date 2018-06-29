#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

typedef long long ll;

const ll MAXINT = 2100000000;

ll an, bn;
ll ggcd, xa, ya;

ll exgcd(ll a, ll b, ll &x, ll &y){
  if(b == 0){
    x = 1, y = 0;
    return a;
  }
  ll ret = exgcd(b, a%b, x, y);
  ll z = x;
  x = y, y = z - y * (a/b);
  return ret;
}

int main(){

  scanf("%lld %lld", &an, &bn);
  ggcd = exgcd(an, bn, xa, ya);
  printf("%lld", (xa + (MAXINT*bn))%bn);
  // printf("%lld %lld %lld", xa, ya, ggcd);

  return 0;
}
