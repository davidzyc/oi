#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAXN 401
using namespace std;

int n, m, maxt;
int id[MAXN], pi[MAXN], pj[MAXN], pw[MAXN], cnt = 0;

int cmp(int a, int b){
  return pw[a] > pw[b];
}

int main(){
  int tw;
  cin >> n >> m >> maxt;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> tw;
      if(tw != 0){
        id[cnt] = cnt;
        pi[cnt] = i;
        pj[cnt] = j;
        pw[cnt] = tw;
        cnt++;
      }
    }
  }
  int lasti = 0, lastj, remt = maxt - 1, globalw = 0;
  sort(id, id+cnt, cmp);
  lastj = pj[id[0]];
  for(int i=0; i<cnt; i++){
    int tid = id[i];
    // cout << remt << " ";
    if(remt - abs(pi[tid]-lasti) - abs(pj[tid]-lastj) - pi[tid] - 1 >= 1){
      globalw += pw[tid];
      remt -= abs(pi[tid]-lasti) + abs(pj[tid]-lastj) + 1;
      lasti = pi[tid];
      lastj = pj[tid];
    }else{
      break;
    }
  }

  cout << globalw;

  return 0;
}
