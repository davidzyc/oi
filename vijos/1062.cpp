#include<cstdio>
#include<iostream>
#include<stack>
#include<cstring>
#define MAXN 1505
using namespace std;

int main(){
  int n, a[MAXN], q[MAXN*2], curpos = 0, curcnt = 0, scnt[MAXN], tcnt;
  stack<int> s;
  memset(scnt, 0, sizeof(scnt));
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  for(int i=0; i<2*n; i++){
    if(curcnt < a[curpos]){
      q[i] = 0;
      s.push(i);
      curcnt++;
    }else{
      q[i] = 1;
      // cout << s.size() << " ";
      // cout << i - s.top() - curpos << " ";
      tcnt = 0;
      for(int i=s.size(); i<n; i++){
        tcnt += scnt[i];
        scnt[i] = 0;
      }
      tcnt++;
      scnt[s.size()-1] += tcnt;
      cout << tcnt << " ";
      s.pop();
      curpos++;
    }
    // cout << q[i] << " ";
  }
  cout << endl;
  for(int i=0; i<2*n; i++){
    cout << q[i] << " ";
  }
  // cout << curcnt << " " << curpos;
  return 0;
}
