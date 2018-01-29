#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define MAXV 5005
#define MAXN 205
#define MAXK 55
#define NEGINF -10000000
using namespace std;

int dp[MAXV][MAXK];
int used[MAXV];

int main(){
  memset(dp, 0, sizeof(dp));
  queue<int> q1, q2;
  int k, v, n, w[MAXN], val[MAXN], tot = 0;
  cin >> k >> v >> n;
  for(int i=0; i<n; i++){
    cin >> w[i] >> val[i];
  }
  for(int i=0; i<=v; i++){
    for(int j=0; j<k; j++){
      dp[i][j] = NEGINF;
    }
  }
  dp[0][0] = 0;
  for(int i=0; i<n; i++){
    for(int j=v; j>=w[i]; j--){
      for(int ik=0; ik<k; ik++){
        q1.push(dp[j][ik]);
        q2.push(dp[j-w[i]][ik]+val[i]);
      }
      for(int ik=0; ik<k; ik++){
        if(q1.front() > q2.front()){
          dp[j][ik] = q1.front();
          q1.pop();
        }else{
          dp[j][ik] = q2.front();
          q2.pop();
        }
      }
      while(!q1.empty()){
        q1.pop();
      }
      while(!q2.empty()){
        q2.pop();
      }
    }
  }
  // for(int i=0; i<k; i++){
  //   // for(int j=0; j<=n; j++){
  //     for(int l=0; l<=v; l++){
  //       cout << dp[l][i] << " ";
  //     }
  //     cout << endl;
  //   // }
  //   cout << endl << endl;
  // }

  for(int i=0; i<k; i++){
    if(dp[v][i] > 0)
    tot += dp[v][i];
  }
  cout << tot;
  return 0;
}
