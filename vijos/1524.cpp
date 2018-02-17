#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#define MAXN 105
#define INF 2100000000
using namespace std;

int n, e;
int m, a[MAXN];
int netm[MAXN][MAXN] = {0};
int tnetm[MAXN][MAXN], vis[MAXN], prv[MAXN];

int augpath(int st, int ed){
  memset(vis, 0, sizeof(vis));
  memset(prv, 0, sizeof(prv));
  queue<int> q;
  q.push(st);
  while(!q.empty()){
    int tn = q.front();
    q.pop();
    if(tn == ed) break;
    if(vis[tn]) continue;
    vis[tn] = 1;
    // cout << tn << " " << vis[tn] << " ";
    for(int i=1; i<=n; i++){
      if(tnetm[tn][i] && !vis[i]){
        prv[i] = tn;
        q.push(i);
      }
    }
  }
  int tprv = ed, minflow = INF;
  while(tprv){
    if(tprv == st) break;
    minflow = min(minflow, tnetm[prv[tprv]][tprv]);
    tprv = prv[tprv];
  }
  tprv = ed;
  while(tprv){
    if(tprv == st) break;
    tnetm[prv[tprv]][tprv] -= minflow;
    tnetm[tprv][prv[tprv]] += minflow;
    tprv = prv[tprv];
  }
  return minflow;
}

int main(){
  cin >> n >> e;
  int tfrom, tto, tw;
  for(int i=0; i<e; i++){
    cin >> tfrom >> tto >> tw;
    netm[tfrom][tto] = netm[tto][tfrom] = tw;
  }
  cin >> m;
  int anspath = 0;
  int globalpath = 0, tpath;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      tnetm[i][j] = netm[i][j];
    }
  }
  for(int i=0; i<m; i++){
    cin >> a[i];
    // int tst, ted;
    // cin >> tst >> ted;
    while(tpath = augpath(1, a[i])){
      globalpath += tpath;
    }
    anspath += globalpath;
    // cout << globalpath << endl;
  }
  cout << anspath;

  return 0;
}
