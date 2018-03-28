#include<cstdio>
#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 1e5+7;
const int RNDS = 274523569;
const int RNDM = 734523974;
const int INF = 0x7fffffff;
const int FINDFAIL = -1;

priority_queue<pii, vector<pii>, greater<pii> > pq;

int gmin, opn;
int tadd = 0;

struct treap_node {
  int val, key;
  int l, r;
  int size, cnt;
};

treap_node t[MAXN];

int t_cnt = 0;
int treap_root;

int new_node(int tval){
  ++t_cnt;
  t[t_cnt].val = tval;
  t[t_cnt].key = rand() % RNDM;
  t[t_cnt].cnt = t[t_cnt].size = 1;
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
  treap_root = 1;
  update(treap_root);
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

int insert(int &p, int tval){
  int tid;
  if(p == 0){
    p = new_node(tval);
    tid = p;
    return tid;
  }
  if(tval == t[p].val){
    t[p].cnt++;
    update(p);
    tid = p;
    return tid;
  }
  if(tval < t[p].val){
    tid = insert(t[p].l, tval);
    if(t[p].key < t[t[p].l].key){
      zig(p);
    }
  }else if(tval > t[p].val){
    tid = insert(t[p].r, tval);
    if(t[p].key < t[t[p].r].key){
      zag(p);
    }
  }
  update(p);
  return tid;
}

int t_remove(int &p, int tval){
  int tid;
  if(p == 0) return FINDFAIL;
  if(tval == t[p].val){
    if(t[p].cnt >= 1){
      t[p].cnt --;
      update(p);
      tid = p;
      return tid;
    }
    if(t[p].l || t[p].r){
      if(!t[p].r || t[t[p].l].key > t[t[p].r].key){
        zig(p);
        tid = t_remove(t[p].r, tval);
      }else{
        zag(p);
        tid = t_remove(t[p].l, tval);
      }
      update(p);
    }else{
      tid = p;
      p = 0;
    }
    return tid;
  }
  tval < t[p].val ? tid = t_remove(t[p].l, tval) : tid = t_remove(t[p].r, tval);
  update(p);
  // tid = p;
  return tid;
}

int get_val_by_rank(int p, int trank){
  if(p == 0) return -INF;
  if(trank <= t[t[p].r].size){
    return get_val_by_rank(t[p].r, trank);
  }
  if(trank <= t[t[p].r].size + t[p].cnt){
    return t[p].val;
  }
  if(trank > t[t[p].r].size + t[p].cnt){
    return get_val_by_rank(t[p].l, trank - t[t[p].r].size - t[p].cnt);
  }
  return -INF;
}

int leavecnt = 0;

int main(){
  // freopen("1486.txt", "r", stdin);
  srand(RNDS);
  init();
  char opt;
  int opx;
  scanf("%d%d", &opn, &gmin);
  for(int i=0; i<opn; i++){
    cin >> opt >> opx;
    switch(opt){
      case 'I':
        if(opx - gmin >= 0){
          int tid;
          int tval = opx - gmin - tadd;
          tid = insert(treap_root, tval);
          pq.push(make_pair(tval, tid));
          // cout << "Insert: " << tid << " value: " << tval << endl;
        }
        break;
      case 'A':
        tadd += opx;
        break;
      case 'S':
        tadd -= opx;
        while(!pq.empty() && pq.top().first + tadd < 0){
          int tval = pq.top().first;
          int tid;
          pq.pop();
          tid = t_remove(treap_root, tval);
          ++leavecnt;
          // cout << "Remove: " << tid << " value: " << tval << endl;
        }
        break;
      case 'F':
        int ans = get_val_by_rank(treap_root, opx+1);
        printf("%d\n", ans > -INF ? ans + tadd + gmin : FINDFAIL);
        break;
    }
  }
  printf("%d", leavecnt);

  return 0;
}
