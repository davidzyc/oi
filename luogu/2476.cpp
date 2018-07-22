#include<cstdio>
#include<iostream>

using namespace std;

typedef long long ll;

const ll GMOD = 1000000007;
const int MAXM = 100;
const int MAXN = 20;

int n;
int a[MAXN], s[MAXN];
ll c[MAXM][MAXM] = {0};
ll dp[MAXN][MAXM] = {0};

ll cptc(int i, int j, int k){
  ll ret = 0;
  // for(int k=j; k>=1; k-=2){
  //   ret += c[i-(j-k)/2][k];
  // }
  // cout << "CPTC - " << i << " " << j << " " << k << endl;
  for(int h=0; h<=k; h++){
    if(i-h < 0 || j-2*h < 0) break;
    ret += ((c[i-h][j-2*h] % GMOD) * (c[k][h] % GMOD)) % GMOD;
    ret %= GMOD;
  }
  // return c[i][j];
  return ret;
}

int main(){
  c[0][0] = 1;
  for(int i=1; i<MAXM; i++){
    for(int j=0; j<=i; j++){
      c[i][j] = c[i-1][j];
      if(j-1 >= 0)  c[i][j] += c[i-1][j-1];
      c[i][j] %= GMOD;
    }
  }
  // for(int i=1; i<MAXM; i++){
  //   for(int j=0; j<=i; j++){
  //     cout << c[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  for(int i=1; i<=n; i++){
    s[i] = s[i-1] + a[i];
  }
  for(int i=1; i<=n; i++){
    s[i] ++;
    // cout << s[i] << " ";
  }
  dp[1][a[1]-1] = 1;
  for(int k=2; k<=n; k++){
    for(int i=0; i<=s[k]-1-k; i++){
      dp[k][i] += (dp[k-1][i] * cptc(s[k-1]-i, a[k], i)%GMOD);
      dp[k][i] %= GMOD;
      printf("S I k:%d, i:%d - %d\n", k, i, dp[k][i]);
      for(int j=max(0, i-a[k]+1); j<i; j++){
        dp[k][i] += dp[k-1][j] * c[s[k-1]-j][a[k]-i+j] % GMOD;
        // dp[k][i] += (dp[k-1][j] * cptc(s[k-1]-j, a[k]-i+j, i)%GMOD);
        dp[k][i] %= GMOD;
      }
      printf("L I k:%d, i:%d - %d\n", k, i, dp[k][i]);
      for(int j=i+1; j<=(i+a[k]); j++){
        dp[k][i] += dp[k-1][j] * (c[s[k-1]-j][a[k]-j+i] * c[j][j-i] % GMOD) % GMOD;
        // dp[k][i] += (dp[k-1][j] * cptc(s[k-1]-j, a[k]-j+i, i) * c[j][j-i]%GMOD);
        dp[k][i] %= GMOD;
      }
      printf("H I k:%d, i:%d - %d\n", k, i, dp[k][i]);
      dp[k][i] %= GMOD;
      cout << endl;
    }
  }
  for(int k=2; k<=n; k++){
    for(int i=0; i<=s[k]-1-k; i++){
      printf("k:%d, i:%d - %lld\n", k, i, dp[k][i]);
    }
    printf("\n");
  }
  printf("%lld", dp[n][0] % GMOD);
  return 0;
}
