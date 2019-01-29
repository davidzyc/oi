#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 1007;

int n;
int a[MAXN] = {0};
int dp[MAXN][MAXN] = {0};
int gcd[MAXN][MAXN];

int fgcd(int x, int y){
  return y == 0 ? x : fgcd(y, x % y);
}

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  memset(dp, 0x3f, sizeof(dp));
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      gcd[i][j] = fgcd(a[i], a[j]);
    }
  }
  dp[1][1] = 1;
  for(int i=2; i<=n; i++){
    for(int j=1; j<=i; j++) dp[i][j] = i;

    if(gcd[i][i-1] > 1){
      for(int j=1; j<i; j++){
        dp[i][j] = min(dp[i][j], dp[i-1][j]);
        if(dp[i-1][j] > 1){
          for(int k=1; k<dp[i-1][j]; k++){
            if(gcd[k][i] > 1){
              dp[i][k] = min(dp[i][k], dp[dp[i-1][j]-1][k]);
            }
          }
        }
      }
    }

    for(int j=1; j<i; j++){
      if(gcd[i][j] > 1){
        dp[i][i] = min(dp[i-1][j], dp[i][i]);
      }
    }
  }
  int gmax = 1000;
  for(int i=1; i<=n; i++){
    gmax = min(gmax, dp[n][i]);
  }

  // for(int i=1; i<=n; i++){
  //   for(int j=1; j<=i; j++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  gmax == 1 ? printf("Yes\n") : printf("No\n");


  return 0;
}
