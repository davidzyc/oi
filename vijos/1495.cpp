#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

bool isprime(int n){
  if(n <= 1) return false;
  for(int i=2; i<=sqrt(n); i++){
    if(n%i == 0) return false;
  }
  return true;
}

int main(){
  string s;
  cin >> s;
  int cnt[27] = {0};
  for(int i=0; i<s.length(); i++){
    int c = s[i] - 'a';
    cnt[c] ++;
  }
  int cmax = 0, cmin = 2100000000;
  for(int i=0; i<26; i++){
    if(cnt[i] == 0) continue;
    // cout << cnt[i] << " ";
    cmax = max(cmax, cnt[i]);
    cmin = min(cmin, cnt[i]);
  }
  int ct = cmax - cmin;
  // cout << ct;
  if(isprime(ct)){
    cout << "Lucky Word" << endl;
    cout << ct;
  }else{
    cout << "No Answer" << endl;
    cout << 0;
  }

  return 0;
}
