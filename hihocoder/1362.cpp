#include<cstdio>
#include<iostream>
using namespace std;

const int MAXN = 1001;
const int MAXINT = 100000000;

int n, m, l;
int a[2*MAXN];

bool check(int tl){
  for(int i=0; i<n; i++){
    int tcnt = 0;
    for(int j=1; j<=n;){
      if(a[j+i] < tl){
        j += l;
        tcnt ++;
      }else{
        j ++;
      }
    }
    // cout << tcnt << " ";
    if(tcnt <= m){
      return true;
    }
  }
  return false;
}

int main(){
  freopen("1362.txt", "r", stdin);
  scanf("%d %d %d", &n, &m, &l);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    a[n+i] = a[i];
  }
  int ub = MAXINT, lb = 0, mid, ans = -1;
  while(ub >= lb){
    mid = (ub+lb)/2;
    if(check(mid)){
      lb = mid+1;
      ans = mid;
    }else{
      ub = mid-1;
    }
  }
  printf("%d", ans);
  return 0;
}
