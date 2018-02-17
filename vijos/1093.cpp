#include<cstdio>
#include<iostream>
#define MAXN 10005
#define M 7654321
using namespace std;

int fib[MAXN];

int main(){
  fib[0] = fib[1] = 1;
  int n;
  cin >> n;
  for(int i=2; i<n; i++){
    fib[i] = (fib[i-1] + fib[i-2]) % M;
  }
  cout << fib[n-1];
  return 0;
}
