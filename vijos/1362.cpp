#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int MAXN = 601;
const int INF = 0x3f3f3f3f;

int n, k;
int first[MAXN], nxt[MAXN], to[MAXN], l[MAXN];
int d[MAXN] = {0}, fa[MAXN] = {0}, v[MAXN] = {0};
int onpath[MAXN] = {0};
int ecnt = 0;
int gecc = INF;

void add_edge(int x, int y, int tl){
  ++ecnt;
  nxt[ecnt] = first[x];
  first[x] = ecnt;
  to[ecnt] = y;
  l[ecnt] = tl;
  return;
}

int main(){
  // freopen("1362.txt", "r", stdin);
  int tx, ty, tl;
  scanf("%d%d", &n, &k);
  for(int i=0; i<n-1; i++){
    scanf("%d%d%d", &tx, &ty, &tl);
    add_edge(tx, ty, tl);
    add_edge(ty, tx, tl);
  }
  queue<int> q;
  for(int st=1; st<=n; st++){
    for(int ed=1; ed<=n; ed++){
      memset(v, 0, sizeof(v));
      memset(fa, 0, sizeof(fa));
      memset(d, 0, sizeof(d));
      // cout << st << " " << ed << endl;
      q.push(st);
      while(!q.empty()){
        int x = q.front();
        q.pop();
        if(v[x]) continue;
        if(x == ed){
          // cout << st << " " << x << " " << fa[x] << endl;
          break;
        }
        v[x] = 1;
        for(int e=first[x]; e!=0; e=nxt[e]){
          int y = to[e];
          d[y] = d[x] + l[e];
          if(!v[y]){
            fa[y] = x;
            q.push(y);
          }
        }
      }
      while(!q.empty()){
        q.pop();
      }
      if(d[ed] > k) continue;
      // cout << st << " " << ed  << " " << d[ed] << endl;
      memset(onpath, 0, sizeof(onpath));
      for(int x = ed; ; x=fa[x]){
        // cout << x << " ";
        onpath[x] = 1;
        // cout << x << " ";
        if(x == st) break;
      }
      int tecc = 0;
      for(int x = ed; ; x=fa[x]){
        memset(v, 0, sizeof(v));
        memset(d, 0, sizeof(d));
        // cout << x << endl;
        // memset(fa, 0, sizeof(fa));
        q.push(x);
        while(!q.empty()){
          int tx = q.front();
          q.pop();
          if(v[tx]) continue;
          // cout << tx << " " ;
          tecc = max(tecc, d[tx]);
          v[tx] = 1;
          for(int e=first[tx]; e!=0; e=nxt[e]){
            int y = to[e];
            d[y] = d[tx] + l[e];
            // fa[y] = x;
            if(!onpath[y]){
              q.push(y);
            }
          }
        }
        if(x == st) break;
      }
      gecc = min(gecc, tecc);
    }
  }
  cout << gecc;
  return 0;
}
