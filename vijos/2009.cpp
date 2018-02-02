#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define M 3
using namespace std;

int main(){
  int n, minp = 100000000;
  int pn[M], pp[M], tn, tp;
  cin >> n;
  for(int i=0; i<M; i++){
    cin >> pn[i] >> pp[i];
    tn = (int) ceil(n*1.0/pn[i]);
    tp = tn * pp[i];
    minp = min(minp, tp);
  }
  cout << minp;

  return 0;
}
