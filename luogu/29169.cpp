#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 5007;

int n;
ll r;
ll x[MAXN], y[MAXN];
int fa[MAXN];

int getfa(int i){
  return i == fa[i] ? i : fa[i] = getfa(fa[i]);
}

int main(){
  scanf("%lld%d", &r, &n);
  for(int i=1; i<=n; i++){
    fa[i] = i;
  }
  for(int i=1; i<=n; i++){
    scanf("%lld%lld", &x[i], &y[i]);
    for(int j=1; j<i; j++){
      // cout << i << " " << j << endl;
      if(((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])) <= 4*r*r){
        fa[getfa(j)] = getfa(i);
      }
    }
  }
  for(int i=1; i<=n; i++){
    getfa(i);
  }
  // for(int i=1; i<=n; i++) cout << fa[i] << " ";
  sort(fa+1, fa+1+n);
  int ans = unique(fa+1, fa+n+1) - fa - 1;
  printf("%d", ans);

  return 0;
}
