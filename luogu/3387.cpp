#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 2e5+7;

struct Graph{
  int n;
  int en = 0;
  int from[MAXN], to[MAXN], head[MAXN], nxt[MAXN];
  int cnt = 0;
  int dfn[MAXN], low[MAXN];
  int sccn = 0, sccid[MAXN];
  vector<int> scc[MAXN];
  int stan = 0, sta[MAXN], ins[MAXN];
  int dot[MAXN];
  int indeg[MAXN], outdeg[MAXN];
  int dp[MAXN];

  void add_edge(int f, int t){
    ++en;
    from[en] = f;
    to[en] = t;
    nxt[en] = head[f];
    head[f] = en;
    outdeg[f] ++;
    indeg[t] ++;
    return;
  }

  void tarjan(int x){
    dfn[x] = low[x] = ++cnt;
    sta[stan++] = x;
    ins[x] = 1;
    for(int e=head[x]; e; e=nxt[e]){
      int y = to[e];
      if(!dfn[y]){
        tarjan(y);
        low[x] = min(low[x], low[y]);
      }else if (ins[y]){
        low[x] = min(low[x], low[y]);
      }
    }
    if(low[x] == dfn[x]){
      ++sccn;
      int y;
      do{
        y = sta[--stan];
        ins[y] = 0;
        sccid[y] = sccn;
        scc[sccn].push_back(y);
      }while(x != y);
    }
  }

  void get_dag_dp(){
    queue<int> q;
    for(int i=1; i<=n; i++){
      if(indeg[i] == 0){
        q.push(i);
      }
    }

    while(!q.empty()){
      int x = q.front();
      q.pop();
      dp[x] += dot[x];
      for(int e = head[x]; e; e=nxt[e]){
        int y = to[e];
        dp[y] = max(dp[y], dp[x]);
        --indeg[y];
        if(!indeg[y] && !ins[y]){
          q.push(y);
          ins[y] = 1;
        }
      }
    }
  }

};

struct DJSet{
  int fa[MAXN];
  void init(int n){
    for(int i=1; i<=n; i++) fa[i] = i;
  }
  int get_fa(int x){
    return fa[x] == x ? x : fa[x] = get_fa(fa[x]);
  }
};

Graph a, b;
DJSet d;

int main(){
  int f, t, m;
  scanf("%d%d", &a.n, &m);
  for(int i=1; i<=a.n; i++){
    scanf("%d", &a.dot[i]);
  }
  for(int i=1; i<=m; i++){
    scanf("%d%d", &f, &t);
    a.add_edge(f, t);
  }
  for(int i=1; i<=a.n; i++){
    if(!a.dfn[i]){
      a.tarjan(i);
    }
  }
  b.n = a.sccn;
  d.init((b.n*2)+2);
  for(int i=1; i<=a.en; i++){
    f = a.sccid[a.from[i]], t = a.sccid[a.to[i]];
    // cout << f << " -> " << t << " " << d.get_fa(f) << " " << d.get_fa(t + b.n) <;
    if(f != t && (d.get_fa(f) != d.get_fa(t + b.n))){
      b.add_edge(f, t);
      d.fa[d.get_fa(f)] = d.get_fa(t + b.n);
    }
  }
  for(int i=1; i<=a.n; i++){
    b.dot[a.sccid[i]] += a.dot[i];
  }
  b.get_dag_dp();
  int maxdp = 0;
  for(int i=1; i<=b.n; i++){
    // cout << b.dp[i] << " ";
    maxdp = max(maxdp, b.dp[i]);
  }
  printf("%d\n", maxdp);
  // for(int i=1; i<=a.n; i++) cout << a.sccid[i] << " ";
  // cout << endl;
  // for(int i=1; i<=a.sccn; i++){
  //   for(int j=0; j<a.scc[i].size(); j++){
  //     printf("%d ", a.scc[i][j]);
  //   }
  //   printf("\n");
  // }

  return 0;
}
