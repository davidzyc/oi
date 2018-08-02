#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int MAXN = 1e4+7;
const int INF = 0x7f7f7f7f;

class Network {

private:

  int s, t;
  int n, en;
  int head[MAXN], nxt[MAXN], from[MAXN], to[MAXN], flow[MAXN];
  int lev[MAXN], v[MAXN], cur[MAXN];

public:

  void init(int n, int s, int t){
    en = 1;
    this -> n = n;
    this -> s = s;
    this -> t = t;
  }

  void add_edge(int f, int t, int w){
    ++ en;
    from[en] = f;
    to[en] = t;
    flow[en] = w;
    nxt[en] = head[f];
    head[f] = en;
    return;
  }

  bool bfs(){
    queue<int> q;
    memset(lev, 0, sizeof(lev));
    lev[s] = 1;
    q.push(s);
    while(!q.empty()){
      int x = q.front();
      q.pop();
      for(int e=head[x]; e; e=nxt[e]){
        int y = to[e];
        if(!lev[y] && flow[e] > 0){
          lev[y] = lev[x] + 1;
          q.push(y);
        }
      }
    }
    return lev[t] > 0 ? true : false;
  }

  int dfs(int x, int xf){
    if(x == t) return xf;
    for(int& e=cur[x]; e; e=nxt[e]){
      int y = to[e];
      if(lev[y] == lev[x] + 1 && flow[e] > 0){
        int rf = dfs(y, min(xf, flow[e]));
        if(rf > 0){
          flow[e] -= rf;
          flow[e^1] += rf;
          return rf;
        }
      }
    }
    return 0;
  }

  int dinic(){
    int ans = 0, tmp;
    while(bfs()){
      for(int i=1; i<=n; i++) cur[i] = head[i];
      while(tmp = dfs(s, INF)){
        ans += tmp;
      }
    }
    return ans;
  }

};

Network nt;
int n, m, s, t;

int main(){

  scanf("%d%d%d%d", &n, &m, &s, &t);
  nt.init(n*2, s + n, t);
  for(int i=1; i<=n; i++){
    nt.add_edge(i, i+n, 1);
    nt.add_edge(i+n, i, 0);
  }
  for(int i=1; i<=m; i++){
    scanf("%d%d", &s, &t);
    nt.add_edge(s+n, t, INF);
    nt.add_edge(t, s+n, 0);
    nt.add_edge(t+n, s, INF);
    nt.add_edge(s, t+n, 0);
  }

  printf("%d", nt.dinic());

  return 0;
}
