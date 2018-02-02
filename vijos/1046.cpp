#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 105
#define INF 100000000
using namespace std;

int n, m, rstart;
int adjm[MAXN][MAXN], vis[MAXN];

int dfs(int nid, int level){
  int routemin = INF;
  // cout << nid << " " << level << endl;
  if(level > 2 && nid == rstart){
    return adjm[nid][rstart];
  }
  if(level+1 == n){
    // cout << endl << "Find! " << nid << " " << rstart << " " << adjm[nid][rstart] << endl;
    return INF;
  }
  for(int i=0; i<n; i++){
    if(vis[i] == 0 && adjm[nid][i] < INF){
      vis[i] = 1;
      routemin = min(dfs(i, level+1)+adjm[nid][i], routemin);
      vis[i] = 0;
    }
  }
  return routemin;
}

int main(){

  while(cin >> n >> m){
    int tu, tv, tc;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(i!=j){
          adjm[i][j] = INF;
        }else{
          adjm[i][j] = 0;
        }
      }
    }
    for(int i=0; i<m; i++){
      cin >> tu >> tv >> tc;
      tu--;
      tv--;
      adjm[tu][tv] = min(adjm[tu][tv], tc);
      adjm[tv][tu] = min(adjm[tv][tu], tc);
    }
    memset(vis, 0, sizeof(vis));
    int rmin = INF, dfsmin;
    for(int i=0; i<n; i++){
      // vis[i] = 1;
      rstart = i;
      dfsmin = dfs(i, 0);
      rmin = min(rmin, dfsmin);
      // cout << dfsmin << " ";
      // vis[i] = 0;
    }
    // for(int i=0; i<n; i++){
    //   for(int j=0; j<n; j++){
    //     cout << adjm[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    if(rmin < INF){
      cout << rmin << endl;
    }else{
      cout << "No Solution." << endl;
    }

  }

  return 0;
}
