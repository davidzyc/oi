#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN = 1e5+7;
const int INF = 0x3f3f3f3f;

class Network {
private:
  int n, en;
  int s, t;
  int head[MAXN], nxt[MAXN], from[MAXN], to[MAXN], flow[MAXN];
  int lev[MAXN], cur[MAXN], v[MAXN];
public:
  void init(int n, int s, int t) {
    this->n = n;
    this->s = s;
    this->t = t;
    en = 1;
  }

  void add_edge(int f, int t, int w){
    ++en;
    from[en] = f;
    to[en] = t;
    flow[en] = w;
    nxt[en] = head[f];
    head[f] = en;
    return;
  }

  bool bfs() {
    memset(lev, 0, sizeof(lev));
    queue<int> q;
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

  int dfs(int x, int xflow){
    if(x == t){
      return xflow;
    }
    for(int& e=cur[x]; e; e=nxt[e]){
      int y = to[e];
      if(lev[y] == lev[x] + 1 && flow[e] > 0){
        int rflow = dfs(y, min(xflow, flow[e]));
        if(rflow > 0){
          flow[e] -= rflow;
          flow[e^1] += rflow;
          return rflow;
        }
      }
    }
    return 0;
  }

  int dinic(){
    int ans = 0, tmp;
    while(bfs()){
      for(int i=1; i<=n; i++) cur[i] = head[i];
      // cout << ans << " ";
      while(tmp = dfs(s, INF)){
        ans += tmp;
      }
    }
    return ans;
  }

};

Network nt;
int n, m, s, t, w;

int main(){

  scanf("%d%d%d%d", &n, &m, &s, &t);
  nt.init(n, s, t);
  for(int i=0; i<m; i++){
    scanf("%d%d%d", &s, &t, &w);
    nt.add_edge(s, t, w);
    nt.add_edge(t, s, 0);
  }
  printf("%d", nt.dinic());

  return 0;
}
