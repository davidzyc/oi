#include<cstdio>
#include<iostream>
#define MAXN 16
#define INF 2100000000
using namespace std;

int n;
int cm[MAXN][MAXN];
int dp[1 << MAXN][MAXN] = {0};

int main(){

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> cm[i][j];
        }
    }
    int ans = INF;
    for(int stage=0; stage<n; stage++){
    for(int i=0; i< (1 << n); i++){
        for(int j=0; j<n; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][stage] = 0;
    for(int i=1; i< (1 << n); i++){
        for(int v=0; v<n; v++){
            for(int u=0; u<n; u++){
                if((i >> u)&1 == 0) continue;
                if(u == v) continue;
                dp[i][v] = min(dp[i][v], dp[i&(~(1 << u))][u]+cm[u][v]);
            }
        }
    }
    // for(int i=0; i<n; i++){
        ans = min(ans, dp[(1 << n)-1][stage]);
    // }
    }
    cout << ans;

    return 0;
}