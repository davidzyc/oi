#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;
typedef pair<int, int> pii;

const int fac[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int vis[400000] = {0};
int m[4][4], serial[10];

int main(){
  int s = 123804765, ter;
  cin >> ter;
  pii f;
  f.first = s;
  f.second = 0;
  queue<pii> q;
  q.push(f);
  while(!q.empty()){
    pii c = q.front();
    q.pop();
    int cserial = c.first;
    int t = cserial;
    int ccnt = c.second;
    if(cserial == ter){
      cout << ccnt << endl;
      return 0;
    }
    for(int j=9; j>=1; j--){
      serial[j] = cserial % 10;
      cserial /= 10;
    }
    int cantor = 0;
    for(int j=1; j<=9; j++){
      int cantorcnt = 0;
      for(int k=j+1; k<=9; k++){
        if(serial[k] < serial[j]){
          cantorcnt++;
        }
      }
      cantor += cantorcnt * fac[9-j];
    }
    if(vis[cantor]){
      continue;
    }
    vis[cantor] = 1;
    int cx, cy, tx, ty;
    for(int i=3; i>=1; i--){
      for(int j=3; j>=1; j--){
        m[i][j] = t % 10;
        if(m[i][j] == 0){
          cx = j;
          cy = i;
        }
        t /= 10;
      }
    }
    int tex, ts;
    for(int k=0; k<4; k++){
      tx = dx[k] + cx;
      ty = dy[k] + cy;
      if(tx >= 1 && tx <= 3 && ty >= 1 && ty <= 3){
        tex = m[cy][cx];
        m[cy][cx] = m[ty][tx];
        m[ty][tx] = tex;
        ts = 0;
        for(int i=1; i<=3; i++){
          for(int j=1; j<=3; j++){
            ts *= 10;
            ts += m[i][j];
          }
        }
        q.push(make_pair(ts, ccnt+1));
        tex = m[cy][cx];
        m[cy][cx] = m[ty][tx];
        m[ty][tx] = tex;
      }
    }
  }

  return 0;
}
