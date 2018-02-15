#include<cstdio>
#include<iostream>
#define MAXN 25
#define INF 2100000000
using namespace std;

int n, a[MAXN], s[MAXN];
int dp[MAXN][MAXN] = {0};
int sep[MAXN][MAXN];
int bef[MAXN] = {0}, aft[MAXN] = {0};

void dfs(int l, int r, int type){
  if(r-l > 0){
    int k;
    k = sep[l][r];
    dfs(l, k, type);
    dfs(k+1, r, type);
    if(type == 0){
      bef[l] ++;
      aft[r] ++;
    }else{
      cout << s[r] - s[l-1] << " ";
    }
  }
  return;
}

int main(){
  cin >> n;
  s[0] = 0;
  for(int i=1; i<=n; i++){
    cin >> a[i];
    s[i] = s[i-1] + a[i];
    sep[i][i] = i;
  }
  for(int len=1; len<n; len++){
    for(int l=1, r; (r=l+len)<=n; l++){
      dp[l][r] = INF;
      for(int k=l; k<r; k++){
        if(dp[l][r] >= dp[l][k]+dp[k+1][r]+s[r]-s[l-1]){
          dp[l][r] = dp[l][k]+dp[k+1][r]+s[r]-s[l-1];
          sep[l][r] = k;
        }
      }
    }
  }
  dfs(1, n, 0);
  for(int i=1; i<=n; i++){
    for(int j=0; j<bef[i]; j++) cout << "(";
    cout << a[i];
    for(int j=0; j<aft[i]; j++) cout << ")";
    if(i!=n) cout << "+";
  }
  cout << endl << dp[1][n] << endl;
  dfs(1, n, 1);
  // cout << endl << sep[1][n];
  return 0;
}
