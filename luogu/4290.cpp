#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int MAXN = 205;

int dic[20][5] = {0};
int dp[MAXN][MAXN][4] = {0};
char ci[5];
// w, i, n, g
int a[5];
char ch[MAXN];
int n;
char ans[4];

int getid(char c){
  if(c == 'W') return 0;
  if(c == 'I') return 1;
  if(c == 'N') return 2;
  if(c == 'G') return 3;
  return -1;
}

int main(){
  ans[0] = 'W';
  ans[1] = 'I';
  ans[2] = 'N';
  ans[3] = 'G';
  scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
  for(int i=0; i<4; i++){
    for(int j=0; j<a[i]; j++){
      scanf("%s", ci);
      dic[getid(ci[0])*4+getid(ci[1])][i] = 1;
    }
  }
  scanf("%s", ch+1);
  n = strlen(ch+1);
  for(int i=1; i<=n; i++){
    dp[i][i][getid(ch[i])] = 1;
  }
  for(int len=1; len<n; len++){
    for(int l=1, r; (r=l+len)<=n; l++){
      for(int mid=l; mid<r; mid++){
        for(int f=0; f<16; f++){
          if(dp[l][mid][f>>2] && dp[mid+1][r][f&3]){
            for(int t=0; t<4; t++){
              if(dic[f][t]) dp[l][r][t] = 1;
            }
          }
        }
      }
    }
  }
  int cnt = 0;
  for(int t=0; t<4; t++){
    if(dp[1][n][t]){
      printf("%c", ans[t]);
      ++cnt;
    }
  }
  if(!cnt){
    printf("The name is wrong!");
  }
  return 0;
}
