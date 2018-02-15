#include<cstdio>
#include<iostream>
#define MAXN 105
using namespace std;

const int fac[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int main(){
  int n, a[MAXN];
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  int lg, ans = 0;
  for(int i=0; i<n; i++){
    lg = 0;
    for(int j=i+1; j<n; j++){
      if(a[i] > a[j]){
        lg++;
      }
    }
    ans += lg*fac[n-i-1];
  }
  cout << ans;

  return 0;
}
