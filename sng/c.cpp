#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

const int MAXN = 1e5+7;

int q;
int cl;
char c[107];
int gx = 0, gy = 0;
int dx[107], dy[107];
int gxmax = 0, gxmin = 0, gymax = 0, gymin = 0;
int gxd, gyd, xpre = 0;


inline int read(){
  char c;
  int neg = 1;
  int ret = 0;
  for(c = getchar(); c < '0' || c > '9'; c = getchar()) if(c == '-') neg = -1;
  for(; c >= '0' && c <= '9'; c = getchar()) ret = ret*10 + c - '0';
  return ret*neg;
}


inline int inabs(int x){
  return x < 0 ? -x : x;
}

int main(){

  scanf("%s", c);
  cl = strlen(c);
  for(int i=0; i<cl ;i++){
    if(c[i] == 'U'){
      ++gy;
      dy[i] = 1;
    }else if(c[i] == 'D'){
      --gy;
      dy[i] = -1;
    }else if(c[i] == 'L'){
      --gx;
      dx[i] = -1;
    }else if(c[i] == 'R'){
      ++gx;
      dx[i] = 1;
    }
    gxmax = max(gx, gxmax);
    gxmin = min(gx, gxmin);
    gymax = max(gy, gymax);
    gymin = min(gy, gymin);
  }
  gxd = gxmax - gxmin;
  gyd = gymax - gymin;
  // xpre = max(gyd, gxd) + 1;
  xpre = max(gy ? inabs(gyd/gy) : gyd, gx ? inabs(gxd/gx) : gxd) + 1;
  // cout << "HI";
  // cout << gx << " " << gy;
  int x, y;
  // scanf("%d", &q);
  q = read();
  // cout << q << "JI";
  for(int k=0; k<q; k++){
    // scanf("%d%d", &x, &y);
    x = read(), y = read();
    // cout << x << " " << y << endl;
    // if(!gx || !gy || x/gx == y/gy){
      int cx, cy, tmul = 0;
      if(gx){
        tmul = x / gx;
      }else if(gy){
        tmul = y / gy;
      }
      cx = gx*(tmul-xpre>=0 ? tmul-xpre : 0), cy = gy*(tmul-xpre>=0 ? tmul-xpre : 0);
      // cout << cx << " " << cy << endl;
      if(cx == x && cy == y){
        printf("Yes\n");
        // continue;
      }else{
        bool flag = false;
        for(int j=0; j<xpre*2; j++){
          for(int i=0; i<cl ;i++){
            // if(c[i] == 'U'){
            //   ++cy;
            // }else if(c[i] == 'D'){
            //   --cy;
            // }else if(c[i] == 'L'){
            //   --cx;
            // }else if(c[i] == 'R'){
            //   ++cx;
            // }
            cx += dx[i];
            cy += dy[i];
            if(cx == x && cy == y){
              // printf("Yes\n");
              flag = true;
              break;
            }
          }
          if(flag) break;
        }
        if(flag){
          printf("Yes\n");
        }else{
          printf("No\n");
        }
      }
    // }else{
    //   printf("No\n");
    // }
  }

  return 0;
}
