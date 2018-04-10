#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

const int MAXN = 1507;

typedef pair<int, int> pii;
int n, m;
int si, sj;
char mat[MAXN][MAXN];
int v[MAXN][MAXN], cc[MAXN][MAXN];

int main(){
  freopen("1363.txt", "r", stdin);
  while(scanf("%d%d", &n, &m) == 2){
    memset(v, 0, sizeof(v));
    memset(cc, 0, sizeof(cc));
    for(int i=0; i<n; i++){
      cin >> mat[i];
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(mat[i][j] == 'S'){
          si = i;
          sj = j;
          break;
        }
        // cout << mat[i][j] << " ";
      }
      // cout << endl;
    }
    queue<pii> q;
    q.push(make_pair(si, sj));
    while(!q.empty()){
      pii cur = q.front();
      q.pop();
      int ti = cur.first, tj = cur.second;
      if(ti < 0 || ti >= n || tj < 0 || tj >= m || v[ti][tj] || mat[ti][tj] == '#') continue;
      v[ti][tj] = 1;
      cc[ti][tj] = 1;
      q.push(make_pair((ti+1+n)%n, (tj+m)%m));
      q.push(make_pair((ti+n)%n, (tj+1+m)%m));
      q.push(make_pair((ti-1+n)%n, (tj+m)%m));
      q.push(make_pair((ti+n)%n, (tj-1+m)%m));
    }
    bool ct = false;
    for(int i=0; i<n; i++){
      if(cc[i][0] == 1 && cc[i][m-1] == 1){
        ct = true;
      }
    }
    for(int i=0; i<m; i++){
      if(cc[0][i] == 1 && cc[n-1][i] == 1){
        ct = true;
      }
    }
    if(ct){
      printf("Yes\n");
    }else{
      printf("No\n");
    }
  }

  return 0;
}
