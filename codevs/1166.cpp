#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXM 31
using namespace std;

long long dp[MAXM][MAXM];

int main(){
  int n;
  long long m, mpow = 1, tmpow;
  long long ans = 0;
  long long a[MAXM];
  cin >> n >> m;
  for(int i=0; i<m; i++){
    mpow *= 2;
  }
  for(int stage = 0; stage < n; stage++){
    memset(dp, 0, sizeof(dp));
    tmpow = mpow;
    for(int i=1; i<=m; i++){
      cin >> a[i];
      dp[i][i] = tmpow * a[i];
    }
    for(int len=1; len<m; len++){
      tmpow /= 2;
      for(int l=1, r; (r=l+len)<=m; l++){
        dp[l][r] = max(dp[l][r], dp[l+1][r]+a[l]*tmpow);
        dp[l][r] = max(dp[l][r], dp[l][r-1]+a[r]*tmpow);
      }
    }
    ans += dp[1][m];
    // cout << dp[1][m] << " ";
  }
  cout << ans;

  return 0;
}
