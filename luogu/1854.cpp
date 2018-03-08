#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 101;
const int INF = 2100000000;
int f, v;
int mat[MAXN][MAXN] = {0};
int last[MAXN][MAXN] = {0};
int maxpath[MAXN];
int pcnt;

void find_path(int tf, int a){
  if(a == 0 || !tf){
    pcnt = 0;
    return;
  }
  find_path(tf-1, last[tf][a]);
  // cout << tf << " " << a << endl;
  maxpath[pcnt] = a;
  ++pcnt;
  return;
}

int main(){
  freopen("1854.txt", "r", stdin);
  int temp;
  cin >> f >> v;
  for(int i=1; i<=f; i++){
    for(int j=0; j<=v; j++){
      mat[i][j] = -INF;
    }
  }
  for(int i=1; i<=f; i++){
    for(int j=1; j<=v; j++){
      cin >> mat[i][j];
      if(i == 1){
        temp = 0;
      }else{
        temp = -INF;
      }
      for(int k=1; k<j; k++){
        if(mat[i-1][k] > temp){
          temp = max(temp, mat[i-1][k]);
          last[i][j] = k;
        }
      }
      mat[i][j] += temp;
    }
  }
  int ans = -INF;
  for(int j=f; j<=v; j++){
    if(mat[f][j] > ans){
      ans = max(ans, mat[f][j]);
      find_path(f, j);
    }
  }
  cout << ans << endl;
  for(int i=0; i<pcnt; i++){
    cout << maxpath[i] << " ";
  }
  return 0;
}
