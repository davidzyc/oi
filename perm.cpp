#include<cstdio>
#include<iostream>
#include<ctime>
using namespace std;

int n, a[105];

int dfs(int k){
  if(k==n){
    for(int j=0; j<n; j++){
      cout << a[j]+1 << " ";
    }
    cout << endl;
  }
  int t;
  for(int i=k; i<n; i++){
    // cout << k << " " << i << endl;
    t = a[i];
    a[i] = a[k];
    a[k] = t;
    dfs(k+1);
    t = a[i];
    a[i] = a[k];
    a[k] = t;
  }
}

int main(){

  int vis[105] = {0}, t, cnt = 0;
  cin >> n;
  for(int i=0; i<n; i++){
    a[i] = i;
  }
  // for(int i=0; i<n; i++){
  //
  // }
  dfs(0);
  // srand((unsigned) time(NULL));
  // while(cnt<n){
  //   t = rand() % n;
  //   if(!vis[t]){
  //     cout << t+1 << " ";
  //     vis[t] ++ ;
  //     cnt++;
  //   }
  // }

  return 0;
}
