#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 205
#define INF 2100000000
using namespace std;

int dp[MAXN][MAXN];
int dpmax[MAXN][MAXN] = {0};

int main(){
  int locmin = INF, locmax = 0;
  int n, a[MAXN], sum[MAXN];
  cin >> n;
  sum[0] = 0;
  for(int i=1; i<=n; i++){
    cin >> a[i];
    // dp[i][i] = a[i];
    sum[i] = sum[i-1] + a[i];
  }
  for(int i=1; i<=n; i++){
    a[i+n] = a[i];
    sum[i+n] = sum[i+n-1] + a[i];
  }
  for(int offset = 0; offset < n; offset++){
    memset(dpmax, 0, sizeof(dpmax));
    memset(dp, 0, sizeof(dp));
    for(int len=2; len<=n; len++){
      for(int l=1, r; (r=l+len-1) <= n; l++){
        dp[l][r] = INF;
        for(int k=l; k<r; k++){
          dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]+sum[r+offset]-sum[l+offset-1]);
          dpmax[l][r] = max(dpmax[l][r], dpmax[l][k]+dpmax[k+1][r]+sum[r+offset]-sum[l+offset-1]);
        }
      }
    }
    locmin = min(locmin, dp[1][n]);
    locmax = max(locmax, dpmax[1][n]);
  }

  cout << locmin << endl << locmax;

  return 0;
}
