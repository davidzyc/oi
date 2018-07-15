#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 4e5+7;

int n, m;
ll b[MAXN];

ll a[MAXN][4];

void debug_out(int x, int l, int r){
  printf("Node %d: %d-%d\t(%d) (%d] [%d) [%d]\n", x, l, r, a[x][0], a[x][1], a[x][2],a[x][3]);
}

void debug(int x, int l, int r){
  if(l == r){
    debug_out(x, l, r);
    return;
  }
  int mid = (l+r)>>1;
  if(l <= mid) debug(x*2, l, mid);
  if(r > mid) debug(x*2+1, mid+1, r);
  debug_out(x, l, r);
  return;
}

void pushup(int x, int l, int r){
  int mid = (l+r) >> 1;
  for(int i=0; i<4; i++) a[x][i] = 0;
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      if((i&1)&((j>>1)&1) == 1) continue;
      int cmb = (i&(1<<1))|(j&1);
      a[x][cmb] = max(a[x][cmb], a[x*2][i] + a[x*2+1][j]);
    }
  }
  return;
}

void build(int x, int l, int r){
  if(l == r){
    a[x][3] = b[l];
    return;
  }
  int mid = (l+r) >> 1;
  if(l <= mid) build(x*2, l, mid);
  if(r > mid) build(x*2+1, mid+1, r);
  pushup(x, l, r);
}

void update(int p, ll val, int x, int l, int r){
  if(l == r && p == l){
    a[x][3] = val;
    return;
  }
  int mid = (l+r) >> 1;
  if(p <= mid){
    update(p, val, x*2, l, mid);
  }else{
    update(p, val, x*2+1, mid+1, r);
  }
  pushup(x, l, r);
}

int main(){

  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++){
    scanf("%lld", &b[i]);
  }
  build(1, 1, n);
  // debug(1, 1, n);
  int opa;
  ll opb;
  ll gcnt = 0, tcnt;
  for(int i=1; i<=m; ++i){
    scanf("%d%lld", &opa, &opb);
    update(opa, opb, 1, 1, n);
    tcnt = 0;
    for(int i=0; i<4; i++){
      tcnt = max(tcnt, a[1][i]);
    }
    // debug(1, 1, n);
    // cout << tcnt << endl;
    gcnt += tcnt;
  }
  printf("%lld\n", gcnt);

  return 0;
}
