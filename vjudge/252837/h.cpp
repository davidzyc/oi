#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 507;
const ll INF = 0x7f7f7f7f7f7f7f7f;

int n, m;
ll a[MAXN][MAXN];
ll ap[MAXN][MAXN];
ll s[MAXN];

int main(){
  memset(a, 0, sizeof(a));
  memset(ap, 0, sizeof(ap));
  scanf("%d%d", &m, &n);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      scanf("%lld", &a[i][j]);
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      ap[i][j] = ap[i][j-1] + a[i][j];
    }
  }

  ll gmax = 0, tmin;
  for(int l=1; l<=m; l++){
    for(int r=l; r<=m; r++){
      memset(s, 0, sizeof(s));
      tmin = 0;
      for(int i=1; i<=n; i++){
        s[i] = s[i-1] + ap[i][r] - ap[i][l-1];
        tmin = min(tmin, s[i]);
        gmax = max(gmax, s[i] - tmin);
      }
    }
  }

  printf("%lld", gmax);


  return 0;
}
