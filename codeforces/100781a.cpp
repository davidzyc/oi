#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int MAXN = 1e5+7;

int n, m;
vector<int> to[MAXN];
int dep[MAXN], v[MAXN], globalv[MAXN];
int treecnt = 0, tmaxdep[MAXN], tmaxid[MAXN], tmidid[MAXN], tsta[MAXN];
int gmaxdep = 0, gmidid;
int ans = 0, gdep[MAXN];

void ginit(){
  memset(globalv, 0, sizeof(globalv));
}

void dfs(int x){
  // cout << x << " ";
  v[x] = 1, globalv[x] = 1;
  tsta[dep[x]] = x;
  if(dep[x] > tmaxdep[treecnt]){
    tmaxdep[treecnt] = dep[x];
    tmaxid[treecnt] = x;
    tmidid[treecnt] = tsta[(dep[x]+1)/2];
  }
  for(int i=0; i<to[x].size(); i++){
    int y = to[x][i];
    if(v[y]) continue;
    dep[y] = dep[x] + 1;
    dfs(y);
  }
  // cout << x << " ";
}

// void dfsdep(int x){
//   v[x] =  1;
//   for(int i=0; i<to[x].size(); i++){
//     int y = to[x][i];
//     if(v[y]) continue;
//     dfsdep(y);
//     dep[y] = dep[x]+1;
//   }
// }

int main(){
  ginit();
  int tf, tt;
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++){
    scanf("%d%d", &tf, &tt);
    // ++tf, ++tt;
    to[tf].push_back(tt);
    to[tt].push_back(tf);
  }

  for(int i=0; i<n; i++){
    if(globalv[i]) continue;
    memset(v, 0, sizeof(v));
    ++treecnt;
    dep[i] = 1;
    dfs(i);
    memset(v, 0, sizeof(v));
    dep[tmaxid[treecnt]] = 1;
    dfs(tmaxid[treecnt]);
    if(tmaxdep[treecnt] > gmaxdep){
      gmaxdep = tmaxdep[treecnt];
      gmidid = tmidid[treecnt];
    }
    // printf("%d: maxdep %d - maxid %d - mid %d\n", treecnt, tmaxdep[treecnt], tmaxid[treecnt], tmidid[treecnt]);
  }
  for(int i=1; i<=treecnt; ++i){
    if(tmidid[i] != gmidid){
      // printf("Connect %d - %d\n", tmidid[i], gmidid);
      to[tmidid[i]].push_back(gmidid);
      to[gmidid].push_back(tmidid[i]);
    }
  }
  memset(v, 0, sizeof(v));
  // memset(globalv, 0, sizeof(globalv));
  ++treecnt;
  dep[0] = 1;
  dfs(0);
  memset(v, 0, sizeof(v));
  // memset(globalv, 0, sizeof(globalv));
  dep[tmaxid[treecnt]] = 1;
  dfs(tmaxid[treecnt]);

  printf("%d\n", tmaxdep[treecnt] - 1);

  return 0;
}
