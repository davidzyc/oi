#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 1e7+7;

typedef long long ll;

const ll GMOD = 998244353;

ll dp[MAXN][4] = {0};

int main(){
  freopen("diet.in", "r", stdin);
  freopen("diet.ans", "w", stdout);
  int n;
  scanf("%d", &n);
  for(int i=0; i<4; i++) dp[0][i] = 1;
  for(int i=1; i<n; i++){
    for(int j=0; j<4; j++){
      dp[i][2] += dp[i-1][j];
      dp[i][3] += dp[i-1][j];
      dp[i][2] %= GMOD;
      dp[i][3] %= GMOD;
    }
    for(int j=0; j<4; j++){
      if(j != 0) dp[i][0] += dp[i-1][j];
      if(j != 1) dp[i][1] += dp[i-1][j];
      dp[i][0] %= GMOD;
      dp[i][1] %= GMOD;
    }
  }
  ll ans = 0;
  for(int i=0; i<4; i++){
    ans += dp[n-1][i];
    ans %= GMOD;
  }
  printf("%lld", ans);

  return 0;
}
