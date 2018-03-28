#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long ll;
const int MAXN = 5e5+7;
const int MAXB = 300;

int n, m, gn, bcnt, blen;
int a[MAXN], b[MAXN];
int ql[MAXN], qr[MAXN], qid[MAXN];
ll qnum[MAXN], qdeno[MAXN];
int qpos[MAXN], bl[MAXB] = {0}, br[MAXB] = {0};
int tid[MAXN];
ll tcnt[MAXN];

bool cmp_pre(int a, int b){
  return ql[a] < ql[b];
}

bool cmp_post(int a, int b){
  return qr[a] < qr[b];
}

void discrete_seq(){
  sort(b+1, b+1+n);
  gn = unique(b+1, b+1+n) - b - 1;
  for(int i=1; i<=n; i++){
    a[i] = lower_bound(b+1, b+gn+1, a[i]) - b - 1;
  }
  return;
}

void init(){
  discrete_seq();
  bcnt = (int) sqrt(m*1.0);
  blen = m / bcnt;
  sort(qid+1, qid+m+1, cmp_pre);
  for(int i=1; i<=bcnt; i++){
    bl[i] = br[i-1] + 1;
    br[i] = br[i-1] + blen;
    for(int j=bl[i]; j<=br[i]; j++){
      qpos[qid[j]] = i;
    }
  }
  if(br[bcnt] < m){
    bcnt++;
    bl[bcnt] = br[bcnt-1] + 1;
    br[bcnt] = m;
    for(int j=bl[bcnt]; j<=br[bcnt]; j++){
      qpos[qid[j]] = bcnt;
    }
  }
  return;
}

ll gcd(ll a, ll b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

void proc_frac(int proc_id){
  if(qnum[proc_id] == 0){
    qdeno[proc_id] = 1;
    return;
  }
  int cdiv = gcd(qnum[proc_id], qdeno[proc_id]);
  qnum[proc_id] /= cdiv;
  qdeno[proc_id] /= cdiv;
  return;
}

int main(){
  // freopen("1494.txt", "r", stdin);
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  for(int i=1; i<=m; i++){
    scanf("%d%d", &ql[i], &qr[i]);
    qid[i] = i;
  }

  init();

  for(int i=1; i<=bcnt; i++){
    memset(tid, 0, sizeof(tid));
    memset(tcnt, 0, sizeof(tcnt));

    int tidcnt = 0;
    ll lastl, lastr;
    ll tans = 0, topt = 0;
    for(int j=bl[i]; j<=br[i]; j++){
      tid[tidcnt++] = qid[j];
    }
    sort(tid, tid+tidcnt, cmp_post);
    for(int j=ql[tid[0]]; j<=qr[tid[0]]; j++){
      tcnt[a[j]]++;
    }
    lastl = ql[tid[0]];
    lastr = qr[tid[0]];
    for(int i=0; i<=gn; i++){
      if(tcnt[i] > 1){
        tans += tcnt[i] * (tcnt[i] - 1);
      }
      topt += tcnt[i];
    }
    topt = topt * (topt - 1);
    qnum[tid[0]] = tans;

    for(int i=1; i<tidcnt; i++){
      tans = 0;
      topt = 0;
      for(int j=lastr+1; j<=qr[tid[i]]; j++){
        tcnt[a[j]]++;
      }
      if(ql[tid[i]] < lastl){
        for(int j=ql[tid[i]]; j<lastl; j++){
          tcnt[a[j]]++;
        }
      }else{
        for(int j=lastl; j<ql[tid[i]]; j++){
          tcnt[a[j]]--;
        }
      }
      for(int j=0; j<=gn; j++){
        if(tcnt[j] > 1){
          tans += tcnt[j] * (tcnt[j] - 1);
        }
        topt += tcnt[j];
      }
      topt = topt * (topt - 1);
      qnum[tid[i]] = tans;
      lastl = ql[tid[i]];
      lastr = qr[tid[i]];
    }
  }

  for(int i=1; i<=m; i++){
    qdeno[i] = (ll)(qr[i]+1-ql[i]) * (ll)(qr[i]-ql[i]);
    proc_frac(i);
    printf("%lld/%lld\n", qnum[i], qdeno[i]);
  }

  return 0;
}
