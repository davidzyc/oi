#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 1e6+7;
const ll INF = 0x7f7f7f7f7f7f7f7f;

int n, me = 0;
ll c[MAXN];
int head[MAXN], nxt[MAXN], to[MAXN], from[MAXN];
ll w[MAXN];
int v[MAXN], fa[MAXN];
ll tup[MAXN], tc[MAXN], tdown[MAXN];
int rt = 1;

void add_edge(int tf, int tt, ll tw){
  ++me;
  from[me] = tf;
  to[me] = tt;
  w[me] = tw;
  nxt[me] = head[tf];
  head[tf] = me;
}

void dfs1(int x){
  v[x] = 1;
  ll tmax = 0, tmaxid = 0, tmaxse = 0, tmaxseid = 0, tmp;
  for(int e=head[x]; e; e=nxt[e]){
    int y = to[e];
    // cout << x << " " << y << endl;
    if(v[y]) {
      fa[x] = y;
      continue;
    }
    dfs1(y);
    tmp = max(tup[y] - w[e], (ll)0);
    if(tmp >= tmax){
      tmaxseid = tmaxid;
      tmaxid = y;
      tmaxse = tmax;
      tmax = tmp;
    }
  }
  tmax += c[x];
  tmaxse += c[x];
  for(int e=head[x]; e; e=nxt[e]){
    int y = to[e];
    if(y == fa[x]) continue;
    tmp = max(tup[y] - w[e], (ll)0);
    if(tmaxid && y != tmaxid){
      tc[y] = max(tmax - w[e], (ll)0) + c[y];
    }else if(tmaxseid && y != tmaxseid){
      tc[y] = max(tmaxse - w[e], (ll)0) + c[y];
    }
  }
  // printf("Node %d: 1st y%d-%d, 2nd y%d-%d\n", x, tmaxid, tmax, tmaxseid, tmaxse);
  tup[x] = max(tmax, c[x]);
}

void dfs2(int x){
  v[x] = 1;
  for(int e=head[x]; e; e=nxt[e]){
    int y = to[e];
    if(v[y]) continue;
    tdown[y] = max(max(tdown[x] - w[e], (ll)0) + c[y], tc[y]);
    dfs2(y);
  }
}

int main(){

    freopen("1084d.in", "r", stdin);
    freopen("1084d.out", "w", stdout);
  scanf("%d", &n);
  int tf, tt;
  ll tw;
  for(int i=1; i<=n; i++){
    scanf("%lld", &c[i]);
  }
  for(int i=1; i<n; i++){
    scanf("%d%d%lld", &tf, &tt, &tw);
    // cout << tf << " " << tt << endl;
    add_edge(tf, tt, tw);
    add_edge(tt, tf, tw);
  }

  dfs1(rt);
  memset(v, 0, sizeof(v));
  dfs2(rt);
  // cout << "HI";
  ll gans = 0;

  for(int i=1; i<=n; i++){
    gans = max(gans, tup[i]);
    gans = max(gans, tdown[i]);
  }

  // for(int i=1; i<=n; i++){
  //   printf("Up: %lld | Down: %lld | TC: %lld\n", tup[i], tdown[i], tc[i]);
  // }

  // for(int i=1; i<=me; i++){
  //   cout << from[i] << " " << to[i] << endl;
  // }

  printf("%lld\n", gans);

  return 0;
}
