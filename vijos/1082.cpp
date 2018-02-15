#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 5005
#define MAXM 80005
#define INF 2100000000
using namespace std;

int n, m;
int gfrom, gto, gw, gans = INF;
int vis[MAXN] = {0}, from[MAXM], to[MAXM], w[MAXM], t[MAXM], first[MAXN], nxt[MAXM];

void dfs(int fromid, int curw, int curt){
  if(vis[fromid] || curw > gw){
    return;
  }
  if(fromid == gto){
    gans = min(gans, curt);
  }
  int e = first[fromid];
  vis[fromid] = 1;
  while(e != -1){
    dfs(to[e], curw+w[e], curt+t[e]);
    e = nxt[e];
  }
  vis[fromid] = 0;
  return;
}

int main(){
  memset(first, -1, sizeof(first));
  memset(nxt, -1, sizeof(nxt));
  int tfrom, tto, tw, tt;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    cin >> tfrom >> tto >> tw >> tt;
    from[2*i] = to[2*i+1] = tfrom;
    from[2*i+1] = to[2*i] = tto;
    w[2*i] = w[2*i+1] = tw;
    t[2*i] = t[2*i+1] = tt;
    nxt[2*i] = first[tfrom];
    nxt[2*i+1] = first[tto];
    first[tfrom] = 2*i;
    first[tto] = 2*i+1;
  }
  cin >> gfrom >> gto >> gw;
  dfs(gfrom, 0, 0);
  if(gans < INF){
    cout << gans;
  }else{
    cout << -1;
  }
  return 0;
}
