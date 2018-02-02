#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 100005
#define MAXM 100005
#define MAXLEN 11
using namespace std;

int main(){
  int n, m, td, ts, ans = 0;
  int sd[MAXN];
  char s[MAXN][MAXLEN];
  cin >> n >> m;
  for(int i=0; i<n; i++){
    // scanf("%d %s", &sd[i], &s[i]);
    cin >> sd[i] >> s[i];
    if(sd[i] == 0) sd[i] = -1;
  }
  for(int i=0; i<m; i++){
    // scanf("%d %d", &td, &ts);
    cin >> td >> ts;
    if(td == 0) td = -1;
    ans += n + (ts % n) * td * sd[ans] * (-1);
    ans %= n;
    // cout << ans << " " << s[ans] << endl;
  }
  cout << s[ans];

  return 0;
}
