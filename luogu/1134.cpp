#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int n, ans = 1;
int two, five;

int main(){
  // freopen("1134.in", "r", stdin);
  // freopen("1134.out", "w", stdout);

  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    int ti = i;
    while(ti % 2 == 0) ++two, ti /= 2;
    while(ti % 5 == 0) ++five, ti /= 5;
    ans *= ti;
    ans %= 10;
  }
  int qfac = two - five, fac = 2;
  while(qfac > 0){
    if(qfac % 2){
      ans *= fac;
      ans %= 10;
    }
    qfac >>= 1;
    fac *= fac;
    fac %= 10;
  }

  printf("%d", ans);

  return 0;
}
