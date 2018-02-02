#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 105
#define MAXM 10
#define INF 2100000000
using namespace std;

int dpmin[MAXM][MAXN], dpmax[MAXM][MAXN];

int main(){
  int n, m, a[MAXN], s[MAXN] = {0}, ansmin, ansmax;
  cin >> n >> m;
  for(int i=1; i<=n; i++){
    cin >> a[i];
    s[i] = s[i-1] + a[i];
  }
  for(int i=n+1; i<=n*2; i++){
    a[i] = a[i-n];
    s[i] = s[i-1] + a[i];
  }
  // for(int i=1; i<=n*2; i++){
  //   cout << a[i] << " ";
  // }
  // cout << endl;
  // for(int i=1; i<=n*2; i++){
  //   cout << s[i] << " ";
  // }
  ansmin = INF;
  ansmax = 0;
  for(int st=0; st<n; st++){
    // memset(dpmin, 0, sizeof(dp));
    memset(dpmax, 0, sizeof(dpmax));
    for(int j=1; j<=n; j++){
      dpmax[1][j] = (s[j+st] - s[st] + 1000000) % 10;
      dpmin[1][j] = (s[j+st] - s[st] + 1000000) % 10;
      // cout << dpmax[1][j] << " ";
    }
    for(int i=2; i<=m; i++){
      for(int j=i; j<=n; j++){
        dpmin[i][j] = INF;
        for(int k=i-1; k<j; k++){
          dpmax[i][j] = max(dpmax[i][j], dpmax[i-1][k] * ((s[j+st]-s[k+st]+1000000)%10) );
          dpmin[i][j] = min(dpmin[i][j], dpmin[i-1][k] * ((s[j+st]-s[k+st]+1000000)%10) );
        }
      }
    }
    ansmax = max(ansmax, dpmax[m][n]);
    ansmin = min(ansmin, dpmin[m][n]);
    // cout << dpmin[m][n] << endl;
  }
  cout << ansmin << endl << ansmax;
  // cout << (-1)%10;

  return 0;
}
