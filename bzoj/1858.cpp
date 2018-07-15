#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

// #define DEB true

typedef pair<int, int> pii;

const int MAXN = 4e5+7;

int n, q;
int a[MAXN];
int glen = 0;

struct {
  int cnt[2];
  // [1] -> 0, 1 || [2] -> left right mid;
  int len[2][3];
  int rev, stval, stavail;
} Node[MAXN] ;

#ifdef DEB

void debug_out(int x, int l, int r){
  printf("Node %d: %d-%d, cnt[1]=%d, left=%d, mid=%d, right=%d\n", x, l, r, Node[x].cnt[1], Node[x].len[1][0], Node[x].len[1][2], Node[x].len[1][1]);
}

void debug(int x, int l, int r){
  if(l == r){
    debug_out(x, l, r);
    return;
  }
  int mid = (l+r)>>1;
  if(l <= mid){
    debug(x*2, l, mid);
  }
  if(r > mid){
    debug(x*2+1, mid+1, r);
  }
  debug_out(x, l, r);
  return;
}

// void debug(int x, int l, int r){
//     return;
// }

#endif

void pushdown(int x, int l, int r){
  int mid = (l+r) >> 1;
  if(Node[x].stavail){
    Node[x*2].stavail = Node[x*2+1].stavail = 1;
    Node[x].stavail = 0;
    Node[x*2].stval = Node[x].stval;
    Node[x*2+1].stval = Node[x].stval;
    Node[x*2].cnt[Node[x].stval] = mid+1-l;
    Node[x*2].cnt[Node[x].stval^1] = 0;
    Node[x*2+1].cnt[Node[x].stval] = r - mid;
    Node[x*2+1].cnt[Node[x].stval^1] = 0;
    for(int i=0; i<3; i++){
      Node[x*2].len[Node[x].stval][i] = mid + 1 - l;
      Node[x*2].len[Node[x].stval^1][i] = 0;
      Node[x*2+1].len[Node[x].stval][i] = r - mid;
      Node[x*2+1].len[Node[x].stval^1][i] = 0;
    }
    Node[x].rev = Node[x*2].rev = Node[x*2+1].rev = 0;
    return;
    // Node[x].stval = -1;
  }
  if(Node[x].rev){

    if(Node[x*2].stavail){
        Node[x*2].stval ^= 1;
        Node[x*2].cnt[Node[x*2].stval] = mid - l + 1;
        Node[x*2].cnt[Node[x*2].stval^1] = 0;
        for(int i=0; i<3; i++){
          Node[x*2].len[Node[x*2].stval][i] = mid - l + 1;
          Node[x*2].len[Node[x*2].stval^1][i] = 0;
        }
        Node[x*2].rev = 0;
    }else{
        Node[x*2].rev ^= 1;
        swap(Node[x*2].cnt[0], Node[x*2].cnt[1]);
        for(int i=0; i<3; i++){
            swap(Node[x*2].len[0][i], Node[x*2].len[1][i]);
          }
    }
    if(Node[x*2+1].stavail){
        Node[x*2+1].stval ^= 1;
        Node[x*2+1].cnt[Node[x*2+1].stval] = r - mid;
        Node[x*2+1].cnt[Node[x*2+1].stval^1] = 0;
        for(int i=0; i<3; i++){
          Node[x*2+1].len[Node[x*2+1].stval][i] = r - mid;
          Node[x*2+1].len[Node[x*2+1].stval^1][i] = 0;
        }
        Node[x*2+1].rev = 0;
    }else{
        Node[x*2+1].rev ^= 1;
        swap(Node[x*2+1].cnt[0], Node[x*2+1].cnt[1]);
        for(int i=0; i<3; i++){
            swap(Node[x*2+1].len[0][i], Node[x*2+1].len[1][i]);
          }
    }
    Node[x].rev = 0;
  }

  return;
}

void pushup(int x, int l, int r){
  int mid = (l+r) >> 1;
  for(int i=0; i<2; i++){
    Node[x].len[i][0] = (Node[x*2].len[i][0] == mid - l + 1) ? Node[x*2].len[i][0] + Node[x*2+1].len[i][0] :  Node[x*2].len[i][0];
    Node[x].len[i][1] = (Node[x*2+1].len[i][1] == r - mid) ? Node[x*2].len[i][1] + Node[x*2+1].len[i][1] : Node[x*2+1].len[i][1];
    Node[x].len[i][2] = max(max(Node[x].len[i][0], Node[x].len[i][1]), Node[x*2].len[i][1]+Node[x*2+1].len[i][0]);
    Node[x].len[i][2] = max(Node[x].len[i][2], max(Node[x*2].len[i][2], Node[x*2+1].len[i][2]));
    Node[x].cnt[i] = Node[x*2].cnt[i] + Node[x*2+1].cnt[i];
  }
  return;
}

void build(int x, int l, int r){
  if(l == r){
    Node[x].cnt[a[l]] = Node[x].len[a[l]][0] = Node[x].len[a[l]][1] = Node[x].len[a[l]][2] = 1;
    return;
  }
  int mid = (l+r) >> 1;
  if(l <= mid){
    build(x*2, l, mid);
  }
  if(r > mid){
    build(x*2+1, mid+1, r);
  }
  pushup(x, l, r);
  return;
}

int query_cnt(int a, int b, int x, int l, int r){
  if(a <= l && b >= r){
    // #ifdef DEB
    // debug_out(x, l, r);
    // #endif
    return Node[x].cnt[1];
  }
  // #ifdef DEB
  // debug_out(x, l, r);
  // #endif
  pushdown(x, l, r);
  int mid = (l+r) >> 1, ans = 0;
  if(a <= mid){
    ans += query_cnt(a, b, x*2, l, mid);
  }
  if(b > mid){
    ans += query_cnt(a, b, x*2+1, mid+1, r);
  }
  return ans;
}

pii query_len(int a, int b, int x, int l, int r){
  if(a <= l && b >= r){
    // debug_out(x, l, r);
    // printf("RETURN %d L-R %d\n",Node[x].len[1][0], Node[x].len[1][1]);
    glen = max(glen, Node[x].len[1][0]);
    glen = max(glen, Node[x].len[1][1]);
    glen = max(glen, Node[x].len[1][2]);
    return make_pair(Node[x].len[1][0], Node[x].len[1][1]);
  }
  pushdown(x, l, r);
  int mid = (l+r) >> 1;
  pii ans;
  if(a <= mid){
    ans = query_len(a, b, x*2, l, mid);
  }
  if(b > mid){
    pii tans = query_len(a, b, x*2+1, mid+1, r);
    glen = max(glen, ans.second + tans.first);
    if(ans.first == mid - l + 1){
      ans.first += tans.first;
    }
    if(tans.second == r - mid){
      ans.second += tans.second;
    }else{
        ans.second = tans.second;
    }
  }
  glen = max(glen, ans.first);
  glen = max(glen, ans.second);
//   debug_out(x, l, r);
//   printf("RETURN %d L-R %d\n", ans.first, ans.second);
  return ans;
}

void uset(int a, int b, int x, int val, int l, int r){
  if(a <= l && b >= r){
    Node[x].cnt[val] = r - l + 1;
    Node[x].cnt[val^1] = 0;
    for(int i=0; i<3; i++){
      Node[x].len[val][i] = r - l + 1;
      Node[x].len[val^1][i] = 0;
    }
    Node[x].rev = 0;
    Node[x].stavail = 1;
    Node[x].stval = val;
    return;
  }
  pushdown(x, l, r);
  int mid = (l+r) >> 1, ans = 0;
  if(a <= mid){
    uset(a, b, x*2, val, l, mid);
  }
  if(b > mid){
    uset(a, b, x*2+1, val, mid+1, r);
  }
  pushup(x, l, r);
  return;
}

void urev(int a, int b, int x, int l, int r){
  if(a <= l && b >= r){
    if(Node[x].stavail){
      Node[x].stval ^= 1;
      int val = Node[x].stval;
      Node[x].cnt[val] = r - l + 1;
      Node[x].cnt[val^1] = 0;
      for(int i=0; i<3; i++){
        Node[x].len[val][i] = r - l + 1;
        Node[x].len[val^1][i] = 0;
      }
    }else{
        swap(Node[x].cnt[0], Node[x].cnt[1]);
        for(int i=0; i<3; i++){
          swap(Node[x].len[0][i], Node[x].len[1][i]);
        }
      Node[x].rev ^= 1;
    }
    return;
  }
  pushdown(x, l, r);
  int mid = (l+r) >> 1;
  if(a <= mid){
    urev(a, b, x*2, l, mid);
  }
  if(b > mid){
    urev(a, b, x*2+1, mid+1, r);
  }
  pushup(x, l, r);
  return;
}

int main(){
  // freopen("1858.in", "r", stdin);
  // freopen("1858.out", "w", stdout);
  int op, opa, opb;
  scanf("%d%d", &n, &q);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  build(1, 1, n);
  // debug(1, 1, n);
  for(int i=0; i<q; i++){
    scanf("%d%d%d", &op, &opa, &opb);
    ++opa, ++opb;
    if(op == 0){
      uset(opa, opb, 1, 0, 1, n);
    }else if(op == 1){
      uset(opa, opb, 1, 1, 1, n);
    }else if(op == 2){
      urev(opa, opb, 1, 1, n);
    }else if(op == 3){
      printf("%d\n", query_cnt(opa, opb, 1, 1, n));
    }else if(op == 4){
      glen = 0;
      query_len(opa, opb, 1, 1, n);
    //   debug(1, 1, n);
      printf("%d\n", glen);
      // printf("NO FUNC\n");
    }
    // debug(1, 1, n);
    // printf("\n");
    // for(int i=1; i<=n; i++){
        // query_cnt(i, i, 1, 1, n);
    //   printf("%d ", query_cnt(i, i, 1, 1, n));
    // }
    // printf("\n");
  }


  return 0;
}
