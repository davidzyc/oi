#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 2e5+7;

int n, a[MAXN], an;
int ft[MAXN];
int cnt[MAXN] = {0}, lsta[MAXN] = {0};

int lowbit(int x){
  return x&(-x);
}

void upd(int x, int val){
  while(x <= an){
    ft[x] += val;
    x += lowbit(x);
  }
  return;
}

int query(int x){
  int ans = 0;
  while(x > 0){
    ans += ft[x];
    x -= lowbit(x);
  }
  return ans;
}

int main(){
  int gcnt = 0;
  scanf("%d", &n);
  n *= 2;
  for(an=1; an<n; an<<=1);
  for(int i=n; i>=1; i--){
    scanf("%d", &a[i]);
    upd(i, 1);
  }

  for(int i=1; i<=n; i++){
    if(!cnt[a[i]]){
      lsta[a[i]] = i;
    }
    cnt[a[i]]++;
    if(cnt[a[i]] == 2){
      gcnt += query(i) - query(lsta[a[i]]) - 1;
      upd(i, -1);
      upd(lsta[a[i]], -1);
    }
  }

  printf("%d\n", gcnt);

  return 0;
}
