#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

const int RNDS = 8247252;
const int RNDM = 2394522123;
const int MAXN = 1e5+7;
const int INF = 0x7fffffff;

int treap_root;
int tncnt = 0;

struct treap_node {
  int key, val;
  int l, r;
  int size, cnt;
};

treap_node tn[MAXN];

int new_node(int val){
  ++tncnt;
  tn[tncnt].val = val;
  tn[tncnt].key = rand() % RNDM;
  tn[tncnt].size = tn[tncnt].cnt = 1;
  return tncnt;
}

void update(int p){
  tn[p].size = tn[tn[p].l].size + tn[tn[p].r].size + tn[p].cnt;
  return;
}

void init(){
  new_node(-INF);
  new_node(INF);
  tn[1].r = 2;
  treap_root = 1;
  update(treap_root);
  return;
}

int get_val_by_rank(int p, int trank){
  if(p == 0) return INF;
  if(trank <= tn[tn[p].l].size){
    return get_val_by_rank(tn[p].l, trank);
  }
  if(trank > tn[tn[p].l].size && trank <= tn[tn[p].l].size + tn[p].cnt){
    return tn[p].val;
  }
  if(trank > tn[tn[p].l].size + tn[p].cnt){
    return get_val_by_rank(tn[p].r, trank - tn[tn[p].l].size - tn[p].cnt);
  }
}

int get_rank_by_val(int p, int tval){
  if(p == 0) return 0;
  if(tn[p].val == tval){
    return tn[tn[p].l].size + 1;
  }
  if(tval < tn[p].val){
    return get_rank_by_val(tn[p].l, tval);
  }
  if(tval > tn[p].val){
    return get_rank_by_val(tn[p].r, tval) + tn[tn[p].l].size + tn[p].cnt;
  }
}

void zig(int &p){
  int q = tn[p].l;
  tn[p].l = tn[q].r;
  tn[q].r = p;
  p = q;
  update(tn[p].r);
  update(p);
  return;
}

void zag(int &p){
  int q = tn[p].r;
  tn[p].r = tn[q].l;
  tn[q].l = p;
  p = q;
  update(tn[p].l);
  update(p);
  return;
}

void tn_insert(int &p, int tval){
  if(p == 0){
    p = new_node(tval);
    return;
  }
  if(tn[p].val == tval){
    tn[p].cnt++;
  }else if(tval < tn[p].val){
    tn_insert(tn[p].l, tval);
    if(tn[tn[p].l].key > tn[p].key){
      zig(p);
    }
  }else if(tval > tn[p].val){
    tn_insert(tn[p].r, tval);
    if(tn[tn[p].r].key > tn[p].key){
      zag(p);
    }
  }
  update(p);
  return;
}

int get_pre(int tval){
  int ans = 1;
  int p = treap_root;
  while(p){
    if(tn[p].val == tval){
      if(tn[p].l){
        p = tn[p].l;
        while(tn[p].r){
          p = tn[p].r;
        }
        ans = p;
      }
      break;
    }
    if(tn[p].val > tn[ans].val && tn[p].val < tval){
      ans = p;
    }
    p = tval < tn[p].val ? tn[p].l : tn[p].r;
  }
  return tn[ans].val;
}

int get_post(int tval){
  int p = treap_root;
  int ans = 2;
  while(p){
    if(tn[p].val == tval){
      if(tn[p].r){
        p = tn[p].r;
        while(tn[p].l){
          p = tn[p].l;
        }
        ans = p;
      }
      break;
    }
    if(tn[p].val < tn[ans].val && tn[p].val > tval){
      ans = p;
    }
    p = tval < tn[p].val ? tn[p].l : tn[p].r;
  }
  return tn[ans].val;
}

void tn_remove(int &p, int tval){
  if(p == 0) return;
  if(tval == tn[p].val){
    if(tn[p].cnt > 1){
      tn[p].cnt--;
      update(p);
      return;
    }
    if(tn[p].l || tn[p].r){
      if(!tn[p].r || tn[tn[p].l].key > tn[tn[p].r].key){
        zig(p);
        tn_remove(tn[p].r, tval);
      }else{
        zag(p);
        tn_remove(tn[p].l, tval);
      }
      update(p);
    }else{
      p = 0;
    }
    return;
  }
  if(tval < tn[p].val){
    tn_remove(tn[p].l, tval);
  }else{
    tn_remove(tn[p].r, tval);
  }
  update(p);
  return;
}

int main(){
  srand(RNDS);
  init();
  int opn, optype, opx;
  scanf("%d", &opn);
  for(int opnt=0; opnt<opn; opnt++){
    scanf("%d%d", &optype, &opx);
    switch(optype){
      case 1:
        tn_insert(treap_root, opx);
        break;
      case 2:
        tn_remove(treap_root, opx);
        break;
      case 3:
        printf("%d\n", get_rank_by_val(treap_root, opx) - 1);
        break;
      case 4:
        printf("%d\n", get_val_by_rank(treap_root, opx + 1));
        break;
      case 5:
        printf("%d\n", get_pre(opx));
        break;
      case 6:
        printf("%d\n", get_post(opx));
        break;
    }
  }

  return 0;
}
