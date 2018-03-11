#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int INF = 2100000000;
const int MAXN = 5e5+7;

int n, m;
int a[MAXN];
int segsum[MAXN*4] = {0}, lmax[MAXN*4], rmax[MAXN*4], segmax[MAXN*4];

struct segbundle {
  int segsum = 0, segmax = -INF, lmax = -INF, rmax = -INF;
};

void init(int node_id, int l, int r){
  if(l == r){
    segsum[node_id] = a[l];
    lmax[node_id] = a[l];
    rmax[node_id] = a[l];
    segmax[node_id] = a[l];
    return;
  }
  int mid = (l+r)/2;
  init(node_id*2, l, mid);
  init(node_id*2+1, mid+1, r);
  segsum[node_id] = segsum[node_id*2] + segsum[node_id*2+1];
  lmax[node_id] = max(max(lmax[node_id*2], segsum[node_id*2]), segsum[node_id*2]+lmax[node_id*2+1]);
  rmax[node_id] = max(max(rmax[node_id*2+1], segsum[node_id*2+1]), segsum[node_id*2+1]+rmax[node_id*2]);
  segmax[node_id] = max(max(segmax[node_id*2+1], segmax[node_id*2]), rmax[node_id*2]+lmax[node_id*2+1]);
  return;
}

void update(int x, int k, int node_id, int l, int r){
  if(l == r && l == x && r == x){
    segsum[node_id] = k;
    lmax[node_id] = k;
    rmax[node_id] = k;
    segmax[node_id] = k;
    return;
  }
  int mid = (l+r)/2;
  if(x <= mid){
    update(x, k, node_id*2, l, mid);
  }else{
    update(x, k, node_id*2+1, mid+1, r);
  }
  segsum[node_id] = segsum[node_id*2] + segsum[node_id*2+1];
  lmax[node_id] = max(max(lmax[node_id*2], segsum[node_id*2]), segsum[node_id*2]+lmax[node_id*2+1]);
  rmax[node_id] = max(max(rmax[node_id*2+1], segsum[node_id*2+1]), segsum[node_id*2+1]+rmax[node_id*2]);
  segmax[node_id] = max(max(segmax[node_id*2+1], segmax[node_id*2]), rmax[node_id*2]+lmax[node_id*2+1]);
  return;
}

segbundle query(int x, int y, int node_id, int l, int r){
  if(x <= l && y >= r){
    segbundle tbundle;
    tbundle.lmax = lmax[node_id];
    tbundle.rmax = rmax[node_id];
    tbundle.segmax = segmax[node_id];
    tbundle.segsum = segsum[node_id];
    return tbundle;
  }
  int mid = (l+r)/2;
  segbundle lbundle, rbundle, tbundle;
  if(x <= mid) lbundle = query(x, y, node_id*2, l, mid);
  if(y > mid) rbundle = query(x, y, node_id*2+1, mid+1, r);
  tbundle.segsum = lbundle.segsum + rbundle.segsum;
  tbundle.segmax = max(max(lbundle.segmax, rbundle.segmax), lbundle.rmax+rbundle.lmax);
  tbundle.lmax = max(max(lbundle.lmax, lbundle.segsum), lbundle.segsum+rbundle.lmax);
  tbundle.rmax = max(max(rbundle.rmax, rbundle.segsum), rbundle.segsum+lbundle.rmax);
  return tbundle;
}

int main(){
  // freopen("1083.txt", "r", stdin);
  memset(lmax, 0x8f, sizeof(lmax));
  memset(rmax, 0x8f, sizeof(rmax));
  memset(segmax, 0x8f, sizeof(segmax));
  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  init(1, 1, n);
  int optype, x, y;
  for(int mi=0; mi<m; mi++){
    scanf("%d %d %d", &optype, &x, &y);
    if(optype == 1){
      if(x > y){
        int tswap;
        tswap = x;
        x = y;
        y = tswap;
      }
      printf("%d\n", query(x, y, 1, 1, n).segmax);
    }else if(optype == 2){
      update(x, y, 1, 1, n);
    }
  }
  return 0;
}
