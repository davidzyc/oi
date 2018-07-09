#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN = 1e5+7;
const int MAXSL = 100;

int n;
int cb = 0;
char blk[MAXSL];
int ccnt[MAXN][MAXSL] = {0};
int tnum[MAXN];
int ans = 0;

bool verify(int cid, string s){
  char tblk[MAXSL];
  int tcnt[MAXSL];
  int tcb = 0;
  for(int i=0; i<s.length(); i++){
    if(tcb == 0 || s[i] != tblk[tcb-1]){
      tblk[tcb] = s[i];
      tcb++;
    }
    tcnt[tcb-1]++;
  }
  if(tcb != cb) return false;
  for(int i=0; i<cb; i++){
    if(tblk[i] != blk[i]) return false;
  }
  for(int i=0; i<cb; i++){
    ccnt[cid][i] = tcnt[i];
  }
  return true;
}

int main(){

  string s;
  scanf("%d", &n);
  cin >> s;
  for(int i=0; i<s.length(); i++){
    if(cb == 0 || s[i] != blk[cb-1]){
      blk[cb] = s[i];
      cb++;
    }
    ccnt[0][cb-1]++;
  }

  for(int i=1; i<n; i++){
    cin >> s;
    if(!verify(i, s)){
      printf("-1");
      return 0;
    }
  }
  
  for(int i=0; i<cb; i++){
    cout << blk[i] << " ";
    for(int j=0; j<n; j++){
      cout << ccnt[j][i] << " ";
    }
    cout << endl;
  }

  for(int i=0; i<cb; i++){
    for(int j=0; j<n; j++){
      tnum[j] = ccnt[j][i];
    }
    sort(tnum, tnum+n);
    for(int j=0; j<n; j++){
      cout << tnum[j] << " ";
      ans += (int) tnum[n/2] - tnum[j];
      printf("%d\n", ans);
    }
  }


  return 0;
}
