#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 1007;

int n;
char s[MAXN];
int isp[MAXN][MAXN];
int dp[MAXN];

int main(){

  int tset;
  scanf("%d", &tset);
  while(tset--){
    memset(isp, 0, sizeof(isp));
    memset(s, 0, sizeof(s));
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    scanf("%s", s+1);
    n = strlen(s+1);
    int l, r;
    for(int i=1; i<=n; i++){
      l = r = i;
      // dp[l][r] = 1;
      for(; l>=1 && r <= n;--l,++r){
        if(s[l] != s[r]) break;
        isp[l][r] = 1;
      }
      if(l == n) continue;
      l = i, r = l+1;
      for(; l>=1 && r <= n;--l,++r){
        if(s[l] != s[r]) break;
        isp[l][r] = 1;
      }
    }
    for(int i=1; i<=n; i++){
      for(int j=1; j<=i; j++){
        if(isp[j][i]){
          dp[i] = min(dp[i], dp[j-1]+1);
        }
      }
    }
    printf("%d\n", dp[n] - 1);
  }


  return 0;
}
