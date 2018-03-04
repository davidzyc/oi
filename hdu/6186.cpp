#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 1e5+7;
int n, q;
int a[MAXN] = {0};
int andpr[MAXN] = {0}, andbk[MAXN] = {0}, orpr[MAXN] = {0}, orbk[MAXN] = {0}, xorpr[MAXN] = {0}, xorbk[MAXN] = {0};

int main(){
  // freopen("6186.txt", "r", stdin);
  for(;scanf("%d %d", &n, &q) == 2;){
    // scanf("%d %d", &n, &q);
    memset(andpr, 0, sizeof(andpr));
    memset(andbk, 0, sizeof(andbk));
    memset(orpr, 0, sizeof(orpr));
    memset(orbk, 0, sizeof(orbk));
    memset(xorpr, 0, sizeof(xorpr));
    memset(xorbk, 0, sizeof(xorbk));
    for(int i=1; i<=n; i++){
      scanf("%d", &a[i]);
    }
    andpr[0] = ~0;
    andbk[n+1] = ~0;
    for(int i=1; i<=n; i++){
      andpr[i] = andpr[i-1] & a[i];
      orpr[i] = orpr[i-1] | a[i];
      xorpr[i] = xorpr[i-1] ^ a[i];
    }
    for(int i=n; i>0; i--){
      andbk[i] = andbk[i+1] & a[i];
      orbk[i] = orbk[i+1] | a[i];
      xorbk[i] = xorbk[i+1] ^ a[i];
    }
    int p;
    for(int i=0; i<q; i++){
      scanf("%d", &p);
      printf("%d %d %d\n", andpr[p-1]&andbk[p+1], orpr[p-1]|orbk[p+1], xorpr[p-1]^xorbk[p+1]);
    }
  }

  return 0;
}
