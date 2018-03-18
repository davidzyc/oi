#include<cstdio>
#include<iostream>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5+7;
int n;
int a[MAXN];
int dfn[MAXN] = {0}, indfn = 0, cnt = 0;
int ring = INF;

void dfs(int x){
  dfn[x] = ++cnt;
  if(!dfn[a[x]]){
    dfs(a[x]);
  }else{
    if(dfn[a[x]] > indfn){
      ring = min(ring, dfn[x]-dfn[a[x]]+1);
      // cout << x << " " << ring << endl;
    }
  }
  return;
}

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
    --a[i];
  }
  for(int i=0; i<n; i++){
    indfn = cnt;
    if(!dfn[i]) dfs(i);
  }
  cout << ring << endl;

  return 0;
}
