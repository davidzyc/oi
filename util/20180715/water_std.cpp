#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 207;

const int INF = 0x3f3f3f3f;

int n, m;
int d[MAXN][MAXN];

int main(){
  memset(d, 0x3f, sizeof(d));
  int tf, tt, tl;
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++){
    scanf("%d%d%d", &tf, &tt, &tl);
    d[tf][tt] = d[tt][tf] = tl;
  }
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int ans = 0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(i == j) continue;
      if(d[i][j] < INF){
        ans = max(ans, d[i][j]);
        // cout << d[i][j] << " ";
      }
      // else{
        // cout << "-1 ";
      // }
    }
    // cout << endl;
  }
  // cout << ans;
  printf("%.2f", ans*1.0/2.0);

  return 0;
}
