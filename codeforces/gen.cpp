#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>

using namespace std;

const int MAXN = 100;
const int MAXNUM = 10000000;
// const int MAXN = 100;

int random(int n){
  return rand() % n + 1;
}

int main(){
  freopen("1084d.in", "w", stdout);

  srand((unsigned) time(0));

  int n = random(MAXN);
  cout << n << endl;
  for(int i=1; i<=n; i++) cout << random(MAXNUM) << " ";
  cout << endl;
  for(int i=2; i<=n; i++){
    cout << random(i-1) << " " << i << " " << random(MAXNUM) << endl;
  }
  // for(int i=1; i<n; i++){
  //   printf("%d %d %d\n", i, i+1, random(MAXNUM));
  // }
  // for(int i=2; i<=n; i++){
  //   printf("%d %d %d\n", 1, i, random(MAXNUM));
  // }
  return 0;

}
