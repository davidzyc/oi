#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 100;

int n;
int dp[MAXN][MAXN][4] = {06};

int main(){

  scanf("%d", &n);
  dp[1][1][1] = 1;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(i == 1 && j == 1) continue;
      dp[i][j][1] = dp[i-1][j-1][1] +  dp[i-1][j-1][2] +  dp[i-1][j-1][3];
      dp[i][j][2] = dp[i-1][j][1] + dp[i-1][j][2];
      dp[i][j][3] = dp[i][j-1][1] + dp[i][j-1][3];
    }
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cout << dp[i][j][1] << " ";
    }
    cout << endl;
  }
  cout << endl;

    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        cout << dp[i][j][2] << " ";
      }
      cout << endl;
    }

    cout << endl;

    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        cout << dp[i][j][3] << " ";
      }
      cout << endl;
    }

    cout << endl;

  cout << dp[n][n][1] + dp[n][n][2] + dp[n][n][3];

  return 0;
}
