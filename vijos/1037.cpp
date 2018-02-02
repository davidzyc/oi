#include<cstdio>
#include<iostream>
#include<algorithm>
#define NEGINF -100000000
#define MAXN 105
#define MAXH 2000
using namespace std;

int dp[MAXN][MAXH];

int main(){
  int n, h[MAXN], hsum = 0;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> h[i];
    hsum += h[i];
  }
  for(int i=0; i<MAXN; i++){
    for(int j=0; j<MAXH; j++){
      dp[i][j] = NEGINF;
    }
  }
  dp[0][0] = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<= hsum; j++){
      dp[i+1][j] = dp[i][j];
      dp[i+1][j] = max(dp[i+1][j], dp[i][j+h[i]]+h[i]); //往低塔堆，但没有超过高塔
      if(j-h[i] >= 0){
        dp[i+1][j] = max(dp[i+1][j], dp[i][j-h[i]]);  //往高塔上堆
      }else{
        dp[i+1][j] = max(dp[i+1][j], dp[i][h[i]-j]+h[i]-j);
      }
    }
  }
  // for(int i=0; i<=n; i++){
  //   for(int j=0; j<= hsum; j++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  if(dp[n][0]){
    cout << dp[n][0];
  }else{
    cout << "Impossible";
  }

  return 0;
}
