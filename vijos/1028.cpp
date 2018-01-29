#include<cstdio>
#include<iostream>
#include<cstring>
#define MAX_N 2005
using namespace std;

string s[MAX_N];
int dp[MAX_N], nmax = 0;

bool checkcipher(int pre, int a){
  for(int i=0; i<s[pre].length(); i++){
    if(s[pre][i] != s[a][i]) return false;
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> s[i];
  }
  for(int i=0; i<n; i++){
    dp[i]= 1;
    for(int j=0; j<i; j++){
      if(checkcipher(j, i)){
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    nmax = max(nmax, dp[i]);
  }

  cout << nmax;

  return 0;
}
