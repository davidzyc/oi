#include<cstdio>
#include<iostream>
#define MAXN 13
#define MAXNN 1 << 13
using namespace std;

int n, m;
long long dp[MAXN][MAXNN];
int mat[MAXN] = {0};

int main(){
  int t;
  cin >> n >> m;
  for(int i=1; i<=n; i++){
    for(int j=m-1; j>=0; j--){
      cin >> t;
      if(t == 0){
        mat[i] = mat[i] | (1<<j);
      }
    }
    // cout << mat[i] << " ";
  }
  long long gans = 0;
  dp[0][0] = 1;
  for(int i=1; i<=n; i++){
    for(int j=0; j<(1 << m); j++){
      if(j&(j<<1) || j&mat[i]) continue;
      for(int k=0; k<(1 << m); k++){
        if(k&(k<<1) || j&k) continue;
        dp[i][j] += dp[i-1][k];
        dp[i][j] = dp[i][j] % 100000000;
      }
      if(i == n){
        gans += dp[i][j];
        gans = gans % 100000000;
      }
    }
  }
  cout << gans << endl;

  return 0;
}
