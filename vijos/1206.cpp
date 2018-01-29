#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

int main(){
  int mstart[4][4], mend[4][4], tempm[4][4], tempmi, tmi, s = 0, e = 0;
  int dirx[4] = {0, -1, 0, 1}, diry[4] = {1, 0, -1, 0};
  int vis[70000] = {0};
  queue<int> q;
  char c;
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      c = getchar();
      mstart[i][j] = c - '0';
      s *= 2;
      s += mstart[i][j];
    }
    scanf("\n");
  }
  q.push(s);
  vis[s] = 1;
  scanf("\n");
  for(int i=0; i<4; i++){
    scanf("\n");
    for(int j=0; j<4; j++){
      c = getchar();
      mend[i][j] = c - '0';
      e *= 2;
      e += mend[i][j];
    }
  }
  while(!q.empty()){
    tempmi = q.front();
    tmi = tempmi;
    q.pop();
    // cout << tempmi << endl;
    if(tempmi == e){
      cout << vis[tempmi] - 1;
      return 0;
    }
    for(int i=3; i>=0; i--){
      for(int j=3; j>=0; j--){
        tempm[i][j] = tempmi % 2;
        tempmi /= 2;
      }
    }
    tempmi = tmi;
    int tx, ty, tc, tm;
    for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
        for(int k=0; k<4; k++){
          tx = i+dirx[k];
          ty = j+diry[k];
          if(tx>=0 && tx<4 && ty>=0 && ty<4 && tempm[i][j] != tempm[tx][ty]){
            tm = 0;
            tc = tempm[tx][ty];
            tempm[tx][ty] = tempm[i][j];
            tempm[i][j] = tc;
            for(int ti = 0; ti<4; ti++){
              for(int tj = 0; tj <4; tj++){
                tm *= 2;
                tm += tempm[ti][tj];
              }
            }
            // cout << tempmi << " - " << tm << endl;
            if(vis[tm] == 0){
              q.push(tm);
              vis[tm] = vis[tempmi]+1;
            }
            tc = tempm[i][j];
            tempm[i][j] = tempm[tx][ty];
            tempm[tx][ty] = tc;
          }
        }
        // cout << tempm[i][j] << " ";
      }
      // cout << endl;
    }
  }

  // cout << s << endl << e;
  return 0;
}
