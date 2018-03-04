#include<cstdio>
#include<iostream>
#define MAXNN 10
#define MAXN 1 << 10
#define MAXP 82
using namespace std;

typedef long long ll;
int n, ki;
int can[MAXN], canno[MAXN] = {0}, cancnt = 0;
ll dp[MAXNN][MAXN][MAXP] = {0};
ll gans = 0;

int main(){
  cin >> n >> ki;
  for(int i=0; i<(1 << n); i++){
    if((i&(i<<1)) == 0){
      can[cancnt] = i;
      for(int j=0; j<n; j++){
        if(((i>>j)&1) == 1){
          canno[cancnt]++;
        }
      }
      // cout << cancnt << " " << can[cancnt] << " " << canno[cancnt] << endl;
      cancnt++;
    }
  }
  dp[0][0][0] = 1;
  int cur, last;
  for(int i=1; i<=n; i++){
    cur = i;
    last = i-1;
    for(int j=0; j<cancnt; j++){
      for(int k=0; k<cancnt; k++){
        if((can[j]&(can[k] << 1)) != 0 || (can[j]&can[k])!=0 || (can[j]&(can[k] >> 1))!=0) continue;
        // cout << can[k] << " -> " << can[j] << endl;
        for(int g=canno[j]; g<=ki; g++){
          dp[cur][can[j]][g] += dp[last][can[k]][g-canno[j]];
        }
      }
      if(can[j] == 0) continue;
      // if(dp[cur][can[j]][ki] != 0){
      //   cout << i << " " << can[j] << " " << dp[cur][can[j]][ki] << endl;
      // }
      gans += dp[cur][can[j]][ki];
    }
    // cout << gans << endl;
  }

  cout << gans << endl;

  return 0;
}
