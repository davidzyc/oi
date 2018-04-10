#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

const int MAXN = 1e5+7;

int n;
int to[MAXN];
int v[MAXN];
int dfncnt = 0;
int dfn[MAXN];
int in_ring, ring_end;
int cnt[MAXN];

void dfs(int x){
  int y = to[x];
  v[x] = 1;
  // cout << x << " "; 
  dfn[x] = ++dfncnt;
  if(v[y] == 2){
    cnt[x] = cnt[y] + 1;
  }else if(v[y] == 1){
    if(x != y){
      ring_end = y;
      in_ring = 1;
    }
    cnt[x] = dfn[x] - dfn[y] + 1;
  }else if(v[y] == 0){
    dfs(y);
    if(in_ring == 1){
      cnt[x] = cnt[y];
      if(x == ring_end) in_ring = 0;
    }else{
      cnt[x] = cnt[y] + 1;
    }
  }
  v[x] = 2;
  return;
}

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &to[i]);
  }
  for(int i=1; i<=n; i++){
    if(v[i]) continue;
    dfs(i);
  }
  for(int i=1; i<=n; i++){
    printf("%d\n", cnt[i]);
  }

  return 0;
}
