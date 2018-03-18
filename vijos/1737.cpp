#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXK = 51;
const int MAXN = 2e5+7;
int n, k, p;
int nk[MAXN], coffee[MAXN];
vector<int> nkv[MAXK];
int nkcnt[MAXK] = {0};
long long gcnt = 0;

int main(){
  // freopen("1737.txt", "r", stdin);
  scanf("%d %d %d", &n, &k, &p);
  int t;
  for(int i=0; i<n; i++){
    scanf("%d %d", &nk[i], &t);
    coffee[i] = t > p ? 0 : 1;
  }
  int max_coffee = 0;
  for(int i=0; i<n; i++){
    if(coffee[i]) max_coffee = i;
    long long curcnt = upper_bound(nkv[nk[i]].begin(), nkv[nk[i]].end(), max_coffee) - nkv[nk[i]].begin();
    // cout << i << " " << curcnt << endl;
    gcnt += curcnt;
    nkv[nk[i]].push_back(i);
  }
  printf("%lld", gcnt);
  return 0;
}
