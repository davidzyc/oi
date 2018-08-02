#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 1e5+7;

int n, en = 0;
int head[MAXN], nxt[MAXN], from[MAXN], to[MAXN];
int isstu[MAXN], isoccu[MAXN];
int v[MAXN] = {0}, match[MAXN] = {0};

void add_edge(int f, int t){
  ++en;
  to[en] = t;
  from[en] = f;
  nxt[en] = head[f];
  head[f] = en;
  return;
}

bool hungarian(int x){
  for(int e=head[x]; e; e=nxt[e]){
    int y = to[e];
    if(v[y]) continue;
    v[y] = 1;
    if(!match[y] || hungarian(match[y])){
      match[y] = x;
      match[x] = y;
      return true;
    }
  }
  return false;
}

int main(){
  int tset;
  scanf("%d", &tset);
  // cout << tset << endl;
  while(tset--){
    en = 0;
    memset(head, 0, sizeof(head));
    memset(nxt, 0, sizeof(nxt));
    memset(to, 0, sizeof(to));
    memset(isstu, 0, sizeof(isstu));
    memset(isoccu, 0, sizeof(isoccu));
    memset(v, 0, sizeof(v));
    memset(match, 0, sizeof(match));

    scanf("%d", &n);
    for(int i=1; i<=n; i++){
      scanf("%d", &isstu[i]);
    }
    for(int i=1; i<=n; i++){
      scanf("%d", &isoccu[i]);
      isoccu[i] ^= 1;
    }
    int t;
    for(int i=1; i<=n; i++){
      if(isstu[i] == 1 && isoccu[i] == 0){
        for(int j=1; j<=n; j++) scanf("%d", &t);
        continue;
      }
      if(isstu[i] == 1){
        add_edge(i, i+n);
        add_edge(i+n, i);
      }
      for(int j=1; j<=n; j++){
        scanf("%d", &t);
        if(isstu[j] == 0) continue;
        if(!t) continue;
        add_edge(i, j+n);
        add_edge(j+n, i);
      }
    }
    // for(int i=1; i<=en; i++) printf("%d -> %d\n", from[i], to[i]);
    // int cnt = 0;
    int flag = 1;
    for(int i=1; i<=n; i++){
      if(isstu[i] == 1 && isoccu[i] == 0) continue;
      memset(v, 0, sizeof(v));
      if(!hungarian(i)) flag = 0;
    }
    // for(int i=1; i<=n; i++) cout << match[i] << " ";
    // cout << cnt;
    if(flag){
      printf("^_^\n");
    }else{
      printf("T_T\n");
    }

  }

  return 0;
}
