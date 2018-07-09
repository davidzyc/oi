#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 2e5+7;
const long double MAXUB = 2000.0;
const long double eps = 1e-6;

int n, f;
long double ans = 0.0;
int a[MAXN];
long double ta[MAXN];
long double lb = 0.0, ub = MAXUB;

void ginit(){
  ans = 0.0;
  memset(a, 0, sizeof(a));
  fill(ta, ta+MAXN, 0.0);
  lb = 0.0, ub = MAXUB;
  return;
}

bool chk(long double avg){
  ta[0] = 0.0;
  for(int i=1; i<=n; i++){
    ta[i] = ta[i-1] + a[i]*1.0 - avg;
  }
  long double temp = 2140000000.0;
  for(int i=f; i<=n; i++){
    temp = min(temp, ta[i-f]);
    if(ta[i] - temp >= -eps) return true;
  }
  return false;
}

int main(){

  	// freopen("2018.in", "r", stdin);
  	// freopen("2018.out", "w", stdout);
  // while(
    scanf("%d%d", &n, &f);
    // ==2){
    ginit();

    for(int i=1; i<=n; i++){
      scanf("%d", &a[i]);
    }

    // while(ub-lb>eps){
    for(int i=0; i<100; i++){
      long double mid = (lb+ub)/2;
      if(chk(mid)){
        ans = mid;
        lb = mid;
      }else{
        ub = mid;
      }
    }

    ans *= 1000.0;
    ans+=1e-2;
    printf("%d\n",(int)ans);
  // }

  return 0;
}
