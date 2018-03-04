#include<cstdio>
#include<iostream>
#define INF 100000000
#define MAXN 3001
using namespace std;

int n, mc, mi;
int l[MAXN] = {0}, r[MAXN] = {0}, c[MAXN];
int dp[MAXN][MAXN] = {0};
int sonno[MAXN] = {0};

int dfs(int tcur){
  if(tcur == 0) return 0;
  int ntyp = 1;
  dfs(l[tcur]);
  dfs(r[tcur]);
  // cout << tcur << " ";
  for(int i=1; i<=n; i++){
     dp[tcur][i] = dp[r[tcur]][i];
  }
  sonno[tcur] = sonno[l[tcur]] + sonno[r[tcur]];
  if(tcur <= mi){
    ntyp = 0;
  }else{
    sonno[tcur] ++;
  }
  for(int i=1; i<=sonno[tcur]; i++){
    for(int k=0; k<=i-ntyp; k++){
      dp[tcur][i] = max(dp[tcur][i], dp[r[tcur]][k]+dp[l[tcur]][i-k-ntyp]+c[tcur]);
    }
  }
  // cout << endl << tcur << ": ";
  // for(int i=0; i<=n; i++){
  //    cout << dp[tcur][i] << " ";
  // }
  return sonno[tcur];
}

int main(){
  // freopen("1273.txt", "r", stdin);
  int tn, tto, tw, t;
  cin >> n >> mc;
  mi = n - mc;
  for(int i=0; i<=n; i++){
    for(int j=1; j<=n; j++){
      dp[i][j] = -INF;
    }
  }
  for(int i=1; i<=mi; i++){
    cin >> tn;
    for(int j=0; j<tn; j++){
      cin >> tto >> tw;
      t = l[i];
      l[i] = tto;
      r[tto] = t;
      c[tto] -= tw;
    }
  }
  for(int i=mi+1; i<=n; i++){
    cin >> t;
    c[i] += t;
    // sonno[i] = 1;
  }
  dfs(1);
  // for(int i=1; i<=n; i++){
  //   // cout << l[i] << " " << r[i] << endl;
  //   cout << sonno[i] << " ";
  // }
  // cout << endl;
  for(int i=n; i>=0; i--){
    if(dp[1][i] >= 0){
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
