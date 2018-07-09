#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

typedef long long ll;

const int MAXN = 1007;
const ll MOD = 10007;

ll a, b;
int k, n, m;
ll ans = 1;
ll c[MAXN][MAXN] = {0};

int main(){
  scanf("%lld%lld%d%d%d", &a, &b, &k, &n, &m);
  for(int i=1; i<=n; i++){
    ans *= a;
    ans %= MOD;
  }
  for(int i=1; i<=m; i++){
    ans *= b;
    ans %= MOD;
  }
  for(int i=1; i<=k; i++){
    c[i][0] = 1;
    c[i][1] = i;
    for(int j=2; j<=i; j++){
      c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
      // cout << i << " " << j << " " << c[i][j] << endl;
    }
  }
  ans = ans * c[k][n];
  ans %= MOD;
  printf("%lld", ans);

  return 0;
}
