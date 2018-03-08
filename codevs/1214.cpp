#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 2100000000;
const int MAXN = 101;
int n, tmax = -INF, cnt = 0;
int s[MAXN], e[MAXN], id[MAXN];

int cmp(int a, int b){
  return e[a] < e[b];
}

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d %d", &s[i], &e[i]);
    if(s[i] > e[i]) swap(s[i], e[i]);
    id[i] = i;
  }
  sort(id, id+n, cmp);
  for(int i=0; i<n; i++){
    int ti = id[i];
    if(s[ti] >= tmax){
      tmax = e[ti];
      cnt++;
    }
  }
  printf("%d", cnt);
  return 0;
}
