#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int random(int x){
  return rand()%x + 1;
}

int main(){
  freopen("c.in", "w", stdout);
  srand((unsigned) time(0));
  int n = random(10000000) , m = random(11) - 1;
  printf("%d %d\n", n, m);
  for(int i=0; i<m; i++){
    printf("%d ", random(21)-1);
  }
  return 0;
}
