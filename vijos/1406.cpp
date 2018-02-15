#include<cstdio>
#include<iostream>
#include<queue>
#define MAXN 25
#define INF 2100000000
#define MAXC 500
#define ST 497
#define ED 496
using namespace std;

typedef pair<int, int> pii;
int n, m;
const int dx[5] = {0, -1, 0, 1}, dy[5] = {1, 0, -1, 0};
char cm[MAXN][MAXN];
bool visv[MAXN][MAXN] = {false}, visf[MAXN][MAXN] = {false};
bool adjm[MAXC][MAXC] = {false}, vbfs[MAXC] = {false};
int blockid[MAXC][MAXC] = {0}, cnt = 1;

void dfsf(char c, int y, int x, int fill){
  if(y < 1 || y > m || x < 1 || x > n || (visv[y][x] && cm[y][x] == c) || cm[y][x] != c){
    return;
  }
  visv[y][x] = true;
  blockid[y][x] = fill;
  int tx, ty;
  for(int i=0; i<4; i++){
    tx = x + dx[i];
    ty = y + dy[i];
    dfsf(c, ty, tx, fill);
  }
  return;
}

void dfsbgraph(char c, int y, int x, int fill){
  if(y < 1 || y > m || x < 1 || x > n || (visf[y][x] && cm[y][x] == c)){
    return;
  }
  if(fill!=blockid[y][x]){
    adjm[fill][blockid[y][x]] = true;
    return;
  }
  visf[y][x] = true;
  int tx, ty;
  for(int i=0; i<4; i++){
    tx = x + dx[i];
    ty = y + dy[i];
    dfsbgraph(c, ty, tx, fill);
  }
  return;
}

int main(){

  cin >> m >> n;
  
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      // scanf("%c", &cm[i][j]);
      cin >> cm[i][j];
    }
  }

  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      dfsf(cm[i][j], i, j, cnt++);
    }
  }

  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      dfsbgraph(cm[i][j], i, j, blockid[i][j]);
    }
  }

  for(int j=1; j<=n; j++){
    adjm[ST][blockid[1][j]] = adjm[blockid[1][j]][ST] = true;
    adjm[ED][blockid[m][j]] = adjm[blockid[m][j]][ED] = true;
  }

  queue<pii> q;
  q.push(make_pair(ST, 0));
  while(!q.empty()){
    pii p = q.front();
    q.pop();
    int node = p.first;
    if(vbfs[node]) continue;
    int steps = p.second;
    // cout << node << " " ;
    if(node == ED){
      cout << steps-1 << endl;
      return 0;
    }
    vbfs[node] = true;
    for(int i=0; i<=499; i++){
      if(adjm[node][i]){
        q.push(make_pair(i, steps+1));
      }
    }
  }

  return 0;
}
