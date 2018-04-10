#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 3005;
const int MAXM = 70007;

int n, m;
int ecnt = 0;
int first[MAXN], nxt[MAXM], to[MAXM];
ll l[MAXM];
vector<int> bpre[MAXN];
// vector<int> tob[MAXN];
ll d[MAXN], ds[MAXN], mint[MAXN];
int v[MAXN] = {0};
int indeg[MAXN] = {0};
priority_queue<pli, vector<pli>, greater<pli> > pq;
int open[MAXN][MAXN];

void add_edge(int tf, int tt, int tl){
  if(tf == tt) return;
  ++ecnt;
  nxt[ecnt] = first[tf];
  first[tf] = ecnt;
  l[ecnt] = tl;
  to[ecnt] = tt;
  return;
}

void dij(){
  d[1] = 0;
  ds[1] = 0;
  for(int i=1; i<=n; i++){
    if(indeg[i] == 0) mint[i] = 0;
  }
  pq.push(make_pair(d[1], 1));
  while(!pq.empty()){
    pli tpq = pq.top();
    pq.pop();
    int x = tpq.second;
    if(v[x]) continue;
    v[x] = 1;

    // cout << x << ":" << endl;
    // for(int i=1; i<=n; i++){
    //   cout << mint[i] << " ";
    // }
    // cout << endl;
    // for(int i=1; i<=n; i++){
    //   cout << ds[i] << " ";
    // }
    // cout << endl;
    // for(int i=1; i<=n; i++){
    //   cout << d[i] << " ";
    // }
    // cout << endl;

    for(int e=first[x]; e!=0; e=nxt[e]){
      int y = to[e];
      ds[y] = min(d[x]+l[e], ds[y]);
      if(indeg[y] == 0){
        d[y] = min(d[y], max(ds[y], mint[y]));
        pq.push(make_pair(d[y], y));
      }
    }

    for(int i=0; i<bpre[x].size(); i++){
      int y = bpre[x][i];
      if(open[x][y] == 0){
        // cout << "HI";
        indeg[y]--;
        open[x][y] = 1;
        mint[y] = max(mint[y], d[x]);
      }
      if(indeg[y] == 0){
        d[y] = min(d[y], max(ds[y], mint[y]));
        pq.push(make_pair(d[y], y));
      }
    }
  }

  return;
}

int main(){
  memset(d, 0x3f, sizeof(d));
  memset(ds, 0x3f, sizeof(ds));
  // memset(mint, 0x3f, sizeof(mint));
  int tf, tt;
  ll tl;
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++){
    scanf("%d%d%lld", &tf, &tt, &tl);
    add_edge(tf, tt, tl);
  }
  int precnt, bto;
  for(int i=1; i<=n; i++){
    scanf("%d", &precnt);
    indeg[i] = precnt;
    for(int j=0; j<precnt; j++){
      scanf("%d", &bto);
      // tob[i].push_back(bto);
      bpre[bto].push_back(i);
    }
  }
  dij();

  printf("%lld", d[n]);

  return 0;
}
