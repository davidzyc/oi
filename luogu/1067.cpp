#include<cstdio>
#include<iostream>
#define MAXN 101
using namespace std;

int n, a[MAXN];
bool flag = false;
int main(){
  cin >> n;
  for(int i=n; i>=0; i--){
    cin >> a[i];
    if(a[i] == 0) continue;
    if(flag || a[i] == -1){
      if(a[i] > 0){
        cout << "+";
      } else{
        cout << "-";
        a[i] *= -1;
      }
    }
    if(a[i] != 1 || i == 0) cout << a[i];
    if(i > 1) {
      cout << "x^" << i;
    } else if(i > 0) {
      cout << "x";
    }
    flag = true;
  }
  return 0;
}
