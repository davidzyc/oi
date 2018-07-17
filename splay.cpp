#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 1e6+7;

int n, cn = 0, root = 0, ch[MAXN][2], fa[MAXN], val[MAXN], sz[MAXN], cnt[MAXN], tag[MAXN] = {0};

void pushdown(int x){
  if(tag[x]){
    swap(ch[x][0], ch[x][1]);
    tag[ch[x][0]] = tag[ch[x][1]] ^= 1;
    tag[x] = 0;
  }
}

void upd(int x){
  sz[x] = cnt[x] + sz[ch[x][0]] + sz[ch[x][1]];
}

int idfa(int x){
  return x == ch[fa[x]][1] ? 1 : 0;
}

void conn(int x, int f, int fson){
  fa[x] = f;
  ch[f][fson] = x;
}

void rotate(int x){
  int y = fa[x];
  int z = fa[y];
  int zson = idfa(y);
  int yson = idfa(x);
  conn(ch[x][yson^1], y, yson);
  conn(y, x, yson^1);
  conn(x, z, zson);
  upd(y);
  upd(x);
}

void splay(int at, int to){
  while(fa[at] != to){
    // cout << at << " "<< fa[at] << endl;
    int up = fa[at];
    if(fa[up] == to){
      rotate(at);
      continue;
    }
    if(idfa(up) == idfa(fa[up])){
      rotate(up);
      rotate(at);
    }else{
      rotate(at);
      rotate(at);
    }
  }
}

void write(int x){
  pushdown(x);
  if(ch[x][0]){
    write(ch[x][0]);
  }
  if(x > 1 && x <= n+1) printf("%d ", val[x]-1 );
  if(ch[x][1]){
    write(ch[x][1]);
  }
}

int kth(int tsz){
  int x = root;
  while(true){
    pushdown(x);
    if(tsz <= sz[ch[x][0]]) x = ch[x][0];
    else if(tsz == sz[ch[x][0]]+1) return x;
    else tsz-=(sz[ch[x][0]]+1), x=ch[x][1];
  }
}

void ins(int v){
  int x = root, y;
  while(true){
    int di = val[x] < v ? 1 : 0;
    y = x;
    x = ch[x][di];
    if(!x){
      x = ++cn;
      val[x] = v;
      fa[x] = y;
      ch[y][di] = x;
      sz[x] = 1;
      cnt[x] = 1;
      break;
    }
  }
}

int main(){
  int q;
  root = 0;
  scanf("%d%d", &n, &q);
  for(int i=1; i<=n+2; i++){
    ins(i);
    splay(i, root);
    // for(int i=1; i<=n+2; i++){
    //   printf("%d<-(^%d)%d(val:%d)->%d\n", ch[i][0], fa[i], i, val[i], ch[i][1]);
    // }
    // cout << endl;
  }
  write(root);
  cout << endl;
  int tl, tr;
  for(int i=0; i<q; i++){
    scanf("%d%d", &tl, &tr);
    tl = kth(tl);
    tr = kth(tr+2);
    cout << tl << " " << tr << " ";
    splay(tl, root);
    splay(tr, tl);
    cout << ch[ch[root][1]][0] << endl;
    tag[ch[ch[root][1]][0]] ^= 1;
    write(root);
    cout << endl;
  }

  return 0;
}
