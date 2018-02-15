#include<cstdio>
#include<iostream>
#include<stack>
#define MAXN 1505
using namespace std;

int main(){
  int n, a[MAXN], ans[MAXN], cnt = 0;
  stack<int> s;
  cin >> n;
  a[0] = 0;
  for(int i=1; i<=n; i++){
    cin >> a[i];
    int ndif = a[i] - a[i-1];
    for(int j=0; j<ndif; j++){
      s.push(i-1);
    }
    int ntar = s.top();
    s.pop();
    ans[i] = i - ntar;
  }
  for(int i=1; i<=n; i++){
    cout << ans[i] << " ";
  }

  return 0;
}
