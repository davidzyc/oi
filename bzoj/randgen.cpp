#include<cstdlib>
#include<ctime>
#include<iostream>
#include<cstdio>

using namespace std;

const int MAXR = 1000;

int random(int n){
  return rand() % n;
}

int main(){
  freopen("4300.in", "w", stdout);
  srand((unsigned) time(0));
  int n;
  n = random(MAXR)+2;
  printf("%d\n", n);
  for(int i=0; i<n; i++){
    printf("%d ", random(MAXR)+2100000000);
  }

  return 0;
}
