#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 13;
const int MAXTWON = 1 << 13;
const int INF = 0x3f3f3f3f;
int n, m;
int adjm[MAXN][MAXN];
int dp[MAXTWON][MAXN][MAXN]; // dp[BITSET][FROM][NTHNODE]
int gans = INF;

int main(){
  // freopen("2032.txt", "r", stdin);
  // freopen("2032_out.txt", "w", stdout);
  memset(adjm, 0x3f, sizeof(adjm));
  memset(dp, 0x3f, sizeof(dp));
  scanf("%d %d", &n, &m);
  if(m == 0){
    cout << 0;
    return 0;
  }
  for(int i=0; i<m; i++){
    int tfrom, tto, tl;
    scanf("%d %d %d", &tfrom, &tto, &tl);
    --tfrom;
    --tto;
    adjm[tfrom][tto] = adjm[tto][tfrom] = min(adjm[tfrom][tto], tl);
  }
  for(int j=1; j<n; j++){
    dp[0][0][j] = 0;
    for(int i=0; i<n; i++){
      dp[(1<<i)][i][j] = 0;
    }
  }
  for(int i=1; i<(1<<n); i++){
    for(int j=1; j<(1<<n); j++){
      if((i|j)!=i) continue;
      int inj = i^(i&j);
      // cout << j << " & " << inj << " -> " << i << endl;
      for(int u=0; u<n; u++){
        if(((inj>>u)&1) == 0) continue;
        for(int v=0; v<n; v++){
          if(((j>>v)&1) == 0) continue;
          if(u == v || adjm[u][v] >= INF) continue;
          //merge sets
          for(int nth=1; nth<n; nth++){
            dp[i][u][nth] = min(dp[i][u][nth], dp[inj][u][nth]+dp[j][v][nth+1]+adjm[u][v]*nth);
            dp[i][v][nth] = min(dp[i][v][nth], dp[inj][u][nth+1]+dp[j][v][nth]+adjm[u][v]*nth);
          }
        }
      }
    }
  }
  for(int i=0; i<n; i++){
    gans = min(gans, dp[(1<<n)-1][i][1]);
  }
  cout << gans;

  return 0;
}
