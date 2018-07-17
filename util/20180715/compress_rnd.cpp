#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int MAXN = 1000;
const int MAXA = 100000;

int random(int x){
  return rand() % x + 1;
}

int main(){
  freopen("compress.in", "w", stdout);
  srand((unsigned) time(0));
  int n = random(MAXN), m = random(MAXN);
  printf("%d %d\n", n, m);
  // printf("%d %d\n", 3000, 3000);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      // printf("%d ", 100000);
        printf("%d ", random(MAXA));
    }
    printf("\n");
  }

  return 0;
}
