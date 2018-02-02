#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 1005
using namespace std;

int ufs[MAXN];
unsigned long long x[MAXN], y[MAXN], z[MAXN];

void init(int n){
  for(int i=0; i<=n; i++){
    ufs[i] = i;
  }
  return;
}

int find(int a){
  int rt = a, trt = a, ttrt;
  while(rt != ufs[rt]){
    rt = ufs[rt];
  }
  while(trt != ufs[trt]){
    ttrt = trt;
    trt = ufs[trt];
    ufs[ttrt] = rt;
  }
  return rt;
}

void unite(int a, int b){
  // cout << "Unite " << a << " " << b << endl;
  int rta, rtb;
  rta = find(a);
  rtb = find(b);
  ufs[rtb] = rta;
  return;
}

unsigned long long getdsq(int i, int j){
  return (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) + (z[i] - z[j])*(z[i] - z[j]);
}

bool sameufs(int a, int b){
  return find(a) == find(b);
}

int main(){
  int t, n, h;
  unsigned long long r, rr, d;
  cin >> t;
  for(int roun=0; roun<t; roun++){
    cin >> n >> h >> r;
    init(n+1);
    rr = r*r*4;
    for(int i=1; i<=n; i++){
      cin >> x[i] >> y[i] >> z[i];
      if(z[i] <= r){
        unite(0, i);
      }
      if(z[i] + r >= h){
        unite(n+1, i);
      }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
          if(i != j){
            d = getdsq(i, j);
            // cout << d << " " << r*r << endl;
            if(d <= rr){
              unite(i, j);
            }
          }
        }
    }
    if(sameufs(0, n+1)){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  return 0;
}
