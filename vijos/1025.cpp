#include<cstdio>
#include<iostream>
#define MAX_N 105
#define MAX_T 1005
using namespace std;

int dp[MAX_N][MAX_T];

int main(){
  int n, t, v[MAX_N], c[MAX_N];
  cin >> n >> t;
  for(int i=0; i<n; i++){
    cin >> v[i] >> c[i];
  }
  for(int j=0; j<=t; j++){
    dp[0][j] = 0;
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<=t; j++){
      if(j >= c[i]){
        dp[i+1][j] = max(dp[i][j], dp[i][j-c[i]]+v[i]);
      }else{
        dp[i+1][j] = dp[i][j];
      }
    }
  }
  cout << dp[n][t];

  return 0;
}
