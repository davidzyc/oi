#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2007;

int n;
ll x1, y1, x2, y2;
ll xi[MAXN], yi[MAXN];
ll d1[MAXN], d2[MAXN];
int v[MAXN];

ll get_dis(ll tx1, ll ty1, ll tx2, ll ty2){
  return (tx2 - tx1)*(tx2 - tx1) + (ty2 - ty1)*(ty2 - ty1);
}

int main(){

  scanf("%d", &n);
  scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
  for(int i=1; i<=n; i++){
    scanf("%lld%lld", &xi[i], &yi[i]);
    d1[i] = get_dis(x1, y1, xi[i], yi[i]);
    d2[i] = get_dis(x2, y2, xi[i], yi[i]);
  }
  ll tdis, gdis = 0x7f7f7f7f7f7f7f7f;
  for(int i=1; i<=n; i++){
    tdis = 0;
    for(int j=1; j<=n; j++){
      if(d1[j] <= d1[i]) continue;
      tdis = max(tdis, d2[j]);
    }
    gdis = min(gdis, tdis+d1[i]);
  }
  tdis  = 0;
  for(int i=1; i<=n; i++){
    tdis = max(tdis, d2[i]);
  }
  gdis = min(gdis, tdis);
  printf("%lld", gdis);

  return 0;
}
