#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAXM 10
#define MAXN 100
using namespace std;

int n, m;
int mat[MAXN];
int can[1 << MAXM], canno[1 << MAXM], cancnt = 0;
int dp[2][1 << MAXM][1 << MAXM];

int main(){
  cin >> n >> m;
  int t;
  char c;
  for(int i=0; i<n; i++){
    t = 0;
    getchar();
    for(int j=m-1; j>=0; j--){
      c = getchar();
      t |= (c=='P'?1:0) << j;
    }
    mat[i] = t;
    // cout << endl << mat[i] << endl;
  }
  for(int i=0; i<(1 << m); i++){
    if((i & (i << 1)) == 0 && (i & (i << 2)) == 0){
      int tcnt = 0;
      can[cancnt] = i;
      for(int j=0; j<m; j++){
        if(((i >> j) & 1) == 1) tcnt++;
      }
      canno[cancnt] = tcnt;
      cancnt ++;
    }
  }
  // for(int i=0; i<cancnt; i++){
  //   cout << can[i] << " : " << canno[i] << endl;
  // }
  int cur, last, ansmax = 0;
  for(int i=0; i<n; i++){
    cur = (i+1) % 2;
    last = i % 2;
    for(int j=0; j<(1 << MAXM); j++){
      for(int k=0; k<(1 << MAXM); k++){
        dp[cur][j][k] = 0;
      }
    }
    for(int j=0; j<cancnt; j++){
      if((can[j]&mat[i]) == can[j]){
        for(int k=0; k<cancnt; k++){
          if((can[j]&can[k]) == 0){
            for(int l=0; l<cancnt; l++){
                if((can[j]&can[l]) == 0 && (can[l]&can[k]) == 0){
                  dp[cur][can[j]][can[k]] = max(dp[last][can[k]][can[l]]+canno[j], dp[cur][can[j]][can[k]]);
                  if(i == n-1){
                    ansmax = max(ansmax, dp[cur][can[j]][can[k]]);
                  }
                }
            }
          }
        }
      }
    }
  }
  cout << ansmax << endl;

  return 0;
}
