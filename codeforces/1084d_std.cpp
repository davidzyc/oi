#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 1e6+7;

int n, m = 0;
int c[MAXN];
int head[MAXN], nxt[MAXN], to[MAXN], w[MAXN];
int v[MAXN];
int tup[MAXN], tc[MAXN], tdown[MAXN];
int tm[MAXN];
int rt = 1;

void add_edge(int tf, int tt, int tw){
  ++m;
  to[m] = tt;
  w[m] = tw;
  nxt[m] = head[tf];
  head[tf] = m;
}

void dfs(int x){
  v[x] = 1;
  for(int e=head[x]; e; e=nxt[e]){
    int y = to[e];
    if(v[y]) continue;
    dfs(y);
    tup[x] = max(tup[x], tup[y]- w[e]);
  }
  tup[x] += c[x];
}

int main(){
  freopen("1084d.in", "r", stdin);
  freopen("1084d.ans", "w", stdout);
  scanf("%d", &n);
  int tf, tt, tw;
  for(int i=1; i<=n; i++){
    scanf("%d", &c[i]);
  }
  for(int i=1; i<n; i++){
    scanf("%d%d%d", &tf, &tt, &tw);
    add_edge(tf, tt, tw);
    add_edge(tt, tf, tw);
  }
  int gans = 0;
  for(int i=1; i<=n; i++){
    memset(tup, 0, sizeof tup);
    memset(v, 0, sizeof(v));
    dfs(i);
    for(int j=1; j<=n; j++){
      // cout << tup[j] << " ";
      gans = max(gans, tup[j]);
    }
    // cout << endl;
  }
  // for(int i=1; i<=n; i++){
  //   printf("Up: %d | Down: %d\n", tup[i]+c[i], tdown[i]+c[i]);
  // }

  printf("%d\n", gans);

  return 0;
}
