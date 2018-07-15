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
int a[MAXN], cnt, mcnt[MAXM];
int glen = MAXN, gl = 0, gr = 0;

int main(){

    freopen("exhibit.in", "r", stdin);
    freopen("exhibit.ans", "w", stdout);

  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }

  for(int i=1; i<=n; i++){
    cnt = 0;
    memset(mcnt, 0, sizeof(mcnt));
    for(int j=i; j<=n; j++){
      if(cnt == m){
        if(j - i < glen){
          glen = j - i;
          gl = i, gr = j - 1;
        }
      }
      if(mcnt[a[j]] == 0){
        cnt++;
      }
      ++mcnt[a[j]];
    }
  }

  printf("%d %d", gl, gr);


  return 0;
}
