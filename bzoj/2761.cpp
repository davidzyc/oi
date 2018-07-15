#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 1e5+7;

int n;
int a[MAXN], id[MAXN], uni[MAXN];

bool cmp(int x, int y){
  if(a[x] != a[y])
  return a[x] < a[y];
  return x < y;
}

int main(){
  // freopen("2761.out", "w", stdout);
  // freopen("2761.in", "r", stdin);
  int gset = 0;
  scanf("%d", &gset);
  while(gset--){
    memset(a, 0, sizeof(a));
    memset(id, 0, sizeof(id));
    memset(uni, 0, sizeof(uni));
    scanf("%d", &n);
    for(int i=0; i<n; i++){
      scanf("%d", &a[i]);
      id[i] = i;
    }
    sort(id, id+n, cmp);
    // int temp;
    for(int i=0; i<n; i++){
      if(i == 0 || a[id[i]] != a[id[i-1]]){
        // temp = a[id[i]];
        uni[id[i]] = 1;
      }
    }
    for(int i=0; i<n; i++){
      if(uni[i]) {
        printf("%d", a[i]);
        if(i != n-1) printf(" ");
      }
    }
    //   if(gset != 0)
    printf("\n");
  }



  return 0;
}
