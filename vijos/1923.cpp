#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 1e5+7;
const int MAXM = 1e6+7;

int n, m, dn;
int a[MAXN], b[MAXN], c[MAXN];
int l[MAXM], r[MAXM], k[MAXM], w[MAXM], id[MAXM], klow[MAXM], whigh[MAXM];
int dat[MAXN];

bool cmp_l(int x, int y){
  return l[x] < l[y];
}

bool cmp_r(int x, int y){
  return r[x] > r[y];
}

void discrete_seq_gen(){
  for(int i=1; i<=n; i++){
    b[i] = a[i];
  }
  sort(b+1, b+n+1);
  dn = unique(b+1, b+n+1) - b - 1;
  for(int i=1; i<=n; i++){
    c[i] = lower_bound(b+1, b+dn+1, a[i]) - b;
  }
  return;
}

int get_discrete_lower(int x){
  return lower_bound(b+1, b+dn+1, x) - b;
}


int get_discrete_upper(int x){
  return upper_bound(b+1, b+dn+1, x) - b;
}

int lowbit(int a){
  return a&-a;
}

void update(int k, int p){
  if(k == 0) return;
  while(k <= n){
    dat[k] += p;
    k += lowbit(k);
  }
  return;
}

int query(int k){
  int cnt = 0;
  while(k > 0){
    cnt += dat[k];
    k -= lowbit(k);
  }
  return cnt;
}

int main(){
  freopen("1923.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  discrete_seq_gen();
  for(int i=0; i<m; i++){
    scanf("%d %d %d %d", &l[i], &r[i], &k[i], &w[i]);
    k[i] = get_discrete_lower(k[i]);
    w[i] = get_discrete_upper(w[i]);
    w[i]--;
    // cout << k[i] << " " << w[i] << endl;
    id[i] = i;
  }
  // for(int i=1; i<=n; i++){
  //   cout << c[i] << " ";
  // }
  // cout << endl;

  memset(dat, 0, sizeof(dat));
  sort(id, id+m, cmp_l);
  int cur = 1;
  for(int i=0; i<m; i++){
    int ti = id[i];
    while(cur < l[ti]){
      update(c[cur], 1);
      cur++;
    }
    if(k[ti] > w[ti]) continue;
    klow[ti] = query(w[ti]) - query(k[ti]-1);
  }
  memset(dat, 0, sizeof(dat));
  cur = n;
  sort(id, id+m, cmp_r);
  for(int i=0; i<m; i++){
    int ti = id[i];
    // cout <<
    while(cur > r[ti]){
      update(c[cur], 1);
      cur--;
    }
    if(k[ti] > w[ti]) continue;
    whigh[ti] = query(w[ti]) - query(k[ti]-1);
  }
  // for(int i=0; i<m; i++){
  //   cout << klow[i] << " ";
  // }
  memset(dat, 0, sizeof(dat));
  for(int i=1; i<=n; i++){
    update(c[i], 1);
  }
  for(int i=0; i<m; i++){
    // cout << whigh[i] << " " << klow[i] << " ";
    printf("%d\n", query(w[i]) - query(k[i]-1) - whigh[i] - klow[i]);
  }

  return 0;
}
