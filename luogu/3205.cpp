#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 1007;
const int MOD = 19650827;

int n;
int h[MAXN];
int dp[MAXN][MAXN][2];

int main(){

  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &h[i]);
    dp[i][i][0] = dp[i][i][1] = 1;
  }
  for(int l=1; l<n; l++){
    if(h[l+1] > h[l]) dp[l][l+1][1] = 1;
    if(h[l] < h[l+1]) dp[l][l+1][0] = 1;
  }
  for(int len=2; len<n; len++){
    for(int l=1, r; (r=l+len)<=n; l++){
      if(h[r] > h[r-1]) dp[l][r][1] += dp[l][r-1][1];
      if(h[r] > h[l]) dp[l][r][1] += dp[l][r-1][0];
      if(h[l] < h[r]) dp[l][r][0] += dp[l+1][r][1];
      if(h[l] < h[l+1]) dp[l][r][0] += dp[l+1][r][0];
      dp[l][r][0] %= MOD;
      dp[l][r][1] %= MOD;
    }
  }
  // for(int i=1; i<=n; i++){
  //   for(int j=i; j<=n; j++){
  //     cout << i << " " << j << " L " << dp[i][j][0] << " R " << dp[i][j][1] << endl;
  //   }
  // }
  printf("%d", ((dp[1][n][0] + dp[1][n][1]))%MOD);

  return 0;
}
