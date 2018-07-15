#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 2007;
const int MAXC = 2000;

int c[MAXN][MAXN] = {0};
int cnt[MAXN][MAXN] = {0};

int n, m;

int main(){
  scanf("%d%d", &n, &m);
  c[0][0] = 1;
  for(int i=1; i<=MAXC; i++){
    for(int j=0; j<=i; j++){
      c[i][j] = c[i-1][j];
      if(j) c[i][j] += c[i-1][j-1];
      c[i][j] %= m;
      // printf("C(%d, %d)=%d ",i, j, c[i][j]);
      if(!c[i][j]) {cnt[i][j]++;}

    }
  }

  for(int i=0; i<=MAXC; i++){
    for(int j=0; j<=MAXC; j++){
      if(i) cnt[i][j] += cnt[i-1][j];
      if(j) cnt[i][j] += cnt[i][j-1];
      if(i && j) cnt[i][j] -= cnt[i-1][j-1];
    }
  }

  for(int i=0; i<n; i++){
    int opn, opm;
    // cout << "HI";
    scanf("%d%d", &opn, &opm);
    printf("%d\n", cnt[opn][min(opn, opm)]);
  }


  return 0;
}
