#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int MAXL = 23;
const int MAXN = 1e6+7;

int n, m, q;
int tp[MAXL];
int dat[MAXN][MAXL];

int main(){

  scanf("%d", &n);
  m = (int)(log(n)/log(2))+1;
  tp[0] = 1;
  for(int i=1; i<=m; i++){
    tp[i] = tp[i-1]*2;
  }
  for(int i=1; i<=n; i++){
    scanf("%d", &dat[i][0]);
  }
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n+1-tp[i]; j++){
      dat[j][i] = min(dat[j][i-1], dat[j+tp[i-1]][i-1]);
      // cout << dat[j][i] << " ";
    }
    // cout << endl;
  }
  int qb, lb, ub;
  scanf("%d", &q);
  for(int i=0; i<q; i++){
    scanf("%d%d", &lb, &ub);
    qb = (int) (log(ub - lb + 1)/log(2));
    printf("%d\n", min(dat[lb][qb], dat[ub+1-tp[qb]][qb]));
  }

  return 0;
}
