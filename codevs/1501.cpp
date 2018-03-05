#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 18;

int n;
int l[MAXN] = {0}, r[MAXN] = {0};
int d[MAXN] = {0}, lc[MAXN] = {0};

void dfs(int c){
  if(c == 0) return;
  d[l[c]] = d[c] + 1;
  dfs(l[c]);
  d[r[c]] = d[c] + 1;
  dfs(r[c]);
  return;
}


int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d %d", &l[i], &r[i]);
  }
  d[1] = 1;
  dfs(1);
  int dmax = 0, bmax = 0;
  for(int i=1; i<=n; i++){
    lc[d[i]]++;
    dmax = max(dmax, d[i]);
  }
  for(int i=1; i<=n; i++){
    bmax = max(bmax, lc[i]);
  }
  printf("%d %d", bmax, dmax);
  return 0;
}
