#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int MAXK = 17;
const int MAXP = 10007;
const int MAXN = 107;

typedef pair<int, int> pii;

char c[MAXN];
int a[MAXN][MAXN];
int n, m, kn;
int x[MAXK], y[MAXK];
int val[MAXN][MAXN] = {0};
vector<int> to[MAXP];
vector<int> from[MAXP];
int dat[MAXP*4] = {0};

int get_id(int i, int j){
  return i*m + j;
}

pii get_pos(int id){
  return make_pair(id/m, id%m);
}

bool chk_pos(int i, int j){
  return ((i >= 0 && i < n) && (j >= 0 && j < m)) ? 1 : 0;
}

void pushup(int node_id){
  dat[node_id] = max(dat[node_id*2], dat[node_id*2+1]);
  return;
}

void build(int node_id, int l, int r){
  if(l == r){
    // cout << node_id << " " << get_pos(l-1).first << " " << get_pos(l-1).second << " " <<  val[get_pos(l-1).first][get_pos(l-1).second] << endl;
    dat[node_id] = val[get_pos(l-1).first][get_pos(l-1).second];
    return;
  }
  int mid = (l+r)>>1;
  build(node_id*2, l, mid);
  build(node_id*2+1, mid+1, r);
  pushup(node_id);
  return;
}

void upd(int p, int v, int node_id, int l, int r){
  if(l == r && l == p){
    dat[node_id] += v;
    return;
  }
  int mid = (l+r)>>1;
  if(p <= mid) upd(p, v, node_id*2, l, mid);
  else upd(p, v, node_id*2+1, mid+1, r);
  pushup(node_id);
  return;
}

int qry(int p, int node_id, int l, int r){
  if(l == r && l == p){
    // dat[node_id] += v;
    // cout << "(" << l << ", " << dat[node_id] << ")\t";
    // printf("(%d, id %d, val %d)\t", l, node_id, dat[node_id]);
    return dat[node_id];
  }
  int mid = (l+r)>>1;
  if(p <= mid) return qry(p, node_id*2, l, mid);
  else return qry(p, node_id*2+1, mid+1, r);
  return -1;
}

void print_seg(){
  for(int k=1; k<=n*m; k++){
    cout << qry(k, 1, 1, n*m) << " ";
  }
  cout << endl;
}

int main(){
  freopen("garden.in", "r", stdin);
  freopen("garden.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &kn);
  for(int i=0; i<n; i++){
    scanf("%s", c);
    for(int j=0; j<m; j++){
      a[i][j] = c[j] - '0';
    }
  }
  for(int i=0; i<kn; i++){
    scanf("%d%d", &x[i], &y[i]);
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      // printf("%d ", a[i][j]);
      // printf("(%d, %d) %d\t", get_pos(get_id(i, j)).first, get_pos(get_id(i, j)).second, get_id(i, j));
      for(int k=0; k<kn; k++){
        int ni = i + x[k], nj = j + y[k];
        if(!chk_pos(ni, nj)) continue;
        to[get_id(i, j)].push_back(get_id(ni, nj));
        from[get_id(ni, nj)].push_back(get_id(i, j));
      }
    }
    // printf("\n");
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int nid = get_id(i, j);
      for(int k=0; k<to[nid].size(); k++){
        int ni = get_pos(to[nid][k]).first, nj = get_pos(to[nid][k]).second;
        val[i][j] += a[ni][nj];
      }
    }
  }
  int gans = 0;
  build(1, 1, n*m);
  // for(int i=1; i<=50; i++) cout << dat[i] << " ";
  // print_seg();
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int nid = get_id(i, j);
      upd(nid+1, -val[i][j], 1, 1, n*m);
      for(int k=0; k<to[nid].size(); k++){
        int tid = to[nid][k];
        int tv = a[get_pos(tid).first][get_pos(tid).second];
        for(int h=0; h<from[tid].size(); h++){
          int fid = from[tid][h];
          upd(fid+1, -tv, 1, 1, n*m);
        }
      }
      gans = max(gans, val[i][j] + dat[1]);
      // printf("(%d,%d) %d+max(%d)\n", i, j, val[i][j], dat[1]);
      // print_seg();
      for(int k=0; k<to[nid].size(); k++){
        int tid = to[nid][k];
        int tv = a[get_pos(tid).first][get_pos(tid).second];
        for(int h=0; h<from[tid].size(); h++){
          int fid = from[tid][h];
          upd(fid+1, tv, 1, 1, n*m);
        }
      }
      upd(nid+1, val[i][j], 1, 1, n*m);
      // printf("%d ", val[i][j]);
    }
    // printf("\n");
  }

  printf("%d\n", gans);

  return 0;
}
