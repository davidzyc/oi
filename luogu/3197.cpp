#include<cstdio>
#include<iostream>

using namespace std;

typedef long long ll;

const ll GMOD = 100003;

ll n, m;
ll tot = 1, subtr = 1;

int main(){

  scanf("%lld%lld", &m, &n);
  ll t = n, tm = m;
  while(t){
    if(t&1){
      tot *= tm;
      tot %= GMOD;
    }
    tm *= tm;
    tm %= GMOD;
    t >>= 1;
  }
  t = n - 1, tm = m - 1;
  while(t){
    if(t&1){
      subtr *= tm;
      subtr %= GMOD;
    }
    tm *= tm;
    tm %= GMOD;
    t >>= 1;
  }
  subtr *= m;
  subtr %= GMOD;
  printf("%lld", (tot - subtr + GMOD) % GMOD);

  return 0;
}
