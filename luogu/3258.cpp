#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;
const int MAXL = 20;
const int MAXN = 3e5+7;

int n, nl;
int tvorder[MAXN];
int vorder[MAXN];
vector<int> to[MAXN];
int fa[MAXN][MAXL];
ll fv[MAXN][MAXL] = {0};
ll nodev[MAXN] = {0};
int vdep[MAXN], dfn[MAXN];
int dcnt = 0;

int read(){
  char c = getchar();
  int num = 0;
  for(;!isdigit(c);c=getchar());
  for(;isdigit(c);c=getchar()){
    num = num*10+c-'0';
  }
  return num;
}

void dfs(int x){
  dfn[x] = ++dcnt;
  for(int i=1; i<=nl; i++){
    fa[x][i] = fa[fa[x][i-1]][i-1];
  }
  for(int i=0; i<to[x].size(); i++){
    int y = to[x][i];
    if(dfn[y]) continue;
    vdep[y] = vdep[x] + 1;
    fa[y][0] = x;
    dfs(y);
  }
  return;
}

int lca(int x, int y){
  if(vdep[x] < vdep[y]) swap(x, y);
  for(int i=nl; i>=0; i--){
    if(vdep[fa[x][i]] >= vdep[y]){
      nodev[x] ++;
      fv[x][i] ++;
      x = fa[x][i];
    }
  }
  if(x == y){
    nodev[x] ++;
    return x;
  }
  for(int i=nl; i>=0; i--){
    if(fa[x][i] != fa[y][i]){
      nodev[x] ++;
      nodev[y] ++;
      fv[x][i] ++;
      fv[y][i] ++;
      x = fa[x][i];
      y = fa[y][i];
    }
  }
  nodev[x] ++;
  nodev[fa[x][0]] ++;
  nodev[y] ++;
  return fa[x][0];
}

int main(){
  // freopen("3258.txt", "r", stdin);
  int tf, tt;
  scanf("%d", &n);
  int vn = 0;
  for(int i=1; i<=n; i++){
    // scanf("%d", &tvorder[i]);
    tvorder[i] = read();
    if(tvorder[i] != vorder[vn]){
      vorder[++vn] = tvorder[i];
    }
  }
  for(int i=1; i<n; i++){
    // scanf("%d%d", &tf, &tt);
    tf = read();
    tt = read();
    to[tf].push_back(tt);
    to[tt].push_back(tf);
  }
  nl = (int) log(n) / log(2);
  ++nl;
  vdep[1] = 1;
  dfs(1);
  for(int i=1; i<vn; i++){
    int lcan = lca(vorder[i], vorder[i+1]);
    nodev[vorder[i+1]]--;
    // cout << endl;
    // cout << lcan << endl;
  }
  for(int i=nl; i>0; i--){
    for(int j=1; j<=n; j++){
      fv[j][i-1] += fv[j][i];
      fv[fa[j][i-1]][i-1] += fv[j][i];
      nodev[fa[j][i-1]] += fv[j][i];
    }
  }
  // for(int i=2; i<=n; i++){
  //   nodev[vorder[i]] --;
  // }
  if(vn == 1){
    nodev[vorder[1]]++;
  }
  for(int i=1; i<=n; i++){
    printf("%d\n", nodev[i]);
  }

  return 0;
}
