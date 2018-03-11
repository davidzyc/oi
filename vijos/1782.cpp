#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 1e6+7;
const int INF = 2100000000;

int n, m;
int a[MAXN];
int dat[MAXN*4], lazyop[MAXN*4] = {0};

void init(int node_id, int l, int r){
  if(l == r){
    dat[node_id] = a[l];
    return;
  }
  int mid = (l+r)/2;
  init(node_id*2, l, mid);
  init(node_id*2+1, mid+1, r);
  dat[node_id] = min(dat[node_id*2], dat[node_id*2+1]);
  return;
}

void spread(int node_id, int l, int r){
  if(lazyop[node_id] != 0){
    lazyop[node_id*2] += lazyop[node_id];
    lazyop[node_id*2+1] += lazyop[node_id];
    dat[node_id*2] -= lazyop[node_id];
    dat[node_id*2+1] -= lazyop[node_id];
    lazyop[node_id] = 0;
  }
  return;
}

void update(int x, int y, int p, int node_id, int l, int r){
  if(x <= l && y >= r){
    dat[node_id] -= p;
    lazyop[node_id] += p;
    return;
  }
  spread(node_id, l, r);
  int mid = (l+r)/2;
  if(x <= mid) update(x, y, p, node_id*2, l, mid);
  if(y > mid) update(x, y, p, node_id*2+1, mid+1, r);
  dat[node_id] = min(dat[node_id*2], dat[node_id*2+1]);
  return;
}

int query(int x, int y, int node_id, int l, int r){
  if(x <= l && y >= r){
    return dat[node_id];
  }
  spread(node_id, l, r);
  int mid = (l+r)/2, tmin = INF;
  if(x <= mid) tmin = min(tmin, query(x, y, node_id*2, l, mid));
  if(y > mid) tmin = min(tmin, query(x, y, node_id*2+1, mid+1, r));
  return tmin;
}

int main(){
  freopen("1782.txt", "r", stdin);
  memset(dat, 0x3f, sizeof(dat));
  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  init(1, 1, n);
  // for(int i=1; i<=10; i++){
  //   cout << dat[i] << " ";
  // }
  int x, y, p;
  for(int mi=1; mi<=m; mi++){
    scanf("%d %d %d", &p, &x, &y);
    // cout << query(x, y, 1, 1, n) << endl;
    if(query(x, y, 1, 1, n) < p){
      printf("%d\n%d", -1, mi);
      return 0;
    }
    update(x, y, p, 1, 1, n);
  }
  printf("%d\n", 0);
  return 0;
}
