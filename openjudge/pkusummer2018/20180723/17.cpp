#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXV = 10007;
const int MAXN = 207;

typedef long long ll;

int n, v;
int a[MAXN];
int dp[MAXV] = {0};
int dplast[MAXV];
int mustcnt = 0;
int mustuse[MAXN];

int main(){
  scanf("%d%d", &n, &v);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);
  sort(a+1, a+1+n);
  dp[0] = 1;
  for(int i=1; i<=n; i++){
    for(int j=v; j>=0; j--){
      if(j-a[i] >= 0){
        dp[j] += dp[j-a[i]];
        if(dp[j-a[i]]) dplast[j] = j-a[i];
      }
    }
      // for(int i=0; i<=v; i++) cout << dplast[i] << " ";
      // cout << endl;
  }
  // for(int i=0; i<=v; i++) cout << dp[i] << " ";
  // cout << endl;
  // for(int i=0; i<=v; i++) cout << dplast[i] << " ";
  int x = v;
  while(x){
    int nxt = dplast[x];
    if(dp[nxt] == dp[x]){
      mustuse[mustcnt++] = x - nxt;
    }
    x = nxt;
  }
  sort(mustuse, mustuse+mustcnt);
  printf("%d\n", mustcnt);
  for(int i=0; i<mustcnt; i++) printf("%d ", mustuse[i]);


  return 0;
}
