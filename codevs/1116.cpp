#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 11;

int n;
int mat[MAXN][MAXN] = {0};
int co[MAXN] = {0};
int cnt = 0;

void dfs(int l){
  if(l > n){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(mat[i][j] && co[i] == co[j]){
          return;
        }
      }
    }
    ++cnt;
    return;
  }
  for(int i=1; i<=4; i++){
    co[l] = i;
    dfs(l+1);
  }
}

int main(){
  // freopen("1116.txt", "r", stdin);
  cin >> n;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cin >> mat[i][j];
    }
  }
  dfs(1);
  cout << cnt;
  return 0;
}
