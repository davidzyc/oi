#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e6+7;
const int MAXLOG = 22;

int n, m, bn;
int two[MAXLOG];
int l[MAXN], r[MAXN];
pii st[MAXN][MAXLOG];
int nxt[MAXN][MAXLOG];
int a[MAXN], ll[MAXN], rr[MAXN];

void discretify(){
  for(int i=1; i<=n; i++){
    a[i] = l[i];
    a[n+i] = r[i];
  }
  sort(a+1, a+1+n*2);
  bn = unique(a+1, a+1+n*2) - a - 1;
  for(int i=1; i<=n; i++){
    ll[i] = lower_bound(a+1, a+1+bn, l[i]) - a;
    rr[i] = lower_bound(a+1, a+1+bn, r[i]) - a;
  }
  return;
}

int main(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++){
    scanf("%d%d", &l[i], &r[i]);
  }
  int tn = 0;
  for(int i=1; i<=n; i++){
    if(l[i] < r[i]){
      ++tn;
      l[tn+n] = l[i] + m;
      r[tn+n] = r[i] + m;
    }else{
      r[i] += m;
    }
  }
  n += tn;
  m *= 2;
  two[0] = 1;
  for(int i=1; i<MAXLOG; i++) two[i] = two[i-1] * 2;
  discretify();
  for(int i=1; i<=n; i++){
    // cout << ll[i] << " " << rr[i] << endl;
    st[ll[i]][0] = max(st[ll[i]][0], make_pair(rr[i], i));
  }
  for(int i=1; i<MAXLOG; i++){
    for(int j=1; j<=bn-two[i]+1; j++){
      st[j][i] = max(st[j][i-1], st[j+two[i-1]][i-1]);
    }
  }
  for(int i=1; i<=n; i++){
    int tlog = (int)(log(rr[i]-ll[i]+1)/log(2));
    nxt[i][0] = max(st[ll[i]][tlog], st[rr[i]-two[tlog]+1][tlog]).second;
    if(nxt[i][0] == i) nxt[i][0] = 0;
    // cout << l[i] << " " << r[i] << " " << nxt[i][0] << endl;
  }
  for(int k=1; k<MAXLOG; k++){
    for(int i=1; i<=n; i++){
      if(!nxt[i][k-1]) continue;
      nxt[i][k] = nxt[nxt[i][k-1]][k-1];
    }
  }
  // for(int i=1; i<=n; i++){
  //   cout << i << ": ";
  //   for(int j=0; j<MAXLOG; j++){
  //     cout << nxt[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  for(int i=1; i<= n-tn; i++){
    // cout << "I";
    int ans = 0, x = i;
    for(int k=MAXLOG-1; k>=0; k--){
      if(nxt[x][k] && r[nxt[x][k]] - l[i]  < (m/2)){
        // printf("nxt[%d][%d]=%d, len = %d\n", x, k, nxt[x][k], r[nxt[x][k]] - l[i] + 1);
        x = nxt[x][k];
        ans += two[k];
      }
    }
    printf("%d ", ans+2);
  }


  return 0;
}
