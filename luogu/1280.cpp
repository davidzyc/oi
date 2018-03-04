#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXN 10001
#define INF 2100000000
using namespace std;

int n, k;
int s[MAXN], l[MAXN], e[MAXN], id[MAXN];
int dp[MAXN];

bool cmp(int a, int b){
  return s[a] < s[b];
}

int main(){
  cin >> n >> k;
  for(int i=0; i<k; i++){
    cin >> s[i] >> l[i];
    // s[i] --;
    e[i] = s[i] + l[i] - 1;
    id[i] = i;
  }
  s[k] = e[k] = n+1;
  l[k] = 0;
  id[k] = k;
  sort(id, id+k+1, cmp);
  int ti, tj, lts = 0, lastlts = 0;
  for(int i=0; i<=k; i++){
    ti = id[i];
    if(s[i] != lts){
      lastlts = lts;
      lts = s[i];
    }
    dp[ti] = INF;
    for(int j=0; j<i; j++){
      tj = id[j];
      if(e[tj] >= lastlts && e[tj] < s[ti]){
        cout << tj << " -> " << ti << endl;
        dp[ti] = min(dp[ti], dp[tj]);
      }
    }
    if(dp[ti] == INF){
      dp[ti] = 0;
    }
    dp[ti] += l[ti];
    if(i == k) cout << "lts: " << lts << " lastlts:" << lastlts << endl;
    cout << dp[ti] << " ";
  }
  cout << n-dp[id[k]];

  return 0;
}
