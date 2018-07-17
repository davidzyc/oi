#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int MAXM = 507;
const int MAXN = 17;
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};

typedef long long ll;
typedef pair<int, int> pii;

int r, c, n;
int a[MAXM][MAXM];
int dist[MAXN][MAXN];
char cc[MAXM];
char ch[MAXN];
int ci[MAXN], cj[MAXN], id[MAXN];
int nx = 0;
int vis[MAXM][MAXM], qa[MAXM][MAXM];
queue<pii> q;
int dp[(1<<MAXN)][MAXN];
int dplast[(1<<MAXN)][MAXN];
ll dpperm[(1<<MAXN)][MAXN];
int exc[MAXN];

void dfs(int i, int v){
  if(dplast[i][v] == -1){
    printf("%c", ch[v+1]);
    return;
  }
  dfs(i&(~(1<<v)), dplast[i][v]);
  printf("%c", ch[v+1]);
}

bool cmp(int aa, int bb){
  return ch[aa] < ch[bb];
}

int main(){
  memset(dist, 0x3f, sizeof(dist));
  scanf("%d%d%d", &r, &c, &n);
  for(int i=1; i<=r; i++){
    scanf("%s",cc+1);
    for(int j=1; j<=c; j++){
      if(cc[j] == '.'){
        a[i][j] = 0;
      }else if(cc[j] == '*'){
        a[i][j] = -1;
      }else{
        a[i][j] = ++nx;
        ch[nx] = cc[j];
        ci[nx] = i;
        cj[nx] = j;
        id[nx] = nx;
      }
    }
  }
  sort(id+1, id+1+n, cmp);
  for(int i=1; i<=n; i++){
    exc[i] = ch[id[i]];
  }
  for(int i=1; i<=n; i++){
    ch[i] = exc[i];
  }
  for(int i=1; i<=n; i++){
    exc[i] = ci[id[i]];
  }
  for(int i=1; i<=n; i++){
    ci[i] = exc[i];
  }
  for(int i=1; i<=n; i++){
    exc[i] = cj[id[i]];
  }
  for(int i=1; i<=n; i++){
    cj[i] = exc[i];
  }
  for(int i=1; i<=n; i++){
    a[ci[i]][cj[i]] = i;
  }
  // for(int i=1; i<=r; i++){
  //   for(int j=1; j<=c; j++){
  //     cout << a[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // for(int i=1; i<=n; i++){
  //   printf("%c:(%d,%d) ", ch[i], ci[i], cj[i]);
  // }

  for(int i=1; i<=n; i++){
    int tcnt = 0;
    while(!q.empty()) q.pop();
    memset(vis, 0, sizeof(vis));
    memset(qa, 0x3f, sizeof(qa));
    qa[ci[i]][cj[i]] = 0;
    q.push(make_pair(ci[i], cj[i]));
    while(!q.empty()){
      int ti = q.front().first, tj = q.front().second;
      q.pop();
      if(vis[ti][tj]) continue;
      vis[ti][tj] = 1;
      if(a[ti][tj] > 0) tcnt++;
      if(tcnt == n){
        break;
      }
      for(int j=0; j<4; j++){
        int ni = ti + di[j], nj = tj + dj[j];
        if(ni >= 1 && ni <= r && nj >= 1 && nj <= c && !vis[ni][nj] && a[ni][nj] != -1){
          qa[ni][nj] = qa[ti][tj] + 1;
          q.push(make_pair(ni, nj));
        }
      }
    }
    // for(int j=1; j<=r; j++){
    //   for(int k=1; k<=c; k++){
    //     printf("%d\t", qa[j][k] >= 0x3f3f3f3f ? -1 : qa[j][k]);
    //   }
    //   printf("\n");
    // }
    // printf("\n");
    for(int j=1; j<=n; j++){
      dist[i][j] = qa[ci[j]][cj[j]];
    }
  }

  // for(int i=1; i<=n; i++){
  //   for(int j=1; j<=n; j++){
  //     printf("%d\t", dist[i][j] >= 0x3f3f3f3f ? -1 : dist[i][j]);
  //   }
  //   printf("\n");
  // }

  memset(dp, 0x3f, sizeof(dp));
  memset(dplast, 0xff, sizeof(dplast));
  // cout << dplast[0][0];
  for(int i=1; i<=n; i++){
    if(ch[i] == 'A') dp[(1<<(i-1))][i-1] = 0;
  }
  for(int i=1; i<(1<<n); i++){
    for(int v=0; v<n; v++){
      if(!dp[i][v]) continue;
      if(((i>>v)&1) == 0) continue;
      for(int u=0; u<n; u++){
        if(v == u) continue;
        if(((i>>u)&1) == 0) continue;
        if(dp[i&(~(1<<v))][u] + dist[u+1][v+1] < dp[i][v]){
          dp[i][v] = dp[i&(~(1<<v))][u] + dist[u+1][v+1];
          dplast[i][v] = u;
          dpperm[i][v] = dp[i&(~(1<<v))][u] * 16 + (ll) v;
        }else if(dp[i&(~(1<<v))][u] + dist[u+1][v+1] == dp[i][v]){
          if(dp[i&(~(1<<v))][u] * 16 + (ll) v > dpperm[i][v]){
            dplast[i][v] = u;
            dpperm[i][v] = dp[i&(~(1<<v))][u] * 16 + (ll) v;
          }
        }
      }
    }
  }
  int ans = 0x3f3f3f3f, aperm = 0, ansi;
  for(int i=0; i<n; i++){
    if(dp[(1<<n)-1][i] < ans){
      ans = dp[(1<<n)-1][i];
      aperm = dpperm[(1<<n)-1][i];
      ansi = i;
    }
    if(dp[(1<<n)-1][i] > aperm){
      aperm = dpperm[(1<<n)-1][i];
      ansi = i;
    }
  }
  printf("%d\n", ans);
  dfs((1<<n)-1, ansi);

  return 0;
}
