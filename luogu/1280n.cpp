#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 10001
using namespace std;

int n, k;
int l[MAXN], from[MAXN], to[MAXN], dp[MAXN], first[MAXN] = {0}, nxt[MAXN] = {0};

int main(){
  cin >> n >> k;
  for(int i=1; i<=n; i++){
    dp[i] = -1;
  }
  for(int i=1; i<=k; i++){
    cin >> to[i] >> l[i];
    from[i] = to[i] + l[i];
    int t;
    t = first[from[i]];
    first[from[i]] = i;
    nxt[i] = t;
  }

  for(int i=n+1; i>0; i--){
    if(dp[i] == -1){
      dp[i] = dp[i+1]+1;
    }
    for(int j=first[i]; j!=0; j=nxt[j]){
      dp[to[j]] = max(dp[to[j]], dp[i]);
    }
  }
  cout << dp[1];
  // for(int i=1; i<=n+1; i++){
  //   cout << dp[i] << " ";
  // }

  return 0;
}
