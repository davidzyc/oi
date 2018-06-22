#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int MAXL = 20;
const int MAXN = 1e4+7;

int nt, n, m, q;
int nday[MAXN];
int nd[MAXN];
int dat[MAXN];

void build(int nid, int l, int r){
  if(l == r){
    dat[nid] = nd[l];
    return;
  }
  int mid = (l+r) / 2;
  build(nid*2, l, mid);
  build(nid*2+1, mid+1, r);
  dat[nid] = dat[nid*2] + dat[nid*2+1];
  return;
}

int query(int x, int y, int nid, int l, int r){
  if(x <= l && y >= r){
    // cout << nid << " " << dat[nid] << endl;
    return dat[nid];
  }
  int mid = (l+r) / 2;
  int ans = 0;
  if(x <= mid){
    ans += query(x, y, nid*2, l, mid);
  }
  if(y > mid){
    ans += query(x, y, nid*2+1, mid+1, r);
  }
  return ans;
}

int main(){
  int tset;
  scanf("%d", &tset);
  while(tset--){
    memset(dat, 0, sizeof(dat));
    memset(nd, 0, sizeof(nd));
    memset(nday, 0, sizeof(nday));

    scanf("%d%d", &nt, &q);
    n = nt + 1;

    for(int i=1; i<=nt; i++){
      scanf("%d", &nday[i]);
    }
    nd[1] = nday[1] - 1;
    for(int i=2; i<=nt; i++){
      nd[i] = nday[i] - nday[i-1] - 1;
    }
    nd[nt+1] = 100 - nday[nt];
    // for(int i=1; i<=n; i++){
    //   cout << nd[i] << " ";
    // }
    // cout << endl;
    build(1, 1, n);

    int qb, lb, ub, tans;
    int gans = 0;
    q = min(q, nt);
    for(int i=1; i<=n-q; i++){
      lb = i;
      ub = i + q;
      tans = query(lb, ub, 1, 1, n);
      // cout << lb << " " << ub << " " << tans << " | " ;
      gans = max(gans, tans);
    }
    printf("%d\n", gans + q);
  }

  return 0;
}
