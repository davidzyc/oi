#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;

const int MAXN = 2e6+7;
const ll NEGINF = -(1e18);

int n, rn = 0;
ll val[MAXN] = {0};
int indeg[MAXN] = {0};
int inring[MAXN] = {0};
int ecnt = 1, to[MAXN], first[MAXN], nxt[MAXN];
queue<int> q;
ll f[MAXN][2] = {0};
int fa[MAXN];
ll rf[MAXN][2];
int vis[MAXN];
ll dpf[MAXN][2];

inline void add_edge(int x, int y){
  ++ecnt;
  to[ecnt] = y;
  nxt[ecnt] = first[x];
  first[x] = ecnt;
}

inline ll read_ll(){
  ll ret = 0;
  char c = getchar();
  for(; c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar()) ret = ret*10 + c - '0';
  return ret;
}

inline int read(){
  int ret = 0;
  char c = getchar();
  for(; c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar()) ret = ret*10 + c - '0';
  return ret;
}

inline void dfs(int x){
  // cout<<"DFS "<<x <<endl;
  // for(register int i=0; i<to[x].size(); i++){
  for(register int e=first[x]; e; e=nxt[e]){
    int y = to[e];
    if(inring[y]) continue;
    if(fa[x] == y) continue;
    fa[y] = x;
    dfs(y);
    f[x][0] += f[y][1];
    f[x][1] += max(f[y][0], f[y][1]);
    // cout << x << " " << y << " " << g[x] << " " << f[y] << endl;
  }

  f[x][0] += val[x];
  return;
}

inline void getring(int x){
  vis[x] = 1;
  rn++;
  rf[rn][0] = f[x][0], rf[rn][1] = f[x][1];
  for(register int e=first[x]; e; e=nxt[e]){
    int y = to[e];
    if(vis[y] || !inring[y]) continue;
    getring(y);
  }
}

int main(){
  int t;
  scanf("%d", &n);
  for(register int i=1; i<=n; i++){
    // scanf("%lld%d", &val[i], &t);
    val[i] = read_ll();
    t = read();
    // to[t].push_back(i);
    // to[i].push_back(t);
    add_edge(i, t);
    add_edge(t, i);
    indeg[i]++;
    indeg[t]++;
  }
  for(register int i=1; i<=n; i++){
    if(indeg[i] == 1) q.push(i);
  }
  while(!q.empty()){
    int x = q.front();
    q.pop();
    for(register int e=first[x]; e; e=nxt[e]){
      int y = to[e];
      indeg[y]--;
      if(indeg[y] == 1){
        q.push(y);
      }
    }
  }
  for(register int i=1; i<=n; i++){
    if(indeg[i] > 1) inring[i] = 1;
  }

  for(register int i=1; i<=n; i++){
    if(inring[i]){
      dfs(i);
    }
  }

  // for(int j=1; j<=n; j++){
  //   printf("%d f %lld g %lld\n", j, f[j], g[j]);
  // }
  // cout << "G1 " << g[1] << endl;
  ll gans = 0;
  for(register int i=1; i<=n; i++){
    if(inring[i] && !vis[i]){
      ll ans = NEGINF;
      rn = 0;
      memset(rf, 0, sizeof(rf));
      getring(i);
      memset(dpf, 0, sizeof(dpf));
      dpf[1][0] = NEGINF;
      dpf[1][1] = rf[1][1];
      for(register int i=2; i<=rn; i++){
        dpf[i][0] = dpf[i-1][1] + rf[i][0];
        dpf[i][1] = max(dpf[i-1][1], dpf[i-1][0]) + rf[i][1];
      }
      ans = max(dpf[rn][0], dpf[rn][1]);
      memset(dpf, 0, sizeof(dpf));
      for(register int i=1; i<=rn; i++){
        dpf[i][0] = dpf[i-1][1] + rf[i][0];
        dpf[i][1] = max(dpf[i-1][1], dpf[i-1][0]) + rf[i][1];
      }
      ans = max(ans, dpf[rn][1]);
      gans += ans;
    }
  }
  // for(int i=1; i<=rn; i++){
  //   cout << rf[i] << " " << rg[i] << endl;
  // }
  printf("%lld", gans);
  return 0;
}
