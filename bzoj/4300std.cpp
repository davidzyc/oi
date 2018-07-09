#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 2e5+7;
const int MAXB = 30;

int n;
int gmax = 0;
int a[MAXN];
int f[MAXN] = {0}, d[MAXN] = {0};

int main(){

  freopen("4300.in", "r", stdin);
  freopen("4300.ans", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  for(int i=0; i<n; i++){
    f[i] = 1;
    for(int j=0; j<i; j++){
      if(a[i]&a[j]) f[i] = max(f[i], f[j]+1);
    }
    gmax = max(gmax, f[i]);
  }

  printf("%d", gmax);

  return 0;
}
