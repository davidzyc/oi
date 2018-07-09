#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

typedef unsigned long long ull;

const int MAXN = 1e6+7;
const int MP = 137;

int clen = 0;
char s[MAXN];
ull mpow[MAXN] = {0}, shash[MAXN] = {0};

int main(){

  scanf("%s", s+1);
  clen = strlen(s+1);
  mpow[0] = 1;
  // shash[0] = s[0] - 'a' + 1;
  for(int i=1; i<=clen; i++){
    mpow[i] = mpow[i-1] * MP;
    shash[i] = shash[i-1] * MP + (s[i] - 'a' + 1);
  }
  int q, l1, r1, l2, r2;
  scanf("%d", &q);
  for(int i=0; i<q; i++){
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    if(r1 - l1 == r2 - l2 && shash[r1] - shash[l1-1] * mpow[r1 - l1 + 1] == shash[r2] - shash[l2-1] * mpow[r2 - l2 + 1] ){
      printf("Yes\n");
    }else{
      printf("No\n");
    }
  }

  return 0;
}
