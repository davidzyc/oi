#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 400;

int gn, n, yn;
int xlid[MAXN], xltype[MAXN];
int xlpos[MAXN], xls[MAXN], xle[MAXN];
int dy[MAXN];
int dat[MAXN*4];
int gans = 0.0;

bool cmp(int a, int b){
  return xlpos[a] < xlpos[b];
}

int seg_query(int nid, int l, int r){
  if(l < r){
    if(dat[nid]){
      return dy[r] - dy[l-1];
    }
    int ans = 0;
    int mid = (l+r) >> 1;
    ans += seg_query(nid*2, l, mid);
    ans += seg_query(nid*2+1, mid+1, r);
    return ans;
  }else if(l == r){
    if(dat[nid]){
      return dy[r] - dy[l-1];
    }
  }
  return 0;
}

void seg_update(int x, int y, int val, int nid, int l, int r){
  if(x <= l && y >= r){
    dat[nid] += val;
    return;
  }
  int mid = (l+r) >> 1;
  if(x <= mid){
    seg_update(x, y, val, nid*2, l, mid);
  }
  if(y > mid){
    seg_update(x, y, val, nid*2+1, mid+1, r);
  }
  return;
}

int main(){
  int tfx, tfy, ttx, tty;
  int tcase = 0;
  while(true){
    gans = 0.0;
    ++tcase;
    gn = 0, n=0, yn=0;
    memset(xlid, 0, sizeof(dat));
    memset(xltype, 0, sizeof(dat));
    memset(dat, 0, sizeof(dat));
    memset(dy, 0, sizeof(dy));
    scanf("%d", &n);
    if(!n) break;
    for(int i=0; i<n; i++){
      scanf("%d%d%d%d", &tfx, &tfy, &ttx, &tty);
      tfx += 10000;
      tfy += 10000;
      ttx += 10000;
      tty += 10000;
      xlid[gn] = gn;
      xlpos[gn] = tfx;
      xle[gn] = tty;
      xls[gn] = tfy;
      xltype[gn] = 1;
      dy[gn] = tty;
      ++gn;
      xlid[gn] = gn;
      xlpos[gn] = ttx;
      xle[gn] = tty;
      xls[gn] = tfy;
      xltype[gn] = -1;
      dy[gn] = tfy;
      ++gn;
    }
    sort(dy, dy+gn);
    yn = unique(dy, dy+gn) - dy;
    sort(xlid, xlid+gn, cmp);
    int lastx = xlpos[xlid[0]];
    int lastlen = 0;
    int lb, ub;
    // for(int i=0; i<yn; i++){
    //   cout << dy[i] << " ";
    // }
    for(int ti=0; ti<gn; ti++){
      int i = xlid[ti];
      if(xlpos[i] != lastx){
        // cout <<  seg_query(1, 1, yn) << "*" << (xlpos[i] - lastx) << endl;
        int curlen = seg_query(1, 1, yn);
        gans += (int)abs(curlen-lastlen);
        gans += 2 * (xlpos[i] - lastx);
        lastlen = curlen;
        lastx = xlpos[i];
      }
      lb = lower_bound(dy, dy+yn, xls[i]) - dy + 1;
      ub = lower_bound(dy, dy+yn, xle[i]) - dy;
      // cout << lb << " " << ub << " | ";
      seg_update(lb, ub, xltype[i], 1, 1, yn);
      // cout << xlpos[i] << " from " << xls[i] << " to " << xle[i] << " type " << xltype[i] << endl;
    }
    printf("%d\n", gans);
  }
  return 0;
}
