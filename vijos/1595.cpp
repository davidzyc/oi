#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 101;

int n;
int dfncnt = 0;
int dfn[MAXN], low[MAXN];
int cut[MAXN], sccid[MAXN];
vector<int> gto[MAXN];
int scccnt = 0;
vector<int> scc[MAXN];
int stackcnt = 0, sta[MAXN], ins[MAXN] = {0};

vector<int> sccto[MAXN];
int indeg[MAXN] = {0}, outdeg[MAXN] = {0};

void tarjan(int x){
  dfn[x] = low[x] = ++dfncnt;
  sta[stackcnt++] = x;
  ins[x] = 1;
  for(int i=0; i<gto[x].size(); i++){
    int y = gto[x][i];
    if(!dfn[y]){
      tarjan(y);
      low[x] = min(low[x], low[y]);
    }else if(ins[y]){
      low[x] = min(low[x], low[y]);
    }
  }
  if(low[x] == dfn[x]){
    int y;
    ++scccnt;
    do{
      y = sta[--stackcnt];
      sccid[y] = scccnt;
      ins[y] = 0;
      scc[scccnt].push_back(y);
    }while(x != y);
  }
  return;
}

int main(){
  int t;
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    while(true){
      scanf("%d", &t);
      if(!t) break;
      gto[i].push_back(t);
    }
  }
  for(int i=1; i<=n; i++){
    if(!dfn[i]) tarjan(i);
  }
  // for(int i=1; i<=scccnt; i++){
  //   for(int j=0; j<scc[i].size(); j++){
  //     cout << scc[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  for(int i=1; i<=n; i++){
    for(int j=0; j<gto[i].size(); j++){
      if(sccid[i] == sccid[gto[i][j]]) continue;
      // cout << i << " " << j << endl;
      // cout << sccid[i] << " " << sccid[j] << endl ;
      sccto[sccid[i]].push_back(sccid[gto[i][j]]);
      outdeg[sccid[i]] ++;
      indeg[sccid[gto[i][j]]] ++;
    }
  }
  int indegzero = 0, outdegzero = 0;
  for(int i=1; i<=scccnt; i++){
    if(!indeg[i]) indegzero++;
    if(!outdeg[i]) outdegzero++;
  }
  if(scccnt == 1){
    cout << 1 << endl << 0;
  }else{
    printf("%d\n%d", indegzero, max(indegzero, outdegzero));
  }
  return 0;
}
