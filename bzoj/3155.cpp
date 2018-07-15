#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

typedef long long ll;

const int MAXN = 2e5+7;

int n, q, sn;
char c[6];
ll a[MAXN], s[MAXN], ss[MAXN];

ll lowbit(ll x){
  return x&(-x);
}

void s_update(int x, ll val){
  while(x <= sn){
    s[x] += val;
    x += lowbit(x);
  }
  return;
}

ll s_query(ll x){
  ll ans = 0;
  while(x > 0){
    ans += s[x];
    x -= lowbit(x);
  }
  return ans;
}


void ss_update(int x, ll val){
  while(x <= sn){
    ss[x] += val;
    x += lowbit(x);
  }
  return;
}

ll ss_query(ll x){
  ll ans = 0;
  while(x > 0){
    ans += ss[x];
    x -= lowbit(x);
  }
  return ans;
}

int main(){
  freopen("3155.in", "r", stdin);
  freopen("3155.out", "w", stdout);
  int x;
  ll val;
  scanf("%d%d", &n, &q);
  for(sn=1; sn<n; sn<<=1);
  for(int i=1; i<=n; i++){
    scanf("%lld", &val);
    a[i] = val;
    s_update(i, val);
    ss_update(i, val * (ll)i);
  }
  for(int i=1; i<=q; i++){
    scanf("%s", c);
    if(c[0] == 'Q'){
      scanf("%d", &x);
      printf("%lld\n", ((ll)(x+1)) * s_query(x) - ss_query(x));
    }else if(c[0] = 'M'){
      scanf("%d%lld", &x, &val);
      s_update(x, (val - a[x]));
      ss_update(x, (val - a[x]) * (ll)x);
      a[x] = val;
    }
  }

  return 0;
}
