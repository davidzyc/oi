#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int MAXM = 3007;
const int MAXN = 1e7+7;
// const int dj[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
// const int di[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int di[3] = {1, 1, 1};
const int dj[3] = {-1, 0, 1};
const int INF = 2147483647;

typedef pair<int, int> pii;

int n, m;
int gans = INF;
int a[MAXM][MAXM] = {0};
int d[MAXN], v[MAXN] = {0};
priority_queue<pii, vector<pii>, greater<pii> > q;

int get_node_id(int y, int x){
  return m * y + x;
}

pii get_pos(int node_id){
  return make_pair(node_id / m, node_id % m);
}

int main(){
  freopen("compress.in", "r", stdin);
  freopen("compress.ans", "w", stdout);

  memset(d, 0x3f, sizeof(d));
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &a[i][j]);
    }
  }

  // for(int i=0; i<n; i++){
  //   for(int j=0; j<m; j++){
  //     cout << "(" << get_pos(get_node_id(i, j)).first << ", " << get_pos(get_node_id(i, j)).second << ") ";
  //   }
  //   cout << endl;
  // }

  for(int i=0; i<m; i++){
    d[get_node_id(0, i)] = a[0][i];
    q.push(make_pair(a[0][i], get_node_id(0, i)));
  }

  while(!q.empty()){
    int node_id = q.top().second;
    q.pop();
    if(v[node_id]) continue;
    v[node_id] = 1;
    if(get_pos(node_id).first == n){
      gans = min(gans, d[node_id]);
      continue;
    }
    int i = get_pos(node_id).first, j = get_pos(node_id).second;
    for(int k=0; k<3; k++){
      int ci = i + di[k], cj = (j + dj[k] + m) % m;
      if(ci < 0 || ci > n) continue;
      int cnode = get_node_id(ci, cj);
      if(!v[cnode] && d[node_id] + a[ci][cj] < d[cnode]){
        d[cnode] = d[node_id] + a[ci][cj];
        q.push(make_pair(d[cnode], cnode));
      }
    }
  }

  printf("%d", gans);

  return 0;
}
