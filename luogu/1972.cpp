#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

const int MAXN = 2e5+7;
const int MAXM = 2e5+7;
// const int MAXB = 1000;

int n, m, gn;
int a[MAXN], b[MAXN];
int bcnt, blen;
int ql[MAXM], qr[MAXM], qid[MAXM], qans[MAXM];
int bl[MAXN] = {0}, br[MAXN] = {0};
int tid[MAXN], tcum[MAXN];

bool cmp_pre(int a, int b){
  return ql[a] < ql[b];
}

bool cmp_post(int a, int b){
  return qr[a] < qr[b];
}

void discrete_seq(){
  sort(b+1, b+n+1);
  gn = unique(b+1, b+n+1) - b - 1;
  for(int i=1; i<=n; i++){
    a[i] = lower_bound(b+1, b+gn+1, a[i]) - b - 1;
  }
  // for(int i=1; i<=n; i++){
  //   cout << a[i] << " ";
  // }
  return;
}

void init(){
  discrete_seq();
  sort(qid + 1, qid + m + 1, cmp_pre);
  bcnt = (int) sqrt(m*1.0);
  blen = m / bcnt;
  for(int i=1; i<=bcnt; i++){
    bl[i] = br[i-1] + 1;
    br[i] = br[i-1] + blen;
  }
  if(br[bcnt] < m){
    bcnt++;
    bl[bcnt] = br[bcnt-1] + 1;
    br[bcnt] = m;
  }
  return;
}

int main(){
  // freopen("1972.txt", "r", stdin);
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  scanf("%d", &m);
  for(int i=1; i<=m; i++){
    scanf("%d%d", &ql[i], &qr[i]);
    qid[i] = i;
  }
  init();

  for(int i=1; i<=bcnt; i++){
    // cout << i << ": " << bl[i] << " -> " << br[i] << endl;
    memset(tid, 0, sizeof(tid));
    memset(tcum, 0, sizeof(tcum));
    int tidcnt = 0, tanscnt = 0;
    int lastl, lastr;
    for(int j=bl[i]; j<=br[i]; j++){
      tid[tidcnt++] = qid[j];
    }
    sort(tid, tid+tidcnt, cmp_post);
    for(int j=ql[tid[0]]; j<=qr[tid[0]]; j++){
      if(tcum[a[j]] == 0) tanscnt++;
      tcum[a[j]]++;
    }
    lastl = ql[tid[0]];
    lastr = qr[tid[0]];
    qans[tid[0]] = tanscnt;
    // cout << tid[0] << endl;
    for(int j=1; j<tidcnt; j++){
    // cout << tid[j] << endl;
      for(int k=lastr+1; k<=qr[tid[j]]; k++){
        if(tcum[a[k]] == 0) tanscnt++;
        tcum[a[k]]++;
      }
      if(ql[tid[j]] < lastl){
        for(int k=ql[tid[j]]; k<lastl; k++){
          if(tcum[a[k]] == 0) tanscnt++;
          tcum[a[k]]++;
        }
      }else{
        for(int k=lastl; k<ql[tid[j]]; k++){
          if(tcum[a[k]] <= 1) tanscnt--;
          tcum[a[k]]--;
        }
      }
      lastl = ql[tid[j]];
      lastr = qr[tid[j]];
      qans[tid[j]] = tanscnt;
    }
  }

  for(int i=1; i<=m; i++){
    printf("%d\n", qans[i]);
  }

  return 0;
}
