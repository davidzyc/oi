#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

const int MAXN = 105;

int n;
char c[MAXN];
int dp[MAXN][2] = {0};

int main(){
  scanf("%d", &n);
  if(n == 0){
    cout << 0 << endl;
    return 0;
  }
  cin >> c;
  for(int i=1; i<n; i++){
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
    if(c[i-1] != c[i]){
      dp[i][1] = dp[i-1][0] + 1;
    }
  }
  cout << n - max(dp[n-1][0], dp[n-1][1]);

  return 0;
}
