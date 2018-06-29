#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+7;
ll n, m, p, t, tex;
ll a[MAXN];

int main(){
  scanf("%lld%lld", &n, &m);
  p = (int) (sqrt(2*m+0.25)-0.5);
  for(int i=1; i<n-p; i++){
    a[i] = i;
  }
  t = n;
  for(int i=n-p; i<=n; i++){
    a[i] = t--;
  }
  m -= p*(p+1)/2;
  for(int i=0; i<m; i++){
    tex = a[t];
    a[t] = a[n-i];
    a[n-i] = tex;
  }
  for(int i=1; i<=n; i++){
    printf("%lld ", a[i]);
  }
  return 0;
}
