#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e5+7;
const int INF = 0x3f3f3f3f;

class Network {

private:

  int n, en, s, t;
  int head[MAXN], nxt[MAXN], from[MAXN], to[MAXN], flow[MAXN], cost[MAXN];
  int dist[MAXN], inq[MAXN], pedge[MAXN], xflow[MAXN];
  int mat[100][100];

  void _add(int f, int t, int w, int c){
    ++en;
    from[en] = f;
    to[en] = t;
    flow[en] = w;
    cost[en] = c;
    nxt[en] = head[f];
    head[f] = en;
  }

public:

  void init(int n, int s, int t){
    this -> en = 1;
    this -> n = n;
    this -> s = s;
    this -> t = t;
  }

  void add_edge(int f, int t, int w, int c){
    _add(f, t, w, c);
    _add(t, f, 0, -c);
  }

  bool spfa(){
    queue<int> q;
    memset(dist, 0x3f, sizeof(dist));
    memset(inq, 0, sizeof(inq));
    memset(pedge, 0, sizeof(pedge));
    q.push(s);
    inq[s] = 1;
    dist[s] = 0;
    while(!q.empty()){
      int x = q.front();
      inq[x] = 0;
      q.pop();
      for(int e=head[x]; e; e=nxt[e]){
        int y = to[e];
        if(flow[e] > 0 && dist[y] > dist[x] + cost[e]){
          dist[y] = dist[x] + cost[e];
          pedge[y] = e;
          if(!inq[y]){
            inq[y] = 1;
            q.push(y);
          }
        }
      }
    }
    return dist[t] < INF;
  }

  int dfs(int x, int xf){
    if(!pedge[x]){
      return xf;
    }
    int ans = dfs(from[pedge[x]], min(xf, flow[pedge[x]]));
    flow[pedge[x]] -= ans;
    flow[pedge[x]^1] += ans;
    return ans;
  }

  pii ek(){
    int tmp, ans = 0, cst = 0;
    printm(0, 0);
    while(spfa()){
      tmp = dfs(t, INF);
      printm(tmp, dist[t]);
      ans += tmp;
      cst += tmp * dist[t];
    }
    return make_pair(ans, cst);
  }

  void printm(int cost, int di){
    memset(mat, 0, sizeof(mat));
    cout << "----------------" << endl;

    for(int e=2; e<=en; e+=2){
      mat[from[e]][to[e]] = flow[e];
      printf("%d %d %d:%d\n", from[e], to[e], flow[e], flow[e+1]);
    }
    cout << endl << endl;
    for(int i=0; i<=n; i++) cout << i << ", ";
    cout << endl;
    for(int i=1; i<=n; i++){
      cout << i << ", ";
      for(int j=1; j<=n; j++){
        cout << mat[i][j] << ", ";
      }
      cout << endl;
    }

    cout << endl << endl;
    printf("Cost: %d\nDistance: %d\n", cost, di);
    cout << "----------------" << endl;
  }

};

Network nt;
int n, m, s, t, w, c;

int main(){
  freopen("C:\\Users\\David\\Desktop\\math.txt", "w", stdout);
  scanf("%d%d%d%d", &n, &m, &s, &t);
  nt.init(n, s, t);
  for(int i=0; i<m; i++){
    scanf("%d%d%d%d", &s, &t, &w, &c);
    nt.add_edge(s, t, w, c);
  }
  pii ans = nt.ek();
  printf("%d %d", ans.first, ans.second);

  return 0;
}
