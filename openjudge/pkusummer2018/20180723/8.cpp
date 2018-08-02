#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e5+7;

int n, k;
int a[MAXN];

bool cmp(int x, int y){
  return x > y;
}

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &a[i]);
  sort(a, a+n, cmp);
  scanf("%d", &k);
  for(int i=0; i<k; i++) printf("%d\n", a[i]);

  return 0;
}
