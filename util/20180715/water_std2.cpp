#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXP = 207;
const int MAXN = 40007;
const double DINF = 2100000000.0;

int n, m, gcx;
int ecnt = 1;
int efrom[MAXN], eto[MAXN], ew[MAXN];
int ehead[MAXN], enxt[MAXN];
double ecovlen[MAXN][MAXP], td[MAXP];
int ev[MAXN], pv[MAXN];

void add_edge(int x, int y, int z){
  ++ecnt;
  efrom[ecnt] = x;
  eto[ecnt] = y;
  ew[ecnt] = z;
  enxt[ecnt] = ehead[x];
  ehead[x] = ecnt;
  return;
}

void einit(){
  for(int e=2; e<=ecnt; e++){
    for(int i=1; i<=n; i++){
      ecovlen[e][i] = 0.0;
    }
    ev[e] = 0;
  }
  for(int i=1; i<=n; i++){
    td[i] = DINF;
  }
}

void dfs(int x, double rem_dist){
  cout << gcx << " " << x << " " << rem_dist << endl;
  for(int e=ehead[x]; e!=0; e=enxt[e]){
    if(td[x] > rem_dist) continue;
    int y = eto[e];
    td[x] = rem_dist;
    if(rem_dist > (ew[e] * 1.0)){
      ecovlen[e][gcx] = ew[e] * 1.0;
      dfs(y, rem_dist - ew[e] * 1.0);
    }else{
      ecovlen[e][gcx] = rem_dist;
    }
  }
}

bool chk(double dist){
  einit();
  for(int i=1; i<=n; i++){
    gcx = i;
    memset(ev, 0, sizeof(ev));
    fill(td, td+n+1, 0.0);
    td[i] = 0.0;
    dfs(i, dist);
  }
  for(int e=2; e<=ecnt; e+=2){
    int ccnt = 0;
    double l, r;
    l = r = ew[e]*1.0;
    for(int i=1; i<=n; i++){
      if(ecovlen[e][i] + ecovlen[e^1][i] >= ew[e]){
         ccnt++;
         continue;
         // cout << e << " eid - gcx " << gcx << " " << i << " Success" << endl;
       }
       if(ecovlen[e][i] == 0){
         l = min(l, ecovlen[e][i]);
       }else if(ecovlen[e^1][i] == 0){
         r = min(r, ecovlen[e^1][i]);
       }
       ccnt++;
       if(ecovlen[e][i] + r < ew[e]*1.0 && ecovlen[e^1][i] + l < ew[e]*1.0) return false;
    }
    if(l + r < ew[e]*1.0) continue;
    if(ccnt >= n) return true;
  }
  return false;
}

int main(){
  int x, y, z;
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++){
    scanf("%d%d%d", &x, &y, &z);
    add_edge(x, y, z);
    add_edge(y, x, z);
  }
  chk(100);
  double lb = 0.0, ub = DINF;
  // for(int i=0; i<100; i++){
  //   double mid = (lb + ub ) / 2;
  //   if(chk(mid)){
  //     lb = mid;
  //   }else{
  //     ub = mid;
  //   }
  // }
  printf("%.2f", lb);

  return 0;
}
