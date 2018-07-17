#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 3007;

int n, m;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];

int read(){
  char c;
  int ret = 0;
  for(c = getchar(); c < '0' || c > '9'; c = getchar());
  for(; c >= '0' && c <= '9'; c = getchar()) ret = ret*10 + c - '0';
  return ret;
}

int main(){
  freopen("compress.in", "r", stdin);
  freopen("compress.out", "w", stdout);
  memset(dp, 0x3f, sizeof(dp));
  // scanf("%d%d", &n, &m);
  n = read();
  m = read();
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      // scanf("%d", &a[i][j]);
      a[i][j] = read();
    }
  }
  for(int j=0; j<m; j++){
    dp[0][j] = a[0][j];
  }
  for(int i=1; i<n; i++){
    for(int j=0; j<m; j++){
      dp[i][j] = min(min(dp[i-1][(j-1+m)%m], dp[i-1][(j+1+m)%m]), dp[i-1][j]);
      dp[i][j] += a[i][j];
    }
  }
  int ans = 2147483647;
  for(int j=0; j<m; j++){
    ans = min(ans, dp[n-1][j]);
  }
  printf("%d", ans);

  return 0;
}
