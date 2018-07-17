#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 1e6+7;

int n, m, s;
int a[MAXN], v[MAXN];
int ans[MAXN], ax = 0;

int  inabs(int x){
  return x < 0 ? -x : x;
}

int main(){
  scanf("%d%d%d", &n, &m, &s);
  for(int i=1; i<=m; i++){
    scanf("%d", &a[i]);
  }
  a[0] = 0;
  a[m+1] = n;
  m += 2;

  for(int x = lower_bound(a, a+m, s) - a; x<m;){
    v[x] = 1;
    x = lower_bound(a, a+m, a[x]+s) - a;
  }
  //
  // for(int i=0; i<m; i++){
  //   cout << a[i] << " " << v[i] << endl;
  // }
  int t;
  int flag = 0;
  for(int i=0; i<m; i++){
    if(v[i]) ans[ax++] = i, t = a[i];
  }
  for(int i=m-1; i>=0; i--){
    if(v[i]) continue;
    if(inabs(a[i] - t) < s){
      flag = 1;
      break;
    }
    ans[ax++] = i;
    t = a[i];
  }
  if(flag){
    printf("NO\n");
  }else{
    printf("YES\n");
    for(int i=0; i<m; i++){
      printf("%d ", ans[i]);
    }
  }

  return 0;
}
