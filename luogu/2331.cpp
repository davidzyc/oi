#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 107;
const int MAXM = 4;
const int MAXK = 12;

int n, m, gk;
int a[MAXN][MAXM];
int dp[MAXN][MAXK][5];

int main(){
  memset(dp, 0x8f, sizeof(dp));
  // cout << dp[0][0][0];
  scanf("%d%d%d", &n, &m, &gk);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      scanf("%d", &a[i][j]);
    }
  }
  dp[0][0][0] = 0;
  for(int i=1; i<=n; i++){
    for(int k=0; k<=gk; k++){

      for(int h=0; h<5; h++){
        dp[i][k][0] = max(dp[i][k][0], dp[i-1][k][h]);
      }
      dp[i][k][1] = max(dp[i][k][1], dp[i-1][k][1]);
      dp[i][k][1] = max(dp[i][k][1], dp[i-1][k][3]);
      if(k-1 >= 0){
        dp[i][k][1] = max(dp[i][k][1], dp[i-1][k-1][0]);
        dp[i][k][1] = max(dp[i][k][1], dp[i-1][k-1][2]);
        dp[i][k][1] = max(dp[i][k][1], dp[i-1][k-1][4]);
      }
      dp[i][k][2] = max(dp[i][k][2], dp[i-1][k][2]);
      dp[i][k][2] = max(dp[i][k][2], dp[i-1][k][3]);
      if(k-1 >= 0){
        dp[i][k][2] = max(dp[i][k][2], dp[i-1][k-1][0]);
        dp[i][k][2] = max(dp[i][k][2], dp[i-1][k-1][1]);
        dp[i][k][2] = max(dp[i][k][2], dp[i-1][k-1][4]);
      }
      dp[i][k][3] = max(dp[i][k][3], dp[i-1][k][3]);
      if(k-1 >= 0){
        dp[i][k][3] = max(dp[i][k][3], dp[i-1][k-1][1]);
        dp[i][k][3] = max(dp[i][k][3], dp[i-1][k-1][2]);
      }
      if(k-2 >= 0){
        dp[i][k][3] = max(dp[i][k][3], dp[i-1][k-2][0]);
        dp[i][k][3] = max(dp[i][k][3], dp[i-1][k-2][4]);
      }
      if(k-1 >= 0){
        dp[i][k][4] = max(dp[i][k][4], dp[i-1][k-1][0]);
        dp[i][k][4] = max(dp[i][k][4], dp[i-1][k-1][1]);
        dp[i][k][4] = max(dp[i][k][4], dp[i-1][k-1][2]);
        dp[i][k][4] = max(dp[i][k][4], dp[i-1][k-1][3]);
      }
      dp[i][k][4] = max(dp[i][k][4], dp[i-1][k][4]);
      dp[i][k][1] += a[i][2];
      dp[i][k][2] += a[i][1];
      dp[i][k][3] += (a[i][1] + a[i][2]);
      dp[i][k][4] += (a[i][1] + a[i][2]);
    }
  }

  int gans = 0x8f8f8f8f;
  for(int h=0; h<5; h++) gans = max(gans, dp[n][gk][h]);

  printf("%d", gans);

  return 0;
}
