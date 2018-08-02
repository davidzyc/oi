#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int MAXN = 1e6+7;
const int MAXM = 2e4+7;
const int MAXL = 26;

struct Trie{
  int mcnt = 0;
  int cnt = 0;
  int fail[MAXM];
  int nxt[MAXM][MAXL];
  int val[MAXM];
  vector<int> ed[MAXM];
  int ans[MAXM];

  void init(){
    mcnt = 0;
    cnt = 0;
    memset(fail, 0, sizeof(fail));
    memset(nxt, 0, sizeof(nxt));
    memset(ans, 0, sizeof(ans));
    memset(val, 0, sizeof(val));
    for(int i=0; i<MAXM; i++) ed[i].clear();
  }

  void insert(char *s){
    int x = 0, y;
    int l = strlen(s);
    for(int i=0; i<l; i++){
      y = s[i] - 'a';
      if(!nxt[x][y]){
        nxt[x][y] = ++cnt;
      }
      x = nxt[x][y];
    }
    val[x] ++;
    ed[x].push_back(++mcnt);
  }

  void get_fail(){
    queue<int> q;
    int x = 0, y;
    for(int i=0; i<MAXL; i++){
      if(nxt[x][i]){
        fail[nxt[x][i]] = x;
        q.push(nxt[x][i]);
      }
    }
    while(!q.empty()){
      x = q.front();
      q.pop();
      for(int i=0; i<MAXL; i++){
        if(nxt[x][i]){
          fail[nxt[x][i]] = nxt[fail[x]][i];
          q.push(nxt[x][i]);
        }else{
          nxt[x][i] = nxt[fail[x]][i];
        }
      }
    }
  }

  int query(char *s){
    int as = 0;
    int x = 0, y;
    int l = strlen(s);
    for(int i=0; i<l; i++){
      y = s[i] - 'a';
      x = nxt[x][y];
      for(int t = x; t; t = fail[t]){
        if(val[t] > 0){
          for(int j=0; j<ed[t].size(); j++){
            ans[ed[t][j]]++;
          }
        }
        as += val[t];
        // val[t] = -1;
      }
    }
    return as;
  }

} AC;

int n;
char inp[157][77];
char c[MAXN];

int main(){
  while(true){
    scanf("%d", &n);
    if(!n) break;
    AC.init();
    for(int i=1; i<=n; i++){
      scanf("%s", c);
      AC.insert(c);
      for(int j=0; j<=strlen(c); j++){
        inp[i][j] = c[j];
      }
    }
    AC.get_fail();
    scanf("%s", c);
    AC.query(c);
    int maxapp = 0;
    int maxcnt = 0, maxid[157];
    // cout << AC.query(c) << endl;
    for(int i=1; i<=n; i++){
      maxapp = max(maxapp, AC.ans[i]);
      // printf("%d ", AC.ans[i]);
    }
    for(int i=1; i<=n; i++){
      if(AC.ans[i] == maxapp){
        maxid[maxcnt++] = i;
      }
    }
    printf("%d\n", maxapp);
    sort(maxid, maxid + maxcnt);
    for(int i=0; i<maxcnt; i++){
      printf("%s\n", inp[maxid[i]]);
    }
    // printf("\n");
  }



  return 0;
}
