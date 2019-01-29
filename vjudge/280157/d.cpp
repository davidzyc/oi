#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;
const int MAXN = 1e6+7;

int n, h;
ll x[MAXN], y[MAXN];
// \even: re, /even: le, \odd: rd, /odd: ld
ll re[MAXN], le[MAXN], rd[MAXN], ld[MAXN];
// int ren, len, rdn, ldn;
int en, dn;

int main(){

  scanf("%d%d", &n, &h);
  for(int i=1; i<=n; i++){
    scanf("%lld%lld", &x[i], &y[i]);
    if(((x[i] + y[i]) % 2) == 0){
      ++en;
      re[en] = x[i] - y[i];
      le[en] = x[i] + y[i];
    }else{
      ++dn;
      rd[dn] = x[i] - y[i];
      ld[dn] = x[i] + y[i];
    }
  }
  sort(re+1, re+en+1);
  sort(le+1, le+en+1);
  sort(rd+1, rd+dn+1);
  sort(ld+1, ld+dn+1);
  // ren = en, len = en, rdn = dn, ldn = dn;
  // ren = unique(re+1, re+en+1) - re - 1;
  // len = unique(le+1, le+en+1) - le - 1;
  // rdn = unique(rd+1, rd+dn+1) - rd - 1;
  // ldn = unique(ld+1, ld+dn+1) - ld - 1;

  ll ans = 0, li, ui, lb, ub;
  for(int i=1; i<=en; i++){
    ui = le[i];
    li = le[i] - 2*((ll)h - 1);
    lb = lower_bound(re+1, re+en+1, li) - re;
    ub = upper_bound(re+1, re+en+1, ui) - re;
    ans += (ub - lb);
  }
  
  for(int i=1; i<=dn; i++){
    ui = ld[i];
    li = ld[i] - 2*((ll)h - 1);
    lb = lower_bound(rd+1, rd+dn+1, li) - rd;
    ub = upper_bound(rd+1, rd+dn+1, ui) - rd;
    ans += (ub - lb);
  }

  ans = ((ll)(dn + en)) * ((ll)h) * ((ll) 2) - ans - ((ll)n);
  printf("%lld", ans);

  return 0;
}
