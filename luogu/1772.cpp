#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXD = 105;
const int MAXN = 20;
const int MAXDPN = 18;
const int INF = 0x3f3f3f3f;

int n, m, k, e;
int disabled[MAXD] = {0};
int route[1 << MAXDPN];
int dp[2][1 << MAXDPN] = {0};
int routemin[2] = {0};
int adjm[MAXN][MAXN];
int v[MAXN] = {0};

void dfs(int x, int tl){
  if(x == n-1){
    int routeid = 0;
    for(int i=1; i<n-1; i++){
      if(v[i]){
        routeid = routeid | (1 << (i-1));
      }
    }
    route[routeid] = min(route[routeid], tl);
    return;
  }
  for(int i=1; i<n; i++){
    if(!v[i] && adjm[x][i] < INF){
      v[i] = 1;
      dfs(i, tl+adjm[x][i]);
      v[i] = 0;
    }
  }
  return;
}

int main(){
  freopen("1772.txt", "r", stdin);
  int tf, tt, tl;
  memset(route, 0x3f, sizeof(route));
  // memset(dp, 0x3f, sizeof(dp));
  memset(adjm, 0x3f, sizeof(adjm));
  scanf("%d%d%d%d", &n, &m, &k, &e);
  for(int i=0; i<e; i++){
    scanf("%d%d%d", &tf, &tt, &tl);
    --tf;
    --tt;
    adjm[tf][tt] = adjm[tt][tf] = tl;
  }
  dfs(0, 0);
  int discnt, nid, nf, nt;
  scanf("%d", &discnt);
  for(int i=0; i<discnt; i++){
    scanf("%d%d%d", &nid, &nf, &nt);
    for(int j=nf; j<=nt; j++){
      disabled[j] = disabled[j] | (1 << (nid-2));
    }
  }
  for(int tn=1; tn<=n; tn++){
    int cur = tn % 2, last = (tn+1) % 2;
    routemin[cur] = INF;
    for(int i=0; i<(1 << (m-2)); i++){
      dp[cur][i] = INF;
    }
    for(int i=0; i<(1 << (m-2)); i++){
      if(route[i] >= INF || i&disabled[tn]) continue;
      dp[cur][i] = min(dp[last][i], routemin[last]+k);
      dp[cur][i] += route[i];
      // cout << i << " " << dp[cur][i] << endl;
      routemin[cur] = min(routemin[cur], dp[cur][i]);
    }
    // cout << endl;
  }
  int gans = INF;
  for(int i=0; i<(1 << (m-2)); i++){
    gans = min(gans, dp[n%2][i]);
  }
  printf("%d\n", gans);
  // for(int i=0; i<(1 << (m-2)); i++){
  //   if(route[i] < INF) cout << i << " " << route[i] << endl;
  // }
  return 0;
}
