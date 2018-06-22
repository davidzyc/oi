#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 5e4+7;
const int MAXLOG = 20;

int n, qn, l;
int twopow[MAXLOG];
int datmin[MAXN][MAXLOG];
int datmax[MAXN][MAXLOG];

int main(){
    while(scanf("%d%d", &n, &qn) == 2){
      memset(datmin, 0, sizeof(datmin));
      memset(datmax, 0, sizeof(datmax));
      for(int i=0; i<n; i++){
        scanf("%d", &datmin[i][0]);
        datmax[i][0] = datmin[i][0];
      }
      l = (int) (log(n) / log(2)) + 1;
      twopow[0] = 1;
      for(int i=1; i<MAXLOG; i++){
        twopow[i] = twopow[i-1] * 2;
        // cout << twopow[i] << " ";
      }
      for(int i=1; i<=l; i++){
        for(int j=0; j<n-twopow[i]+1; j++){
          datmin[j][i] = min(datmin[j][i-1], datmin[j+twopow[i-1]][i-1]);
          datmax[j][i] = max(datmax[j][i-1], datmax[j+twopow[i-1]][i-1]);
          //cout << datmax[j][i] << "|" << datmin[j][i] << " ";
        }
        //cout << endl;
      }
      int lb, ub, tl, ans;
      for(int ii=0; ii<qn; ii++){
        scanf("%d%d", &lb, &ub);
        tl = (int) (log(ub - lb + 1) / log(2));
        // cout << lb << " " << ub+1-twopow[tl] << " " << tl << " ";
        ans = max(datmax[lb-1][tl], datmax[ub-twopow[tl]][tl]) - min(datmin[lb-1][tl], datmin[ub-twopow[tl]][tl]);
        printf("%d\n", ans);
      }
    }
    return 0;
}
