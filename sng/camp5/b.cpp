#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

const int MAXLOG = 64;
const ll MAXN = 2e18;
const double eps = 1e-3;

int tset;
ll n;
ll maxub[MAXLOG];

bool chk(ll num, int p){
  ll mul = 1;
  for(int i=0; i<p; i++){
    mul *= num;
  }
  if(mul <= n){
    return true;
  }else{
    return false;
  }
}

int main(){

  for(int i=2; i<MAXLOG; i++){
    maxub[i] = (ll) ( pow(MAXN, 1.0/(i*1.0)) + eps );
    // printf("%.5f\t%lld\n", pow(MAXN, 1.0/(i*1.0)), maxub[i]);
  }
  scanf("%d", &tset);
  while(tset--){
    scanf("%lld", &n);
    printf("%lld", n);
    bool flag = false;
    for(int i=2; i<MAXLOG; i++){
      ll lb = 2, ub = maxub[i];
      ll ans = 0;
      while(lb <= ub){
        ll mid = (lb + ub) / 2;
        if(chk(mid, i)){
          ans = mid;
          lb = mid + 1;
        }else{
          ub = mid - 1;
        }
      }
      ll tmul = 1;
      for(int j=0; j<i; j++){
        tmul *= ans;
      }
      if(tmul == n){
        flag = true;
        printf("=%lld^%d", ans, i);
      }
    }
    if(!flag){
      printf(" is powerless.");
    }
    printf("\n");
  }

  return 0;
}
