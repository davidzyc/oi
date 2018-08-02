#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int MAXN = 1e5+7;

int n, m, k;
int val[MAXN];
int fa[MAXN];
int v[MAXN];
vector<int> blk[MAXN];

int getfa(int x){
  return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}

int main(){
  // freopen("game.in", "r", stdin);
  // freopen("game.out", "w", stdout);
  int f, t;
  scanf("%d%d%d", &n, &m, &k);
  for(int i=1; i<=n; ++i){
    fa[i] = i;
    scanf("%d", &val[i]);
  }
  for(int i=0; i<k; i++){
    scanf("%d%d", &f, &t);
    fa[getfa(t)] = getfa(f);
  }
  for(int i=1; i<=n; i++){
    getfa(i);
  }
  for(int i=1; i<=n; i++){
    blk[fa[i]].push_back(i);
  }
  int gans = 0;
  for(int i=1; i<=n; i++){
    int tot = blk[i].size();
    if(tot <= 1) continue;
    int mcnt = 0;
    memset(v, 0, sizeof(v));
    for(int j=0; j<tot; j++){
      v[val[blk[i][j]]]++;
      mcnt = max(mcnt, v[val[blk[i][j]]]);
    }
    gans += (tot - mcnt);
  }

  printf("%d", gans);


  return 0;
}
