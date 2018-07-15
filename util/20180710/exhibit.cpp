#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int MAXN = 1e6+7;
const int MAXM = 2007;
// const int INF = 1e6+7;

int n, m;
int a[MAXN];
int cnt = 0, mcnt[MAXM] = {0};
int l, r;
int glen = MAXN, gl = 1, gr = 1;

// void debug(int t){
//   cout << l << " " << r-1 << " " << cnt << " " << (t == 1 ? "inc " : "dec ");
//   for(int i=1; i<=m; i++){
//     cout << mcnt[i] <<" ";
//   }
//   cout << endl;
// }

int main(){
  freopen("exhibit.in", "r", stdin);
  freopen("exhibit.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }

  l = r = 1;

  while(r <= n){
    while(cnt < m && r <= n){
      if(mcnt[a[r]] == 0){
        ++cnt;
      }
      mcnt[a[r]]++;
      ++r;
      // debug(1);
    }
    // --r;
    while(cnt == m){
      if(r-l+1 < glen){
        glen = r-l+1;
        gl = l;
        gr = r - 1;
      }
      if(mcnt[a[l]] == 1){
        --cnt;
      }
      --mcnt[a[l]];
      ++l;
      // debug(0);
    }
  }
  
  printf("%d %d\n", gl, gr);

  return 0;
}
