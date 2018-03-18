#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 400;
const int MAXC = 41;

int n, m;
int a[MAXN];
int c[5] = {0};
int dp[MAXC][MAXC][MAXC][MAXC] = {0};

int main(){
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  int t;
  for(int i=0; i<m; i++){
    scanf("%d", &t);
    c[t]++;
  }
  for(int c_one=0; c_one<=c[1]; c_one++){
    for(int c_two=0; c_two<=c[2]; c_two++){
      for(int c_three=0; c_three<=c[3]; c_three++){
        for(int c_four=0; c_four<=c[4]; c_four++){
          if(c_one>0){
            dp[c_one][c_two][c_three][c_four] = max(dp[c_one][c_two][c_three][c_four], dp[c_one-1][c_two][c_three][c_four]);
          }
          if(c_two>0){
            dp[c_one][c_two][c_three][c_four] = max(dp[c_one][c_two][c_three][c_four], dp[c_one][c_two-1][c_three][c_four]);
          }
          if(c_three>0){
            dp[c_one][c_two][c_three][c_four] = max(dp[c_one][c_two][c_three][c_four], dp[c_one][c_two][c_three-1][c_four]);
          }
          if(c_four>0){
            dp[c_one][c_two][c_three][c_four] = max(dp[c_one][c_two][c_three][c_four], dp[c_one][c_two][c_three][c_four-1]);
          }
          int pos = c_one*1 + c_two*2 + c_three*3 + c_four*4;
          dp[c_one][c_two][c_three][c_four] += a[pos];
        }
      }
    }
  }
  printf("%d", dp[c[1]][c[2]][c[3]][c[4]]);
  return 0;
}
