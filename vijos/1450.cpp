#include<cstdio>
#include<iostream>
#include<cstdlib>
#define MAXN 200005
#define INF 10000000000000
#define db long double
using namespace std;

typedef long long ll;
int n;
int s[MAXN], e[MAXN], l[MAXN];

bool c(db v){
  db t = 0;
  for(int i=0; i<n; i++){
    t += l[i] / v;
    t = max(t, (db)s[i]);
    if(t > e[i]){
      return false;
    }
    // cout << t << " ";
  }
  // cout << endl;
  return true;
}

int main(){
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> s[i] >> e[i] >> l[i];
  }

  db lb = 0, ub = 2e8;
  while(true){
    if((ub - lb) < 1e-6) break;
    db mid = (ub + lb) / 2;
    if(c(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%.2Lf\n", lb);
  // cout << lb;

  return 0;
}
