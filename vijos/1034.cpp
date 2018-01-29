#include<cstdio>
#include<iostream>
#define MAXN 5005
using namespace std;

int ufs[MAXN];

void init(int n){
  for(int i=0; i<n; i++){
    ufs[i] = i;
  }
}

int find(int a){
  int root = a;
  while(ufs[root] != root){
    root = ufs[root];
  }
  while(ufs[a] != a){
    a = ufs[a];
    ufs[a] = root;
  }
  return root;
}

void unite(int a, int b){
  int aroot, broot;
  aroot = find(a);
  broot = find(b);
  ufs[broot] = aroot;
}

int main(){
  int n, m, p;
  cin >> n >> m >> p;
  init(n);
  int ta, tb;
  for(int i=0; i<m; i++){
    cin >> ta >> tb;
    unite(ta, tb);
  }
  for(int i=0; i<p; i++){
    cin >> ta >> tb;
    if(find(ta) == find(tb)){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }

  return 0;
}
