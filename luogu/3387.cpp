#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 1e4+7;
const int MAXM = 2e5+7;

int n, m;
int a[MAXN];
int first[MAXN], nxt[MAXM], to[MAXM];
int ecnt = 0;
int dfn[MAXN], low[MAXN], dfncnt = 0;
int nodes[MAXN], sh = 0, ins[MAXN] = {0};
vector<int> scc[MAXN];
int scccnt = 0;

void add_edge(int tfrom, int tto){
  int t;
  ++ecnt;
  to[ecnt] = tto;
  t = first[tfrom];
  first[tfrom] = ecnt;
  nxt[ecnt] = t;
  return;
}

void tarjan(int x){
  // if(!first[x]) return;
  dfn[x] = low[x] = ++dfncnt;
  nodes[sh++] = x;
  ins[x] = 1;
  for(int e=first[x]; e != 0; e=nxt[e]){
    int v = to[e];
    // cout << x << " " << to[e] << endl;
    if(!dfn[v]){
      tarjan(v);
      // cout << v << " " << low[v] << endl;
      low[x] = min(low[x], low[v]);
    }else if(ins[v]){
      low[x] = min(low[x], low[v]);
    }
  }
  // cout << x << " " << low[x] << " " << dfn[x] << endl;
  if(low[x] == dfn[x]){
    int s_elem;
    do{
      s_elem = nodes[--sh];
      ins[s_elem] = 0;
      scc[scccnt].push_back(s_elem);
    }while(s_elem != x);
    // cout << scc[scccnt].size() << endl;
    ++scccnt;
  }
  return;
}

int main(){
  int tfrom, tto;
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  for(int i=0; i<m; i++){
    scanf("%d%d", &tfrom, &tto);
    add_edge(tfrom, tto);
  }
  for(int i=1; i<=n; i++){
    if(!dfn[i]){
      tarjan(i);
    }
  }
  for(int i=0; i<scccnt; i++){
    for(int j=0; j<scc[i].size(); j++){
      printf("%d ", scc[i][j]);
    }
    printf("\n");
  }

  return 0;
}
