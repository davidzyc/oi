#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 1e6;
const int MAXM = 2e3;

int dat[MAXN] = {0};
int cnt = 0, mcnt[MAXM] = {0};

int random(int n){
  return rand() % n + 1;
}

int main(){
  freopen("exhibit.in", "w", stdout);
  srand((unsigned) time(0));
  int n = random(1e4), m = min(random(MAXM), n);
  printf("%d %d\n", n, m);
  for(int i=1; i<=1; i++){
    for(int j=1; j<=m; j++){
      int x;
      while(x = random(n) && !dat[x]) dat[x] = j;
    }
  }
  for(int i=1; i<=n; i++){
    if(dat[i] == 0) dat[i] = random(m);
    if(mcnt[dat[i]] == 0) cnt++, mcnt[dat[i]] = 1;
  }
  for(int i=1; i<=n; i++){
    printf("%d ", dat[i] == 0 ? random(m) : dat[i]);
  }
  if(cnt != m){
    cout << "Wrong Input" << endl;
  }

  return 0;
}
