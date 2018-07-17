#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 2e5+7;

int n, m;
int val[MAXN], ch[MAXN][2], fa[MAXN], dist[MAXN];

int merge(int x, int y){
  if(!x || !y){
    return x | y;
  }
  if(val[x] > val[y] || (val[x] == val[y]) && x > y){
    swap(x, y);
  }
  ch[x][1] = merge(ch[x][1], y);
  fa[ch[x][1]] = x;
  if(dist[ch[x][1]] > dist[ch[x][0]]){
    swap(ch[x][1], ch[x][0]);
  }
  dist[x] = dist[ch[x][1]] + 1;
  return x;
}

int getfa(int x){
  return !fa[x] ? x : getfa(fa[x]);
}

int main(){
  memset(val, 0xff, sizeof(val));
  memset(dist, 0xff, sizeof(dist));
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++){
    scanf("%d", &val[i]);
  }
  int opa, opx, opy;
  for(int i=0; i<m; i++){
    scanf("%d", &opa);
    if(opa == 1){
      scanf("%d%d", &opx, &opy);
      if(val[opx] == -1 || val[opy] == -1) continue;
      if(opx == opy) continue;
      opx = getfa(opx), opy = getfa(opy);
      if(opx == opy) continue;
      merge(opx, opy);
    }else if(opa == 2){
      scanf("%d", &opx);
      if(val[opx] == -1){
        printf("-1\n");
        continue;
      }
      opx = getfa(opx);
      printf("%d\n", val[opx]);
      fa[ch[opx][0]] = fa[ch[opx][1]] = 0;
      val[opx] = -1;
      merge(ch[opx][0], ch[opx][1]);
    }
  }


  return 0;
}
