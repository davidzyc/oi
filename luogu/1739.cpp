#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

int main(){
  char c;
  stack<int> s;
  while((c = getchar())!='@'){
    if(c == '('){
      s.push(1);
    }else if(c == ')'){
      if(s.empty()){
        cout << "NO" << endl;
        return 0;
      }else{
        s.pop();
      }
    }
  }
  if(s.empty()){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }

  return 0;
}
