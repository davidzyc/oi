#include<cstdio>
#include<iostream>

#define MAXN 1005
#define MAXM 12005
#define ST 6000
#define INF 2100000000

using namespace std;

int n, a[MAXN], b[MAXN], diff[MAXN], suma = 0, sumb = 0, sdif;
int dp[MAXN][MAXM];

int main(){
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a[i] >> b[i];
    diff[i] = a[i] - b[i];
    suma += a[i];
    sumb += b[i];
  }
  sdif = sumb - suma;
  for(int i=0; i<MAXM; i++){
    dp[0][i] = INF;
  }
  dp[0][ST] = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<MAXM; j++){
      if(j == ST){
        dp[i+1][j] = 0;
        continue;
      }
      if(j - diff[i]*2 >= 0 && j - diff[i]*2 < MAXM){
        dp[i+1][j] = min(dp[i][j], dp[i][j-diff[i]*2]+1);
      }else{
        dp[i+1][j] = dp[i][j];
      }
    }
  }
  // for(int j=5990; j<6010; j++){
  //   cout << dp[n][j] << " ";
  // }
  int ans = INF, cur = 0;
  while(ans == INF){
    if(ST-sdif-cur >= 0 && ST-sdif-cur < MAXM){
      ans = min(ans, dp[n][ST-sdif-cur]);
    }
    if(ST-sdif+cur >= 0 && ST-sdif+cur < MAXM){
      ans = min(ans, dp[n][ST-sdif+cur]);
    }
    cur ++;
  }
  cout << ans;

  return 0;
}
