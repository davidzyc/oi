#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXLEN 105
using namespace std;

int main(){
  int dp[MAXLEN][MAXLEN];
  string s, subs;
  int tot, maxlen, slen, sublen;
  while(cin >> s >> subs){
    tot = 0;
    maxlen = 0;
    slen = s.length();
    sublen = subs.length();
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<s.length(); i++){
      for(int j=0; j<subs.length(); j++){
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j+1]);
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]);
        if(s[i] == subs[j]){
          dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
          if(dp[i][j]+1 == sublen){
            cout << i << " " << j << endl;
            tot++;
          }
          // if(j == sublen - 1){
          //   tot++;
          // }
        }
      }
    }
    cout << dp[slen][sublen] << endl;
    cout << tot << endl;
  }

  return 0;
}
