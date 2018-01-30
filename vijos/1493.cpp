#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXSTEP 105
#define MAXN 55
using namespace std;

int matrix[MAXN][MAXN], dp[MAXSTEP][MAXN][MAXN];

int main(){
  memset(matrix, 0, sizeof(matrix));
  memset(dp, 0, sizeof(dp));
  int n, m;
  cin >> m >> n;
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      cin >> matrix[i][j];
    }
  }
  for(int steps = 2; steps <= n+m; steps++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(steps - i >= 1 && steps - i <= m && steps - j >= 1 && steps - j <= m){
          dp[steps][i][j] = max(dp[steps][i][j], dp[steps-1][i][j]);
          dp[steps][i][j] = max(dp[steps][i][j], dp[steps-1][i-1][j]);
          dp[steps][i][j] = max(dp[steps][i][j], dp[steps-1][i][j-1]);
          dp[steps][i][j] = max(dp[steps][i][j], dp[steps-1][i-1][j-1]);
          if(i == j){
            dp[steps][i][j] += matrix[steps - i][i];
          }else{
            dp[steps][i][j] += matrix[steps - i][i] + matrix[steps - j][j];
          }
        }
      }
    }
  }

  cout << dp[n+m][n][n];

  return 0;
}
