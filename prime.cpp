#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

const int MAXN = 1e7+7;

int n, q, qp, m;
int minp[MAXN] = {0};
int p[MAXN];

int main(){

  scanf("%d", &n);
  for(int i=2; i<=n; i++){
    if(minp[i] == 0){
      minp[i] = i;
      p[m++] = i;
    }
    for(int j=0; j<m; j++){
      if(p[j] > minp[i] || i*p[j] > n) break;
      minp[i*p[j]] = p[j];
    }
  }
  scanf("%d", &q);
  for(int i=0; i<q; i++){
    scanf("%d", &qp);
    printf(minp[qp] == qp ? "Yes\n" : "No\n");
  }

  return 0;
}
