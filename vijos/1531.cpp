#include<cstdio>
#include<iostream>
#define MAXN 150005
using namespace std;

int ufs[MAXN];

void init(int n){
  for(int i=0; i<=n; i++){
    ufs[i] = i;
  }
  return;
}

int find(int a){
  int rt = a, ta = a, tta = a;
  while(ufs[rt] != rt){
    rt = ufs[rt];
  }
  while(ufs[ta] != ta){
    tta = ta;
    ta = ufs[ta];
    ufs[tta] = rt;
  }
  return rt;
}

void unite(int a, int b){
  int rta, rtb;
  rta = find(a);
  rtb = find(b);
  ufs[rta] = rtb;
  return;
}

bool sameufs(int a, int b){
  return find(a) == find(b);
}

int main(){
  int n, k;
  int d, x, y;
  int tot = 0;
  cin >> n >> k;
  init(n*3);
  for(int i=0; i<k; i++){
    // cout << tot << endl;
    cin >> d >> x >> y;
    if(x <= 0 || x > n || y <= 0 || y > n){
      tot++;
      continue;
    }
    if(x == y){
      if(d == 2){
        tot++;
      }
      continue;
    }
    if(d == 1){
      if((sameufs(x, y+n) && sameufs(x+n, y+2*n) && sameufs(x+2*n, y)) || (sameufs(y, x+n) && sameufs(y+n, x+2*n) && sameufs(y+2*n, x))){
        tot++;
      }else{
        unite(x, y);
        unite(x+n, y+n);
        unite(x+2*n, y+2*n);
      }
    }else if(d == 2){
      if(sameufs(x, y) && sameufs(x+n, y+n) && sameufs(x+2*n, y+2*n) || (sameufs(y, x+n) && sameufs(y+n, x+2*n) && sameufs(y+2*n, x))){
        tot++;
      }else{
        unite(x, y+n);
        unite(x+n, y+2*n);
        unite(x+2*n, y);
        // unite(y, x+n);
        // unite(y+n, x+2*n);
        // unite(y+2*n, x);
      }
    }
  }
  cout << tot;

  return 0;
}
