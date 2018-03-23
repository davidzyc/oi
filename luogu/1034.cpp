#include<cstdio>
#include<iostream>
using namespace std;

const int MAXN = 55;
const int INF = 0x3f3f3f3f;

int pn, bn;
int px[MAXN], py[MAXN];
int minarea = INF;
int ax[MAXN], ay[MAXN], bx[MAXN], by[MAXN];

bool is_touched(int a, int b){
  if(ax[b] <= bx[a] && bx[b] >= ax[a] && ay[b] <= by[a] && by[b] >= ay[a]) return true;
  // if(ay[a] <= ay[b] && by[a] >= by[b] && ax[b] <= bx[a] && bx[b] >= ax[a]) return true;
  return false;
}

void dfs(int pcnt, int bcnt, int area){
  if(bcnt > bn){
    return;
  }
  for(int i=0; i<bcnt; i++){
    for(int j=0; j<bcnt; j++){
      if(i == j) continue;
      if(is_touched(i, j) || is_touched(j, i)){
        // cout << endl << i << " " << j << endl;
        // cout << ax[i] << " " << ay[i] << " | " << bx[i] << " " << by[i] << endl;
        // cout << ax[j] << " " << ay[j] << " | " << bx[j] << " " << by[j] << endl;
        return;
      }
    }
  }
  if(pcnt == pn){
    // cout << endl << pcnt << " " << bcnt << " " << area << endl;
    // for(int i=0; i<bcnt; i++){
    //   cout << ax[i] << " " << ay[i] << " | " << bx[i] << " " << by[i] << endl;
    // }
    minarea = min(area, minarea);
    return;
  }
  if(area >= minarea){
    return;
  }
  int i = pcnt;
  // new block
    ax[bcnt] = bx[bcnt] = px[i];
    ay[bcnt] = by[bcnt] = py[i];
    dfs(pcnt+1, bcnt+1, area);
  // cur block
  int tax, tbx, tay, tby;
    for(int j=0; j<bcnt; j++){
      tax = ax[j];
      tbx = bx[j];
      tay = ay[j];
      tby = by[j];
      ax[j] = min(ax[j], px[i]);
      bx[j] = max(bx[j], px[i]);
      ay[j] = min(ay[j], py[i]);
      by[j] = max(by[j], py[i]);
      dfs(pcnt+1, bcnt, area - (tbx-tax)*(tby-tay) + (bx[j]-ax[j])*(by[j]-ay[j]));
      ax[j] = tax;
      bx[j] = tbx;
      ay[j] = tay;
      by[j] = tby;
    }
  return;
}

int main(){
  // freopen("1034.txt", "r", stdin);
  scanf("%d%d", &pn, &bn);
  for(int i=0; i<pn; i++){
    scanf("%d%d", &px[i], &py[i]);
  }
  dfs(0, 0, 0);
  printf("%d", minarea);
  return 0;
}
