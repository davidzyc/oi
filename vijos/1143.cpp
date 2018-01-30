#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 25
#define MAXSTEP 45
using namespace std;

int matrix[MAXN][MAXN], dp[MAXSTEP][MAXN][MAXN][MAXN], tot = 0;

int main(){

  int n;
  cin >> n;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cin >> matrix[i][j];
    }
  }
  memset(dp, 0, sizeof(dp));
  for(int steps = 2; steps <= n*2; steps++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        for(int k=1; k<=n; k++){
          dp[steps][i][j][k] = max(dp[steps][i][j][k], dp[steps-1][i-1][j-1][k-1]);
          dp[steps][i][j][k] = max(dp[steps][i][j][k], dp[steps-1][i-1][j][k]);
          dp[steps][i][j][k] = max(dp[steps][i][j][k], dp[steps-1][i][j-1][k]);
          dp[steps][i][j][k] = max(dp[steps][i][j][k], dp[steps-1][i][j][k-1]);
          dp[steps][i][j][k] = max(dp[steps][i][j][k], dp[steps-1][i-1][j-1][k]);
          dp[steps][i][j][k] = max(dp[steps][i][j][k], dp[steps-1][i][j-1][k-1]);
          dp[steps][i][j][k] = max(dp[steps][i][j][k], dp[steps-1][i-1][j][k-1]);
          dp[steps][i][j][k] = max(dp[steps][i][j][k], dp[steps-1][i][j][k]);
          if(steps-i >= 1 && i == j && j == k){
            dp[steps][i][j][k] += matrix[steps-i][i];
          }else if(steps-i >= 1 && steps-k >= 1 && i == j){
            dp[steps][i][j][k] += matrix[steps-i][i] + matrix[steps-k][k];
          }else if(steps-i >= 1 && steps-k >= 1 && k == j){
            dp[steps][i][j][k] += matrix[steps-i][i] + matrix[steps-k][k];
          }else if(steps-i >= 1 && steps-j >= 1 && i == k){
            dp[steps][i][j][k] += matrix[steps-i][i] + matrix[steps-j][j];
          }else if(steps-i >= 1 && steps-j >= 1 && steps-k >= 1) {
            dp[steps][i][j][k] += matrix[steps-i][i] + matrix[steps-j][j] + matrix[steps-k][k];
          }
        }
      }
    }
  }
  cout << dp[n*2][n][n][n];

  return 0;
}
