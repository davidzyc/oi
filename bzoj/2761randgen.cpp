#include<cstdlib>
#include<ctime>
#include<iostream>
#include<cstdio>

using namespace std;

const int MAXR = 2140000000;

int random(int n){
  return rand() % n;
}

int main(){
  freopen("2761.in", "w", stdout);
  srand((unsigned) time(0));
  int n;
  printf("1\n");
  n = random(1000)+2;
  printf("%d\n", n);
  for(int i=0; i<n; i++){
    printf("%d ", (random(2) == 1 ? 1 : -1) * random(MAXR));
  }

  return 0;
}
