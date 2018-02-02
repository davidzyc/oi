#include<cstdio>
#include<iostream>
#define MAXN 10005
#define INF 2100000000
using namespace std;

int dp[MAXN][MAXN];

int main(){

  int n, a[MAXN], sum[MAXN];
  cin >> n;
  sum[0] = 0;
  for(int i=1; i<=n; i++){
    cin >> a[i];
    // dp[i][i] = a[i];
    sum[i] = sum[i-1] + a[i];
  }
  for(int len=2; len<=n; len++){
    for(int l=1, r; (r=l+len-1) <= n; l++){
      dp[l][r] = INF;
      for(int k=l; k<r; k++){
        dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]+sum[r]-sum[l-1]);
      }
    }
  }
  cout << dp[1][n];

  return 0;
}
