#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXLEN 105
using namespace std;

int dp[MAXLEN][MAXLEN];

int main(){
  string a, b;
  int pos, totlen, alen, blen;
  while(cin >> a >> b){
    totlen = 0;
    alen = a.length();
    blen = b.length();
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<alen; i++){
      for(int j=0; j<blen; j++){
        dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        if(a[i] == b[j]){
          // cout << a[i] << " ";
          dp[i+1][j+1] = max(dp[i][j]+1, dp[i+1][j+1]);
        }
      }
    }
    cout << alen + blen - dp[alen][blen] << endl;
  }

  return 0;
}
