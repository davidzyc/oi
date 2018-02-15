#include<cstdio>
#include<iostream>
#define MAXN 4005
#define INF 2100000000
using namespace std;

int n, k, a[MAXN];
int p[MAXN], plen, pcenter;
int pmax[MAXN][MAXN] = {0}, pmaxp[MAXN][MAXN] = {0};
int dp[MAXN][MAXN][2];

int main(){
  int nsum = 0;
  cin >> n >> k;
  for(int i=0; i<n; i++){
    cin >> a[i];
    nsum += a[i];
    a[i+n] = a[i];
  }
  plen = 2*n-2*k-1;
  pcenter = n-k;
  for(int i=1; i<=plen; i++){
    p[i] = a[i+k];
    pmax[i][i] = p[i];
    // cout << p[i] << " ";
  }
  // cout << endl;
  // cout << endl << pcenter << endl;
  for(int len=1; len<n; len++){
    for(int l=1, r; (r=l+len)<=plen; l++){
      pmax[l][r] = max(pmax[l][r-1], pmax[r][r]);
      // cout << pmax[l][r] << " ";
    }
    // cout << endl;
  }
  for(int len=1; len<n; len++){
    for(int l=1, r; (r=l+len)<=plen; l++){
      int lpos = max(0, r-n);
      pmaxp[l][r] = max(pmax[lpos+1][l-1], pmax[r+1][lpos+n]);
      // cout << l << " " << r << " : " << lpos+1 << " " << l-1 << " | " << r+1 << " " << lpos+n << " " << pmaxp[l][r] << endl;
      // cout << pmaxp[l][r] << " ";
    }
    // cout << endl;
  }
  for(int i=1; i<=plen; i++){
    for(int j=1; j<=plen; j++){
      dp[i][j][0] = dp[i][j][1] = INF;
    }
  }
  int minans = INF;
  dp[pcenter-k][pcenter+k][0] = dp[pcenter-k][pcenter+k][1] = 0;
  for(int pl=1; pl<pcenter-k; pl++){
    for(int l=pcenter-pl-k, r; (r=l+pl+k*2)<=pcenter+pl+k; l++){
      dp[l][r][0] = min(dp[l+1][r][0]+pmaxp[l+1][r], dp[l+1][r][1]+pmaxp[l+1][r]*(r-l-2*k));
      dp[l][r][1] = min(dp[l][r-1][1]+pmaxp[l][r-1], dp[l][r-1][0]+pmaxp[l][r-1]*(r-l-2*k));
      // cout << l << " " << r << " : ";
      // cout << dp[l][r][0] << " " << dp[l][r][1] << endl;
      if(pl == pcenter-k-1){
        minans = min(minans, dp[l][r][0]);
        minans = min(minans, dp[l][r][1]);
      }
    }
    // cout << endl;
  }
  cout << minans + nsum << endl;

  return 0;
}
