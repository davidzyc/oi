#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+7;

int n, m;
vector<int> to[MAXN];
// segment tree
ll rawdat[MAXN] = {0};
ll dat[MAXN*4], datad[MAXN*4];
// tree cut
int sonsize[MAXN], hson[MAXN], fa[MAXN], dep[MAXN];
int dfncnt = 0, dfn[MAXN], dfid[MAXN], top[MAXN];

void init(int node_id, int l, int r){
  if(l == r){
    dat[node_id] = rawdat[dfid[l]];
    return;
  }
  int mid = (l+r)/2;
  init(node_id*2, l, mid);
  init(node_id*2+1, mid+1, r);
  dat[node_id] = dat[node_id*2] + dat[node_id*2+1];
  return;
}

void pushdown(int node_id, int l, int r){
  if(datad[node_id]){
    int mid = (l+r) / 2;
    datad[node_id*2] += datad[node_id];
    datad[node_id*2+1] += datad[node_id];
    dat[node_id*2] += datad[node_id] * (mid - l + 1);
    dat[node_id*2+1] += datad[node_id] * (r - mid);
    datad[node_id] = 0;
  }
  return;
}

ll query(int x, int y, int node_id, int l, int r){
  if(x <= l && y >= r){
    return dat[node_id];
  }
  pushdown(node_id, l, r);
  int mid = (l+r) / 2;
  ll tdat = 0;
  if(x <= mid){
    tdat += query(x, y, node_id*2, l, mid);
  }
  if(y > mid){
    tdat += query(x, y, node_id*2+1, mid+1, r);
  }
  return tdat;
}

void update(int x, int y, ll val, int node_id, int l, int r){
  if(x <= l && y >= r){
    datad[node_id] += val;
    dat[node_id] += val * (r - l + 1);
    return;
  }
  pushdown(node_id, l, r);
  int mid = (l+r) / 2;
  if(x <= mid){
    update(x, y, val, node_id*2, l, mid);
  }
  if(y > mid){
    update(x, y, val, node_id*2+1, mid+1, r);
  }
  dat[node_id] = dat[node_id*2] + dat[node_id*2+1];
  return;
}

ll st_query(int x, ll y){
  return query(x, y, 1, 1, n);
}

void st_update(int x, int y, ll val){
  update(x, y, val, 1, 1, n);
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

ll tpath_query(int x, int y){
  ll tdat = 0;
  // cout<< endl;
  while(top[x] != top[y]){
    if(dep[top[x]] < dep[top[y]]) swap(x, y);
    // cout << top[x] << " -> " << x << " : " << st_query(dfn[top[x]], dfn[x]) << " | ";
    tdat += st_query(dfn[top[x]], dfn[x]);
    x = fa[top[x]];
  }
  if(dep[x] < dep[y]) swap(x, y);
  tdat += st_query(dfn[y], dfn[x]);
  // cout << x << " -> " << y << " : " << st_query(dfn[y], dfn[x]) << endl;
  return tdat;
}

void tpath_update(int x, int y, ll val){
  while(top[x] != top[y]){
    if(dep[top[x]] < dep[top[y]]) swap(x, y);
    st_update(dfn[top[x]], dfn[x], val);
    x = fa[top[x]];
  }
  if(dep[x] < dep[y]) swap(x, y);
  st_update(dfn[y], dfn[x], val);
  return;
}

ll tson_query(int x){
  return st_query(dfn[x], dfn[x] + sonsize[x] - 1);
}

void tson_update(int x, ll val){
  st_update(dfn[x], dfn[x] + sonsize[x] - 1, val);
  return;
}

int main(){
  memset(dat, 0, sizeof(dat));
  memset(datad, 0, sizeof(datad));
  // freopen("3178.txt", "r", stdin);
  int tf, tt;
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++){
    scanf("%lld", &rawdat[i]);
  }
  for(int i=1; i<n; i++){
    scanf("%d%d", &tf, &tt);
    to[tf].push_back(tt);
    to[tt].push_back(tf);
  }
  dep[1] = 1;
  predfs(1);
  cutdfs(1, 1);
  init(1, 1, n);
  int optype, opx;
  ll opy;
  for(int opi=0; opi<m; opi++){
    scanf("%d", &optype);
    // for(int i=1; i<=n; i++){
    //   cout << st_query(dfn[i], dfn[i]) << " ";
    // }
    // cout << endl;
    // cout << st_query(dfn[2], dfn[2]) << endl;
    switch(optype){
      case 1:
        scanf("%d%lld", &opx, &opy);
        // tpath_update(opx, opx, opy);
        // cout << st_query(dfn[opx], dfn[opx]) << " - ";
        st_update(dfn[opx], dfn[opx], opy);
        // cout << st_query(dfn[opx], dfn[opx]) << endl;
        break;
      case 2:
        scanf("%d%lld", &opx, &opy);
        tson_update(opx, opy);
        break;
      case 3:
        scanf("%d", &opx);
        printf("%lld\n", tpath_query(1, opx));
        break;
    }
  }

  return 0;
}
