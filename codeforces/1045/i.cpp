#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>

using namespace std;

typedef long long ll;

const int MAXN = 1e5+7;
const int MAXC = 26;

int n;
int ch[MAXC];
int a[MAXN];
char c[MAXN*10];
int cn;
map<int, ll> mp;

int main(){

  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    memset(ch, 0, sizeof(ch));
    scanf("%s", c);
    cn = strlen(c);
    for(int j=0; j<cn; j++){
      ch[c[j] - 'a'] ++;
      // cout << c[j] - 'a' << " ";
    }
    // cout << endl;
    for(int j=0; j<MAXC; j++){
      ch[j] &= 1;
      // cout << ch[j] << " ";
      if(ch[j]) a[i] |= (1 << j);
    }
    mp[a[i]] ++;
    // cout << a[i] << endl;
  }
  ll gans = 0;
  for(int i=1; i<=n; i++){
    for(int j=0; j<MAXC; j++){
      gans += mp[a[i] ^ (1 << j)];
    }
    gans += mp[a[i]];
    gans --;
  }
  printf("%lld", (gans)/2);

  return 0;
}
