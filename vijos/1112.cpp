#include<cstdio>
#include<iostream>

using namespace std;

unsigned long long catalan = 1;
int vis[31] = {0};

int main(){
  unsigned long long n;
  cin >> n;
  for(unsigned long long i = n+1; i <= 2*n; i++){
    catalan *= i;
    for(unsigned long long j = 2; j <= n; j++){
      if(vis[(int)j] == 0 && catalan % j == 0){
        catalan /= j;
        vis[(int)j] = 1;
      }
    }
  }
  cout << catalan / (n+1);

  return 0;
}
