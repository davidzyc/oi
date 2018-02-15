#include<cstdio>
#include<iostream>
#define MAXN 405
using namespace std;

int ufs[MAXN];
int b[MAXN] = {0}, blen = 1;

void bignmul(int n){
  int t = 0;
  for(int i=0; i<blen; i++){
    b[i]*=n;
    b[i]+=t;
    t = b[i]/10;
    b[i]%=10;
  }
  if(t!=0){
    b[blen] = t;
    blen++;
  }
}

void printbign(){
  // flag = false;
  for(int i=blen-1; i>=0; i--){
    cout << b[i];
  }
}

int getng(int a){
  if(a == 1){
    return 0;
  }else if(a == 0){
    return 1;
  }
}

void init(int n){
  for(int i=0; i<=n; i++){
    ufs[i] = i;
  }
}

int find(int a){
  int rt = a, ta = a, tta;
  while(ufs[rt] != rt){
    rt = ufs[rt];
  }
  while(ufs[ta] != ta){
    tta = ta;
    ta = ufs[ta];
    ufs[tta] = rt;
  }
  return rt;
}

void unite(int a, int b){
  int rta, rtb;
  rta = find(a);
  rtb = find(b);
  ufs[rta] = rtb;
}

bool sameufs(int a, int b){
  return find(a) == find(b);
}

int main(){

  int n, m, vis[MAXN] = {0};
  cin >> n >> m;
  init(2*n);
  int a, ab, c, cd, ngab, ngcd;
  for(int i=0; i<m; i++){
    cin >> a >> ab >> c >> cd;
    // ab++;
    // cd++;
    ngab = getng(ab);
    ngcd = getng(cd);
    // cout << a+n*ab << " " << c+n*ngcd << " | " << a+n*ngab << " " << c+n*cd << endl << endl;
    if((sameufs(a+n*ab, c+n*ngcd) && sameufs(a+n*ngab, c+n*cd))){
      cout << "No Answer" << endl;
      return 0;
    }else{
      unite(a+n*ab, c+n*cd);
      unite(a+n*ngab, c+n*ngcd);
      // vis[a]++;
      // vis[c]++;
    }
  }
  int cnt = 0;
  for(int i=1; i<=2*n; i++){
    if(ufs[i] == i){
      cnt++;
    }
    // vis[ufs[i]]++;
    // cout << ufs[i] << " ";
  }
  // cout << cnt;
  // long long ans=1;
  b[0] = 1;
  for(int i=0; i<cnt/2; i++){
    bignmul(2);
  }
  // if(m == 0){
  //   ans /= 2;
  // }
  // cout << ans;
  printbign();
  return 0;
}
