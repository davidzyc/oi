#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#define MAXR 505
#define NEGINF -2100000000
using namespace std;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
typedef pair<int, int> pii;
int matrix[MAXR][MAXR];
int dp[MAXR][MAXR] = {0};
priority_queue<pii> pq;

int main(){
  int maxlen = 0;
  int r, c;
  cin >> r >> c;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cin >> matrix[i][j];
      pq.push(make_pair(matrix[i][j], i*c+j));
      dp[i][j] = NEGINF;
    }
  }
  pii p;
  int h, tr, tc, tx, ty;
  while(!pq.empty()){
    p = pq.top();
    pq.pop();
    h = p.first;
    tc = p.second % c;
    tr = p.second / c;
    dp[tr][tc] = 1;
    for(int i=0; i<4; i++){
      tx = tc + dx[i];
      ty = tr + dy[i];
      if(tx>=0 && tx < c && ty >=0 && ty < r && h < matrix[ty][tx]){
        dp[tr][tc] = max(dp[tr][tc], dp[ty][tx]+1);
      }
    }
    maxlen = max(maxlen, dp[tr][tc]);
  }
  cout << maxlen;

  return 0;
}
