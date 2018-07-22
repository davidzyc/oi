#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;

ll a, b, n;
ll p[50];
int pn = 0;

ll secprime(ll x){
  ll ans = 0;
  for(int i=1; i<(1<<pn); i++){
    // cout << "HI";
    int cnt = 0;
    ll tmul = 1;
    for(int j=0; j<pn; j++){
      if((i>>j)&1){
        ++cnt;
        tmul *= p[j];
      }
    }
    ans += (ll)(cnt&1 ? 1 : -1) * (x / tmul);
  }
  return x - ans;
}

int main(){
  // freopen("d.in", "r", stdin);
  // freopen("d.out", "w", stdout);
  int tset;
  int cas = 0;
  scanf("%d", &tset);
  while(tset--){
    memset(p, 0, sizeof(p));
    pn = 0;
    scanf("%lld%lld%lld", &a, &b, &n);
    for(ll i=2; i*i<=n; i++){
      if(n % i) continue;
      p[pn++] = i;
      while(!(n % i)) n /= i;
    }
    if(n > 1) p[pn++] = n;

    printf("Case #%d: %lld\n", ++cas, secprime(b) - secprime(a-1));
  }


  return 0;
}
