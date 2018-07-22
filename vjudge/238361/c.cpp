#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXM = 11;

ll n;
int m;
ll a[MAXM];

ll gcd(ll a, ll b){
  return !b ? a : gcd(b, a%b);
}

int main(){
  // freopen("c.in", "r", stdin);
  // freopen("c.out", "w", stdout);

  while(scanf("%lld%d", &n, &m) == 2){
    memset(a, 0, sizeof(a));
    for(int i=0; i<m; i++){
      scanf("%lld", &a[i]);
      if(a[i] == 0){
        --i, --m;
      }
    }
    --n;
    ll ans = 0;
    // cout << "HI";
    for(int i=1; i<(1<<m); i++){
      int cnt = 0;
      ll tlcm = 1;
      for(int j=0; j<m; j++){
        if((i >> j)&1){
          ++cnt;
          tlcm = (tlcm * a[j]) / gcd(a[j], tlcm);
        }
      }
      // cout << tlcm << " " << (cnt&1 ? 1 : -1) * (n / tlcm) << endl;
      ans += (cnt&1 ? 1 : -1) * (n / tlcm);
    }

    printf("%lld\n", ans);

  }

  return 0;
}
