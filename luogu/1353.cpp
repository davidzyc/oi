#include<cstdio>
#include<iostream>
using namespace std;

const int MAXT = 10001;
const int MAXC = 501;

int n, m;
int t[MAXT];
int dp[MAXT][MAXC][2] = {0};

int main(){
  cin >> n >> m;
  for(int i=0; i<n; i++){
    cin >> t[i];
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      dp[i+1][j][0] = max(dp[i][j+1][0], dp[i][j+1][1]);
    }
    dp[i+1][0][0] = max(dp[i+1][0][0], dp[i][0][0]);
    for(int j=1; j<=m; j++){
      dp[i+1][j][1] = dp[i][j-1][1] + t[i];
    }
    dp[i+1][1][1] = max(dp[i+1][1][1], dp[i][0][0] + t[i]);
  }
  cout << dp[n][0][0] << endl;

  return 0;
}
