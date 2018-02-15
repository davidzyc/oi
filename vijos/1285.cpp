#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define MAXN 1005
#define MAXM 10000005
using namespace std;

typedef pair<int, int> pii;
int b[MAXM], c[MAXM], to[MAXM], cnt = 1, nextb[MAXM] = {0}, nextc[MAXM] = {0}, firstb[MAXN] = {0}, firstc[MAXN] = {0};
int approach[MAXN];
bool vis[MAXM] = {0};
priority_queue<pii, vector<pii>, greater<pii> > pq;

int main(){
  int n, a[MAXN];
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a[i];
    approach[i] = 1;
  }
  while(cin >> b[cnt] >> c[cnt] >> to[cnt]){
    nextb[cnt] = firstb[b[cnt]];
    firstb[b[cnt]] = cnt;
    nextc[cnt] = firstc[c[cnt]];
    firstc[c[cnt]] = cnt;
    // cout << a[0] << endl;
    // cout<< a[b[cnt]]+a[c[cnt]] << endl;
    pq.push(make_pair(a[b[cnt]]+a[c[cnt]], cnt));
    cnt++;
  }
  int tnextb, tnextc;
  while(!pq.empty()){
    pii pqi = pq.top();
    pq.pop();
    int eid = pqi.second;
    int ew = pqi.first;
    if(vis[eid]) continue;
    // cout << eid << "- b " << b[eid] << " - c " << c[eid] << " - to " << to[eid] << " - len " << ew << endl;
    vis[eid] = 1;
    if(ew < a[to[eid]]){
      a[to[eid]] = ew;
      approach[to[eid]] = approach[b[eid]] * approach[c[eid]];
      tnextb = firstb[to[eid]];
      while(tnextb){
        pq.push(make_pair(a[b[tnextb]]+a[c[tnextb]], tnextb));
        tnextb = nextb[tnextb];
      }
      tnextc = firstc[to[eid]];
      while(tnextc){
        pq.push(make_pair(a[b[tnextc]]+a[c[tnextc]], tnextc));
        tnextc = nextc[tnextc];
      }
    }else if(ew == a[to[eid]]){
      approach[to[eid]] += approach[b[eid]] * approach[c[eid]];
    }
  }

//   for(int i=0; i<n; i++){
//     cout << a[i] << " ";
//   }
// cout << endl;
//     for(int i=0; i<n; i++){
//       cout << approach[i] << " ";
//     }
  cout << a[0] << " " << approach[0];
  return 0;
}
