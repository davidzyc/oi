#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const int MAXN = 1e6+7;

int an, matn;
char a[MAXN];
char mat[MAXN];

int nxt[MAXN] = {0};

int main(){
  scanf("%s", a+1);
  scanf("%s", mat+1);
  an = strlen(a+1);
  matn = strlen(mat+1);

  for(int i=2, j=0; i<=matn; i++){
    while(j && mat[j+1] != mat[i]) j = nxt[j];
    if(mat[j+1] == mat[i]) ++j;
    nxt[i] = j;
  }

  for(int i=1, j=0; i<=an; i++){
    while(j && a[i] != mat[j+1]) j = nxt[j];
    if(mat[j+1] == a[i]) ++j;
    if(j == matn){
      printf("%d\n", i-j+1);
      j=nxt[j];
    }
  }

  for(int i=1; i<=matn; i++){
    printf("%d ", nxt[i]);
  }

  return 0;
}
