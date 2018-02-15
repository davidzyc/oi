#include<cstdio>
#include<queue>
#include<iostream>
#include<vector>
#define MAXN 100005
#define MAXM 200005
using namespace std;

// typedef pair<int, int> pii;
int n, m;
int u[MAXM], v[MAXM], nxt[MAXM] = {0}, first[MAXN] = {0}, incnt[MAXN] = {0}, vis[MAXN] = {0};
int nid[MAXN], cnt = 0;
priority_queue<int> pq;

int main(){
  cin >> n >> m;
  for(int i=1; i<=m; i++){
    cin >> v[i] >> u[i];
    incnt[v[i]]++;
    nxt[i] = first[u[i]];
    first[u[i]] = i;
  }
  for(int i=1; i<=n; i++){
    if(!incnt[i]){
      pq.push(i);
    }
  }

  // for(int i=1; i<=n; i++){
  //   cout << i << " " << incnt[i]  << " " << first[i] << endl;
  // }
  //
  // for(int i=0; i<m; i++){
  //   cout << u[i] << " " << v[i] << " " << nxt[i] << endl;
  // }
  cnt = n;
  while(!pq.empty()){
    int tid = pq.top();
    pq.pop();
    // vis[tid]++;
    // cout << tid <<  " ";
    nid[tid] = cnt--;
    int e = first[tid];
    while(e != 0){
      if(u[e] != tid){
        cout << "ERR " << e << " " << u[e] << " " << v[e];
        return 0;
      }
      int to = v[e];
      incnt[to]--;
      if(incnt[to] == 0){
        pq.push(to);
      }
      // if(vis[to] == 0){
      // }
      e = nxt[e];
    }
  }

  for(int i=1; i<=n; i++){
    cout << nid[i] << " ";
  }

  return 0;
}
