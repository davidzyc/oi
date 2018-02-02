#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAXS 105
#define SECLEN 100
#define INF 2100000000
using namespace std;

int secbegin[MAXS], secend[MAXS], secsize = 0;
int sect[MAXS][21000];

int main(){
  int l, s, t, m, st[MAXS], tmin = INF;
  cin >> l >> s >> t >> m;
  for(int i=0; i<m; i++){
    cin >> st[i];
  }
  sort(st, st+m);
  if(s == t){
    tmin = 0;
    for(int i=0; i<m; i++){
      if(st[i] % s == 0){
        tmin ++;
      }
    }
    cout << tmin;
    return 0;
  }
  for(int i=0; i<m; i++){
    if(i == 0){
      secsize++;
      secbegin[secsize] = max(0, st[i]-SECLEN);
      secend[secsize] = min(l+t, st[i]+SECLEN);
    }else{
      if(st[i] - st[i-1] > SECLEN*2){
        secsize++;
        secbegin[secsize] = max(0, st[i]-SECLEN);
        secend[secsize] = min(l+t, st[i]+SECLEN);
      }else{
        secend[secsize] = min(l+t, st[i]+SECLEN);
      }
    }
  }
  for(int sid=1; sid<=secsize; sid++){
    for(int i=0; i<=secend[sid] - secbegin[sid]; i++){
      sect[sid][i] = INF;
      if(i < t){
        if(sid == 1){
          sect[sid][0] = 0;
        }else{
          sect[sid][0] = sect[sid-1][secend[sid-1]-secbegin[sid-1]-i];
        }
      }
      for(int j=s; j<=t; j++){
        if(i-j >= 0){
          sect[sid][i] = min(sect[sid][i], sect[sid][i-j]);
        }
      }
      if(binary_search(st, st+m, i+secbegin[sid])){
        sect[sid][i] += 1;
      }
      if(i + secbegin[sid] >= l){
        tmin = min(tmin, sect[sid][i]);
      }
    }
  }
  if(tmin == INF){
    tmin = sect[secsize][secend[secsize] - secbegin[secsize]];
  }
  cout << tmin;
  return 0;
}
