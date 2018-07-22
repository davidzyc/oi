#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXL = 27;
const int MAXM = 550000;

int n, m;
int a[MAXM][MAXL];
int e[MAXM] = {0}, v[MAXM] = {0};
char c[55], cl;
int root, cnt;

int main(){
  root = cnt = 1;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%s", c+1);
    cl = strlen(c+1);
    int cur = root;
    for(int j=1; j<=cl; j++){
      if(!a[cur][c[j]-'a']) a[cur][c[j]-'a'] = ++cnt;
      cur = a[cur][c[j] - 'a'];
    }
    e[cur] = 1;
  }
  scanf("%d", &m);
  for(int i=0; i<m; i++){
    bool flag = true;
      scanf("%s", c+1);
      cl = strlen(c+1);
      int cur = root;
      for(int j=1; j<=cl; j++){
        if(!a[cur][c[j]-'a']){
          flag = false;
          break;
        }
        cur = a[cur][c[j]-'a'];
      }
      if(!e[cur]) flag = false;
      if(!flag){
        printf("WRONG\n");
      }else if(v[cur]){
        printf("REPEAT\n");
      }else{
        printf("OK\n");
        v[cur] = 1;
      }
  }

  return 0;
}
