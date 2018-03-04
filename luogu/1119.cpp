#include<cstdio>
#include<iostream>
#define MAXN 201
#define INF 100000000
using namespace std;

int n, m;
int rebt[MAXN];
int orig[MAXN][MAXN], path[MAXN][MAXN];

int main(){
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      orig[i][j] = INF;
      path[i][j] = INF;
    }
  }
  for(int i=0; i<n; i++){
    cin >> rebt[i];
  }
  int tfrom, tto, tw, tt;
  for(int i=0; i<m; i++){
    cin >> tfrom >> tto >> tw;
    orig[tfrom][tto] = tw;
    orig[tto][tfrom] = tw;
  }
  int cur = 0;
  int q;
  cin >> q;
  for(int i=0; i<q; i++){
    cin >> tfrom >> tto >> tt;
    while(rebt[cur] <= tt && cur < n){
      for(int j=0; j<cur; j++){
        path[cur][j] = min(path[cur][j], orig[cur][j]);
        path[j][cur] = min(path[j][cur], orig[j][cur]);
      }
      // for(int tk=0; tk<=cur; tk++){
      for(int tk=0; tk<cur; tk++){
        for(int ti=0; ti<cur; ti++){
          if(ti == tk) continue;
          path[ti][cur] = min(path[ti][cur], path[ti][tk]+path[tk][cur]);
          path[cur][ti] = min(path[cur][ti], path[cur][tk]+path[tk][ti]);
        }
      }
        for(int ti=0; ti<n; ti++){
          for(int tj=0; tj<n; tj++){
            if(ti == tj) continue;
            path[ti][tj] = min(path[ti][tj], path[ti][cur]+path[cur][tj]);
          }
        }
      // }
      cur++;
    }
    // cout << endl;
    // for(int ti=0; ti<n; ti++){
    //   for(int tj=0; tj<n; tj++){
    //     cout << path[ti][tj] << " ";
    //   }
    //   cout << endl;
    // }
    if(path[tfrom][tto] < INF){
      cout << path[tfrom][tto] << endl;
    }else{
      cout << -1 << endl;
    }
  }

  return 0;
}
