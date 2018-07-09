#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int MAXN = 2e5+7;
const int MAXEX = 51;

typedef pair<int, int> pii;

int n, m, st, ed, kk, pp;
int ecnt = 0;
int from[MAXN], to[MAXN], w[MAXN], head[MAXN], nxt[MAXN];
priority_queue<pii, vector<pii>, greater<pii> > q;
int dist[MAXN], dp[MAXN][MAXEX], v[MAXN];

int tdist[MAXN], tv[MAXN], ring_det;

void ginit(){
  memset(from, 0, sizeof(from));
  memset(to, 0, sizeof(to));
  memset(w, 0, sizeof(w));
  memset(head, 0, sizeof(head));
  memset(nxt, 0, sizeof(nxt));
  memset(tdist, 0, sizeof(tdist));
  memset(tv, 0, sizeof(tv));

  memset(dist, 0x3f, sizeof(dist));
  memset(dp, 0, sizeof(dp));
  memset(v, 0, sizeof(v));
  ecnt = 0;
  while(!q.empty()) q.pop();
}

void add_edge(int x, int y, int l){
  ++ecnt;
  from[ecnt] = x;
  to[ecnt] = y;
  w[ecnt] = l;
  nxt[ecnt] = head[x];
  head[x] = ecnt;
  return;
}

int main(){
  int gset;
  scanf("%d", &gset);
  while(gset--){

    ginit();

    scanf("%d%d", &n, &m);
    kk = 1;
    pp = 1<<30;
    // st = 1, ed = n;
    int x, y, l;
    for(int i=0; i<m; i++){
      scanf("%d%d%d", &x, &y, &l);
      add_edge(x, y, l);
    }
    scanf("%d%d", &st, &ed);


    while(!q.empty()) q.pop();
    dist[st] = 0;
    dp[st][0] = 1;
    q.push(make_pair(0, st));

    while(!q.empty()){
      int x = q.top().second;
      q.pop();
      if(v[x]) continue;
      v[x] = 1;
      for(int e=head[x]; e!=0; e=nxt[e]){
        // cout << "Hello" << endl;
        int y = to[e], l = w[e];
        // cout << x << "->" << y << endl;
        // if(v[y]) continue;
        if(dist[x] + l < dist[y]){
          int tl = dist[y] - dist[x] - l;
          dist[y] = dist[x] + l;
          q.push(make_pair(dist[y], y));
          if(tl <= kk){
            for(int i=kk; i>=tl; i--){
              dp[y][i] = dp[y][i-tl];
              dp[y][i] %= pp;
            }
            for(int i=0; i<tl; i++){
              dp[y][i] = 0;
            }
          }else{
            for(int i=0; i<=kk; i++){
              dp[y][i] = 0;
            }
          }
        }
        if(dist[x] + l > dist[y] && dist[x] - dist[y] + l <= kk){
          int tl = dist[x] - dist[y] + l;
          for(int i=0; i<=kk-(tl); i++){
            dp[y][i+tl] += dp[x][i];
            dp[y][i+tl] %= pp;
          }
        }else if(dist[x] + l == dist[y]){
          for(int i=0; i<=kk; i++){
            dp[y][i] += dp[x][i];
            dp[y][i] %= pp;
          }
        }
      }
    }

    int gcnt = 0;
    // for(int i=1; i<=n; i++){
    //   cout << i << " " << dist[i] << " - ";
    //   for(int j=0; j<=kk; j++){
    //
    //     gcnt %= pp;
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    gcnt = dp[ed][0] + dp[ed][1];
    // cout << n << endl;
    // for(int i=1; i<=n; i++){
    //   cout << dist[i] << " ";
    // }
    printf("%d\n", gcnt % pp);

  }

  return 0;
}
