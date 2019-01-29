#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 1e5+7;
const int INF = 0x3f3f3f3f;

int n;
int a[MAXN], d[MAXN];

int main(){

  int tset;
  scanf("%d", &tset);

  for(int tt=1; tt<=tset; tt++){
    int gmax = -INF, gmin = 0, gmid = 0, gs, ge;
    memset(d, 0, sizeof(d));
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
      scanf("%d", &a[i]);
      d[i] = d[i-1] + a[i];
    }
    for(int i=1; i<=n; i++){
      if(d[i] - gmin > gmax){
        gmax = d[i] - gmin;
        gs = gmid, ge = i;
      }
      if(d[i] < gmin){
        gmin = d[i];
        gmid = i;
      }
    }
    printf("Case %d:\n%d %d %d\n", tt, gmax, gs+1, ge);
    if(tt != tset) printf("\n");
  }

  return 0;
}
