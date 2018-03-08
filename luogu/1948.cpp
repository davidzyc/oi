#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 1001;
const int MAXM = 20001;

int n, p, k;
int ecnt = 0;
int to[MAXM], l[MAXM], first[MAXN] = {0}, nxt[MAXM] = {0};
int d[MAXN], v[MAXN];
priority_queue<pii, vector<pii>, greater<pii> > q;

int check(int len){
  memset(d, 0x3f, sizeof(d));
  memset(v, 0, sizeof(v));
  d[1] = 0;
  q.push(make_pair(d[1], 1));
  while(!q.empty()){
    int curi, curd;
    pii t;
    t = q.top();q.pop();
    curi = t.second;
    curd = t.first;
    if(v[curi]) continue;
    v[curi] = 1;
    for(int e=first[curi]; e!=0; e=nxt[e]){
      int tl = 0;
      // cout << curi << " -> " << to[e] << " : " << l[e] << endl;
      if(l[e] > len){
        tl = 1;
      }
      if(d[to[e]] > d[curi] + tl){
        d[to[e]] = d[curi] + tl;
        q.push(make_pair(d[to[e]], to[e]));
      }
    }
  }
  // cout << len << " " << d[n] << endl;
  return d[n] <= k;
}

int addedge(int tfrom, int tto, int tl){
  int t;
  ++ecnt;
  l[ecnt] = tl;
  to[ecnt] = tto;
  t = first[tfrom];
  first[tfrom] = ecnt;
  nxt[ecnt] = t;
}

int main(){
  // freopen("1948.txt", "r", stdin);
  int tf, tto, tl;
  scanf("%d %d %d", &n, &p, &k);
  for(int i=0; i<p; i++){
    scanf("%d %d %d", &tf, &tto, &tl);
    addedge(tf, tto, tl);
    addedge(tto, tf, tl);
  }
  int ub = 1000000, lb = 0, ans = -1;
  while(ub >= lb){
    int mid = (ub+lb) / 2;
    if(check(mid)){
      ans = mid;
      ub = mid-1;
    }else{
      lb = mid+1;
    }
  }
  printf("%d", ans);

  return 0;
}
