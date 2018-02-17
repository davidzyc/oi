#include<cstdio>
#include<iostream>
#define MAXN 17
#define INF 2100000000
using namespace std;

int n, c[MAXN][MAXN];
int dp[1<<MAXN], from[1<<MAXN];
int one[MAXN][1<<(MAXN-1)], onecnt[MAXN] = {0};

int main(){
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> c[i][j];
    }
  }
  for(int i=0; i<(1<<n); i++){
    int t = i, tcnt = 0;
    for(int j=0; j<n; j++){
      if((t&1)) tcnt++;
      t = t >> 1;
    }
    one[tcnt][onecnt[tcnt]++] = i;
  }
  // for(int i=0; i<=n; i++){
    for(int j=0; j<(1<<n); j++){
      dp[j] = INF;
      from[j] = -1;
    }
  // }
  dp[0] = 0;
  for(int k=0; k<onecnt[1]; k++){
    int t = one[1][k];
    int tcnt = 0, tpos;
    for(int h=0; h<n; h++){
      if((t&1)) {
        tcnt++;
        tpos = h;
      }
      t = t >> 1;
    }
    dp[one[1][k]] = 0;
    from[one[1][k]] = tpos;
    // cout << one[1][k] << " " << tpos << " | ";
  }
  for(int i=2; i<=n; i++){
    for(int j=0; j<onecnt[i]; j++){
      int tmin = INF, tto, tfrom;
      for(int k=0; k<onecnt[i-1]; k++){
        int t = one[i][j] ^ one[i-1][k];
        int tcnt = 0, tpos;
        for(int h=0; h<n; h++){
          if((t&1)) {
            tcnt++;
            tpos = h;
          }
          t = t >> 1;
        }
        if(tcnt == 1){
          // cout << from[one[i-1][k]] << " -> " << tpos << " : " << c[from[one[i-1][k]]][tpos] << endl;
          // cout << "hi ";
          if(dp[one[i-1][k]]+c[from[one[i-1][k]]][tpos] < tmin){
            // cout << from[one[i-1][k]] << " " << tpos << " | ";
            tmin = dp[one[i-1][k]]+c[from[one[i-1][k]]][tpos];
            tto = tpos;
            // tfrom = from[one[i-1][k]];
          }
        }
      }
      dp[one[i][j]] = tmin;
      from[one[i][j]] = tto;
      // cout << one[i][j] << " ";
    }
    // cout << endl;
  }
  // for(int i=0; i<(1<<n); i++){
  //   cout << dp[i] << " ";
  // }
  cout << dp[(1<<n)-1];

  return 0;
}
