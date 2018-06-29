#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

typedef long long ll;

const ll MAXINT = 2100000000;
const ll MAXSQRT = 150000;

int n, m = 0;
int tm, tp[MAXSQRT], tc[MAXSQRT];
ll a, b, c, d, td;
int v[MAXSQRT], p[MAXSQRT];
int cnt;

ll gcd(ll x, ll y){
  return y ? gcd(y, x%y) : x;
}

void dfs(int level, ll num){
  // cout << level << " " << num << endl;
  if(level == tm){
    if(gcd(c, num) * d == c*num && gcd(a, num) == b) ++cnt;
    return;
  }
  ll accu = 1;
  dfs(level+1, num*accu);
  for(int i=0; i<tc[level]; i++){
    accu *= tp[level];
    dfs(level+1, num*accu);
  }
  return;
}

int main(){

  for(int i=2; i<=sqrt(MAXINT); i++){
    if(!v[i]){
      v[i] = i;
      p[m++] = i;
    }
    for(int j=0; j<m; j++){
      if(p[j] > v[i] || p[j]*i >= sqrt(MAXINT)) continue;
      v[p[j]*i] = p[j];
    }
  }

  scanf("%d", &n);

  while(n--){
    cnt = 0, tm = 0;
    memset(tp, 0, sizeof(tp));
    memset(tc, 0, sizeof(tc));
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    td = d;
    for(int i=0; i<m; i++){
      if(p[i] > sqrt(td)) break;
      if(td % p[i]) continue;
      tp[tm] = p[i];
      while(td % p[i] == 0) td /= p[i], tc[tm]++;
      tm++;
    }
    if(td > 1) tp[tm] = td, tc[tm]++, tm++;
    // for(int j=0; j<tm; j++){
    //   cout << tp[j] << " " << tc[j] << endl;
    // }
    dfs(0, 1);
    // for(int i=1; i<=sqrt(d); i++){
    //   if(d % i) continue;
    //   if(gcd(c, i) * d == c*i && gcd(a, i) == b) ++cnt;
    //   if(i*i == d) continue;
    //   if(gcd(c, (d/i)) * d == c*(d/i) && gcd(a, (d/i)) == b) ++cnt;
    // }
    printf("%d\n", cnt);
  }

  return 0;
}
