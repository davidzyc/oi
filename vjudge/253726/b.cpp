#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 100007;

int n, m;
double v[MAXN];
int w[MAXN];
double dp[MAXN];

int main(){
  while(true){
    scanf("%d%d", &n, &m);
    if(n == 0 && m == 0) break;
    for(int i=0; i<MAXN; i++) dp[i] = 1.0;
    for(int i=0; i<MAXN; i++) v[i] = 0.0;
    memset(w, 0, sizeof(w));
    for(int i=1; i<=m; i++){
      scanf("%d%lf", &w[i], &v[i]);
      v[i] = 1.0 - v[i];
    }
    for(int i=1; i<=m; i++){
      for(int j=n; j>=w[i]; j--){
        dp[j] = min(dp[j], dp[j-w[i]]*v[i]);
      }
    }
    double gmin = 1.0;
    for(int i=0; i<=n; i++) gmin = min(gmin, dp[i]);
    // for(int i=0; i<=n; i++) cout << dp[i] << "\t";
    printf("%.1f%%\n", (1.0-gmin)*100);
  }

  return 0;
}
