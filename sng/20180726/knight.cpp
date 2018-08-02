#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 1e6+7;
const int MAXD = 8;

const int dx[MAXD] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[MAXD] = {-1, 1, -2, 2, -2, 2, -1, 1};

int n, m;
int px[MAXN], py[MAXN];
int en = 0, head[MAXN], nxt[MAXN], from[MAXN], to[MAXN];
int v[MAXN], match[MAXN] = {0};
int bipc[MAXN] = {0};
char s[5];

void add_edge(int f, int t){
  ++en;
  from[en] = f;
  to[en] = t;
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
      // match[x] = y;
      return true;
    }
  }
  return false;
}

void dfsmark(int x){
  v[x] = 1;
  for(int e=head[x]; e; e=nxt[e]){
    int y = to[e];
    if(v[y]) continue;
    bipc[y] = bipc[x] ^ 1;
    dfsmark(y);
  }
}

int main(){
  freopen("knight.in", "r", stdin);
  freopen("knight.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for(int i=1; i<=m; i++){
    scanf("%s", s);
    px[i] = s[0] - 'A' + 1;
    py[i] = s[1] - '0';
  }
  for(int i=1; i<=m; i++){
    for(int j=1; j<i; j++){
      for(int k=0; k<MAXD; k++){
        if(px[i] + dx[k] == px[j] && py[i] + dy[k] == py[j]){
          add_edge(i, j);
          add_edge(j, i);
          break;
        }
      }
    }
  }
  // for(int e=1; e<=en; e++){
  //   printf("(%d, %d) - (%d, %d)\n", px[from[e]], py[from[e]], px[to[e]], py[to[e]]);
  // }
  memset(v, 0, sizeof(v));
  for(int i=1; i<=m; i++){
    if(!v[i]) {
      bipc[i] = 2;
      dfsmark(i);
    }
  }

  int ans = 0;
  for(int i=1; i<=m; i++){
    memset(v, 0, sizeof(v));
    if(bipc[i] == 2 && hungarian(i)){
      ++ans;
    }
  }
  printf("%d", ans);
  // for(int i=1; i<=m; i++){
  //   if(match[i]) printf("(%d, %d) - (%d, %d)\n", px[i], py[i], px[match[i]], py[match[i]]);
  // }


  return 0;
}
