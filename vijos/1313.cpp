#include<cstdio>
#include<iostream>
#define MAX_N 32005
#define MAX_M 65
using namespace std;

int dp[MAX_M][MAX_N];

int main(){
  int n, m, v[MAX_M], p[MAX_M], q[MAX_M], tq, sonnum[MAX_M] = {0}, son[MAX_M][2];
  // freopen("1313.txt", "w", stdout);
  cin >> n >> m;
  for(int i=0; i<m; i++){
    cin >> v[i] >> p[i] >> tq;
    q[i] = tq - 1;
  }

  for(int i=0; i<m; i++){
    if(q[i] >= 0){
      son[q[i]][sonnum[q[i]]] = i;
      sonnum[q[i]]++;
      sonnum[i] = -1;
    }
  }

  for(int j=0; j<=n; j++){
    dp[0][j] = 0;
  }

  for(int i=0; i<m; i++){
    if(sonnum[i] < 0){
      for(int j=0; j<=n; j++){
        dp[i+1][j] = dp[i][j];
      }
      continue;
    }
    for(int j=0; j<=n; j++){
      if(sonnum[i] == 0){
        if(j >= v[i]){
          dp[i+1][j] = max(dp[i][j], dp[i][j-v[i]] + v[i]*p[i]);
        }else{
          dp[i+1][j] = dp[i][j];
        }
      }else if(sonnum[i] == 1){
        if(j >= v[i]+v[son[i][0]]){
          dp[i+1][j] = max(max(dp[i][j], dp[i][j-v[i]] + v[i]*p[i]), dp[i][j-v[i]-v[son[i][0]]] + v[i]*p[i] + v[son[i][0]]*p[son[i][0]]);
        }else if(j >= v[i]){
          dp[i+1][j] = max(dp[i][j], dp[i][j-v[i]] + v[i]*p[i]);
        }else{
          dp[i+1][j] = dp[i][j];
        }
      }else if(sonnum[i] == 2){
        if(j >= v[i]+v[son[i][0]]+v[son[i][1]]){
          dp[i+1][j] = max(max(max(dp[i][j], dp[i][j-v[i]] + v[i]*p[i]), max(dp[i][j-v[i]-v[son[i][0]]] + v[i]*p[i] + v[son[i][0]]*p[son[i][0]], dp[i][j-v[i]-v[son[i][1]]] + v[i]*p[i] + v[son[i][1]]*p[son[i][1]])), dp[i][j-v[i]-v[son[i][0]]-v[son[i][1]]] + v[i]*p[i] + v[son[i][0]]*p[son[i][0]] + v[son[i][1]]*p[son[i][1]]);
        }else if(j >= v[i]+v[son[i][0]] || j >= v[i]+v[son[i][1]]){
          if(j >= v[i]+v[son[i][0]])
            dp[i+1][j] = max(max(dp[i][j], dp[i][j-v[i]] + v[i]*p[i]), dp[i][j-v[i]-v[son[i][0]]] + v[i]*p[i] + v[son[i][0]]*p[son[i][0]]);
          if(j >= v[i]+v[son[i][1]])
            dp[i+1][j] = max(max(dp[i][j], dp[i][j-v[i]] + v[i]*p[i]), dp[i][j-v[i]-v[son[i][1]]] + v[i]*p[i] + v[son[i][1]]*p[son[i][1]]);
        }else if(j >= v[i]){
          dp[i+1][j] = max(dp[i][j], dp[i][j-v[i]] + v[i]*p[i]);
        }else{
          dp[i+1][j] = dp[i][j];
        }
      }
    }
  }
  cout << dp[m][n];

  // for(int i=0; i<=m; i++){
  //   for(int j=0; j<=n; j++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }


  // for(int i=0; i<m; i++){
  //   cout << v[i] << " " << p[i];
  //   if(sonnum[i] >= 0){
  //     for(int j=0; j<sonnum[i]; j++){
  //       cout << " " << son[i][j];
  //     }
  //   }else{
  //     cout << " Accessory";
  //   }
  //   cout << endl;
  // }

  return 0;
}
