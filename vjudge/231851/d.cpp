#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 1e6+7;
const int INF = 0x7f7f7f7f;

int n;
int initdat[MAXN];
int dat[MAXN*4];

void build(int nid, int l, int r){
  if(l == r){
    dat[nid] = initdat[l];
    return;
  }
  int mid = (l+r) / 2;
  build(nid*2, l, mid);
  build(nid*2+1, mid+1, r);
  dat[nid] = min(dat[nid*2], dat[nid*2+1]);
  return;
}

int query(int x, int y, int nid, int l, int r){
  if(x <= l && y >= r){
    return dat[nid];
  }
  int mid = (l+r) / 2;
  int ans = INF;
  if(x <= mid){
    ans = min(ans, query(x, y, nid*2, l, mid));
  }
  if(y > mid){
    ans = min(ans, query(x, y, nid*2+1, mid+1, r));
  }
  return ans;
}

void update(int x, int val, int nid, int l, int r){
  if(l == r){
    dat[nid] = val;
    return;
  }
  int mid = (l+r) / 2;
  if(x <= mid){
    update(x, val, nid*2, l, mid);
  }else if(x > mid){
    update(x, val, nid*2+1, mid+1, r);
  }
  dat[nid] = min(dat[nid*2], dat[nid*2+1]);
  return;
}

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &initdat[i]);
  }
  build(1, 1, n);
  int q, op, opx, opy;
  scanf("%d", &q);
  for(int i=0; i<q; i++){
    scanf("%d%d%d", &op, &opx, &opy);
    if(op == 0){
      printf("%d\n", query(opx, opy, 1, 1, n));
    }else if(op == 1){
      update(opx, opy, 1, 1, n);
    }
  }


  return 0;
}
