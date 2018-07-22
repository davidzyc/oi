#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 1e6+7;
const int MUL = 1e6;

int n, m, q;
int x[MAXN], y[MAXN];
int num[MAXN], id[MAXN];
int ft[MAXN];
vector<int> ent[MAXN];

bool cmp(int a, int b){
  return num[a] < num[b];
}

int main(){

  scanf("%d%d%d", &n, &m ,&q);
  for(int i=1; i<=q; i++){
    scanf("%d%d", &x[i], &y[i]);
    num[i] = (y[i] - 1) * m + x[i];
    id[i] = i;
  }
  


  return 0;
}
