#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 18;

int n;
int l[MAXN] = {0}, r[MAXN] = {0};

void preorder(int c){
  if(c == 0) return;
  printf("%d ", c);
  preorder(l[c]);
  preorder(r[c]);
  return;
}

void midorder(int c){
  if(c == 0) return;
  midorder(l[c]);
  printf("%d ", c);
  midorder(r[c]);
  return;
}

void postorder(int c){
  if(c == 0) return;
  postorder(l[c]);
  postorder(r[c]);
  printf("%d ", c);
  return;
}

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d %d", &l[i], &r[i]);
  }
  preorder(1);
  printf("\n");
  midorder(1);
  printf("\n");
  postorder(1);
  printf("\n");

  return 0;
}
