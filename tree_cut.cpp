#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 1e5+7;

int n, m, r, gmod;
int a[MAXN];
vector<int> to[MAXN];

// segment tree
int tsum[MAXN*4] = {0}, lazytag[MAXN*4] = {0};

// tree cut
int fa[MAXN], hson[MAXN], sonsize[MAXN], dep[MAXN];
int dfn[MAXN], dfid[MAXN], top[MAXN], dfncnt = 0;

void init(int node_id, int l, int r){
  if(l == r){
    tsum[node_id] = a[dfid[l]];
  }else{
    int mid = (l+r)/2;
    init(node_id*2, l, mid);
    init(node_id*2+1, mid+1, r);
    tsum[node_id] = tsum[node_id*2] % gmod + tsum[node_id*2+1] % gmod;
    tsum[node_id] %= gmod;
  }
}

void spread(int node_id, int l, int r){
  if(lazytag[node_id] != 0){
    int mid = (l+r)/2;
    tsum[node_id*2] += (mid-l+1) * lazytag[node_id];
    tsum[node_id*2+1] += (r-mid) *lazytag[node_id];
    tsum[node_id*2] %= gmod;
    tsum[node_id*2+1] %= gmod;
    lazytag[node_id*2] += lazytag[node_id];
    lazytag[node_id*2+1] += lazytag[node_id];
    lazytag[node_id*2] %= gmod;
    lazytag[node_id*2+1] %= gmod;
    lazytag[node_id] = 0;
  }
}

void update(int x, int y, int p, int node_id, int l, int r){
  if(x <= l && y >= r){
    tsum[node_id] += ((r-l+1)*p)%gmod;
    tsum[node_id] %= gmod;
    lazytag[node_id] += p;
    lazytag[node_id] %= gmod;
    return;
  }
  spread(node_id, l, r);
  int mid = (l+r)/2;
  if(x <= mid) update(x, y, p, node_id*2, l, mid);
  if(y > mid) update(x, y, p, node_id*2+1, mid+1, r);
  tsum[node_id] = tsum[node_id*2] + tsum[node_id*2+1];
  tsum[node_id] %= gmod;
  return;
}

int query(int x, int y, int node_id, int l, int r){
  if(x <= l && y >= r){
    return tsum[node_id];
  }
  spread(node_id, l, r);
  int mid = (l+r)/2;
  int tsum = 0;
  if(x <= mid) tsum += query(x, y, node_id*2, l, mid);
  if(y > mid) tsum += query(x, y, node_id*2+1, mid+1, r);
  return tsum % gmod;
}

void predfs(int x){
  int tmaxson = 0, maxsonid = 0;
  sonsize[x] = 1;
  for(int i=0; i<to[x].size(); i++){
    int y = to[x][i];
    if(fa[x] == y) continue;
    fa[y] = x;
    dep[y] = dep[x] + 1;
    predfs(y);
    if(sonsize[y] > tmaxson){
      tmaxson = sonsize[y];
      maxsonid = y;
    }
    sonsize[x] += sonsize[y];
  }
  hson[x] = maxsonid;
  return;
}

void cutdfs(int x, int ttop){
  ++dfncnt;
  dfn[x] = dfncnt;
  dfid[dfncnt] = x;
  top[x] = ttop;
  if(!hson[x]) return;
  cutdfs(hson[x], ttop);
  for(int i=0; i<to[x].size(); i++){
    int y = to[x][i];
    if(y == fa[x] || y == hson[x]) continue;
    cutdfs(y, y);
  }
  return;
}

int tree_query(int x, int y){
  int tans = 0;
  while(top[x] != top[y]){
    if(dep[top[x]] < dep[top[y]]) swap(x, y);
    tans += query(dfn[top[x]], dfn[x], 1, 1, n);
    tans %= gmod;
    x = fa[top[x]];
  }
  if(dep[x] < dep[y]) swap(x, y);
  tans += query(dfn[y], dfn[x], 1, 1, n);
  return tans % gmod;
}

void tree_update(int x, int y, int val){
  while(top[x] != top[y]){
    if(dep[top[x]] < dep[top[y]]) swap(x, y);
    update(dfn[top[x]], dfn[x], val, 1, 1, n);
    x = fa[top[x]];
  }
  if(dep[x] < dep[y]) swap(x, y);
  update(dfn[y], dfn[x], val, 1, 1, n);
  return;
}

int son_query(int x){
  // cout << "Q Fa " << dfn[x] << " size " <<dfn[x]+sonsize[x]-1 << endl;
  return query(dfn[x], dfn[x]+sonsize[x]-1, 1, 1, n) % gmod;
}

void son_update(int x, int val){
  // cout << "UPD From " << x << " size " <<dfn[x]+sonsize[x]-1 << endl;
  update(dfn[x], dfn[x]+sonsize[x]-1, val, 1, 1, n);
}

int main(){
  // freopen("tree_cut.txt", "r", stdin);
  int tf, tt;
  scanf("%d%d%d%d", &n, &m, &r, &gmod);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  // init(1, n, 1);
  for(int i=1; i<n; i++){
    scanf("%d%d", &tf, &tt);
    to[tf].push_back(tt);
    to[tt].push_back(tf);
  }
  dep[r] = 1;
  predfs(r);
  cutdfs(r, r);
  init(1, 1, n);
  // uptsume(1, n, 1, 1, 1, n);
  // cout << query(4, n, 1, 1, n) << endl;
  // for(int i=1; i<=n; i++) cout << dfid[i] << " ";
  int optype, opx, opy, opz;
  for(int opi=0; opi<m; opi++){
    // for(int i=1; i<=n; i++){
    //   cout << query(dfn[i], dfn[i], 1, 1, n) << " ";
    // }
    // cout << endl;
    scanf("%d", &optype);
    switch(optype){
      case 1:
        scanf("%d%d%d", &opx, &opy, &opz);
        tree_update(opx, opy, opz);
      break;
      case 2:
        scanf("%d%d", &opx, &opy);
        printf("%d\n", tree_query(opx, opy) % gmod);
      break;
      case 3:
        scanf("%d%d", &opx, &opz);
        son_update(opx, opz);
      break;
      case 4:
        scanf("%d", &opx);
        printf("%d\n", son_query(opx) % gmod);
      break;
    }
  }

  return 0;
}
