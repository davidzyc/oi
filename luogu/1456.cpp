#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 2e5+7;
const int INF = 0x3f3f3f3f;

int n, m;
int fa[MAXN], ch[MAXN][2], val[MAXN], dist[MAXN];

int getfa(int x){
  return fa[x] == 0 ? x : getfa(fa[x]);
}

int merge(int x, int y){
  if(!x || !y){
    return x | y;
  }
  if(val[x] < val[y] || (val[x] == val[y] && x > y)){
    swap(x, y);
  }
  ch[x][1] = merge(ch[x][1], y);
  fa[ch[x][1]] = x;
  if(dist[ch[x][0]] < dist[ch[x][1]]){
    swap(ch[x][0], ch[x][1]);
  }
  dist[x] = dist[ch[x][1]] + 1;
  return x;
}

int main(){

  while(scanf("%d", &n) == 1){
    memset(fa, 0, sizeof(fa));
    memset(ch, 0, sizeof(ch));
    memset(val, 0x3f, sizeof(val));
    memset(dist, 0xff, sizeof(dist));

    for(int i=1; i<=n; i++){
      scanf("%d", &val[i]);
    }
    scanf("%d", &m);
    int x, y;
    while(m--){
      scanf("%d%d", &x, &y);
      if(x == y){
        printf("-1\n");
        continue;
      }
      x = getfa(x), y = getfa(y);
      if(x == y){
        printf("-1\n");
        continue;
      }
      val[x] /= 2, val[y] /= 2;
      fa[ch[x][0]] = fa[ch[x][1]] = fa[ch[y][0]] = fa[ch[y][1]] = 0;
      int cx = merge(ch[x][0], ch[x][1]), cy = merge(ch[y][0], ch[y][1]);
      ch[x][0] = ch[x][1] = ch[y][0] = ch[y][1] = 0;
      dist[x] = dist[y] = -1;
      int ccx = merge(merge(cx, x), merge(cy, y));
      printf("%d\n", val[ccx]);
    }
  }

  return 0;
}
