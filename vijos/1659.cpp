#include<cstdio>
#include<iostream>

using namespace std;

typedef long long LL;
const int INF = 2100000000;
const int MAXN = 1e5+7;
int n, m;
LL a[MAXN] = {0};
LL dat[MAXN*4] = {0}, datad[MAXN*4] = {0};

void init(int node_id, int l, int r){
  if(l == r){
    dat[node_id] = a[l];
  }else{
    int mid = (l+r)/2;
    init(node_id*2, l, mid);
    init(node_id*2+1, mid+1, r);
    dat[node_id] = max(dat[node_id*2], dat[node_id*2+1]);
  }
}

void spread(int node_id, int l, int r){
  if(datad[node_id] != 0){
    int mid = (l+r)/2;
    dat[node_id*2] += datad[node_id];
    dat[node_id*2+1] += datad[node_id];
    datad[node_id*2] += datad[node_id];
    datad[node_id*2+1] += datad[node_id];
    datad[node_id] = 0;
  }
}

void update(int x, int y, LL p, int node_id, int l, int r){
  if(x <= l && y >= r){
    dat[node_id] += p;
    datad[node_id] += p;
    return;
  }
  spread(node_id, l, r);
  int mid = (l+r)/2;
  if(x <= mid) update(x, y, p, node_id*2, l, mid);
  if(y > mid) update(x, y, p, node_id*2+1, mid+1, r);
  dat[node_id] = max(dat[node_id*2], dat[node_id*2+1]);
  return;
}

LL query(int x, int y, int node_id, int l, int r){
  if(x <= l && y >= r){
    return dat[node_id];
  }
  spread(node_id, l, r);
  int mid = (l+r)/2;
  LL tsum = -INF;
  if(x <= mid) tsum = max(tsum, query(x, y, node_id*2, l, mid));
  if(y > mid) tsum = max(tsum, query(x, y, node_id*2+1, mid+1, r));
  return tsum;
}

int main(){
  cin >> n;
  for(int i=1; i<=n; i++){
    scanf("%lld", &a[i]);
  }
  init(1, 1, n);
  cin >> m;
  int optype, x, y;
  LL k;
  for(int mi=0; mi<m; mi++){
    scanf("%d", &optype);
    if(optype == 1){
      scanf("%d %d %lld", &x, &y, &k);
      update(x, y, k, 1, 1, n);
    }else if(optype == 2){
      scanf("%d %d", &x, &y);
      printf("%lld\n", query(x, y, 1, 1, n));
    }
  }

  return 0;
}
