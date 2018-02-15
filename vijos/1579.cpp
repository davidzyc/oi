// 中间结果要用long long
#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAXN 20005
using namespace std;

int n;
int from[MAXN], to[MAXN], id[MAXN];
long long w[MAXN];
int ufs[MAXN];
long long cnt[MAXN];

int cmp(int a, int b){
  return w[a] < w[b];
}

void init(int a){
  for(int i=0; i<=a; i++){
    ufs[i] = i;
    cnt[i] = 1;
  }
  return;
}

int find(int a){
  int roota = a, troota = a, tta = a;
  while(ufs[roota] != roota){
    roota = ufs[roota];
  }
  while(troota != ufs[troota]){
    tta = troota;
    troota = ufs[troota];
    ufs[tta] = roota;
  }
  return roota;
}

long long unite(int a, int b){
  int roota = find(a);
  int rootb = find(b);
  ufs[roota] = rootb;
  long long cntmul = cnt[roota] * cnt[rootb];
  cnt[rootb] += cnt[roota];
  cnt[roota] = 0;
  find(a);
  find(b);
  return cntmul;
}

int main(){
  cin >> n;
  init(n);
  for(int i=0; i<n-1; i++){
    cin >> from[i] >> to[i] >> w[i];
    id[i] = i;
  }
  sort(id, id+n-1, cmp);
  long long globalw = 0;
  for(int i=0; i<n-1; i++){
    int tid = id[i];
    // cout << from[tid] << " " << to[tid] << " " << w[tid] << endl;
    globalw += unite(from[tid], to[tid]) * (w[tid] + 1) - 1;
    // for(int j=1; j<=n; j++){
    //   cout << ufs[j] << " " << cnt[j] << " | ";
    // }
    // cout << endl;
  }
  cout << globalw << endl;

  return 0;
}
