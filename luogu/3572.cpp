#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

const int MAXN = 2e6+7;

int n, q, k;
int h[MAXN];
int dp[MAXN];
int qs = 1, qe = 1, que[MAXN];

int read(){
  char c = getchar();
  int ret = 0;
  for(;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar()) ret = ret*10+c-'0';
  return ret;
}

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    // scanf("%d", &h[i]);
    h[i] = read();
  }
  scanf("%d", &q);
  while(q--){
    scanf("%d", &k);
    memset(dp, 0x3f, sizeof(dp));
    memset(que, 0, sizeof(que));
    qs = qe = 1;
    dp[1] = 0;
    que[qe++] = 1;
    for(int i=2; i<=n; i++){
      // for(int j=qs; j<qe; j++) cout << que[j] << " ";
      // cout << endl;
      if(qs < qe && que[qs] + k < i) que[qs] = 0, qs++;
      dp[i] = dp[que[qs]] + (h[que[qs]] <= h[i] ? 1 : 0);
      while(qs < qe && (dp[que[qe-1]] > dp[i] || (dp[que[qe-1]] == dp[i] && h[que[qe-1]] <= h[i]))){
        --qe;
      }
      que[qe] = i;
      ++qe;
      // for(int j=max(1, i-k); j<i; j++){
      //   dp[i] = min(dp[i], dp[j] + (h[j] <= h[i] ? 1 : 0));
      // }
    }
    printf("%d\n", dp[n]);
  }

  return 0;
}
