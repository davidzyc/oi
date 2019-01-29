#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN = 1e6+7;
const double MAXUB = 5000000.0;
const double MAXV = 1000000.0;
const double EPS = 1e-6;

int n;
int a[MAXN], b[MAXN];
int en = 1;
int from[MAXN], to[MAXN], nxt[MAXN], head[MAXN];
char s[100];

int v[MAXN];
bool gv = true;
double xl[MAXN], xu[MAXN];
double lb = 0.0, ub = MAXUB, mid;

void dfs(int x){
  v[x] = 1;
  if(b[x]){
    xl[x] = -MAXV;
    xu[x] = MAXV;
  }else{
    xl[x] = a[x]*1.0;
    xu[x] = a[x]*1.0;
  }
  for(int e=head[x]; e; e=nxt[e]){
    int y = to[e];
    if(v[y]) continue;
    dfs(y);
    if(b[x] || b[y]){
      xl[x] = max(xl[x], xl[y] - mid);
      xu[x] = min(xu[x], xu[y] + mid);
    }
  }
  if(xl[x] > xu[x] + EPS){
    gv = false;
  }
}

bool chk(){
  memset(v, 0, sizeof(v));
  // memset(xl, 0, sizeof(xl));
  fill(xl, xl+MAXN, 0.0);
  fill(xu, xu+MAXN, 0.0);
  // memset(xu, 0, sizeof(xu));
  gv = true;
  dfs(1);
  return gv;
}

void add_edge(int x, int y){
  ++en;
  from[en] = x;
  to[en] = y;
  nxt[en] = head[x];
  head[x] = en;
}

int main(){

  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%s", s);
    if(s[0] == '*'){
      b[i] = 1;
    }else{
      sscanf(s, "%d", &a[i]);
    }
    // cout << a[i] << " " << b[i] << endl;
  }
  int x, y;
  for(int i=1; i<n; i++){
    scanf("%d%d", &x, &y);
    add_edge(x, y);
    add_edge(y, x);
    if(b[x] == 0 && b[y] == 0){
      lb = max(lb, abs((a[x] - a[y])*1.0));
    }
  }

  for(int i=1; i<=100; i++){
    mid = (lb + ub) / 2.0;
    if(chk()){
      ub = mid;
    }else{
      lb = mid;
    }
  }

  printf("%.8f", mid);

  return 0;
}
