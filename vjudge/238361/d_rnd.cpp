#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int random(int x){
  return rand()%x + 1;
}

int main(){
  freopen("d.in", "w", stdout);
  srand((unsigned) time(0));
  int n = random(1000000), m = random(1000000)+n;
  printf("%d %d %d\n", n, m, random(1000000));

  return 0;
}
