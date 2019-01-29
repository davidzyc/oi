#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[100];

int main(){
  //
  // cin >> n;
  // for(int i=1; i<=n; i++){
  //   cin >> a[i];
  // }
  // int un;
  // un = unique(a+1, a+1+n) - a - 1;
  // cout << un;
  // int l, u;
  // cin >> l >> u;
  // cout << lower_bound(a+1, a+1+n, l)-a << " " << upper_bound(a+1, a+1+n, u)-a;
  char s[100];
  scanf("%s", s);
  sscanf(s, "%d", &n);
  cout << n;


  return 0;
}
