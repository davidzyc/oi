#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

const int MAXL = 25;
const int MAXN = 1e5+7;

int n, kth, nl;
vector<int> to[MAXN];
int tstamp = 0;
int dfn[MAXN] = {0}, d[MAXN] = {0};
int fa[MAXN][MAXL];
int fpr[MAXN][MAXL] = {0};
int tdiff[MAXN] = {0};
int gans = 0;

void dfs(int x){
  dfn[x] = ++tstamp;
  for(int i=1; i<=nl; i++){
    fa[x][i] = fa[fa[x][i-1]][i-1];
  }
  for(int i=0; i<to[x].size(); i++){
    int y = to[x][i];
    if(!dfn[y]){
      d[y] = d[x] + 1;
      fa[y][0] = x;
      dfs(y);
    }
  }
  return;
}

int lca(int x, int y){
  if(d[x] < d[y]) swap(x, y);
  for(int i = nl; i >= 0; i--){
    if(d[fa[x][i]] >= d[y]){
      tdiff[x]++;
      fpr[x][i] ++;
      x = fa[x][i];
    }
  }
  if(x == y){
    tdiff[x]++;
    return x;
  }
  for(int i = nl; i >= 0; i--){
    if(fa[x][i] != fa[y][i]){
      tdiff[x]++;
      tdiff[y]++;
      fpr[x][i] ++;
      fpr[y][i] ++;
      x = fa[x][i];
      y = fa[y][i];
    }
  }
  fpr[x][0] ++;
  tdiff[x]++;
  tdiff[y]++;
  tdiff[fa[x][0]]++;
  return fa[x][0];
}

int main(){
  // freopen("3128.txt", "r", stdin);
  int tf, tt;
  scanf("%d%d", &n, &kth);
  nl = (int) log(n) / log(2);
  for(int i=1; i<n; i++){
    scanf("%d%d", &tf, &tt);
    to[tf].push_back(tt);
    to[tt].push_back(tf);
  }
  d[1] = 1;
  dfs(1);
  for(int i=0; i<kth; i++){
    scanf("%d%d", &tf, &tt);
    int lcan = lca(tf, tt);
    // cout << lcan << endl;
    // tdiff[lcan] ++;
    // if(lcan != tf){
    //   tdiff[tf] ++;
    // }
    // if(lcan != tt){
    //   tdiff[tt] ++;
    // }
  }
  // for(int i=1; i<=n; i++){
  //   cout << tdiff[i] << " ";
  // }
  // tree_diff(1);
  // for(int i=1; i<=n; i++){
  //   cout << tdiff[i] << " ";
  // }
  // cout << endl;
  for(int i=nl; i>0; i--){
    for(int j=1; j<=n; j++){
      fpr[j][i-1] += fpr[j][i];
      fpr[fa[j][i-1]][i-1] += fpr[j][i];
      tdiff[fa[j][i-1]] += fpr[j][i];
    }
  }
  for(int i=1; i<=n; i++){
    gans = max(gans, tdiff[i]);
    // cout << tdiff[i] << " ";
  }
  printf("%d", gans);

  return 0;
}
