#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 1e4+7;
const int MAXINF = 1e6+7;
const int MAXSQRT = 1e3+7;

int n;
int a[MAXN];
int cnt[MAXINF] = {0};

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  for(int j=1; j<MAXSQRT; j++){
    for(int i=1; i<=n; i++){
      if(a[i] % j == 0 && j < a[i] / j){
        cnt[j] ++;
        cnt[a[i]/j] ++;
      }
      if(a[i] % j == 0 && j == a[i] / j){
        cnt[j]++;
      }
    }
  }
  int tcur = 0;
  for(int i=MAXINF-1; i>=1; i--){
    while(tcur < cnt[i]){
      // cout << tcur << " " << cnt[i] << " ";
      printf("%d\n", i);
      ++tcur;
    }
  }

  return 0;
}
