#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

const int MAXN = 4e4+7;

int n, m = 0;
int v[MAXN] = {0}, p[MAXN] = {0}, phi[MAXN] = {0};

int main(){

  scanf("%d", &n);

  if(n < 2){
    printf("0");
    return 0;
  }

  --n;

  for(int i=2; i<=n; i++){
    if(!v[i]){
      v[i] = i;
      p[m++] = i;
      phi[i] = i-1;
    }
    for(int j=0; j<m; j++){
      if(p[j] > v[i] || p[j]*i > n) break;
      v[p[j]*i] = p[j];
      phi[p[j]*i] = i % p[j] ? phi[i] * (p[j] - 1) : phi[i] * p[j];
    }
  }

  int phicnt = 0;
  for(int i=2; i<=n; i++){
    phicnt += phi[i];
  }

  printf("%d", phicnt*2+3);

  return 0;
}
