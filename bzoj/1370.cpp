#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 2007;
// const int MAXN = 10007;

int n, m;
int fa[MAXN], a[MAXN];


int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void uinit(int n){
  for(int i=0; i<=n; i++){
    fa[i] = i;
  }
  return;
}

int ufind(int x){
  return x == fa[x] ? x : fa[x] = ufind(fa[x]);
}

void unite(int x, int y){
  int rx = ufind(x), ry = ufind(y);
  fa[ry] = rx;
  return;
}

int main(){
  int tf, tt;
  // scanf("%d%d", &n, &m);
  n = read(), m = read();
  uinit(n*2);
  for(int i=0; i<m; i++){
    char c[5];
    // scanf("%s%d%d", c, &tf, &tt);
    scanf("%s", c);
    tf = read(), tt = read();
    if(c[0] == 'E'){
      // if(ufind(tf) == ufind(tt) || ufind(tf+n) == ufind(tt+n)) printf("Wrong Answer");
      unite(tf, tt + n);
      unite(tt, tf + n);
    }else if(c[0] == 'F'){
      // if(ufind(tf+n) == ufind(tt) || ufind(tf) == ufind(tt+n)) printf("Wrong Answer");
      unite(tf, tt);
      // unite(tt + n, tf + n);
    }
  }
  for(int i=1; i<=n; i++){
    a[i] = ufind(i);
  }

  int cnt = 0;
  // for(int i=1; i<=n*2; i++){
  //   cout << fa[i] << " ";
  // }
  sort(a+1, a+n+1);
  for(int i=1; i<=n; i++){
    if(a[i] != a[i-1]){
      cnt++;
    }
  }
  printf("%d", cnt);

  return 0;
}
