#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 5001;

int n;
int num[MAXN], dp[MAXN];
int gmax = 0;

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &num[i]);
    dp[i] = 1;
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<i; j++){
      if(num[j] < num[i]){
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    gmax = max(gmax, dp[i]);
  }
  printf("%d", gmax);

  return 0;
}
