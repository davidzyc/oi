#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#define MAXN 30005
using namespace std;

int ufs[MAXN], dis[MAXN] = {0}, ecnt[MAXN];

void init(int n){
  for(int i=0; i<=n; i++){
    ufs[i] = i;
    ecnt[i] = 1;
    // dis[i] = 1;
  }
  return;
}

int find(int a){
  int rt = a, ta = a, tta, tcnt;
  int cnt = 0;
  while(ufs[rt] != rt){
    cnt += dis[rt];
    rt = ufs[rt];
  }
  // cnt -= ecnt[rt];
  while(ufs[ta] != ta){
    tta = ta;
    tcnt = dis[ta];
    dis[ta] = cnt;
    cnt -= tcnt;
    ta = ufs[ta];
    ufs[tta] = rt;
  }
  return rt;
}

void unite(int a, int b){
  int rta, rtb;
  int tcnta, tcntb;
  rta = find(a);
  rtb = find(b);
  if(rta == rtb){
    return;
  }
  ufs[rta] = rtb;
  tcnta = ecnt[rta];
  tcntb = ecnt[rtb];
  ecnt[rta] = 0;
  ecnt[rtb] = tcnta + tcntb;
  dis[rta] = tcntb;
  // dis[rta] = tcntb;
  return;
}

int sameufs(int a, int b){
  if(a == b){
    return 0;
  }
  if(find(a) != find(b)){
    return -1;
  }else{
    return abs(dis[a] - dis[b]) - 1;
  }
}

int main(){
  int n;
  string s;
  cin >> n;
  int x, y;
  init(30000);
  for(int i=0; i<n; i++){
    cin >> s >> x >> y;
    if(s == "M"){
      unite(x, y);
      // cout << "MMM" << endl;
    }else if(s == "C"){
      // cout << endl ;
      cout << sameufs(x, y) << endl;
      // cout << "CCC" << endl;
    }
    // cout << endl << "UFS: ";
    // for(int i=1; i<=5; i++){
    //   cout << ufs[i] << " ";
    // }
    // cout << endl << "DIS: ";
    // for(int i=1; i<=5; i++){
    //   cout << dis[i] << " ";
    // }
    // cout << endl << "ECNT: ";
    // for(int i=1; i<=5; i++){
    //   cout << ecnt[i] << " ";
    // }
    // cout << endl <<  dis[x] << " " << dis[y] << endl << endl;
  }

  return 0;
}
