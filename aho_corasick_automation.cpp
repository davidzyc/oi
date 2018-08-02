#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN = 1e6+7;

char c[MAXN];

struct Aho_corasick_automation {
  int cnt = 0;
  int val[MAXN] = {0};
  int e[MAXN][27] = {0};
  int fail[MAXN] = {0};

  void ins(char *s){
    int l = strlen(s);
    int x = 0, y;
    for(int i=0; i<l; i++){
      y = s[i] - 'a';
      if(!e[x][y]) e[x][y] = ++cnt;
      x = e[x][y];
    }
    val[x] += 1;
  }

  void get_fail(){
    queue<int> q;
    int x = 0, y;
    for(int i=0; i<26; i++){
      if(e[x][i]){
        fail[e[x][i]] = x;
        q.push(e[x][i]);
      }
    }
    while(!q.empty()){
      // cout << "HI ";
      int x = q.front();
      q.pop();
      for(int i=0; i<26; i++){
        if(e[x][i]){
          fail[e[x][i]] = e[fail[x]][i];
          q.push(e[x][i]);
        }else{
          e[x][i] = e[fail[x]][i];
        }
      }
    }
  }

  int ac_query(char *s){
    int x = 0, y;
    int l = strlen(s);
    int ans = 0;
    for(int i=0; i<l; i++){
      y = s[i] - 'a';
      x = e[x][y];
      for(int t = x; t && val[t] != -1; t = fail[t]){
        ans += val[t];
        val[t] = -1;
      }
    }
    return ans;
  }

}AC;

int main(){

  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%s", c);
    AC.ins(c);
  }
  AC.get_fail();
  scanf("%s", c);
  printf("%d", AC.ac_query(c));


  return 0;
}
