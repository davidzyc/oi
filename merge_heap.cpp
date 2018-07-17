
int merge(int x, int y){
  if(!x || !y) return x | y;
  if(v[x] > v[y]) swap(x, y);
  rc[x] = merge(rc[x], y);
  swap(lc[x], rc[x]);
  dist[x] = dist[rc[x]] + 1;
  return x;
}
