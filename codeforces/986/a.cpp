#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXG = 101;
const int MAXN = 1e5+7;

typedef pair<int, int> pii;

int n, m, s, k;
vector<int> to[MAXN];
vector<int> gn[MAXG];
int origg[MAXN];
int distg[MAXN][MAXG];
int v[MAXN];
int tsort[MAXG];
queue<pii> q;

int main(){
  memset(distg, 0x3f, sizeof(distg));
  int tf, tt;
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for(int i=1; i<=n; i++){
    scanf("%d", &origg[i]);
    gn[origg[i]].push_back(i);
  }
  for(int i=0; i<m; i++){
    scanf("%d%d", &tf, &tt);
    to[tf].push_back(tt);
    to[tt].push_back(tf);
  }
  for(int i=1; i<=k; i++){
    memset(v, 0, sizeof(v));
    // q.clear();
    while(!q.empty()) q.pop();
    for(int j=0; j<gn[i].size(); j++){
      int x = gn[i][j];
      q.push(make_pair(x, 0));
    }
    while(!q.empty()){
      pii tp = q.front();
      q.pop();
      int x = tp.first, td = tp.second;
      if(v[x]) continue;
      v[x] = 1;
      distg[x][i] = td;
      for(int h=0; h<to[x].size(); h++){
        int y = to[x][h];
        q.push(make_pair(y, td+1));
      }
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=k; j++){
      tsort[j] = distg[i][j];
    }
    sort(tsort+1, tsort+k+1);
    int ans = 0;
    for(int j=1; j<=s; j++){
      ans += tsort[j];
    }
    printf("%d ", ans);
  }


  return 0;
}
