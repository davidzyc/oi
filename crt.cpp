#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 10;

int n, gm = 1, tm;
int a[MAXN], mod[MAXN];

int exgcd(int a,int b, int &x, int &y){
  if(b == 0){
    x = 1, y = 0;
    return a;
  }
  int ret;
  ret = exgcd(b, a%b, x, y);
  int t = x;
  x = y, y = t - (a/b) * y;
  return ret;
}

int main(){

  int gmod, gdec;
  n = 3;
  mod[1] = 23;
  mod[2] = 28;
  mod[3] = 33;
  gmod = mod[1] * mod[2] * mod[3];
  int gset;
  scanf("%d", &gset);
  while(gset--){

    int tset = 0;
    while(true){
      gm = 1;
      scanf("%d%d%d%d", &a[1], &a[2], &a[3], &gdec);
      if(a[1] == -1 && a[2] == -1 && a[3] == -1 && gdec == -1) break;
      int ans = 0;
      for(int i=1; i<=n; i++){
        gm *= mod[i];
      }
      int x, y;
      for(int i=1; i<=n; i++){
        tm = gm / mod[i];
        exgcd(tm, mod[i], x, y);
        ans += a[i]*x*tm;
      }
      ans = (((ans-gdec) % gmod) + gmod) % gmod;
      printf("Case %d: the next triple peak occurs in %d days.\n", ++tset, ans ? ans : gmod);
    }
    if(gset > 0) printf("\n");
  }

  return 0;
}
