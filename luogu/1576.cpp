#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;

typedef pair<int, int> pii;
typedef pair<double, int> pdi;
const int MAXN = 2001;
const double INF = 2000000000.0;

int n, m, st, ter;
vector<pii> to[MAXN];
int v[MAXN] = {0};
double d[MAXN];
priority_queue<pdi> q;

void dijkstra(){
  d[st] = 1.0;
  q.push(make_pair(d[st], st));
  while(!q.empty()){
    pdi t = q.top();
    int curv, curd;
    curv = t.second;
    curd = t.first;
    q.pop();
    if(v[curv]) continue;
    v[curv] = 1;
    for(int i=0; i<to[curv].size(); i++){
      if(d[to[curv][i].first] < d[curv] * (1 - 0.01 * to[curv][i].second)){
        d[to[curv][i].first] = d[curv] * (1 - 0.01 * to[curv][i].second);
        q.push(make_pair(d[to[curv][i].first], to[curv][i].first));
      }
    }
  }
  return;
}

void spfa(){
  stack<int> s;
  s.push(st);
  v[st] = 1;
  d[st] = 1.0;
  while(!s.empty()){
    int t = s.top();
    s.pop();
    for(int i=0; i<to[t].size(); i++){
      if(d[t]*(1.0-to[t][i].second*0.01) > d[to[t][i].first]){
        d[to[t][i].first] = d[t]*(1.0-to[t][i].second*0.01);
        s.push(to[t][i].first);
      }
    }
  }
  return;
}

int main(){
  // freopen("1576.txt", "r", stdin);
  int tfrom, tto, tc;
  scanf("%d %d" ,&n, &m);
  for(int i=0; i<m; i++){
    scanf("%d %d %d", &tfrom, &tto, &tc);
    to[tfrom].push_back(make_pair(tto, tc));
    to[tto].push_back(make_pair(tfrom, tc));
  }
  scanf("%d %d", &st, &ter);
  dijkstra();
  // spfa();
  printf("%.8f\n", 100.0 / d[ter]);

  return 0;
}
