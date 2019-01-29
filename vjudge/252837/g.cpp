#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 1e6+7;

int n;
int l[MAXN], r[MAXN], id[MAXN];

int datn;
int dat[MAXN*4];

int lowbit(int x){
  return x&(-x);
}

int query(int x){
  int ans = 0;
  while(x){
    ans = max(ans, dat[x]);
    x -= lowbit(x);
  }
  return ans;
}

void update(int x, int val){
  while(x <= datn){
    dat[x] = max(dat[x], val);
    x += lowbit(x);
  }
}

bool cmp(int a, int b){
  if(l[a] != l[b]){
    return l[a] < l[b];
  }else{
    return r[a] < r[b];
  }
}

int main(){
  int casecnt = 0;
  while(scanf("%d", &n)==1){
    memset(dat, 0, sizeof(dat));
    memset(id, 0, sizeof(id));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    for(datn = 1; datn < n; datn <<= 1);
    for(int i=1; i<=n; i++){
      scanf("%d%d", &l[i], &r[i]);
      id[i] = i;
    }
    sort(id+1, id+n+1, cmp);
    int tans, gans = 0;
    for(int ii=1; ii<=n; ii++){
      int i = id[ii];
      // cout << l[i] << " " << r[i] << endl;
      tans = query(r[i]);
      ++tans;
      gans = max(gans, tans);
      update(r[i], tans);
    }
    if(gans == 1){
      printf("Case %d:\nMy king, at most 1 road can be built.\n\n", ++casecnt);
    }else{
      printf("Case %d:\nMy king, at most %d roads can be built.\n\n", ++casecnt, gans);
    }
  }

  return 0;
}
