#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define MAXLEN 2005
#define INF 10000000
using namespace std;
int dp[MAXLEN][MAXLEN];

int main(){
  int n, alen, blen;
  string a, b;
  cin >> a >> b >> n;
  alen = a.length();
  blen = b.length();
  // memset(dp, 0, sizeof(dp));
  for(int i=0; i<=alen; i++){
    for(int j=0; j<=blen; j++){
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  for(int i=0; i<=alen; i++){
    for(int j=0; j<=blen; j++){
      if(i-1>=0){
        dp[i][j] = min(dp[i-1][j]+n, dp[i][j]);
      }
      if(j-1>=0){
        dp[i][j] = min(dp[i][j-1]+n, dp[i][j]);
      }
      if(i-1>=0 && j-1>=0){
        dp[i][j] = min(dp[i-1][j-1]+abs(a[i-1] - b[j-1]), dp[i][j]);
      }
    }
  }
  // for(int i=0; i<=alen; i++){
  //   for(int j=0; j<=blen; j++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << dp[alen][blen];
  return 0;
}
