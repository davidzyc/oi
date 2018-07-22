#include<cstdio>
#include<iostream>

using namespace std;

int gcd(int x, int y){
  return !y ? x : gcd(y, x%y);
}

int main(){
  freopen("d.in", "r", stdin);
  freopen("d.ans", "w", stdout);
  int cnt = 0;
  int a, b, n;
  scanf("%d%d%d", &a, &b, &n);
  for(int i=a; i<=b; i++){
    if(gcd(i, n) == 1){
      // cout << i << " ";
      cnt++;
    }
  }
  printf("%d", cnt);

  return 0;
}
