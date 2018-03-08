#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 2100000000;
const int MAXN = 50007;
int n, q;
int a[MAXN] = {0};
int datmin[MAXN*4], datmax[MAXN*4] = {0};

void init(int node_id, int l, int r){
  if(l == r){
    datmin[node_id] = a[l];
    datmax[node_id] = a[l];
  }else{
    int mid = (l+r)/2;
    init(node_id*2, l, mid);
    init(node_id*2+1, mid+1, r);
    datmax[node_id] = max(datmax[node_id*2], datmax[node_id*2+1]);
    datmin[node_id] = min(datmin[node_id*2], datmin[node_id*2+1]);
    // cout << l << " " << r << " " << datmin[node_id] << endl;
  }
}

int query_max(int x, int y, int node_id, int l, int r){
  if(x <= l && y >= r){
    return datmax[node_id];
  }else{
    int mid = (l+r)/2;
    int tmax = 0;
    if(x <= mid) tmax = max(tmax, query_max(x, y, node_id*2, l, mid));
    if(y > mid) tmax = max(tmax, query_max(x, y, node_id*2+1, mid+1, r));
    return tmax;
  }
}

int query_min(int x, int y, int node_id, int l, int r){
  if(x <= l && y >= r){
    return datmin[node_id];
  }else{
    int mid = (l+r)/2;
    int tmin = INF;
    if(x <= mid) tmin = min(tmin, query_min(x, y, node_id*2, l, mid));
    if(y > mid) tmin = min(tmin, query_min(x, y, node_id*2+1, mid+1, r));
    return tmin;
  }
}

int main(){
  // freopen("2880.txt", "r", stdin);
  // fill(datmin, datmin+n*4, INF);
  memset(datmin, 0x3f, sizeof datmin);
  scanf("%d %d", &n, &q);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  init(1, 1, n);
  int xx, yy;
  for(int qi=0; qi<q; qi++){
    scanf("%d %d", &xx, &yy);
    printf("%d\n", query_max(xx, yy, 1, 1, n) - query_min(xx, yy, 1, 1, n));
  }
  return 0;
}
