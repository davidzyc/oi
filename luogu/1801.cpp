#include<cstdio>
#include<iostream>
#include<cstdlib>

using namespace std;

const int MAXN = 2e5+7;
const int INF = 0x7fffffff;
const int RNDS = 872453453;
const int RNDM = 282342524;

int t_root;
int t_cnt = 0;

struct t_node {
  int key, val;
  int l, r;
  int size, cnt;
};

t_node t[MAXN];

int new_node(int tval){
  ++t_cnt;
  t[t_cnt].val = tval;
  t[t_cnt].key = rand() % RNDM;
  t[t_cnt].size = t[t_cnt].cnt = 1;
  return t_cnt;
}

void update(int p){
  t[p].size = t[p].cnt + t[t[p].l].size + t[t[p].r].size;
  return;
}

void init(){
  new_node(-INF);
  new_node(INF);
  t[1].r = 2;
  t_root = 1;
  update(t_root);
  return;
}

void zig(int &p){
  int q = t[p].l;
  t[p].l = t[q].r;
  t[q].r = p;
  p = q;
  update(t[p].r);
  update(p);
  return;
}

void zag(int &p){
  int q = t[p].r;
  t[p].r = t[q].l;
  t[q].l = p;
  p = q;
  update(t[p].l);
  update(p);
  return;
}

void insert(int &p, int tval){
  if(p == 0){
    p = new_node(tval);
    return;
  }
  if(t[p].val == tval){
    t[p].cnt ++;
    update(p);
    return;
  }
  if(tval < t[p].val){
    insert(t[p].l, tval);
    if(t[p].key < t[t[p].l].key){
      zig(p);
    }
  }else if(tval > t[p].val){
    insert(t[p].r, tval);
    if(t[p].key < t[t[p].r].key){
      zag(p);
    }
  }
  update(p);
  return;
}

int get_val_by_rank(int p, int trank){
  if(p == 0) return INF;
  if(trank <= t[t[p].l].size){
    return get_val_by_rank(t[p].l, trank);
  }
  if(trank <= t[t[p].l].size + t[p].cnt){
    return t[p].val;
  }
  if(trank > t[t[p].l].size + t[p].cnt){
    return get_val_by_rank(t[p].r, trank - t[t[p].l].size - t[p].cnt);
  }
}

int inscnt;
int getcnt = 0;
int opi[MAXN];
int opg[MAXN] = {0};

int main(){
  srand(RNDS);
  init();
  scanf("%d%d", &inscnt, &getcnt);
  for(int i=1; i<=inscnt; i++){
    scanf("%d", &opi[i]);
  }
  int gpos;
  for(int i=0; i<getcnt; i++){
    scanf("%d", &gpos);
    opg[gpos]++;
  }
  getcnt = 1;
  for(int i=1; i<=inscnt; i++){
    insert(t_root, opi[i]);
    for(int j=0; j<opg[i]; j++){
      getcnt ++;
      // cout << getcnt << " " ;
      printf("%d\n", get_val_by_rank(t_root, getcnt));
    }
  }
  return 0;
}
