#include<cstdio>
#include<iostream>
#define MAX_N 105
using namespace std;

int dp[MAX_N], invdp[MAX_N];

int main(){
  int n, a[MAX_N], maxn = 0;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  for(int i=0; i<n; i++){
    dp[i] = 1;
    for(int j=0; j<i; j++){
      if(a[j] < a[i]){
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    // cout << dp[i] << " ";
  }

  // cout << endl;

  for(int i=n-1; i>=0; i--){
    invdp[i] = 1;
    for(int j=n-1; j>i; j--){
      if(a[j] < a[i]){
        invdp[i] = max(invdp[i], invdp[j]+1);
      }
    }
  }

  // for(int i=0; i<n; i++){
  //   cout << invdp[i] << " ";
  // }

  for(int i=0; i<n; i++){
    maxn = max(maxn, dp[i] + invdp[i]);
  }

  cout << n + 1 - maxn;

  return 0;
}
