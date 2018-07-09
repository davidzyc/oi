#include<cstdio>
#include<iostream>
using namespace std;

const int MAXN = 2e5+7;
const int MAXB = 31;

int n;
int gmax = 0;
int a[MAXN];
int f[MAXN] = {0}, d[MAXN] = {0};

int main(){

  freopen("4300.in", "r", stdin);
  freopen("4300.out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);

  for(int i=0; i<n; i++){
    for(int j=0; j<MAXB; j++){
      if(a[i]&(1<<j)){
        f[i] = max(f[i], d[j]+1);
      }
    }
    for(int j=0; j<MAXB; j++){
      if(a[i]&(1<<j)){
        d[j] = max(d[j], f[i]);
      }
    }
    gmax = max(gmax, f[i]);
  }

  printf("%d", gmax);

  return 0;
}
