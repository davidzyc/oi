#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 105
using namespace std;

int main(){
  int n, cnt, tot, pos;
  string sarg, scontent;
  string slearn[MAXN];
  while(cin >> n){
    cnt = 0;
    for(int i=0; i<n; i++){
      cin >> sarg >> scontent;
      if(sarg == "Read"){
        tot = 0;
        for(int i=0; i<cnt; i++){
          pos = 0;
          while(scontent.find(slearn[i], pos) != -1){
            tot++;
            pos = scontent.find(slearn[i], pos)+1;
          }
          // tot += count(scontent.begin(), scontent.end(), slearn[i]);
        }
        cout << tot << endl;
        // cout << "Read";
      }else if(sarg == "Learn"){
        slearn[cnt] = scontent;
        cnt++;
        // cout << "Learn";
      }
    }
  }

  return 0;
}
