#include<cstdio>
#include<iostream>
#define MAXN 101
#define MAXM 1001
using namespace std;

int n, m;
int p[MAXN];
int dpfa[MAXN*MAXM] = {0};
int dp[MAXN*MAXM] = {0};
int v[MAXN] = {0};

int main(){
    cin >> m >> n;
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=m; j>=p[i]; j--){
            // if(dp[j] && dp[j-p[i]]){
            //     cout << -1 << endl;
            //     return 0;
            // }
            // if(dp[j]) continue;
            if(dp[j-p[i]] && !dpfa[j]){
                dpfa[j] = i;
            }
            dp[j] += dp[j-p[i]];
        }
    }
    if(!dp[m]){
        cout << 0 << endl;
        return 0;
    }
    if(dp[m] > 1){
        cout << -1 << endl;
        return 0;
    }
    int cur = m;
    while(cur){
        v[dpfa[cur]] = 1;
        cur = cur - p[dpfa[cur]];
    }
    for(int i=1; i<=n; i++){
        if(!v[i]) cout << i << " ";
    }

    return 0;
}