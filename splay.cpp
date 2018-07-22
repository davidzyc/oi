#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 1e6+7;
const int INF = 0x3f3f3f3f;

int n;
int root = 1;
int node_cnt = 0;
int val[MAXN], fa[MAXN], ch[MAXN][2], sz[MAXN], cnt[MAXN], rev[MAXN];

int rlt(int x){
  return ch[fa[x]][1] == x;
}

void conn(int x, int f, int rlt){
  fa[x] = f;
  ch[f][rlt] = x;
}

void pushup(int x){
  sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x];
  if(ch[x][0]) fa[ch[x][0]] = x;
  if(ch[x][1]) fa[ch[x][1]] = x;
  // fa[ch[x][0]] = fa[ch[x][1]] = x;
}

void pushdown(int x){
  if(rev[x]){
    swap(ch[x][0], ch[x][1]);
    rev[ch[x][0]] ^= 1;
    rev[ch[x][1]] ^= 1;
    rev[x] = 0;
  }
}

void rotate(int x){
  int y, z, zsony, ysonx;
  y = fa[x];
  z = fa[y];
  zsony = rlt(y);
  ysonx = rlt(x);
  conn(ch[x][ysonx^1], y, ysonx);
  conn(y, x, ysonx^1);
  conn(x, z, zsony);
  pushup(y);
  pushup(x);
}

void splay(int x, int des){
  if(x == des) return;
  // cout << "HI";
  while(fa[x] != des){
    int y = fa[x];
    // printf("%d [fa] %d to %d\n", x, y, des);
    if(fa[y] != des){
      if(rlt(x) == rlt(y)){
        rotate(y);
      }else{
        rotate(x);
      }
    }
    rotate(x);
  }
  if(!des) root = x;
}

int new_node(int v){
  ++node_cnt;
  val[node_cnt] = v;
  cnt[node_cnt] = 1;
  sz[node_cnt] = 1;
  return node_cnt;
}

// int ins(int x, int v){
//   if(v == val[x]){
//     cnt[x]++;
//     pushup(x);
//     return x;
//   }
//   if(v < val[x]){
//     if(ch[x][0]){
//       ins(ch[x][0], v);
//     }else{
//       ch[x][0] = new_node(v);
//     }
//   }else{
//     if(ch[x][1]){
//       ins(ch[x][1], v);
//     }else{
//       ch[x][1] = new_node(v);
//     }
//   }
//   pushup(x);
//   return
// }

int ins(int &x, int v){
  if(!x){
    x = new_node(v);
    pushup(x);
    return x;
  }
  int ret;
  if(val[x] == v){
    cnt[x] ++;
    pushup(x);
    return x;
  }else if(v < val[x]) ret = ins(ch[x][0], v);
  else ret = ins(ch[x][1], v);
  pushup(x);
  return ret;
}

int kthnode(int x, int kth){
  pushdown(x);
  if(kth <= sz[ch[x][0]]){
    return kthnode(ch[x][0], kth);
  }else if(kth > sz[ch[x][0]] && kth <= sz[ch[x][0]]+cnt[x]){
    return x;
  }else{
    return kthnode(ch[x][1], kth-sz[ch[x][0]]-cnt[x]);
  }
  return -1;
}

void write(int x){
  pushdown(x);
  if(ch[x][0]) write(ch[x][0]);
  // printf("%d-cnt%d\n", val[x], cnt[x]);
  if(val[x]>0 && val[x] <=n) printf("%d ", val[x]);
  if(ch[x][1]) write(ch[x][1]);
}

int main(){
  root = new_node(INF);
  ch[root][0] = new_node(-INF);
  pushup(root);
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    int x = ins(root, i);
    splay(x, 0);
  }
  // for(int i=1; i<=node_cnt; i++){
    // printf("%d <- [fa %d] %d [val %d] -> %d\n", ch[i][0], fa[i], i, val[i], ch[i][1]);
  // }
  int q, ql, qr;
  scanf("%d", &q);
  for(int i=1; i<=q; i++){
    scanf("%d%d", &ql, &qr);
    ql = kthnode(root, ql);
    qr = kthnode(root, qr+2);
    // cout << ql << " " << qr << endl;
    splay(ql, 0);
    splay(qr, ql);
    rev[ch[qr][0]] ^= 1;
  }
  // printf("%d", kthnode(root, 7));
  write(root);


  return 0;
}
