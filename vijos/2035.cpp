#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 100;

int gn, gmod;

int dp[MAXN][6] = {0};

int main(){
  int gans = 5;
  scanf("%d%d", &gn, &gmod);
  dp[0][0] = 1;
  dp[1][0] = 0;
  dp[1][1] = 5;
  for(int i=2; i<=gn; i++){
    for(int j=0; j<=5; j++){
      // even
      dp[i][j] += dp[i-2][j] * 5;
      dp[i][j] += dp[i-2][j] * j;
      // odd
      if(j-1 >= 0){
        dp[i][j] += dp[i-1][j-1] * (6-j);
      }
    }
    for(int j=0; j<=5; j++){
      gans += dp[i][j];
      cout << dp[i][j] << "\t";
    }
    cout << endl;
  }
  cout << gans << endl;

  return 0;
}
