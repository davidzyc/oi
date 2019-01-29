#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 507;

int n;
int l[MAXN], r[MAXN], id[MAXN];
int dp[MAXN], last[MAXN];

bool cmp(int a, int b){
  return (r[a] - l[a]) < (r[b] - l[b]);
}

bool chk(int a, int b){
  return l[b] < l[a] && r[b] > r[a];
}

void dfs(int a){
  if(!last[a]) return;
  dfs(last[a]);
  printf("%d ", last[a]);
}

int main(){
  int gmax = 0, gid;
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d%d", &l[i], &r[i]);
    id[i] = i;
  }
  sort(id+1, id+n+1, cmp);
  for(int ii=1; ii<=n; ii++){
    int i = id[ii];
    // cout << l[i] << " " <<r[i] << endl;
    dp[i] = 1;
    for(int jj=1; jj<ii; jj++){
      int j = id[jj];
      if(chk(j, i)){
        if(dp[j] + 1 > dp[i]){
          dp[i] = dp[j] + 1;
          last[i] = j;
        }
      }
    }
    if(dp[i] > gmax){
      gmax = dp[i];
      gid = i;
    }
  }
  // 
  // for(int i=1; i<=n; i++){
  //   cout << dp[id[i]] << " ";
  // }
  // cout << endl;
  //
  //
  //   for(int i=1; i<=n; i++){
  //     cout << last[id[i]] << " ";
  //   }
  //   cout << endl;

  printf("%d\n", gmax);
  dfs(gid);
  printf("%d", gid);

  return 0;
}
