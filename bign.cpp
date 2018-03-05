#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int MAXN = 1000;

struct bign{
  int len;
  int a[MAXN];
  void init(){
    len = 0;
    memset(a, 0, sizeof(a));
  }
  void printb(){
    if(len == 0){
      cout << 0 << endl;
      return;
    }
    for(int i=len-1; i>=0; i--){
      printf("%d", a[i]);
    }
    printf("\n");
  }
  bign(){
    len = 0;
    memset(a, 0, sizeof(a));
  }
  bign(long long num){
    len = 0;
    memset(a, 0, sizeof(a));
    while(num > 0){
      a[len] = num % 10;
      ++len;
      num /= 10;
    }
  }
  bign(string snum){
    len = 0;
    memset(a, 0, sizeof(a));
    int st = 0;
    for(int i=0; i<snum.length(); i++){
      if(snum[i] == '0'){
        st++;
      }else{
        break;
      }
    }
    for(int i=snum.length()-1; i>=st; i--){
      a[len] = snum[i] - '0';
      ++len;
    }
  }
  bign operator + (const bign &b) const {
    bign tb;
    int maxlen = max(b.len, len);
    for(int i=0; i<=maxlen; i++){
      tb.a[i] += a[i] + b.a[i];
      tb.a[i+1] += (tb.a[i]) / 10;
      tb.a[i] %= 10;
    }
    if(tb.a[maxlen]){
      tb.len = maxlen + 1;
    }else{
      tb.len = maxlen;
    }
    return tb;
  }
  bign operator * (const bign &b) const {
    bign tb, ttb;
    int bmul;
    for(int i=0; i<b.len; i++){
      ttb.init();
      ttb.len = i;
      bmul = b.a[i];
      for(int j=0; j<=len; j++){
        ttb.a[ttb.len] += a[j]*bmul;
        ttb.a[ttb.len+1] += ttb.a[ttb.len] / 10;
        ttb.a[ttb.len] %= 10;
        ++ttb.len;
      }
      if(!ttb.a[ttb.len]) --ttb.len;
      // ttb.printb();
      tb = tb + ttb;
    }
    return tb;
  }
};

int main(){
  string a, b;
  cin >> a >> b;
  bign numa(a);
  bign numb(b);
  bign ans;
  ans = numa * numb;
  // cout << numa.len << endl;
  ans.printb();


  return 0;
}
