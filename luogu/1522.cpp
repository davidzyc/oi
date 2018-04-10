#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

const int MAXN = 155;
const double INF = 10000000000.0;

int n;
long long x[MAXN], y[MAXN];
double adjm[MAXN][MAXN];
char row[MAXN];
int fa[MAXN];
int scnt = 0;
double sp[MAXN];

double get_path(int i, int j){
  return sqrt((x[i]-x[j])*(x[i]-x[j])*1.0 + (y[i]-y[j])*(y[i]-y[j])*1.0);
}

void dfs(int x){
  fa[x] = scnt;
  for(int i=0; i<n; i++){
    if(adjm[x][i] < INF && !fa[i]){
      dfs(i);
    }
  }
  return;
}

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%lld%lld", &x[i], &y[i]);
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i == j) continue;
      adjm[i][j] = get_path(i, j);
    }
  }
  // double gans = 0.0;
  for(int i=0; i<n; i++){
    scanf("%s", row);
    for(int j=0; j<n; j++){
      if(row[j] == '0'){
        adjm[i][j] = INF;
      }
    }
  }
  // printf("%.6f", gans);
  for(int k=0; k<n; k++){
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(i == j) continue;
        adjm[i][j] = min(adjm[i][j], adjm[i][k]+adjm[k][j]);
      }
    }
  }
  // for(int i=0; i<n; i++){
  //   for(int j=0; j<n; j++){
  //                 printf("%.0f\t", adjm[i][j]);
  //   }
  //   cout << endl;
  // }
  for(int i=0; i<n; i++){
    if(!fa[i]){
      ++scnt;
      dfs(i);
    }
  }
  double gans = INF;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i != j && fa[i] == fa[j] && adjm[i][j] > sp[i] && adjm[i][j] < INF){
        sp[i] = adjm[i][j];
      }
    }
  }
  // cout << endl << endl;
  // for(int i=0; i<n; i++){
  //   printf("%.1f\t", sp[i]);
  // }
  // cout << endl << endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(fa[i] != fa[j]){
        gans = min(gans, sp[i]+sp[j]+get_path(i, j));
      }
    }
  }
  for(int i=0; i<n; i++){
    gans = max(gans, sp[i]);
  }
  if(gans >= INF) gans = 0.0;
  printf("%.6f", gans);

  return 0;
}
