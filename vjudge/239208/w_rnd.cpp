#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
  freopen("w.in", "w", stdout);
  srand((unsigned) time(0));

  printf("%d %d", rand()%10000+1, rand()%100+1);


  return 0;
}
