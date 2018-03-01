#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

string s;
int n = 1;
int cnt = 3;

int printfbi(int a){
  if(a == 0){
    cout << "B";
  }else if(a == 1){
    cout << "I";
  }else{
    cout << "F";
  }
}

int postorder(int l, int r){
  cnt++;
  if(r-l == 1){
    printfbi(s[l]-'0');
    return s[l]-'0';
  }
  int tl, tr;
  tl = postorder(l, (l+r)/2);
  tr = postorder((l+r)/2, r);
  if(tl == tr){
    printfbi(tl);
    return tl;
  }else{
    printfbi(cnt);
    return cnt;
  }
}

int main(){
  int t;
  cin >> t;
  for(int i=0; i<t; i++){
    n *= 2;
  }
  cin >> s;
  postorder(0, s.length());

  return 0;
}
