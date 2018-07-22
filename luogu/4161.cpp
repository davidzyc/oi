#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 10007;

int n;
int pn = 0, v[MAXN] = {0}, p[MAXN] = {0};
int pk[MAXN];
ll dp[MAXN] = {0};

int main(){

  scanf("%d", &n);
  for(int i=2; i<=n; i++){
    if(!v[i]){
      p[pn++] = i;
      for(int j=i*2; j<=n; j+=i){
        v[j] = 1;
      }
    }
  }
  for(int i=0; i<=n; i++){
    dp[i] = 1;
  }
  for(int i=0; i<pn; i++){
      for(int j=n; j>=0; j--){
        for(int k=p[i]; k <= j; k*=p[i]){
          dp[j] += dp[j-k];
        }
      }
  }
  printf("%lld", dp[n]);

  return 0;
}
