#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int MAXN = 13;
const int MAXM = 207;

const char di[6] = {'U','D','L','R','F','B'};
const int fx[6] = {0, 0, -1, 1, 0, 0};
const int fy[6] = {0, 0, 0, 0, 1, -1};
const int fz[6] = {-1, 1, 0, 0, 0, 0};
// const int fd[6] = {0, 0, 1, 1, 2, 2};
int n, m;
int bx[MAXM], by[MAXM], bz[MAXM];
int cx[MAXM], cy[MAXM], cz[MAXM], ld[MAXM];
// int pcnt, px[MAXM], py[MAXM], pz[MAXM];

void dfs(int level){
  if(level == n){
    if(cx[n-1] == 0 && cy[n-1] == 0 && cz[n-1] == 0){
      for(int j=0; j<m; j++){
        for(int k=0; k<j; k++){
          if(bx[j] == bx[k] && by[j] == by[k] && bz[j] == bz[k]) return;
        }
      }
      // for(int i=0; i<level; i++){
      //   printf("%c - %d %d %d\n", di[ld[i]], cx[i], cy[i], cz[i]);
      // }
      // cout << endl;
      //
      //   cout << "LEVEL CNT " << m << endl;
      //   for(int j=0; j<m; j++){
      //     printf("(%d, %d, %d)\n", bx[j], by[j], bz[j]);
      //   }
      for(int i=0; i<n; i++){
        printf("%c", di[ld[i]]);
      }
      printf("\n");
      // printf("\n\n");
    }
    return;
  }
  for(int i=0; i<6; i++){
    if(level != 0 && (i == ld[level-1] || (i^1) == ld[level-1])) continue;
    int lx, ly, lz;
    if(level == 0){
      lx = 0, ly = 0, lz = 0;
    }else{
      lx = cx[level-1], ly = cy[level-1], lz = cz[level-1];
    }
    cx[level] = lx + fx[i] * (level+1);
    cy[level] = ly + fy[i] * (level+1);
    cz[level] = lz + fz[i] * (level+1);
    ld[level] = i;
    bool entry = true, zero = false;
    for(int j=0; j<m; j++){
      if(!zero && bx[j] == 0 && by[j] == 0 && bz[j] == 0){
        zero = true;
        continue;
      }
      if(fx[i] != 0 && (ly == by[j] && cy[level] == by[j]) && (lz == bz[j] && cz[level] == bz[j]) ){
        if((lx <= bx[j] && bx[j] <= cx[level]) || (cx[level] <= bx[j] && bx[j] <= lx)){
          entry = false;
          // cout << "Entrance Failed on X: " << lx << "-> " << bx[j] << "-> " << cx[level] << endl;
          break;
        }
      }else if(fy[i] != 0 && (lx == bx[j] && cx[level] == bx[j]) && (lz == bz[j] && cz[level] == bz[j]) ){
        if((ly <= by[j] && by[j] <= cy[level]) || (cy[level] <= by[j] && by[j] <= ly)){
          // if(bx[j] == 0 && by[j] == 0 && bz[j] == 0) continue;
          entry = false;
          // cout << "Entrance Failed: on Y" << ly << " -> " << by[j] << " -> " << cy[level] << endl;
          break;
        }
      }else if(fz[i] != 0 && (lx == bx[j] && cx[level] == bx[j]) && (lz == bz[j] && cz[level] == bz[j]) ){
        if((lz <= bz[j] && bz[j] <= cz[level]) || (cz[level] <= bz[j] && bz[j] <= lz)){
          // if(bx[j] == 0 && by[j] == 0 && bz[j] == 0) continue;
          entry = false;
          // cout << "Entrance Failed on Z: " << ly << "-> " << by[j] << "-> " << cy[level] << endl;
          break;
        }
      }
    }
    // if(!entry){
    //   cout << "Entrance Failed: ";
    //   for(int j=0; j<level; j++){
    //     printf("%c", di[ld[j]]);
    //   }
    //   cout << "LEVEL CNT " << m << endl;
    //   for(int j=0; j<m; j++){
    //     printf("(%d, %d, %d) ", bx[j], by[j], bz[j]);
    //   }
    //   printf("\n\n");
    // }
    if(entry){
      for(int j=0; j<level+1; j++){
        if(fx[i] != 0){
          by[m+j] = cy[level], bz[m+j] = cz[level];
          bx[m+j] = lx+j*fx[i];
        } else if(fy[i] != 0){
          bx[m+j] = cx[level], bz[m+j] = cz[level];
          by[m+j] = ly+j*fy[i];
        } else if(fz[i] != 0){
          bx[m+j] = cx[level], by[m+j] = cy[level];
          bz[m+j] = lz+j*fz[i];
        }
      }
      m += level + 1;
      dfs(level+1);
      m -= level + 1;
    }
  }
  return;
}

int main(){

  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);

  memset(bx, 0, sizeof(bx));
  memset(by, 0, sizeof(by));
  memset(bz, 0, sizeof(bz));
  // printf("%c", di[0]);
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++){
    scanf("%d%d%d", &bx[i], &by[i], &bz[i]);
  }
  dfs(0);


  return 0;
}
