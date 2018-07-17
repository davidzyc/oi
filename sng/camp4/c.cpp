#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 10007;

int v[MAXN], fa[MAXN], fab[MAXN];

int find(int x){
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main(){
  int tset;
  scanf("%d", &tset);
  while(tset--){
    int n, f, t;
    bool flag = true;
    memset(v, 0, sizeof(v));
    memset(fa, 0, sizeof(fa));
    memset(fab, 0, sizeof(fab));
    scanf("%d", &n);
    for(int i=1; i<=100; i++){
      fa[i] = i;
    }
    for(int i=0; i<n; i++){
      scanf("%d%d", &f, &t);
      if(v[f]) flag = false;
      fa[f] = t;
    }
    // for(int i=1; i<=100; i++){
    //   fab[i] = fa[i];
    // }
    // for(int i=1; i<=100; i++){
    //   find(i);
    // }
    for(int i=1; i<=100; i++){
      // if(fab[i] != fa[i]) flag = false;
      if(i != fa[i] && fa[i] != fa[fa[i]]) flag = false;
    }

    if(flag){
      printf("Lucky dxw!\n");
    }else{
      printf("Poor dxw!\n");
    }
  }

  return 0;
}
