#include<cstdio>
#include<iostream>
#include<queue>
#define MAXN 505
#define INF 2100000000

using namespace std;

int adjm[MAXN][MAXN] = {0}, vis[MAXN] = {0}, sideexist[MAXN][MAXN] = {0};
int ansn[MAXN];

int main(){
  int n, p;
  int f, t, l;
  int ansmin = INF;
  int nodecnt = 0;
  queue<int> q;
  cin >> n >> p;
  for(int i=0; i<p; i++){
    cin >> f >> t >> l;
    adjm[f][t] = l;
    adjm[t][f] = -l;
    if(sideexist[f][t] || sideexist[t][f]){
      cout << -1;
      return 0;
    }
    sideexist[f][t] = 1;
    sideexist[t][f] = 1;
  }
  q.push(1);
  ansn[1] = 0;
  vis[1] = 1;
  while(!q.empty()){
    int qnode = q.front();
    // cout << qnode << " ";
    q.pop();
    nodecnt++;
    for(int i=1; i<=n; i++){
      if(vis[i] && sideexist[qnode][i] && ansn[i] != ansn[qnode] + adjm[qnode][i]){
        cout << -1;
        return 0;
      }
      if(qnode != i && vis[i] == 0 && sideexist[qnode][i]){
        vis[i] = 1;
        ansn[i] = ansn[qnode] + adjm[qnode][i];
        q.push(i);
      }
    }
  }
  if(nodecnt == n){
    for(int i=1; i<=n; i++){
      ansmin = min(ansmin, ansn[i]);
      // cout << ansn[i] << " ";
    }
    for(int i=1; i<=n; i++){
      cout << ansn[i] - ansmin << endl;
    }
  }else{
    cout << -1;
  }

  return 0;
}
