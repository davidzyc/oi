#include<cstdio>
#include<iostream>

using namespace std;

int n, k, sk, t;

int lowbit(int x){
  return x&(-x);
}

int bitnum(int x){
  int num = 0;
  while(x > 0){
    if(x&1) num++;
    x >>= 1;
  }
  return num;
}

int main(){

  scanf("%d%d", &n, &k);
  t = n;
  // cout << bitnum(n) << endl;
  while(bitnum(n) > k){
    n += lowbit(n);
  }
  printf("%d", n - t);

  return 0;
}
