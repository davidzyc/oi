#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

int n, m;
int vis[1001] = {0};
queue<int> q;

int main(){
  cin >> m >> n;
  int t, cnt = 0, ans = 0;
  for(int i=0; i<n; i++){
    cin >> t;
    if(!vis[t]){
      if(cnt >= m){
        vis[ q.front() ] = 0;
        q.pop();
        cnt--;
      }
      ans++;
      cnt++;
      q.push(t);
      vis[t] = 1;
    }
  }
  cout << ans;

  return 0;
}
