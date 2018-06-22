#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 4e4+5;

int n, ann;
int s[MAXN], e[MAXN];
int an[MAXN];
int dat[MAXN*4], lazytag[MAXN*4];
int p[MAXN];
int gans;

void init(){
  n = 0;
  ann = 0;
  memset(s, 0, sizeof(s));
  memset(e, 0, sizeof(e));
  memset(an, 0, sizeof(an));
  memset(dat, 0, sizeof(dat));
  memset(lazytag, 0, sizeof(lazytag));
  memset(p, 0, sizeof(p));
  gans = 0;
  return;
}

void pushdown(int nid){
  if(lazytag[nid]){
    dat[nid*2] = dat[nid];
    dat[nid*2+1] = dat[nid];
    lazytag[nid*2] = 1;
    lazytag[nid*2+1] = 1;
    dat[nid] = 0;
    lazytag[nid] = 0;
  }
  return;
}

void update(int x, int y, int p, int nid, int l, int r){
  if(x <= l && y >= r){
    dat[nid] = p;
    lazytag[nid] = 1;
    return;
  }
  pushdown(nid);
  int mid = (l+r)/2;
  if(x <= mid){
    update(x, y, p, nid*2, l, mid);
  }
  if(y > mid){
    update(x, y, p, nid*2+1, mid+1, r);
  }
  return;
}

void query(int nid, int l, int r){
  if(l == r){
    p[l-1] = dat[nid];
    return;
  }
  pushdown(nid);
  int mid = (l+r)/2;
  query(nid*2, l, mid);
  query(nid*2+1, mid+1, r);
  return;
}

int main(){
  int cn;
  scanf("%d", &cn);
  while(cn--){
    init();
    scanf("%d", &n);
    for(int i=0; i<n; i++){
      scanf("%d%d", &s[i], &e[i]);
      an[i*2] = s[i];
      an[i*2+1] = e[i];
    }
    sort(an, an+2*n);
    ann = unique(an, an+2*n) - an;
    for(int i=0; i<n; i++){
      s[i] = lower_bound(an, an+ann, s[i]) - an + 1;
      e[i] = lower_bound(an, an+ann, e[i]) - an + 1;
      // cout << s[i] << " " << e[i] << endl;
      update(s[i], e[i], i+1, 1, 1, ann);
    }
    query(1, 1, ann);
    // for(int i=0; i<ann; i++){
    //   cout << p[i] << " " ;
    // }
    // cout << endl;
    sort(p, p+ann);
    gans = unique(p, p+ann) - p;
    if(p[0] == 0) gans--;
    printf("%d\n", gans);
  }
  return 0;
}
