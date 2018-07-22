#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<cstring>
using namespace std;

typedef unsigned long long ull;

map<ull, int> v;

int n, ans;
char c[1007];
int cl;

int main(){

  scanf("%d", &n);
  for(int i=0; i<n; i++){
    ull thash = 0;
    scanf("%s", c);
    cl = strlen(c);
    for(int j=0; j<cl ;j++){
      thash = thash * 13331 + c[j] - '0';
    }
    // cout << thash << " ";
    if(v[thash]) ans++;
    v[thash] = 1;
  }
  printf("%d", n-ans);

  return 0;
}
