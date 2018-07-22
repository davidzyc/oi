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
int dat[MAXN*4] = {0};

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

int main(){
  freopen("garden.in", "r", stdin);
  freopen("garden.ans", "w", stdout);
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
  int tans, gans = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int f1id = get_id(i, j);
      for(int k=0; k<n; k++){
        for(int h=0; h<m; h++){
          if(i == k && j == h) continue;
          int f2id = get_id(k, h);
          tans = val[i][j] + val[k][h];
          for(int f=0; f<to[f1id].size(); f++){
            for(int g=0; g<to[f2id].size(); g++){
              if(to[f1id][f] == to[f2id][g]){
                tans -= a[get_pos(to[f1id][f]).first][get_pos(to[f1id][f]).second];
              }
            }
          }
          gans = max(gans, tans);
        }
      }
    }
  }

  printf("%d\n", gans);

  return 0;
}
