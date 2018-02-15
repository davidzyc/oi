#include<cstdio>
#include<iostream>
#define MAXN 10005
using namespace std;

int dp[MAXN][2][2][2] = {0};
const int pn[4][3][3] = { {{0, 0, 0}} , {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}} , {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}} , {{1, 1, 1}} };
const int ps[4] = {1, 3, 3, 1};

int main(){
  int n, a[MAXN];
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> a[i];
  }
  dp[0][0][0][1] = dp[0][0][0][0] = 1;
  for(int i=1; i<=n; i++){
    int pno = a[i];
    int psize = ps[pno];
    for(int j=0; j<psize; j++){
      dp[i][pn[pno][j][0]][pn[pno][j][1]][pn[pno][j][2]] = dp[i-1][0][pn[pno][j][0]][pn[pno][j][1]] + dp[i-1][1][pn[pno][j][0]][pn[pno][j][1]];
    }
  }
  int ans = 0;
  int pno = a[n];
  int psize = ps[pno];
  for(int j=0; j<psize; j++){
    ans += dp[n][pn[pno][j][0]][pn[pno][j][1]][0];
  }
  cout << ans;
  return 0;
}
