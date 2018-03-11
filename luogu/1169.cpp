#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;

const int MAXN = 2001;

typedef pair<int, int> pii;
int n, m;
int matrixans = 0, squareans = 0;
int matrix[MAXN][MAXN] = {0};
int dpx[MAXN][MAXN][2] = {0}, dpy[MAXN][MAXN][2] = {0};
int dpsquare[MAXN][MAXN] = {0};

int main(){
  freopen("1169.txt", "r", stdin);
  memset(matrix, 0x3f, sizeof(matrix));
  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      scanf("%d", &matrix[i][j]);
      if((i+j%2)%2){
        matrix[i][j] ^= 1;
      }
    }
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(matrix[i][j] == matrix[i][j-1] && matrix[i][j] == matrix[i-1][j] && matrix[i][j] == matrix[i-1][j-1]){
        dpsquare[i][j] = min(min(dpsquare[i-1][j], dpsquare[i][j-1]), dpsquare[i-1][j-1])+1;
      }else{
        dpsquare[i][j] = 1;
      }
      squareans = max(squareans, dpsquare[i][j]);
    }
  }
  stack<pii> q;
  for(int i=1; i<=n; i++){
    for(int k=0; k<2; k++){
      for(int j=1; j<=m+1; j++){
        if(j == m+1 || matrix[i][j] != k){
          dpy[i][j][k] = 0;
        }else if(matrix[i][j] == matrix[i-1][j]){
          dpy[i][j][k] = dpy[i-1][j][k]+1;
        }else{
          dpy[i][j][k] = 1;
        }
        // cout << dpy[i][j][k] << " ";
        int lastj = j;
        while(!q.empty() && dpy[i][j][k] < q.top().first){
          pii tfront = q.top();
          q.pop();
          // cout << endl << tfront.second << " " << tfront.first << endl;
          lastj = min(lastj, tfront.second);
          matrixans = max(matrixans, tfront.first * (j - tfront.second));
        }
        if((q.empty() || dpy[i][j][k] > q.top().first) && dpy[i][j][k] != 0) q.push(make_pair(dpy[i][j][k], lastj));
      }
      // cout << endl;
    }
    // cout << endl;
  }
  printf("%d\n%d", squareans*squareans, matrixans);

  return 0;
}
