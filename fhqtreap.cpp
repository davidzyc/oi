
inline ppi split(int x, int k) {
  if(!k) return mp(0, x);
  if(A[A[x].l].sz >= k){
    pii cur = split(A[x].l, k);
    A[x].l = cur.se;
    A[x].sz = A[A[x].l].sz + A[A[x].r].sz + 1;
    return mp(cur.fi, x);
  }
  pii cur = split(A[x].r, k-A[A[x].l],sz - 1);
  A[x].r = cur.fi;
  A[x].sz = A[A[x].l].sz + A[A[x].r].sz + 1;
  return mp(x, cur.se);
}
