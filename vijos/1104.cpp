#include<cstdio>
#include<iostream>
#define MAX_M 105
#define MAX_T 1005
using namespace std;

int dp[MAX_M][MAX_T];

int main(){
  int t, m, a[MAX_M], v[MAX_M];
  cin >> t >> m;
  for(int i=0; i<m; i++){
    cin >> a[i] >> v[i];
  }
  for(int j=0; j<=t; j++){
    dp[0][j] = 0;
  }
  for(int i=0; i<m; i++){
    for(int j=0; j<=t; j++){
      if(j >= a[i]){
        dp[i+1][j] = max(dp[i][j], dp[i][j-a[i]]+v[i]);
      }else{
        dp[i+1][j] = dp[i][j];
      }
    }
  }

  cout << dp[m][t];
  return 0;
}
