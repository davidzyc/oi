#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#define MAXM 1000001
#define MAXN 20001
#define INF 2147483647
using namespace std;

typedef pair<int, int> pii;
int n, m, s;
int from[MAXM] = {0}, to[MAXM] = {0}, c[MAXM], first[MAXN] = {0}, nxt[MAXM] = {0};
int d[MAXN], v[MAXN];
priority_queue<pii, vector<pii>, greater<pii> > pq;
stack<int> st;

void dijkstra(){
  fill(d, d+n+1, INF);
  memset(v, 0, sizeof(v));
  d[s] = 0;
  pq.push(make_pair(d[s], s));
  while(!pq.empty()){
    pii cur = pq.top();
    pq.pop();
    int tc, tid;
    // tc = cur.first;
    tid = cur.second;
    if(v[tid]) continue;
    v[tid] = 1;
    for(int edge=first[tid]; edge!=0; edge=nxt[edge]){
      int tto = to[edge];
      if(v[tto]) continue;
      if(d[tid] < INF && d[tid] + c[edge] < d[tto]){
        d[tto] = d[tid] + c[edge];
        pq.push(make_pair(d[tto], tto));
      }
    }
  }
}

void spfa(){
  fill(d, d+n+1, INF);
  memset(v, 0, sizeof(v));
  d[s] = 0;
  st.push(s);
  while(!st.empty()){
    int tid = st.top();
    st.pop();
    for(int edge=first[tid]; edge != 0; edge = nxt[edge]){
      if(d[tid] < INF && d[tid]+c[edge]<d[to[edge]]){
        d[to[edge]] = d[tid]+c[edge];
        st.push(to[edge]);
      }
    }
  }
}

int main(){
  int t;
  cin >> n >> m >> s;
  for(int i=1; i<=m; i+=1){
    cin >> from[i] >> to[i] >> c[i];
    // from[i+1] = to[i];
    // to[i+1] = from[i];
    // c[i+1] = c[i];
    t = first[from[i]];
    first[from[i]] = i;
    nxt[i] = t;
    // t = first[from[i+1]];
    // first[from[i+1]] = i+1;
    // nxt[i+1] = t;
  }
  dijkstra();
  for(int i=1; i<=n; i++){
    cout << d[i] << " ";
  }

  return 0;
}
