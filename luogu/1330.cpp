#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 1e4+7;
const int MAXM = 1e5+7;

int n, m;
vector<int> to[MAXN];
int color[MAXN];
queue<int> q;

int main(){
  // freopen("1330.txt", "r", stdin);
  int tf, tt;
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++){
    scanf("%d%d", &tf, &tt);
    to[tf].push_back(tt);
    to[tt].push_back(tf);
  }
  int colorcnt, totcnt;
  int gans = 0;
  for(int i=1; i<=n; i++){
    if(!color[i]){
      colorcnt = totcnt = 0;
      q.push(i);
      color[i] = 2;
      while(!q.empty()){
        int x = q.front();
        q.pop();
        // cout << x << " " << color[x] << endl;
        if(color[x] == 2){
          colorcnt++;
        }
        totcnt ++;
        for(int j=0; j<to[x].size(); j++){
          int y = to[x][j];
          if(!color[y]){
            color[y] = color[x] ^ 1;
            q.push(y);
          }else if(color[y] == color[x]){
            printf("Impossible");
            return 0;
          }
        }
      }
      // cout << colorcnt << endl << totcnt << endl;
      gans += min(colorcnt, totcnt - colorcnt);
    }
  }
  printf("%d", gans);

  return 0;
}
