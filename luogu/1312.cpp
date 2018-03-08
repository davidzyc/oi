#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<int, int> pii;
const int MAXM = 1000000;
// const int DX[2] = {-1, 1};
const int DX[1] = {1};
const int DDX[4] = {1, 0, -1, 0}, DDY[4] = {0, 1, 0, -1};
int maxstep, qsize = 0;
int mat[MAXM][5][7] = {0}, steps[MAXM] = {0}, last[MAXM] = {0};
int mvi[MAXM], mvj[MAXM], mvd[MAXM];
int v[5][7], vc[5][7];

void print_mat(int mid){
  cout << endl;
  cout << "QSIZE: " << mid << endl;
  cout << "STEPS: " << steps[mid] << endl;
  cout << "Changed From: " << last[mid] << endl;
  cout << mvi[mid] << " " << mvj[mid] << " " << mvd[mid] << endl;
  for(int i=0; i<5; i++){
    for(int j=0; j<7; j++){
      cout << mat[mid][i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  cout << endl;
}

void print_route(int mid){
  if(mid == 0) return;
  print_route(last[mid]);
  // print_mat(mid);
  cout << mvi[mid] << " " << mvj[mid] << " " << mvd[mid] << endl;
}

void cp_matrix(int from, int to){
  for(int i=0; i<5; i++){
    for(int j=0; j<7; j++){
      mat[to][i][j] = mat[from][i][j];
    }
  }
}

bool check_empty(int mid){
  int cnt = 0;
  for(int i=0; i<5; i++){
    for(int j=0; j<7; j++){
      cnt += mat[mid][i][j];
    }
  }
  return cnt == 0;
}

void natural_fall(int mid){
  for(int i=0; i<5; i++){
    int maxh = 0;
    for(int j=0; j<7; j++){
      if(mat[mid][i][j]){
        mat[mid][i][maxh] = mat[mid][i][j];
        if(maxh != j) mat[mid][i][j] = 0;
        ++maxh;
      }
    }
  }
}

void eliminate_block(int mid){
  bool flag = true;
  while(flag){
    flag = false;
    queue<pii> qc;
    int tcnt, tcolor;
    memset(v, 0, sizeof(v));
    memset(vc, 0, sizeof(vc));
    for(int i=0; i<5; i++){
      for(int j=0; j<7; j++){
        if(v[i][j] || !mat[mid][i][j]) continue;
        tcnt = 0;
        tcolor = mat[mid][i][j];
        v[i][j] = true;
        qc.push(make_pair(i, j));
        while(!qc.empty()){
          pii pcur = qc.front();
          qc.pop();
          int ti = pcur.first, tj = pcur.second;
          int toi, toj;
          tcnt++;
          for(int k=0; k<4; k++){
            toi = ti + DDY[k];
            toj = tj + DDX[k];
            if(toi >= 5 || toi < 0 || toj >= 7 || toj < 0 || v[toi][toj] || mat[mid][toi][toj] != tcolor) continue;
            v[toi][toj] = 1;
            qc.push(make_pair(toi, toj));
          }
        }
        if(tcnt < 3) continue;
        // cout << "Eliminated" << endl;
        vc[i][j] = true;
        qc.push(make_pair(i, j));
        while(!qc.empty()){
          pii pcur = qc.front();
          qc.pop();
          int ti = pcur.first, tj = pcur.second;
          mat[mid][ti][tj] = 0;
          int toi, toj;
          for(int k=0; k<4; k++){
            toi = ti + DDY[k];
            toj = tj + DDX[k];
            if(toi >= 5 || toi < 0 || toj >= 7 || toj < 0 || vc[toi][toj] || mat[mid][toi][toj] != tcolor) continue;
            vc[toi][toj] = 1;
            qc.push(make_pair(toi, toj));
          }
        }
        natural_fall(mid);
        flag = true;
      }
    }

  }
}

int main(){
  freopen("1312.txt", "r", stdin);
  freopen("1312_out.txt", "w", stdout);
  int t;
  cin >> maxstep;
  for(int i=0; i<5; i++){
    for(int j=0; ; j++){
      cin >> t;
      if(t == 0) break;
      mat[0][i][j] = t;
    }
  }
  queue<int> q;
  steps[0] = 0;
  ++qsize;
  q.push(0);
  while(!q.empty()){
    int temp;
    int cur = q.front();
    q.pop();
    eliminate_block(cur);
    if(check_empty(cur)){
      // cout << "Find" << endl;
      print_route(cur);
      return 0;
    }
    // print_mat(cur);
    if(steps[cur] == maxstep) continue;
    for(int i=0; i<5; i++){
      for(int j=0; j<7; j++){
        if(!mat[cur][i][j]) continue;
        for(int k=0; k<1; k++){
          if(i+DX[k] >= 0 && i+DX[k] < 5){
            cp_matrix(cur, qsize);
            mat[qsize][i][j] = mat[cur][i+DX[k]][j];
            mat[qsize][i+DX[k]][j] = mat[cur][i][j];
            mvi[qsize] = i;
            mvj[qsize] = j;
            mvd[qsize] = DX[k];
            steps[qsize] = steps[cur] + 1;
            last[qsize] = cur;
            q.push(qsize);
            ++qsize;
            // cout << "Changed!" << endl;
          }
        }
      }
    }
  }
  cout << -1;
  // natural_fall(0);
  // print_mat(0);
  return 0;
}
