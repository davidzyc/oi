#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e4+7;
const int MAXM = 1e5+7;

int n, m, qy;
int origfrom[MAXM], origto[MAXM], origl[MAXM], origid[MAXM];
// adjacent table
int ecnt;
int first[MAXN], nxt[MAXN], to[MAXN], l[MAXN];
// Union find set
int ufs[MAXN];
// LCA
int tlog;
int f[MAXN][20], fl[MAXN][20];
int d[MAXN], v[MAXN];

int lcainit(int a){
  queue<int> q;
  d[a] = 1;
  q.push(a);
  while(!q.empty()){
    int x = q.front();
    q.pop();
    if(v[x]) continue;
    // cout << x << " ";
    v[x] = 1;
    for(int e=first[x]; e!=0; e=nxt[e]){
      int y = to[e];
      if(!v[y]){
        d[y] = d[x]+1;
        f[y][0] = x;
        fl[y][0] = l[e];
        for(int i=1; i<=tlog; i++){
          f[y][i] = f[f[y][i-1]][i-1];
          fl[y][i] = min(fl[y][i-1], fl[f[y][i-1]][i-1]);
        }
        q.push(y);
      }
    }
  }
}

int lca(int a, int b){
  int ans = INF;
  if(d[a] < d[b]) swap(a, b);
  // cout << a << " ";
  for(int i=tlog; i>=0; i--){
    if(d[f[a][i]] >= d[b]){
      // cout << i << " " << fl[a][i] << endl;
      ans = min(ans, fl[a][i]);
      a = f[a][i];
    }
  }
  if(a == b){
    // return a;
    return ans;
  }
  for(int i=tlog; i>=0; i--){
    if(f[a][i] != f[b][i]){
      ans = min(ans, fl[a][i]);
      a = f[a][i];
      ans = min(ans, fl[b][i]);
      b = f[b][i];
    }
  }
  ans = min(ans, fl[a][0]);
  ans = min(ans, fl[b][0]);
  return ans;
  // return f[a][0];
}

bool cmp(int a, int b){
  return origl[a] > origl[b];
}

void init(int n){
  for(int i=0; i<=n; i++){
    ufs[i] = i;
  }
  return;
}

int find(int a){
  int root, ta = a, tta = a;
  while(ta != ufs[ta]){
    ta = ufs[ta];
  }
  root = ta;
  while(ta != ufs[ta]){
    tta = ta;
    ta = ufs[ta];
    ufs[tta] = root;
  }
  return root;
}

void unite(int a, int b){
  int roota = find(a), rootb = find(b);
  ufs[roota] = rootb;
  return;
}

bool sameufs(int a, int b){
  return find(a) == find(b);
}

void add_edge(int tfrom, int tto, int tl){
  ++ecnt;
  nxt[ecnt] = first[tfrom];
  first[tfrom] = ecnt;
  to[ecnt] = tto;
  l[ecnt] = tl;
  return;
}

int main(){
  // freopen("1967.txt", "r", stdin);
  int tfrom, tto, tl;
  scanf("%d%d", &n, &m);
  tlog = (int) log(n)/log(2) + 1;
  init(n);
  for(int i=0; i<m; i++){
    scanf("%d%d%d", &origfrom[i], &origto[i], &origl[i]);
    origid[i] = i;
  }
  sort(origid, origid+m, cmp);
  for(int i=0; i<m; i++){
    int ti = origid[i];
    if(!sameufs(origfrom[ti], origto[ti])){
      unite(origfrom[ti], origto[ti]);
      // cout << origfrom[ti] << " " << origto[ti] << " " << origl[ti] << endl;
      add_edge(origfrom[ti], origto[ti], origl[ti]);
      add_edge(origto[ti], origfrom[ti], origl[ti]);
    }
  }
  memset(fl, 0x3f, sizeof(fl));
  for(int i=1; i<=n; i++){
    if(!d[i]){
      lcainit(i);
    }
  }
  // for(int i=1; i<=n; i++){
  //   for(int j=0; j<=tlog; j++){
  //     cout << fl[i][j] << " " ;
  //   }
  //   cout << endl;
  // }
  scanf("%d", &qy);
  for(int i=0; i<qy; ++i){
    scanf("%d %d", &tfrom, &tto);
    if(sameufs(tfrom, tto)){
      printf("%d\n", lca(tfrom, tto));
    }else{
      printf("%d\n", -1);
    }
  }

  return 0;
}
