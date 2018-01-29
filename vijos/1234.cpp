#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAXN 1005
#define MAXM 10005
using namespace std;

int ufs[MAXN], u[MAXM], v[MAXM], c[MAXM], id[MAXM];

bool cmp(int a, int b){
  return c[a] < c[b];
}

void init(int a){
  for(int i=0; i<a; i++){
    ufs[i] = i;
  }
  return;
}

int find(int a){
  int root = a, tempa = a, temp;
  while(ufs[root] != root){
    root = ufs[root];
  }
  while(ufs[tempa] != tempa){
    temp = tempa;
    tempa = ufs[tempa];
    ufs[temp] = root;
  }
  return root;
}

void unite(int a, int b){
  int roota, rootb;
  roota = find(a);
  rootb = find(b);
  ufs[roota] = rootb;
}

int main(){
  int n, m, k, ucnt = 0, totc = 0;
  cin >> n >> m >> k;
  init(n);
  for(int i=0; i<m; i++){
    cin >> u[i] >> v[i] >> c[i];
    id[i] = i;
    u[i]--;
    v[i]--;
  }
  sort(id, id+m, cmp);
  int tid;
  for(int i=0; i<m; i++){
    tid = id[i];
    if(find(u[tid]) != find(v[tid])){
      ucnt++;
      totc += c[tid];
      unite(u[tid], v[tid]);
    }
    if(ucnt == n-k){
      cout << totc;
      return 0;
    }
  }
  // cout << totc;
  cout << "No Answer";
  return 0;
}
