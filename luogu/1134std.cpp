// WRONG SOLUTION DO NOT USE AS STD

#include<cstdio>
#include<iostream>

using namespace std;

int n, ans = 1;

int main(){
  freopen("1134.in", "r", stdin);
  freopen("1134.ans", "w", stdout);
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    ans *= i;
    while(ans % 10 == 0){
      ans /= 10;
    }
    ans %= 10;
  }

  printf("%d", ans);

  return 0;
}
