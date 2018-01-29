#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAXN 100000
using namespace std;

int u[MAXN], v[MAXN], c[MAXN], ufs[MAXN], id[MAXN];

bool cmp(int a, int b){
  return c[a] < c[b];
}

void init(int n){
  for(int i=0; i<n; i++){
    ufs[i] = i;
  }
  return;
}

int find(int a){
  int root, tempa;
  root = a;
  while(ufs[root] != root){
    root = ufs[root];
  }
  while(ufs[a] != a){
    tempa = a;
    a = ufs[a];
    ufs[tempa] = root;
  }
  return root;
}

void unite(int a, int b){
  int roota, rootb;
  roota = find(a);
  rootb = find(b);
  ufs[roota] = rootb;
  return;
}

int main(){
  int n, m, tot = 0, maxc = 0;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    cin >> u[i] >> v[i] >> c[i];
    id[i] = i;
    u[i]--;
    v[i]--;
  }
  init(m);
  sort(id, id+m, cmp);
  for(int i=0; i<m; i++){
    if(find(u[id[i]])!=find(v[id[i]])){
      unite(u[id[i]], v[id[i]]);
      maxc = c[id[i]];
      tot++;
    }
  }
  cout << tot << " " << maxc;

  return 0;
}
