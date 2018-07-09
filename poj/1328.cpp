#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

const int MAXN = 1007;

int n, d, casex = 0;
int x[MAXN], y[MAXN], id[MAXN];
double l[MAXN], r[MAXN];

void ginit(){
  fill(l, l+n, 0.0);
  fill(r, r+n, 0.0);
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  return;
}

bool cmp(int a, int b){
  if(r[a] != r[b]){
    return r[a] < r[b];
  }else{
    return l[a] < l[b];
  }
}

int main(){

  while(true){
    scanf("%d%d", &n, &d);
    if(n == 0 && d == 0) return 0;
    ginit();
    bool no_sol = false;
    for(int i=0; i<n; i++){
      scanf("%d%d", &x[i], &y[i]);
      if(y[i] > d){
        no_sol = true;
      }
      l[i] = x[i]*1.0 - sqrt(d*d*1.0 - y[i]*y[i]*1.0);
      r[i] = x[i]*1.0 + sqrt(d*d*1.0 - y[i]*y[i]*1.0);
      id[i] = i;
    }
    if(no_sol){
      printf("Case %d: -1\n", ++casex);
      continue;
    }
    sort(id, id+n, cmp);
    double curx = -210000000.0;
    int cnt = 0;
    for(int ti=0; ti<n; ti++){
      int i = id[ti];
      if(l[i] > curx){
        ++cnt;
        curx = r[i];
      }
    }
    printf("Case %d: %d\n", ++casex, cnt);
  }


  return 0;
}
