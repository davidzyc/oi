#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int MAXN = 1e5+7;
const int MAXM = 7e6+7;

priority_queue<int> q;
int n, m, qq, u, v, t;
int l;
int mm[MAXM];
int tt[MAXM];

int read(){
  int ret = 0;
  char c = getchar();
  for(;c<'0' || c>'9'; c=getchar());
  for(;c>='0'&&c<='9';c = getchar()) ret = ret*10 + c -'0';
  return ret;
}

void printpq(int ttt){
  int nn = 0;
  while(!q.empty()){
    tt[nn] = q.top();
    q.pop();
    cout << tt[nn]+ttt << " ";
    ++nn;
  }
  for(int i=0; i<nn; i++){
    q.push(tt[i]);
  }
  printf("\n");
  return;
}

int main(){
  while(!q.empty()) q.pop();
  scanf("%d%d%d%d%d%d", &n, &m, &qq, &u, &v, &t);
  for(int i=0; i<n; i++){
    // scanf("%d", &l)
    l = read();
    q.push(l);
  }
  for(int i=1; i<=m; i++){
    int x = q.top();
    q.pop();
    mm[i] = (i-1)*qq + x;
    int y, z;
    y = (int) ((long double)((x + (i-1)*qq) * (u*1.0)) / (v*1.0)) - i*qq;
    // z = (int) ((x + (i-1)*qq) * ((v - u)*1.0) / (v*1.0)) - i*qq;
    z = (int) (x + (i-1)*qq) - y - 2*i*qq;
    q.push(y);
    q.push(z);
    // printf("POP %d PUSH %d %d \n", x, y, z);
    // printpq(i);
  }
  // cout << t << " T";
  for(int i=t; i<=m; i+=t){
    printf("%d ", mm[i]);
  }
  printf("\n");
  int ttt = 0;
  while(!q.empty()){
    ++ttt;
    if(ttt % t == 0) printf("%d ", q.top() + qq*m);
    q.pop();
  }

  return 0;
}
