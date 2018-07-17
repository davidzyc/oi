#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 1e5+7;

int n, k;
int a[MAXN], id[MAXN];

bool cmp(int aa, int bb){
  return a[aa] > a[bb];
}

int main(){

  scanf("%d%d", &n, &k);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
    id[i] = i;
  }

  sort(id, id+n, cmp);
  sort(id, id+k);
  int ans = 0;
  for(int i=0; i<k; i++){
    // cout << id[i] << " ";
    ans += a[id[i]];
  }
  printf("%d\n", ans);
  for(int i=0; i<k; i++){
    if(i == k-1){
      id[i] = n - id[i];
      continue;
    }
    if(i == 0){
      id[i] = id[i+1];
      continue;
    }
    id[i] = id[i+1] - id[i];
  }
  if(k == 1){
    id[0] = n;
  }
  for(int i=0; i<k; i++){
    printf("%d ", id[i]);
  }

  return 0;
}
