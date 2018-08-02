#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 1e5+7;

typedef long long ll;

int n;
int a[MAXN], b[MAXN];
ll ans = 0;

void merge(int l, int r){
  int mid = (l+r) >> 1;
  int lp = l, rp = mid+1, gp = l;
  for(; lp<=mid && rp<=r;){
    if(a[lp] > a[rp]){
      b[gp++] = a[lp];
      ++lp;
      ans += ((ll) (r - rp + 1));
    }else{
      b[gp++] = a[rp];
      ++rp;
    }
  }
  for(;lp<=mid;lp++) b[gp++] = a[lp];
  for(;rp<=r;rp++) b[gp++] = a[rp];
  for(int i=l; i<=r; i++) a[i] = b[i];
  return;
}

void merge_sort(int l, int r){
  if(l < r){
    int mid = (l+r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    merge(l, r);
  }
}

int main(){

  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  merge_sort(1, n);
  // for(int i=1; i<=n; i++) cout << a[i] << " ";
  printf("%lld", ans);
  return 0;
}
