#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>

using namespace std;

const int MAXN = 1e4+7;

int tset;
int n, m;
int v[MAXN];
int clr[MAXN];
bool tflag = true;
vector<int> to[MAXN];

void dfs(int x){
  if(!tflag) return;
  v[x] = 1;
  for(int i=0; i<to[x].size(); i++){
    int y = to[x][i];
    if(v[y] && clr[y] != (clr[x]^1)){
      // cout << x << " " << y << " Wrong!!!";
      tflag = false;
      return;
    }
    if(!v[y]){
      clr[y] = (clr[x] ^ 1);
      dfs(y);
    }
  }
  return;
}

int main(){
  int tf, tt;
  scanf("%d", &tset);
  while(tset--){
    tflag = true;
    memset(v, 0, sizeof(v));
    memset(clr, 0, sizeof(clr));
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
      to[i].clear();
    }
    for(int i=0; i<m; i++){
      scanf("%d%d", &tf, &tt);
      to[tf].push_back(tt);
      to[tt].push_back(tf);
    }
    for(int i=1; i<=n; i++){
      if(!tflag) break;
      if(!v[i]){
        dfs(i);
      }
    }
    // for(int i=1; i<=n; i++){
    //   cout << clr[i] << " ";
    // }
    tflag ? printf("Correct\n") : printf("Wrong\n");
  }


  return 0;
}
