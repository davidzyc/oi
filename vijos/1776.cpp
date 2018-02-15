#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAXN 40005
#define MAXM 100005
using namespace std;

int ufs[MAXN];
int x[MAXM], y[MAXM], c[MAXM], id[MAXM];

bool cmp(int a, int b){
  return c[a] > c[b];
}

void init(int n){
  for(int i=0; i<=n; i++){
    ufs[i] = i;
  }
  return;
}

int find(int a){
  int rt = a, ta = a, tta;
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
  int n, m;
  cin >> n >> m;
  init(n*2);
  for(int i=0; i<m; i++){
    cin >> x[i] >> y[i] >> c[i];
    id[i] = i;
  }
  sort(id, id+m, cmp);
  int ti;
  for(int i=0; i<m; i++){
    ti = id[i];
    // cout << c[ti] << " ";
    if(sameufs(x[ti], y[ti]) && sameufs(x[ti]+n, y[ti]+n)){
      cout << c[ti] << endl;
      return 0;
    }
    unite(x[ti], y[ti]+n);
    unite(x[ti]+n, y[ti]);
  }
  cout << 0;

  return 0;
}
