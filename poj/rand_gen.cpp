#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>

using namespace std;

// const int MAXN = 50000000;
// const int MAXN = 100;

int random(int n){
  return rand() % n;
}

int main(){
  freopen("2018.in", "w", stdout);

  srand((unsigned) time(0));

  int n = random(100000-1)+1;
  int f;
  f = random(n-1)+1;

  printf("%d %d\n", n, f);

  for(int i=0; i<n; i++){
    cout << random(2000) << endl;
  }

  return 0;

}
