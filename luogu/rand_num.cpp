#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>

const int MAXRND = 25;

int random(int n){
  return (long long) rand() % n;
}

int main(){
  freopen("1134.in", "w", stdout);
  srand((unsigned) time(0));
  printf("%d", random(MAXRND));

  return 0;
}
