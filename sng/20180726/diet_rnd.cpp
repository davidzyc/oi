#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>

using namespace std;

// const int MAXN = 50000000;
// const int MAXN = 100;

int random(int n){
  return rand() % n + 1;
}

int main(){
  freopen("diet.in", "w", stdout);

  srand((unsigned) time(0));

  int n = random(1e6);
  cout << n;

  return 0;

}
