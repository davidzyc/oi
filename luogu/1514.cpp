#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int MAXN = 1007;

typedef pair<int, int> pii;

const int di[4] = {0, 0, -1, 1};
const int dj[4] = {1, -1, 0, 0};
int n, m;
int a[MAXN][MAXN];
int l[MAXN], r[MAXN], id[MAXN];
int v[MAXN][MAXN] = {0};
int dp[MAXN];
queue<pii> q;

bool cmp(int x, int y){
  if(r[x] != r[y]) return r[x] < r[y];
  return l[x] < l[y];
}

int main(){
  memset(l, 0xff, sizeof(l));
  memset(r, 0xff, sizeof(r));
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &a[i][j]);
    }
  }


  while(!q.empty()) q.pop();
  for(int j=0; j<m; j++){
    q.push(make_pair(0, j));
  }
  while(!q.empty()){
    int ti = q.front().first, tj = q.front().second;
    q.pop();
    if(v[ti][tj]) continue;
    v[ti][tj] = 1;
    for(int i=0; i<4; i++){
      int ni = ti + di[i], nj = tj + dj[i];
      if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
      if(v[ni][nj]) continue;
      if(a[ni][nj] >= a[ti][tj]) continue;
      q.push(make_pair(ni, nj));
    }
  }
  int tot = 0;
  for(int j=0; j<m; j++) tot += v[n-1][j];
  if(tot < m){
    printf("0\n%d", m - tot);
    return 0;
  }

  int flag = 1;
  for(int j=0; j<m; j++){
    memset(v, 0, sizeof(v));
    while(!q.empty()) q.pop();
    q.push(make_pair(0, j));
    while(!q.empty()){
      int ti = q.front().first, tj = q.front().second;
      q.pop();
      if(v[ti][tj]) continue;
      v[ti][tj] = 1;
      for(int i=0; i<4; i++){
        int ni = ti + di[i], nj = tj + dj[i];
        if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        if(v[ni][nj]) continue;
        if(a[ni][nj] >= a[ti][tj]) continue;
        q.push(make_pair(ni, nj));
      }
    }
    for(int cj=0; cj<m; cj++){
      if(v[n-1][cj]){
        l[j] = cj;
        break;
      }
    }
    for(int cj=m-1; cj>=0; cj--){
      if(v[n-1][cj]){
        r[j] = cj;
        break;
      }
    }
    id[j] = j;
    if(l[j] == -1 && r[j] == -1) continue;
    for(int cj=l[j]; cj<=r[j]; cj++){
      flag = min(flag, v[n-1][cj]);
    }
  }
  // cout << flag << endl;
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  sort(id, id+m, cmp);
  for(int j=0; j<m; j++){
    int i = id[j];
    if(l[i] == -1 && r[i] == -1) continue;
    l[i]++, r[i]++;
    for(int k=l[i]-1; k<=r[i]; k++){
      dp[r[i]] = min(dp[r[i]], dp[k]+1);
    }
  }
  printf("1\n%d", dp[m]);
  // for(int i=0; i<m; i++){
  //   printf("%d : %d l - r %d\n", i, l[i], r[i]);
  // }

  return 0;
}
