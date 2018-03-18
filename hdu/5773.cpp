#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 1e5+7;
const int INF = 0x3f3f3f3f;
int gn, n;
int seq[MAXN];
int q[MAXN];

int main(){
  freopen("5773.txt", "r", stdin);
  scanf("%d", &gn);
  for(int tgn=0; tgn<gn; tgn++){
    int gzerocnt = 0, tn = 0, tseq, tzerocnt = 0;
    int gcnt = -1;
    memset(q, 0x3f, sizeof(q));
    memset(seq, 0, sizeof(seq));
    scanf("%d", &n);
    for(int i=0; i<n; i++){
      scanf("%d", &tseq);
      if(tseq){
        seq[tn] = tseq - gzerocnt;
        ++tn;
      }else{
        gzerocnt++;
      }
    }
    for(int i=0; i<tn; i++){
      int pos = lower_bound(q, q+MAXN, seq[i]) - q;
      q[pos] = seq[i];
      gcnt = max(gcnt, pos);
      // for(int i=0; i<=gcnt; i++){
      //   cout << q[i] << " ";
      // }
      // cout << endl;
    }
    printf("Case #%d: %d\n", tgn+1, gcnt+1+gzerocnt);
  }

  return 0;
}
