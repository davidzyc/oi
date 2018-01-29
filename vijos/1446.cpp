#include<cstdio>
#include<iostream>
#include<cstring>
#define INF 10000000
#define MAXN 105
using namespace std;

int graph[MAXN][MAXN], vis[MAXN][MAXN];

int main(){
  int n, m, t1, t2, q;
  cin >> n >> m;
  memset(vis, 0, sizeof(vis));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      graph[i][j] = INF;
    }
  }
  for(int i=0; i<m; i++){
    cin >> t1 >> t2;
    graph[t1-1][t2-1] = 1;
    graph[t2-1][t1-1] = 1;
  }
  for(int k=0; k<n; k++){
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(graph[i][k]+graph[k][j] <= graph[i][j]){
          graph[i][j] = graph[i][k]+graph[k][j];
          graph[j][i] = graph[i][j];
        }
      }
    }
  }
  cin >> q;
  int cnt;
  for(int i=0; i<q; i++){
    cnt = 2;
    cin >> t1 >> t2;
    for(int j=0; j<n; j++){
      if(graph[t1-1][j]+graph[j][t2-1] == graph[t1-1][t2-1]){
        cnt++;
      }
    }
    cout << cnt << endl;
  }

  return 0;
}
