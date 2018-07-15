#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

const int MAXN = 2e5+7;

typedef pair<int, int> pii;

int n;
char fm[MAXN];
int a[MAXN], lst[MAXN], nxt[MAXN];
int v[MAXN] = {0};
priority_queue<pii, vector<pii>, greater<pii> > q;
int pcnt = 0, pfi[MAXN], pse[MAXN];

int inabs(int x){
  return x < 0 ? -x : x;
}

// void fixconn(int x){
//   lst[nxt[x]] = lst[x];
//   nxt[lst[x]] = nxt[x];
// }

// void debug(){
//   for(int i=1; i<=n; i++){
//     if(v[i]) continue;
//     printf("%d<-%d(%d)->%d\n", lst[i], i, fm[i]-'0', nxt[i]);
//   }
//   cout << endl << endl;
// }

int main(){

  freopen("pairs.in", "r", stdin);
  freopen("pairs.out", "w", stdout);

  scanf("%d", &n);
  scanf("%s", fm+1);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    lst[i] = i-1;
    nxt[i] = i+1;
  }
  lst[1] = nxt[n] = 0;
  for(int i=1; i<n; i++){
    if(nxt[i] && fm[i] != fm[nxt[i]]){
      q.push(make_pair(inabs(a[nxt[i]] - a[i]), i));
    }
  }
  while(!q.empty()){
    int x = q.top().second, y = q.top().first;
    q.pop();
    if(nxt[x] && !v[x] && !v[nxt[x]] && inabs(a[nxt[x]] - a[x]) == y ){
      // debug();
      // printf("CURDIFF %d\n", y);
      ++pcnt;
      pfi[pcnt] = x;
      pse[pcnt] = nxt[x];
      // printf("%d %d\n", x, nxt[x]);
      v[x] = 1, v[nxt[x]] = 1;
      if(lst[x] && nxt[nxt[x]] && !v[lst[x]] && !v[nxt[nxt[x]]] && fm[lst[x]] != fm[nxt[nxt[x]]]){
        q.push(make_pair(inabs(a[nxt[nxt[x]]]-a[lst[x]]), lst[x]));
      }
      nxt[lst[x]] = nxt[nxt[x]];
      lst[nxt[nxt[x]]] = lst[x];
    }
  }

  printf("%d\n", pcnt);
  for(int i=1; i<=pcnt; i++){
    printf("%d %d\n", pfi[i], pse[i]);
  }

  return 0;
}
