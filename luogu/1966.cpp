#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 1e5+10;
const int GMOD = 99999997;

int n, fn;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int ft[MAXN];

int lowbit(int x){
  return x&-x;
}

void upd(int x, int val){
  while(x <= fn){
    ft[x] += val;
    x += lowbit(x);
  }
}

int query(int x){
  int ans = 0;
  while(x){
    ans += ft[x];
    x -= lowbit(x);
  }
  return ans;
}

int main(){

  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
    c[i] = a[i];
  }
  sort(c, c+n);
  for(int i=0; i<n; i++){
    a[i] = lower_bound(c, c+n, a[i]) - c;
  }

  for(int i=0; i<n; i++){
    scanf("%d", &b[i]);
    c[i] = b[i];
  }
  sort(c, c+n);
  for(int i=0; i<n; i++){
    b[i] = lower_bound(c, c+n, b[i]) - c;
  }
  for(int i=0; i<n; i++){
    c[a[i]] = i;
  }
  for(int i=0; i<n; i++){
    b[i] = c[b[i]];
    // b[i]++;
  }
  for(int i=0; i<n; i++){
    b[i]++;
    // cout << b[i] << " ";
  }
  int gans = 0;
  for(fn=1; fn<n; fn<<=1);
  for(int i=n-1; i>=0; i--){
    gans += query(b[i]);
    upd(b[i], 1);
    gans %= GMOD;
  }
  printf("%d\n", gans);


  return 0;
}
