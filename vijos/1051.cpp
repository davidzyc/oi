#include<cstdio>
#include<iostream>
#define MAXN 105
using namespace std;

char graph[MAXN][MAXN];
int vis[MAXN][MAXN] = {0};
int n, m;

int dfs(int i, int j){
int cnt = 0;
  if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || graph[i][j] == '-'){
    return cnt;
  }else if(graph[i][j] == '#'){
    vis[i][j] = 1;
    cnt++;
  }
  cnt += dfs(i+1, j);
  cnt += dfs(i+2, j);
  cnt += dfs(i-1, j);
  cnt += dfs(i-2, j);
  cnt += dfs(i, j+1);
  cnt += dfs(i, j+2);
  cnt += dfs(i, j-1);
  cnt += dfs(i, j-2);
  cnt += dfs(i+1, j+1);
  cnt += dfs(i+1, j-1);
  cnt += dfs(i-1, j+1);
  cnt += dfs(i-1, j-1);
  return cnt;
}

int main(){
  int tot = 0;
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> graph[i][j];
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(dfs(i, j)){
        tot ++;
      }
    }
  }
  cout << tot;

  return 0;
}
