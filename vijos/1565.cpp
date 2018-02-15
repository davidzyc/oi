#include<cstdio>
#include<iostream>
#define MAXN 105
#define INF 1000000000
#define NEGINF -1000000000
using namespace std;

int dpmin[MAXN][MAXN], dpmax[MAXN][MAXN];

int mulmax(int a, int b, int c, int d, int e){
  int tmax = NEGINF;
  tmax = max(tmax, a);
  tmax = max(tmax, b);
  tmax = max(tmax, c);
  tmax = max(tmax, d);
  tmax = max(tmax, e);
  return tmax;
}

int mulmin(int a, int b, int c, int d, int e){
  int t = INF;
  t = min(t, a);
  t = min(t, b);
  t = min(t, c);
  t = min(t, d);
  t = min(t, e);
  return t;
}

int main(){

  int n;
  int a[MAXN], op[MAXN];
  char c;
  cin >> n;
  getchar();
  for(int i=1; i<=n; i++){
    c = getchar();
    if(c == '+'){
      op[i] = 0;
    }else if(c == '*'){
      op[i] = 1;
    }
    op[i+n] = op[i];
  }
  getchar();
  for(int i=1; i<=n; i++){
    cin >> a[i];
    dpmin[i][i] = dpmin[i+n][i+n] = dpmax[i][i] = dpmax[i+n][i+n] = a[i];
    a[i+n] = a[i];
  }
  int ansmin = INF, ansmax = NEGINF;
  for(int steps=0; steps<n; steps++){
    for(int len=1; len<n; len++){
      for(int l=1+steps, r; (r=l+len)<=n+steps; l++){
        dpmax[l][r] = NEGINF;
        dpmin[l][r] = INF;
        for(int k=l; k<r; k++){
          if(op[k] == 0){
            dpmax[l][r] = max(dpmax[l][r], dpmax[l][k]+dpmax[k+1][r]);
            dpmin[l][r] = min(dpmin[l][r], dpmin[l][k]+dpmin[k+1][r]);
          }else if(op[k] == 1){
            dpmax[l][r] = mulmax(dpmax[l][r], dpmax[l][k]*dpmax[k+1][r], dpmin[l][k]*dpmax[k+1][r], dpmax[l][k]*dpmin[k+1][r], dpmin[l][k]*dpmin[k+1][r]);
            dpmin[l][r] = mulmin(dpmin[l][r], dpmax[l][k]*dpmax[k+1][r], dpmin[l][k]*dpmax[k+1][r], dpmax[l][k]*dpmin[k+1][r], dpmin[l][k]*dpmin[k+1][r]);
          }
        }
      }
    }
    // cout << dpmax[steps+1][steps+n] << " " << dpmin[steps+1][steps+n] << endl;
    ansmin = min(ansmin, dpmin[steps+1][steps+n]);
    ansmax = max(ansmax, dpmax[steps+1][steps+n]);
  }
  cout << ansmax << endl << ansmin;

  return 0;
}
