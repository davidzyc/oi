#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 40000;
int n;
int gn = 35000;
int x[MAXN], y[MAXN], id[MAXN], w[MAXN];
int tree[MAXN] = {0};
int gcnt[MAXN] = {0};

bool cmp(int a, int b){
  if(y[a] != y[b]){
    return y[a] < y[b];
  }else{
    return x[a] < x[b];
  }
}

int lowbit(int a){
  return a&(-a);
}

int query(int a){
  int ans = 0;
  while(a){
    ans += tree[a];
    a -= lowbit(a);
  }
  return ans;
}

void add(int a, int p){
  while(a <= gn){
    tree[a] += p;
    a += lowbit(a);
  }
  return;
}

int main(){
  // freopen("1066.txt", "r", stdin);
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d %d", &x[i], &y[i]);
    id[i] = i;
    w[i] = 1;
  }
  int disabledcnt = 0;
  sort(id+1, id+n+1, cmp);
  for(int i=1; i<=n; i++){
    int ti = id[i];
    int lasti = id[i-1];
    if(x[ti] == x[lasti] && y[ti] == y[lasti]){
      w[ti] += w[lasti];
      w[lasti] = 0;
      x[lasti] = 0;
      y[lasti] = 0;
      disabledcnt ++;
    }
  }
  sort(id+1, id+n+1, cmp);
  for(int i=1+disabledcnt; i<=n; i++){
    int ti = id[i], cnt = 0;
    // cout << x[ti] << " " << y[ti] << " " << w[ti] << " ";
    add(x[ti], w[ti]);
    cnt = query(x[ti]);
    // cout << cnt << endl;
    gcnt[cnt] += w[ti];
  }
  for(int i=1; i<=n; i++){
    printf("%d\n", gcnt[i]);
  }
  return 0;
}
