#include<cstdio>
#include<iostream>
#define MAXN 1 << 20
using namespace std;
typedef long long ll;
int n, a, m;
ll dat[2*MAXN-1], datp[2*MAXN-1];

void init(int _n){
  n = 1;
  while(n < _n){
    n *= 2;
  }
  for(int i=0; i<2*n-1; i++){
    dat[i] = 0;
    datp[i] = 0;
  }
  return;
}

void update_origin(int p, ll k){
  int pos = p+n-1;
  dat[pos] += k;
  while(pos > 0){
    pos = (pos-1) / 2;
    dat[pos] = dat[pos*2+1] + dat[pos*2+2];
  }
  return;
}

void update(int a, int b, int p, ll k, int l, int r){
  if(a >= r || b <= l){
    return;
  }
  if(r - l == 1 && a <= l && b >= r){
    // cout << "Hi";
    dat[n-1+l] += k;
    return;
  }
  // cout << l << " " << r << endl;
  update(a, b, p*2+1, k, l, (l+r)/2);
  update(a, b, p*2+2, k, (l+r)/2, r);
  dat[p] = dat[p*2+1] + dat[p*2+2];
  return;
}

ll query(int a, int b, int k, int l, int r){
  if(a >= r || b <= l){
    return 0;
  }else if(a <= l && b >= r){
    return dat[k];
  }else{
    ll tsum = 0;
    tsum += query(a, b, k*2+1, l, (l+r)/2);
    tsum += query(a, b, k*2+2, (l+r)/2, r);
    return tsum;
  }
}

int main(){
  ll t;
  cin >> a >> m;
  init(a);
  for(int i=0; i<a; i++){
    cin >> t;
    update_origin(i, t);
  }
  int op, x, y;
  ll k;
  for(int i=0; i<m; i++){
    cin >> op;
    if(op == 1){
      cin >> x >> y >> k;
      update(x-1, y, 0, k, 0, n);
    }else{
      cin >> x >> y;
      cout << query(x-1, y, 0, 0, n) << endl;
    }
  }

  return 0;
}
