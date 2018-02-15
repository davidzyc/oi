#include<cstdio>
#include<iostream>
#define MAXN 305
#define MAXM 305
using namespace std;

int n, m;
int dp[MAXN][MAXM] = {0};
bool adjm[MAXN][MAXN] = {false};
// int indeg[MAXN] = {0};
int from[MAXN] = {0}, w[MAXN] = {0};

void dfs(int nodeid){
  for(int i=1; i<=n; i++){
    if(adjm[nodeid][i]){
      dfs(i);
      if(!nodeid) continue;
      for(int j=1; j<=m; j++){
        dp[nodeid][j] = max(dp[nodeid][j], dp[i][j-1]+w[nodeid]);
      }
    }
  }
}

int main(){
  cin >> n >> m;
  for(int i=1; i<=n; i++){
    cin  >> from[i] >> w[i];
    dp[i][1] = w[i];
    adjm[from[i]][i] = true;
  }
  dfs(0);
  for(int i=1; i<=n; i++){
    if(adjm[0][i]){
      for(int k=1; k<=m; k++){
        for(int j=m; j>=k; j--){
          dp[0][j] = max(dp[0][j], dp[0][j-k]+dp[i][k]);
        }
      }
    }
  }
  for(int i=0; i<=n; i++){
    cout << i << " " << w[i]<< "|";
    for(int j=0; j<=m; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  cout << dp[0][m];
  return 0;
}
