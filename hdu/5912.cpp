#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;

const int MAXN = 9;

ll gcd(int x, int y){
  return y == 0 ? x : gcd(y, x%y);
}

struct fraction{
  ll denominator, numerator;
  fraction(){
    denominator = 1;
    numerator = 0;
  }
  fraction(ll tn, ll td){
    denominator = td;
    numerator = tn;
  }
  fraction operator + (const fraction &f) const {
    ll tden, tnum, tgcd;
    tden = f.denominator * denominator;
    tnum = f.numerator * denominator + f.denominator * numerator;
    tgcd = gcd(tden, tnum);
    return fraction{tnum/tgcd, tden/tgcd};
  }
  fraction operator / (const fraction &f) const {
    ll tden, tnum, tgcd;
    tnum = f.denominator * numerator;
    tden = f.numerator * denominator;
    tgcd = gcd(tden, tnum);
    return fraction{tnum/tgcd, tden/tgcd};
  }
};

int main(){
  // freopen("5912.txt", "r", stdin);
  int tn;
  scanf("%d", &tn);
  for(int ti=0; ti<tn; ti++){
    fraction ans, tfa, tfb;
    int fn;
    int a[MAXN], b[MAXN];
    scanf("%d", &fn);
    for(int i=0; i<fn; i++){
      scanf("%d", &a[i]);
    }
    for(int i=0; i<fn; i++){
      scanf("%d", &b[i]);
    }
    for(int i=fn-1; i>=0; i--){
      tfa.numerator = (ll) a[i];
      tfa.denominator = 1;
      tfb.numerator = (ll) b[i];
      tfb.denominator = 1;
      ans = tfb/(tfa+ans);
      // cout << ans.numerator << "/" << ans.denominator << endl;
    }
    cout << "Case #" << ti+1 << ": " << ans.numerator << " " << ans.denominator << endl;
  }
  // int a, b, c, d;
  // cin >> a >> b >> c >> d;
  // fraction e{a, b}, f{c, d}, ans;
  // // ans = e/f;
  return 0;
}
