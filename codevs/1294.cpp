#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 11;
int gn;
int v[MAXN] = {0};
int perm[MAXN];

void dfs(int n){
  if(n > gn){
    for(int i=1; i<=gn; i++){
      cout << perm[i] << " ";
    }
    cout << endl;
    return;
  }
  for(int i=1; i<=gn; i++){
    if(!v[i]){
      v[i] = 1;
      perm[n] = i;
      dfs(n+1);
      v[i] = 0;
    }
  }
}

int main(){
  // freopen("perm.txt", "w", stdout);
  cin >> gn;
  dfs(1);

  return 0;
}
