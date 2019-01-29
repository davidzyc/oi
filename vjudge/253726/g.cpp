#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int n, k;
int t[15];

void dfs(int nn, int kk){
  // cout << nn << " " << kk << endl;
  if(kk > k){
    for(int i=1; i<=k; i++){
      printf("%d", t[i]);
      if(i!=k) printf(" ");
    }
    printf("\n");
    return;
  }
  if(nn > n) return;
  for(int i=nn; i<=n; i++){
    t[kk] = i;
    dfs(i+1, kk+1);
  }
}

int main(){

  int tset;
  scanf("%d", &tset);
  while(tset--){
    scanf("%d%d", &n, &k);
    dfs(1, 1);
    // printf("\n");
  }

  return 0;
}
