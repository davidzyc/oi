#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 17
using namespace std;

int hx[9] = {2, 2, 1, 1, -1, -1, -2, -2, 0}, hy[9] = {1, -1, 2, -2, 2, -2, 1, -1, 0};
int matrix[MAXN][MAXN], dp[MAXN][MAXN];

int main(){
  int n, m, cx, cy;
  cin >> n >> m >> cx >> cy;
  cx++;
  cy++;
  n++;
  m++;
  memset(matrix, 0, sizeof(matrix));
  memset(dp, 0, sizeof(dp));
  for(int i=0; i<9; i++){
    if(cx + hx[i] >= 0 && cx + hx[i] <= n && cy + hy[i] >= 0 && cy + hy[i] <= m){
      matrix[cx + hx[i]][cy + hy[i]] = 1;
    }
  }
  dp[1][1] = 1;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(matrix[i][j] == 0){
        if(matrix[i-1][j] == 0){
          dp[i][j] += dp[i-1][j];
        }
        if(matrix[i][j-1] == 0){
          dp[i][j] += dp[i][j-1];
        }
      }
    }
  }

  cout << dp[n][m];

  //   for(int i=1; i<=n; i++){
  //     for(int j=1; j<=m; j++){
  //       cout << matrix[i][j] << " ";
  //     }
  //     cout << endl;
  //   }
  //   cout << endl;
  //
  // for(int i=1; i<=n; i++){
  //   for(int j=1; j<=m; j++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  return 0;
}
