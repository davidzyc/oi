#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

const int MAXN = 1e5+7;

int n, m;
vector<int> to[MAXN];
// segment tree
int dat[MAXN*4] = {0};
// tree cut
int sonsize[MAXN], hson[MAXN], fa[MAXN], dep[MAXN];
int dfncnt = 0, dfn[MAXN], dfid[MAXN], top[MAXN];

int query(int x, int y, int node_id, int l, int r){
  if(x <= l && y >= r){
    return dat[node_id];
  }
  int mid = (l+r) / 2;
  int tdat = 0;
  if(x <= mid){
    tdat = max(query(x, y, node_id*2, l, mid), tdat);
  }
  if(y > mid){
    tdat = max(query(x, y, node_id*2+1, mid+1, r), tdat);
  }
  return tdat;
}

void update(int x, int val, int node_id, int l, int r){
  if(l == x && r == x){
    dat[node_id] = val;
    return;
  }
  int mid = (l+r) / 2;
  if(x <= mid){
    update(x, val, node_id*2, l, mid);
  }else{
    update(x, val, node_id*2+1, mid+1, r);
  }
  dat[node_id] = max(dat[node_id*2], dat[node_id*2+1]);
  return;
}

int st_query(int x, int y){
  return query(x, y, 1, 1, n);
}

void st_update(int x, int val){
  update(x, val, 1, 1, n);
  return;
}

void predfs(int x){
  int maxson = 0;
  sonsize[x] = 1;
  for(int i=0; i<to[x].size(); i++){
    int y = to[x][i];
    if(fa[x] == y) continue;
    fa[y] = x;
    dep[y] = dep[x] + 1;
    predfs(y);
    sonsize[x] += sonsize[y];
    if(sonsize[y] > maxson){
      maxson = sonsize[y];
      hson[x] = y;
    }
  }
  return;
}

void cutdfs(int x, int top_id){
  dfn[x] = ++dfncnt;
  dfid[dfncnt] = x;
  top[x] = top_id;
  if(!hson[x]) return;
  cutdfs(hson[x], top_id);
  for(int i=0; i<to[x].size(); i++){
    int y = to[x][i];
    if(fa[x] == y || hson[x] == y) continue;
    cutdfs(y, y);
  }
  return;
}

int tpath_query(int x, int y){
  int tdat = 0;
  while(top[x] != top[y]){
    if(dep[top[x]] < dep[top[y]]) swap(x, y);
    tdat = max(st_query(dfn[top[x]], dfn[x]), tdat);
    x = fa[top[x]];
  }
  if(dep[x] < dep[y]) swap(x, y);
  tdat = max(st_query(dfn[y], dfn[x]), tdat);
  return tdat;
}

int main(){
  // freopen("4092.txt", "r", stdin);
  memset(dat, 0, sizeof(dat));
  int tf, tt;
  scanf("%d%d", &n, &m);
  for(int i=1; i<n; i++){
    scanf("%d%d", &tf, &tt);
    to[tf].push_back(tt);
    to[tt].push_back(tf);
  }
  dep[1] = 1;
  predfs(1);
  cutdfs(1, 1);
  st_update(dfn[1], 1);
  char opc[2];
  int optype, opx;
  for(int opi=0; opi<m; opi++){
    scanf("%s%d", opc, &opx);
    optype = opc[0] == 'C' ? 0 : 1;
    // cout << optype << " " << opx << endl;
    // for(int i=1; i<=n; i++){
    //   cout << st_query(dfn[i], dfn[i]) << " ";
    // }
    // cout << endl;
    switch(optype){
      case 0:
        st_update(dfn[opx], opx);
        break;
      case 1:
        printf("%d\n", tpath_query(1, opx));
        break;
    }
  }

  return 0;
}
