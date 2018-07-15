#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 2e5+7;;

typedef pair<int, int> pii;

int n, bn, m, mcnt = 0;
int a[MAXN], b[MAXN], ai[MAXN];
int alst[MAXN], anxt[MAXN];
int inq[MAXN] = {0};

priority_queue<pii> q;

void discretify(){
  sort(b+1, b+1+n);
  bn = unique(b+1, b+1+n) - b - 1;
  // cout << bn << endl;
  for(int i=1; i<=n; i++){
    ai[i] = lower_bound(b+1, b+1+bn, a[i]) - b;
  }
  for(int i=1; i<=n; i++){
    anxt[alst[ai[i]]] = i;
    alst[ai[i]] = i;
  }
}

int main(){
  memset(anxt, 0x3f, sizeof(anxt));
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  discretify();
  // for(int i=1; i<=n; i++){
  //   printf("%d -nxt> %d\n", ai[i], anxt[i]);
  // }
  int cnt = 0;
  for(int i=1; i<=n; i++){
      if(inq[ai[i]]){
        // cout << "PUSH NO CHANGE " << ai[i] << " " << anxt[i] << endl;
        q.push(make_pair(anxt[i], ai[i]));
        continue;
      }
      if(mcnt >= m){
        int xrem = q.top().second;
        --mcnt;
        // cout << "POP " << xrem << " " << q.top().first<< endl;
        inq[xrem] = 0;
        q.pop();
      }
      ++cnt;
      ++mcnt;
      // cout << "PUSH " << ai[i] << " " << anxt[i] << endl;
      q.push(make_pair(anxt[i], ai[i]));
      inq[ai[i]] = 1;
  }

  printf("%d\n", cnt);

  return 0;
}
