#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN = 1e4+7;

int n, f;
int a[MAXN];
double l = 0.0, r = 100000000000.0;

bool chk(double avg){
  int cnt = 0;
  for(int i=0; i<n; i++){
    cnt += ((int) ((a[i]*a[i]*1.0*M_PI)/avg));
  }
  if(cnt >= f) return true;
  return false;
}

int main(){
  // printf("%.3f", M_PI);
  scanf("%d%d", &n, &f);
  ++f;
  for(int i=0; i<n; i++) scanf("%d", &a[i]);

  for(int i=0; i<100; i++){
    double mid = (l+r)/2.0;
    // cout << mid << endl;
    if(chk(mid)){
      l = mid;
    }else{
      r = mid;
    }
  }
  printf("%.3f", l);

  return 0;
}
