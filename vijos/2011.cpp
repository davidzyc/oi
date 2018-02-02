#include<cstdio>
#include<iostream>
#include<list>
#define MAXN 100005
#define SEPT 86400
using namespace std;

int t[MAXN];
int x[MAXN] = {-1};
int act[MAXN] = {0};
list<int> li;
list<int>::iterator it;

int main(){
  int n, tk, xi, tn;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    tn = 0;
    scanf("%d %d", &t[i], &tk);
    for(int j=0; j<tk; j++){
      scanf("%d", &xi);
      x[xi] = t[i];
      tn ++;
      if(act[xi] == 0){
        li.push_back(xi);
        act[xi] = 1;
      }
    }
    // if(i == 0 || (i > 0 && t[i] - t[i-1] >= SEPT)){
      // cout << tn << endl;
    // }else{
      tn = 0;
      for(it = li.begin(); it!=li.end();){
        if(t[i] - x[*it] >= SEPT){
          act[*it] = 0;
          it = li.erase(it);
        }else{
          it++;
          tn++;
        }
      }
      cout << tn << endl;
    // }
  }

  return 0;
}
