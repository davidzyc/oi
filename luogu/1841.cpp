#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int MAXN = 205;

int adjm[MAXN][MAXN];
int mcnt[MAXN][MAXN];
int mid[MAXN][MAXN];
int n, m;
int v[MAXN];
vector<int> gans;

int main(){
  memset(adjm, 0x3f, sizeof(adjm));
  int tf, tt, tl;
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++){
    scanf("%d%d%d", &tf, &tt, &tl);
    adjm[tf][tt] = adjm[tt][tf] = min(adjm[tf][tt], tl);
  }
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(i == j) continue;
        if(adjm[i][j] > adjm[i][k] + adjm[k][j]){
          mcnt[i][j] = 1;
          adjm[i][j] = adjm[i][k] + adjm[k][j];
          mid[i][j] = k;
        }else if(adjm[i][j] == adjm[i][k] + adjm[k][j]){
          mcnt[i][j]++;
        }
      }
    }
  }
  // cout << fm
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(mcnt[i][j] == 1){
        // cout << i << " -> " << j << " : " << mid[i][j] << endl;
        v[mid[i][j]] = 1;
      }
    }
  }
  for(int i=1; i<=n; i++){
    if(v[i]){
      gans.push_back(i);
    }
  }
  if(!gans.size()){
    printf("No important cities.");
  }else{
    for(int i=0; i<gans.size(); i++){
      printf("%d ", gans[i]);
    }
  }

  return 0;
}
