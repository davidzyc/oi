#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 1e5+7;

typedef long long ll;

int n, bn, m;
ll a[MAXN], b[MAXN], cnt[MAXN];

int main(){
  int tset;
  scanf("%d", &tset);
  while(tset--){
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(cnt, 0, sizeof(cnt));
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
      scanf("%lld", &a[i]);
      b[i] = a[i];
    }
    sort(b, b+n);
    bn = unique(b, b+n) - b;
    for(int i=0; i<n; i++){
      int pos = lower_bound(b, b+bn, a[i]) - b;
      // cout << a[i] << " " << pos << endl;
      cnt[pos]++;
    }
    ll t;
    for(int i=0; i<m; i++){
      scanf("%lld", &t);
      int pos = lower_bound(b, b+bn, t) - b;
      cnt[pos]--;
    }
    int num = 0, gcnt = 0;
    bool flag = false;
    // cout<<bn;
    for(int i=0; i<bn; i++){
      if(b[i] != 1 && cnt[i]) {
        // cout << b[i] << " " << cnt[i] << endl;
        num = b[i];
        gcnt += cnt[i];
      }
    }
    if(gcnt != 1){
      printf("NO\n");
    }else{
      for(int i=2; i*i <= num; i++){
        if(num % i == 0) flag = true;
      }
      if(!flag){
        printf("YES\n");
      }else{
        printf("NO\n");
      }
    }

  }
  return 0;
}
