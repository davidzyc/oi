#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;

typedef long long ll;
int origm[MAXN][MAXN];
int adjm[MAXN][MAXN];
vector<int> fm[MAXN][MAXN];
int n, m;
int v[MAXN];
vector<int> gans;
double kth[MAXN];

ll get_spath_cnt(int i, int j){
  ll cnt = (ll) fm[i][j].size();
  if(origm[i][j] < INF && adjm[i][j] == origm[i][j]){
    ++cnt;
  }
  return cnt;
}

int main(){
  memset(adjm, 0x3f, sizeof(adjm));
  memset(origm, 0x3f, sizeof(origm));
  int tf, tt, tl;
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++){
    scanf("%d%d%d", &tf, &tt, &tl);
    origm[tf][tt] = origm[tt][tf] = min(origm[tf][tt], tl);
    adjm[tf][tt] = adjm[tt][tf] = min(adjm[tf][tt], tl);
  }
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(i == j) continue;
        if(adjm[i][j] > adjm[i][k] + adjm[k][j]){
          adjm[i][j] = adjm[i][k] + adjm[k][j];
        }
      }
    }
  }
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(i == j) continue;
        if(adjm[i][j] == adjm[i][k] + adjm[k][j]){
          fm[i][j].push_back(k);
        }
      }
    }
  }
  // cout << adjm[1][4];
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      for(int k=0; k<fm[i][j].size(); k++){
        int kp = fm[i][j][k];
        double pos = (get_spath_cnt(i, kp) * get_spath_cnt(kp, j)) * 1.0 / (get_spath_cnt(i, j) * 1.0);
        // cout << i << " - " << kp << " > " << j << " : " << pos << endl;
        kth[kp] += pos;
      }
    }
  }

  for(int i=1; i<=n; i++){
    printf("%.3f\n", kth[i]);
  }

  return 0;
}
