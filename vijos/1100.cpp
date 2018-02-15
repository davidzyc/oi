#include<cstdio>
#include<iostream>
#define MAXN 35
using namespace std;

int dp[MAXN][MAXN] = {0};
int s[MAXN][MAXN] = {0};
int n, a[35];

int dfs(int i, int j){
  if(i > j){
    return 1;
  }
  if(dp[i][j] != 0){
    return dp[i][j];
  }
  int ltree, rtree;
  dp[i][j] = 0;
  for(int k=i; k<=j; k++){
    ltree = dfs(i, k-1);
    rtree = dfs(k+1, j);
    if(dp[i][j] < a[k] + ltree * rtree){
      dp[i][j] = a[k] + ltree * rtree;
      s[i][j] = k;
    }
  }
  // cout << i << " " << j << " " << dp[i][j] << endl;
  return dp[i][j];
}

void preorder(int i, int j){
  if(i>j) return;
  int k = s[i][j];
  if(k){
    cout << k << " ";
    preorder(i, k-1);
    preorder(k+1, j);
  }
}

int main(){
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> a[i];
    dp[i][i] = a[i];
    s[i][i] = i;
  }
  cout << dfs(1, n) << endl;
  preorder(1, n);
  return 0;
}
