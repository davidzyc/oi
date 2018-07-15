#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

const int MAXN = 10;

int a[5];

int random(int x){
  return (rand() % x) + 1;
}

int main(){
  freopen("1858.in", "w", stdout);
  srand((unsigned) time(0));
  a[1] = 1, a[2] = 3;
  int n = random(MAXN), q = random(MAXN);
  printf("%d %d\n", n, q);
  for(int i=0; i<n; i++){
    printf("%d ", random(2)-1);
  }
  printf("\n");
  for(int i=0; i<q; i++){
    int st = random(n);
    printf("%d %d %d\n", random(2), st-1, st+random(n-st)-1);
  }

  return 0;
}
