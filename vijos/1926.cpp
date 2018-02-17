#include<cstdio>
#include<iostream>
#include<stack>
#define MAXN 100005
using namespace std;

typedef pair<int, int> pii;
int st[MAXN], ed[MAXN], m[MAXN];


int main(){
  int n, a[MAXN], lastpop;
  stack<int> s;
  cin >> n;
  lastpop = 0;
  for(int i=0; i<n; i++){
    cin >> a[i];
    while(!s.empty() && a[s.top()] < a[i]){
      ed[s.top()] = i-1;
      s.pop();
    }
    s.push(i);
  }
  while(!s.empty()){
    ed[s.top()] = n-1;
    s.pop();
  }
  lastpop = 0;
  for(int i=n-1; i>=0; i--){
    while(!s.empty() && a[s.top()] < a[i]){
      st[s.top()] = i+1;
      s.pop();
    }
    s.push(i);
  }
  while(!s.empty()){
    st[s.top()] = 0;
    s.pop();
  }
  int gans = 0;
  for(int i=0; i<n; i++){
    int seclg = 0;
    for(int j=i+1; j<=ed[i]; j++){
      seclg = max(seclg, a[j]);
      gans = max(gans, seclg^a[i]);
    }
    seclg = 0;
    for(int j=i-1; j>=st[i]; j--){
      seclg = max(seclg, a[j]);
      gans = max(gans, seclg^a[i]);
    }
    // cout << st[i] << " " << ed[i] << " "  << m[i] << endl;
  }
  cout << gans;
  return 0;
}
