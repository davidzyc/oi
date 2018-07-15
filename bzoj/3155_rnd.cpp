#include<cstdlib>
#include<ctime>
#include<iostream>
#include<cstdio>

using namespace std;

const int MAXR = 1e5;

int random(int n){
  return rand() % n + 1;
}

int main(){
  freopen("3155.in", "w", stdout);
  srand((unsigned) time(0));
  int n = random(MAXR), m = random(MAXR);
  cout << n << " " << m << endl;
  for(int i=1; i<=n; i++){
    cout << random(MAXR) << " " ;
  }
  cout << endl;
  for(int i=0; i<m; i++){
    if(random(2) - 1){
      cout << "Modify " << random(n) <<  " " << random(MAXR) << endl;
    }else{
      cout << "Query " << random(n) << endl;
    }
  }
  return 0;
}
