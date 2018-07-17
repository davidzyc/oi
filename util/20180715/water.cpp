#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 207;
const int MAXM = 2e4+7;

int n, m;
int from[MAXM], to[MAXM], w[MAXM];
int d[MAXN][MAXN];

bool chk(double ans){
  double f, t;
  for(int e=2; e<=m*2; e+=2){
    f = t = w[e] * 1.0;
    for(int i=1; i<=n; i++){
      f = min(f, d[i][from[e]])
    }
  }
}

int main(){

  memset(d, 0x3f, sizeof(d));

  int x, y, z;

  scanf("%d%d", &n, &m);

  for(int i=1; i<=m; i++){
    scanf("%d%d%d", &x, &y, &z);
    from[i*2] = to[i*2+1] = x;
    to[i*2] = from[i*2+1] = y;
    w[i*2] = w[i*2+1] = z;
    d[x][y] = d[y][x] = z;
  }

  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  double lb = 0.0, ub = 2100000000.0;
  for(int i=1; i<=100; i++){
    int mid = (lb + ub )/2;
    if(chk(mid)){
      lb = mid;
    }else{
      ub = mid;
    }
  }

  printf("%.2f", lb);

  return 0;
}
