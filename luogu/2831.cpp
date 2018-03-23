#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

const int MAXN = 18;
const double DDIFF = 1e-8;
int t, n, m;
double x[MAXN], y[MAXN];
double fa[MAXN*MAXN], fb[MAXN*MAXN];
int coverage[400], fcnt;
int dp[1 << MAXN];
int v[1 << MAXN];
vector<int> fopt;

int main(){
  // freopen("2831.txt", "r", stdin);
  scanf("%d", &t);
  for(int ttt=0; ttt<t; ttt++){
    fcnt = 0;
    fopt.clear();
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    memset(fa, 0, sizeof(fa));
    memset(fb, 0, sizeof(fb));
    memset(dp, 0x3f, sizeof(dp));
    memset(v, 0, sizeof(v));
    memset(coverage, 0, sizeof(coverage));
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
      scanf("%lf%lf", &x[i], &y[i]);
    }
    double ta, tb;
    int tcover;
    for(int i=0; i<n; i++){
      tcover = 0;
      tcover = tcover | (1 << i);
      coverage[fcnt] = tcover;
      ++fcnt;
      if(!v[tcover]){
        fopt.push_back(tcover);
        v[tcover] = 1;
      }
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(j == i || x[i] == x[j]) continue;
        tb = (y[i]*x[j]*x[j] - y[j]*x[i]*x[i]) / (x[i]*x[j]*x[j] - x[j]*x[i]*x[i]);
        ta = (y[i] - tb*x[i]) / (x[i]*x[i]);
        if(ta >= 0) continue;
        fa[fcnt] = ta;
        fb[fcnt] = tb;
        tcover = 0;
        for(int k=0; k<n; k++){
          if(abs(ta*x[k]*x[k] + tb*x[k] - y[k]) < DDIFF){
            tcover = tcover | (1 << k);
          }
        }
        coverage[fcnt] = tcover;
        ++fcnt;
        if(!v[tcover]){
          fopt.push_back(tcover);
          v[tcover] = 1;
        }
      }
    }
    dp[0] = 0;
    for(int i=0; i<(1<<n); i++){
      for(int j=0; j<fopt.size(); j++){
        dp[i|fopt[j]] = min(dp[i|fopt[j]], dp[i]+1);
      }
    }
    cout << dp[(1<<n)-1] << endl;
  }

  return 0;
}
