#include<cstdio>
#include<iostream>

using namespace std;

int main(){
  freopen("c.in", "r", stdin);
  freopen("c.ans", "w", stdout);
  int n, m;
  int cnt = 0;
  int a[10];
  scanf("%d%d", &n, &m);
  for(int j=1; j<=m; j++){
    scanf("%d", &a[j]);
  }
  for(int i=1; i<n; i++){
    for(int j=1; j<=m; j++){
      if(a[j] == 0) continue;
      if(i%a[j] == 0){
        cnt++;
         break;
      }
    }
  }
  printf("%d", cnt);
  return 0;
}
