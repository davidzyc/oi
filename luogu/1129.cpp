#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 100007;

int n;
int ec, from[MAXN], to[MAXN], first[MAXN], nxt[MAXN];
int match[MAXN], v[MAXN];

bool dfs(int x){
  for(int e=first[x]; e; e=nxt[e]){
    int y = to[e];
    if(v[y]) continue;
    v[y] = 1;
    if(!match[y] || dfs(match[y])){
      match[y] = x;
      match[x] = y;
      return true;
    }
  }
  return false;
}

void add_edge(int x, int y){
  ++ec;
  from[ec] = x;
  to[ec] = y;
  nxt[ec] = first[x];
  first[x] = ec;
  return;
}

int main(){
  int tset;
  scanf("%d", &tset);
  while(tset--){
    memset(match, 0, sizeof(match));
    memset(from, 0, sizeof(from));
    memset(to, 0, sizeof(to));
    memset(nxt, 0, sizeof(nxt));
    memset(first, 0, sizeof(first));
    memset(v, 0, sizeof(v));
    ec = 0;
    int t;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        scanf("%d", &t);
        if(t){
          add_edge(i, j+n);
          add_edge(j+n, i);
        }
      }
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
      memset(v, 0, sizeof(v));
      if(dfs(i)) cnt++;
    }
    if(cnt == n){
      printf("Yes\n");
    }else{
      printf("No\n");
    }

  }

  return 0;
}
