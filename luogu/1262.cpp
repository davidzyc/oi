#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 3005;
const int INF = 0x3f3f3f3f;

int n, p, m;
int bribe[MAXN];
vector<int> to[MAXN];
//SCC
int dfncnt = 0;
int low[MAXN], dfn[MAXN];
int sta[MAXN], ins[MAXN], stah;
int sccb[MAXN];
int sccid[MAXN];
int scccnt = 0;
vector<int> scc[MAXN];
vector<int> sccto[MAXN];
int sccindeg[MAXN];

void tarjan(int x){
  low[x] = dfn[x] = ++dfncnt;
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
    int y;
    scccnt++;
    do{
      y = sta[--stah];
      ins[y] = 0;
      sccid[y] = scccnt;
      scc[scccnt].push_back(y);
      sccb[scccnt] = min(sccb[scccnt], bribe[y]);
    }while(x != y);
  }
}

int main(){
  // freopen("1262.txt", "r", stdin);
  scanf("%d%d", &n, &p);
  memset(bribe, 0x3f, sizeof(bribe));
  memset(sccb, 0x3f, sizeof(sccb));
  int tn, tp;
  for(int i=0; i<p; i++){
    scanf("%d%d", &tn, &tp);
    bribe[tn] = tp;
  }
  scanf("%d", &m);
  int tf, tt;
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
        sccto[sccid[i]].push_back(sccid[y]);
      }
    }
  }
  for(int i=1; i<=scccnt; i++){
    for(int j=0; j<sccto[i].size(); j++){
      int y = sccto[i][j];
      sccindeg[y] ++;
    }
  }
  bool canbribe = true;
  int gbribe = 0, mincannot = INF;
  for(int i=1; i<=scccnt; i++){
    if(!sccindeg[i]){
      if(sccb[i] < INF){
        gbribe += sccb[i];
      }else{
        canbribe = false;
        for(int j=0; j<scc[i].size(); j++){
          mincannot = min(mincannot, scc[i][j]);
        }
      }
    }
  }
  if(canbribe){
    printf("YES\n%d", gbribe);
  }else{
    // sort(cannotbribe.begin(), cannotbribe.end());
    printf("NO\n%d", mincannot);
  }
  return 0;
}
