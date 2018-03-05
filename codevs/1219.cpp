#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 51;

int n, m;
long long dp[MAXN][MAXN] = {0};
int sj, si, tj, ti;

int main(){
  cin >> n >> m;
  cin >> sj >> si >> tj >> ti;
  dp[si][sj] = 1;
  for(int j=sj+1; j<=tj; j++){
    for(int i=0; i<=n; i++){
      if(i+2 <= n){
        dp[i][j] += dp[i+2][j-1];
      }
      if(j-2 >= 0 && i+1 <= n){
        dp[i][j] += dp[i+1][j-2];
      }
      if(j-2 >= 0 && i-1 >= 0){
        dp[i][j] += dp[i-1][j-2];
      }
      if(i-2 >= 0){
        dp[i][j] += dp[i-2][j-1];
      }
    }
  }
  cout << dp[ti][tj];

  return 0;
}
