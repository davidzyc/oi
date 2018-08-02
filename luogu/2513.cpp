#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 1007;

int n;
int p[MAXN];

int a[MAXN], b[MAXN];
ll ans = 0;

int cnt[MAXN] = {0};

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
  n = 5;
  for(int i=1; i<=n; i++){
    p[i] = i;
  }
  for(int i=1; i<120; i++){
    ans = 0;
    for(int j=1; j<=n; j++){
      printf("%d ", p[j]);
      a[j] = p[j];
    }
    merge_sort(1, n);
    printf(": %lld", ans);
    cnt[ans]++;
    printf("\n");
    next_permutation(p+1, p+1+n);
  }
  ans = 0;
  for(int j=1; j<=n; j++){
    printf("%d ", p[j]);
    a[j] = p[j];
  }
  merge_sort(1, n);
  cnt[ans]++;
  printf(": %lld", ans);
  printf("\n");
  for(int i=0; i<=10; i++) printf("%d ", cnt[i]);
  return 0;
}
