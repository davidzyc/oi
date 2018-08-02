#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;

const int MAXN = 1e4+7;
const ll INF = 2100000000000000;

ll ub, lb, n;
ll l[MAXN], len[MAXN], r[MAXN], w[MAXN];
ll leastdiff = INF;

bool chk(ll x, int chktype){
  ll lv = 0, rv = 0;
  for(int i=1; i<=n; i++){
    if(r[i] <= x){
      lv += w[i] * len[i];
    }else if(l[i] >= x){
      rv += w[i] * len[i];
    }else{
      lv += w[i] * (x - l[i]);
      rv += w[i] * (r[i] - x);
    }
  }
  // return true;
  // printf("chklen:%lld - l %lld - r %lld\n", x, lv, rv);
  // if(lv >= r5v) leastdiff = lv - rv;
  if(chktype == 1){
    if(lv >= rv){
      leastdiff = lv - rv;
      return true;
    }else{
      return false;
    }
  }else{
    if(leastdiff == lv - rv){
      return true;
    }else{
      return false;
    }
  }
  return false;
}

ll gub;
int main(){
  // while(
    scanf("%lld%lld", &ub, &n);
     // == 2){
    lb = 0;
    gub = ub;
    // cout << gub << endl;
    for(ll i=1; i<=n; i++){
      ll t;
      scanf("%lld%lld%lld%lld", &l[i], &t, &len[i], &w[i]);
      r[i] = l[i] + len[i];
      // cout << l[i] << " " << len[i] << " " << r[i] << endl;
    }
    // cout << "HI";
    // return 0;
    ll ans = 0;
    while(ub >= lb){
      ll mid = (ub + lb) / 2;
      if(chk((mid), 1)){
        ans = mid;
        ub = mid - 1;
      }else{
        lb = mid + 1;
      }
    }
    lb = ans, ub = gub;
    ll gans = ans;
    // for(int i=ans; i<=gub; i++){
    //   if(chk(i, 0)){
    //     gans = i;
    //   }else{
    //     break;
    //   }
    // }
    // cout << lb << " " << ub << endl;
    while(ub >= lb){
      ll mid = (ub + lb) / 2;
      if(chk((mid), 0)){
        gans = mid;
        lb = mid + 1;
      }else{
        ub = mid - 1;
      }
    }
    // if(!leastdiff){
      // printf("%d\n", ans - 1);
    // }else{
      printf("%lld\n", gans);
    // }

  // }

  return 0;
}
