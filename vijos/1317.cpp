#include<cstdio>
#include<iostream>
#define MAX_N 30005
#define MAX_M 30
using namespace std;

int dp[MAX_M][MAX_N];

int main(){
  int n, m, v[MAX_M], p[MAX_M];
  cin >> n >> m;
  for(int i=0; i<m; i++){
    cin >> v[i] >> p[i];
  }

  for(int j=0; j<=n; j++){
    dp[0][j] = 0;
  }

  for(int i=0; i<m; i++){
    for(int j=0; j<=n; j++){
      if(j >= v[i]){
        dp[i+1][j] = max(dp[i][j], dp[i][j-v[i]]+v[i]*p[i]);
      }else{
        dp[i+1][j] = dp[i][j];
      }
    }
  }
  cout << dp[m][n];

  return 0;
}
