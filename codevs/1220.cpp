#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 101;

int n;
int mat[MAXN][MAXN];
int dp[MAXN][MAXN] = {0};

int main(){

  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=i; j++){
      scanf("%d", &mat[i][j]);
    }
  }
  for(int i=n-1; i>=1; i--){
    for(int j=1; j<=i; j++){
      mat[i][j] += max(mat[i+1][j], mat[i+1][j+1]);
      // dp[i][j] += mat[i][j];
    }
  }
  printf("%d", mat[1][1]);
  return 0;
}
