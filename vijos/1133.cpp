#include<cstdio>
#include<iostream>

using namespace std;

int dp[35][20005];

int main(){
  int v, n, a[35], vis[35] = {0}, outcnt = 0, incnt = 0;
  cin >> v >> n;
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  for(int j=0; j<=v; j++){
    dp[0][j] = 0;
  }
  for(int i=1; i<=n; i++){
    for(int j=0; j<=v; j++){
      if(j>=a[i-1]){
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i-1]]+a[i-1]);
      }else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  cout << v - dp[n][v];
  return 0;
}
