#include<cstdio>
#include<iostream>

using namespace std;

const int MAXM = 2007;
const int GMOD = 1e9+7;

int n, m, k;
int l[MAXM], r[MAXM];
int gans = 0;
int seq[MAXM];

int main(){
  freopen("sequence.in", "r", stdin);
  freopen("sequence.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  for(int i=0; i<m; i++){
    scanf("%d%d", &l[i], &r[i]);
  }
  if(n <= 20){
    for(int i=0; i<(1<<n); i++){
      bool flag = true;
      for(int j=0; j<m; j++){
        int cnt = 0;
        for(int h=l[j]-1; h<=r[j]-1; h++){
          if((i>>h)&1) cnt++;
        }
        if(cnt > k) flag = false;
      }
      if(flag) ++gans;
    }
    printf("%d\n", gans);
    return 0;
  }
  if(k == 0){
    for(int i=1; i<=n; i++){
      seq[i] = 1;
    }
    for(int i=0; i<m; i++){
      for(int j=l[i]; j<=r[i]; j++){
        seq[i] = 0;
      }
    }
    int ans = 1;
    for(int i=1; i<=n; i++){
      if(seq[i]){
        ans *= 2;
        ans %= GMOD;
      }
    }
    printf("%d\n", ans);
    return 0;
  }

  return 0;
}
