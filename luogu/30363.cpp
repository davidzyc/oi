#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 1007;

int n, m, k;
int a[MAXN][MAXN];
int h[MAXN][MAXN];
int dp[MAXN][MAXN];

int read(){
  char c = getchar();
  int ret = 0;
  for(; c < '0' || c > '9'; c = getchar());
  for(; c >= '0' && c <= '9'; c = getchar()) ret = ret * 10 + c - '0';
  return ret;
}

int main(){
  memset(a, 0, sizeof(a));
  memset(h, 0, sizeof(a));
  memset(dp, 0, sizeof(dp));
  n = read();
  m = read();
  k = read();
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      a[i][j] = read();
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(a[i][j] >= a[i-1][j] && a[i][j] >= a[i][j-1] && a[i][j] >= a[i+1][j] && a[i][j] >= a[i][j+1]){
        h[i][j] = 1;
      }
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(h[i][j]){
        dp[i][j] = i;
      }else{
        dp[i][j] = max(dp[i-1][j], max(dp[i-1][j-1], dp[i-1][j+1]));
      }
    }
  }
  int ti, tj;
  for(int i=1; i<=k; i++){
    ti = read();
    tj = read();
    if(!dp[ti][tj]){
      printf("Pool Babingbaboom!\n");
    }else{
      printf("%d\n", ti - dp[ti][tj]);
    }
  }

  return 0;
}
