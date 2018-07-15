#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

typedef unsigned long long ull;

const int MAXN = 1007;
const int P = 131;

int n;
char s[MAXN];
ull ppow[MAXN], f[MAXN], fr[MAXN];

int main(){

  scanf("%s", s+1);
  n = strlen(s+1);
  ppow[0] = 1;
  f[0] = 0;
  for(int i=1; i<=n; i++){
    f[i] = f[i-1] * P;
    f[i] += s[i] - 'a' + 1;
    ppow[i] = ppow[i-1] * P;
  }
  fr[n+1] = 0;
  for(int i=n; i>=1; i--){
    fr[i] = fr[i+1] * P;
    fr[i] += s[i] - 'a' + 1;
  }
  int ans = 0;
  for(int i=1; i<=n; i++){
    int lb = 0, ub = min(i-1, n-i);
    while(ub > lb){
      int mid = (lb + ub + 1) >> 1;
      if(f[i-1] - f[i-mid-1] * ppow[mid] == fr[i+1] - fr[i+mid+1] * ppow[mid]){
        lb = mid;
      }else{
        ub = mid - 1;
      }
    }
    ans = max(ans, lb * 2 + 1);
    lb = 0, ub = min(i, n-i);
    while(ub > lb){
      int mid = (lb + ub + 1) >> 1;
      if(f[i] - f[i-mid] * ppow[mid] == fr[i+1] - fr[i+mid+1] * ppow[mid]){
        lb = mid;
      }else{
        ub = mid - 1;
      }
    }
    ans = max(ans, lb * 2);
  }

  printf("%d\n", ans);

  return 0;
}
