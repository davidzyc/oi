#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 1e7+7;

int n, m, p, q;
int a[MAXN] = {0};
int fa[MAXN] = {0};

void init(int x){
  for(int i=1; i<=x; i++){
    fa[i] = i;
  }
  return;
}

int ufind(int x){
    int r=x,cx;
    while(r!=fa[r])  r=fa[r];
    while(x!=r){
        cx=fa[x];fa[x]=r;x=cx;
    }
    return r;
}

void unite(int x, int y){
  int rx = ufind(x), ry = ufind(y);
  fa[rx] = ry;
  return;
}

int main(){
  // freopen("3284.in", "r", stdin);
  // freopen("3284.out", "w", stdout);
  scanf("%d%d%d%d", &n, &m, &p, &q);
  init(n+2);
  int l, r;

  for(int i=m; i>=1; i--){
    l = ((i * p + q) % n) + 1;
    r = ((i * q + p) % n) + 1;
    if(l > r) swap(l, r);
    // l = ufind(l);
    // while(l <= r){
    //   // cout << l << " " << r << endl;
    //   a[l] = i;
    //   unite(max(1,l), min(l+1, n));
    //   l = ufind(l);
    // }
    // cout << endl;
    for(int j=ufind(l); j<=r; j=ufind(l)){
      a[j] = i;
      fa[j] = j+1;
    }
  }

  for(int i=1; i<=n; i++){
    printf("%d\n", a[i]);
  }

  return 0;

}
