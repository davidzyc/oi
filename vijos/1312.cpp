#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAXN 2005
using namespace std;

int dp[MAXN][MAXN] = {0};

int main(){
  int n, a[MAXN], emax = 0;
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> a[i];
    a[i+n] = a[i];
  }
  for(int len=2; len<=n; len++){
    for(int l=1,r; (r=l+len)<=n*2; l++){
      for(int k=l+1; k<r; k++){
        dp[l][r] = max(dp[l][r], dp[l][k]+dp[k][r]+a[l]*a[k]*a[r]);
      }
      if(len == n){
        // cout << dp[l][r] << " ";
        emax = max(emax, dp[l][r]);
      }
    }
  }
  cout << emax;

  return 0;
}
