#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int MAXN = 1e4+7;
const int MAXM = 1e5+7;

int n, m;
vector<int> to[MAXN];
// SCC
int dfn[MAXN], low[MAXN], dfncnt = 0;
int scccnt = 0, sccid[MAXN];
int sta[MAXN], stah = 0, ins[MAXN];
vector<int> scc[MAXN];
vector<int> sccto[MAXN];
int d[MAXN], sccd[MAXN];
int sccindeg[MAXN], sccoutdeg[MAXN];
queue<int> q;

void tarjan(int x){
  dfn[x] = low[x] = ++dfncnt;
  sta[stah++] = x;
  ins[x] = 1;
  for(int i=0; i<to[x].size(); i++){
    int y = to[x][i];
    if(!dfn[y]){
      tarjan(y);
      low[x] = min(low[x], low[y]);
    }else if(ins[y]){
      low[x] = min(low[x], dfn[y]);
    }
  }
  if(low[x] == dfn[x]){
    int cnt = 0;
    int y;
    do{
      y = sta[--stah];
      scc[scccnt].push_back(y);
      sccid[y] = scccnt;
      ins[y] = 0;
      ++cnt;
    }while(x != y);
    d[scccnt] = cnt;
    sccd[scccnt] = cnt;
    scccnt++;
  }
  return;
}

int main(){
  // freopen("2341.txt", "r", stdin);
  int tf, tt;
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++){
    scanf("%d%d", &tf, &tt);
    to[tf].push_back(tt);
  }
  for(int i=1; i<=n; i++){
    if(!dfn[i]){
      tarjan(i);
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=0; j<to[i].size(); j++){
      int y = to[i][j];
      if(sccid[i] != sccid[y]){
        // cout << i << " " << y << endl;
        sccto[sccid[i]].push_back(sccid[y]);
        sccindeg[sccid[y]]++;
        sccoutdeg[sccid[i]]++;
      }
    }
  }
  int outdegcnt = 0, lastscc;
  for(int i=0; i<scccnt; i++){
    if(!sccoutdeg[i]){
      ++outdegcnt;
      lastscc = i;
    }
  }
  if(outdegcnt == 1){
    printf("%d", sccd[lastscc]);
  }else{
    printf("%d", 0);
  }
  
  return 0;
}
