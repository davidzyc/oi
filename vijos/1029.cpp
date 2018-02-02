#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#define TPN 50
#define MSIZE 4
#define MLEN 3
#define TARGETTMP 15
#define MAXENCODE 370000
using namespace std;

int matrix[MSIZE][MSIZE];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
const int fac[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int vis[MAXENCODE] = {0}, steps[MAXENCODE] = {0}, contorvis[10];

int encode_matrix(){
  int m=0, t, ct;
  for(int i=0; i<MLEN; i++){
    for(int j=0; j<MLEN; j++){
      ct = 0;
      t = (MLEN-i-1) * MLEN + (MLEN-j-1);
      for(int kt = MLEN*MLEN-t; kt<MLEN*MLEN; kt++){
        if(matrix[kt/MLEN][kt%MLEN] < matrix[i][j]){
          ct++;
        }
      }
      m += ct * fac[t];
      // cout << m << " ";
    }
  }
  return m;
}

void decode_matrix(int m){
  memset(contorvis, 0, sizeof(contorvis));
  int t, smaller, k, cnt = 0;
  for(int i=0; i<MLEN; i++){
    for(int j=0; j<MLEN; j++){
      int num;
      t = (MLEN-i-1)*MLEN + (MLEN-j-1);
      smaller = m / fac[t];
      // cout << smaller << " ";
      for(num=1; num<10; num++){
        if(contorvis[num] == 0 && smaller == 0) break;
        if(contorvis[num] == 0) smaller --;
      }
      contorvis[num] = 1;
      matrix[i][j] = num;
      m %= fac[t];
    }
  }
}

bool check_matrix(){
  // bool flag = true;
  int tmp;
  for(int i=0; i<MLEN; i++){
    tmp = 0;
    for(int j=0; j<MLEN; j++){
      tmp += matrix[i][j];
    }
    if(tmp != TARGETTMP){
      return false;
    }
  }
  for(int i=0; i<MLEN; i++){
    tmp = 0;
    for(int j=0; j<MLEN; j++){
      tmp += matrix[j][i];
    }
    if(tmp != TARGETTMP){
      return false;
    }
  }
  tmp = 0;
  for(int i=0; i<MLEN; i++){
    tmp += matrix[i][i];
  }
  if(tmp != TARGETTMP){
    return false;
  }
  tmp = 0;
  for(int i=0; i<MLEN; i++){
    tmp += matrix[i][MLEN-1-i];
  }
  if(tmp != TARGETTMP){
    return false;
  }
  return true;
}

int main(){

  for(int rr = 0; rr < TPN; rr++){
    bool noresult = true;
    int tmatrix;
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    memset(steps, 0, sizeof(steps)); //这个没清零，出错都找不到！！！！
    for(int i=0; i<MLEN; i++){
      for(int j=0; j<MLEN; j++){
        cin >> matrix[i][j];
      }
    }
    int mstart = encode_matrix();
    q.push(mstart);
    // vis[mstart] = 1;
    while(!q.empty()){
      tmatrix = q.front();
      q.pop();
      decode_matrix(tmatrix);
      if(check_matrix()){
        cout << steps[tmatrix] << endl;
        noresult = false;
        break;
      }
      // for(int i=0; i<MLEN; i++){
      //   for(int j=0; j<MLEN; j++){
      //     cout << matrix[i][j] << " ";
      //   }
      //   cout << endl;
      // }
      // cout << endl;
        for(int i=0; i<MLEN; i++){
          for(int j=0; j<MLEN; j++){
            for(int k=0; k<4; k++){
              int ti = i+dy[k], tj = j+dx[k], tt, tm;
              if(ti>=0&&ti<MLEN&&tj>=0&&tj<MLEN){
                tt = matrix[i][j];
                matrix[i][j] = matrix[ti][tj];
                matrix[ti][tj] = tt;
                tm = encode_matrix();
                if(vis[tm] == 0){
                  vis[tm] = 1;
                  steps[tm] = steps[tmatrix] +1;
                  q.push(tm);
                }
                tt = matrix[i][j];
                matrix[i][j] = matrix[ti][tj];
                matrix[ti][tj] = tt;
              }
            }
          }
        }
    }
    if(noresult){
      cout << "-1" << endl;
    }
  }

  return 0;
}
