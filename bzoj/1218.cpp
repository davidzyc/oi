#include<cstdio>
#include<iostream>
#define MAXN 5002
using namespace std;

int r, n;
int s[MAXN][MAXN] = {0};

int main(){
  int tx, ty;
  cin >> n >> r;
  for(int i=0; i<n; i++){
    cin >> tx >> ty;
    cin >> s[ty][tx];
  }
  for(int i=0; i<MAXN; i++){
    for(int j=0; j<MAXN; j++){
      if(i == 0 && j == 0) continue;
      if(i == 0){
        s[i][j] += s[i][j-1];
      }else if(j == 0){
        s[i][j] += s[i-1][j];
      }else{
        s[i][j] += s[i][j-1] + s[i-1][j] - s[i-1][j-1];
      }
    }
  }
  // for(int i=0; i<10; i++){
  //   for(int j=0; j<10; j++){
  //     cout << s[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  if(r == 0){
    cout << 0 << endl;
    return 0;
  }
  int gans = 0, tans;
  gans = max(gans, s[r-1][r-1]);
  for(int i=0; i<MAXN-r; i++){
    tans = s[i+r][r-1]-s[i][r-1];
    gans = max(gans, tans);
    tans = s[r-1][i+r]-s[r-1][i];
    gans = max(gans, tans);
  }
  for(int i=0; i<MAXN-r; i++){
    for(int j=0; j<MAXN-r; j++){
      tans = s[i][j] + s[i+r][j+r] - s[i][j+r] - s[i+r][j];
      gans = max(gans, tans);
    }
  }
  cout << gans << endl;

  return 0;
}
