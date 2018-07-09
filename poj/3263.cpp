#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

const int MAXN = 1e4+7;

int n, in, h, r, t;
int hdiff[MAXN] = {0};
map<int, int> mp[MAXN];

int main(){
  int tl, tr;
  scanf("%d%d%d%d", &n, &in, &h, &r);
  for(int i=0; i<r; i++){
    scanf("%d%d", &tl, &tr);
    // if(tl == tr) continue;
    if(tl > tr) swap(tl, tr);
    if(mp[tl][tr]) continue;
    mp[tl][tr] = 1;
    hdiff[tl+1]--;
    hdiff[tr]++;
  }

  for(int i=1; i<=n; i++){
    hdiff[i] += hdiff[i-1];
  }
  t = hdiff[in];
  // t = 0;
  for(int i=1; i<=n; i++){
    hdiff[i] += h - t;
  }

  for(int i=1; i<=n; i++){
    printf("%d\n", hdiff[i]);
  }

  return 0;
}
