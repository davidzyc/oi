#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;

const int MAXN = 40007;
const int MAXM = 80007;
const int MAXLOG = 20;

int n, m;
int tlog;
int f[MAXN][MAXLOG] = {0};
int d[MAXN] = {0};
int t[MAXN] = {0};
int ecnt;
int first[MAXN] = {0}, to[MAXM] = {0}, nxt[MAXM] = {0};
int l[MAXM] = {0};
int vis[MAXN];

void add_edge(int tfrom, int tto, int tl){
  ++ecnt;
  // indeg[tto]++;
  nxt[ecnt] = first[tfrom];
  first[tfrom] = ecnt;
  to[ecnt] = tto;
  l[ecnt] = tl;
  return;
}

void bfs(int s){
  queue<int> q;
  q.push(s);
  d[s] = 1;
  vis[s] = 1;
  while(!q.empty()){
    int x = q.front();
    q.pop();
    vis[x] = 1;
    for(int e=first[x]; e!=0; e=nxt[e]){
      int y = to[e];
      if(vis[y]) continue;
      d[y] = d[x]+1;
      t[y] = t[x]+l[e];
      f[y][0] = x;
      for(int i=1; i<=tlog; i++){
        f[y][i] = f[f[y][i-1]][i-1];
      }
      q.push(y);
    }
  }
  return;
}

int lca(int x, int y){
  // cout << d[x] << " " << d[y] << endl;
  if(d[x] < d[y]) swap(x, y);
  for(int i=tlog; i>=0; i--){
    if(d[f[x][i]] >= d[y]) x = f[x][i];
  }
  if(x == y) return x;
  for(int i=tlog; i>=0; i--){
    if(f[x][i] != f[y][i]){
      x = f[x][i];
      y = f[y][i];
    }
  }
  return f[x][0];
}

int main(){
  // freopen("2586.txt", "r", stdin);
  int gnnnn;
  scanf("%d", &gnnnn);
  for(int ttt=0; ttt<gnnnn; ttt++){
    int tfrom, tto, tl;
    ecnt = 0;
    memset(f, 0, sizeof(f));
    memset(d, 0, sizeof(d));
    memset(t, 0, sizeof(t));
    memset(first, 0, sizeof(first));
    memset(to, 0, sizeof(to));
    memset(nxt, 0, sizeof(nxt));
    memset(l, 0, sizeof(l));
    memset(vis, 0, sizeof(vis));
    scanf("%d %d", &m, &n);
    // cout << m << " "<< n << endl;
    for(int i=1; i<m; i++){
      scanf("%d %d %d", &tfrom, &tto, &tl);
      // cout << tfrom << " " << tto << " " << tl <<endl;
      add_edge(tfrom, tto, tl);
      add_edge(tto, tfrom, tl);
    }
    tlog = (int) log(m) / log(2) + 1;
    bfs(1);
    for(int i=0; i<n; i++){
      scanf("%d %d", &tfrom, &tto);
      // cout << tfrom << " " << tto << endl;
      int lcan = lca(tfrom, tto);
      // cout << t[tfrom] << " " << t[tto] << " " << t[lcan] << endl;
      printf("%d\n", t[tfrom]+t[tto]-2*t[lcan]);
    }
  }

  return 0;
}
