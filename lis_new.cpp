#include<cstdio>
#include<iostream>
using namespace std;

const int MAXN = 1000;

int n;
int a[MAXN];
int sprev[MAXN] = {0};
int dp[MAXN];

void print_seq(int p){
  if(!p) return;
  print_seq(sprev[p]);
  printf("%d ", a[p]);
  return;
}

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  int gans = 0;
  int gend;
  //DP
  for(int i=1; i<=n; i++){
    for(int j=1; j<i; j++){
      if(a[i] > a[j] && dp[j] > dp[i]){
        dp[i] = dp[j];
        sprev[i] = j;
      }
    }
    dp[i] ++;
    if(dp[i] > gans){
      gans = dp[i];
      gend = i;
    }
  }
  printf("%d\n", gans);
  print_seq(gend);
  return 0;
}
