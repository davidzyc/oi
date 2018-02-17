#include<cstdio>
#include<iostream>
#define INF 2100000000
#define MAXN 50005

using namespace std;

int l, n, m;
int seg[MAXN] = {0};

bool c(int len){
  int tlen = 0;
  int chance = m;
  for(int i=0; i<=n; i++){
    tlen += seg[i];
    if(chance > 0 && len > tlen){
      chance --;
    }else if(len <= tlen){
      tlen = 0;
    }else{
      return false;
    }
  }
  return true;
}

int main(){
  cin >> l >> n >> m;
  int lastt = 0, t = 0;
  for(int i=0; i<n; i++){
    cin >> t;
    seg[i] = t - lastt;
    lastt = t;
  }
  seg[n] = l - t;
  // for(int i=0; i<=n; i++) cout << seg[i] << " ";
  int lb = 0, ub = INF;
  while(ub - lb > 1){
    int mid = (ub + lb) / 2;
    if(c(mid)){
      lb = mid;
    }else{
      ub = mid;
    }
  }
  cout << lb;
  return 0;
}
