#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 1e4+7;
const int WIN = 200;

int n;
int a[MAXN], b[MAXN], id[MAXN];

bool cmp(int x, int y){
  int cnt1 = 0, cnt2 = 0;
  if(a[x] > b[x]){
    ++cnt1;
  }else if(a[x] < b[x]){
    --cnt1;
  }
  if(a[y] > b[y]){
    ++cnt1;
  }else if(a[y] < b[y]){
    --cnt1;
  }
  if(a[x] > b[y]){
    ++cnt2;
  }else if(a[x] < b[y]){
    --cnt2;
  }
  if(a[y] > b[x]){
    ++cnt2;
  }else if(a[y] < b[x]){
    --cnt2;
  }
  // cout << x << " " << y << " " << cnt1 << " " << cnt2 << endl;
  printf("x:%d, ax:%d, bx:%d, cntx:%d | y:%d, ay:%d, by:%d, cnty:%d\n", x, a[x], b[x], cnt1, y, a[y], b[y], cnt2);
  if(cnt1 >= cnt2) return true;
  return false;
}

int main(){
  while(scanf("%d", &n) == 1){
    int ans = 0;
    if(n == 0) break;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for(int i=0; i<n; i++){
      scanf("%d", &a[i]);
      id[i] = i;
    }
    for(int i=0; i<n; i++){
      scanf("%d", &b[i]);
    }
    sort(id, id+n, cmp);
    for(int i=0; i<n; i++){
      // int i = id[ii];
      cout << a[i] << " to " << b[id[i]] << endl;
      if(a[i] > b[id[i]]){
        ans += WIN;
      }else if(a[i] < b[id[i]]){
        ans -= WIN;
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
