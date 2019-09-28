#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 105;
const int MAXM = 10005;
const int MMOD = 1e9+7;

int n, w, h;
int dp[MAXN][MAXM];

int main(){

    scanf("%d%d%d", &n, &w, &h);
    n = min(n, w*h);
    for(int i=0; i<=h; i++){
        dp[1][n-i] = 1;
    }
    for(int i=2; i<=w; i++){
        for(int j=0; j<=h; j++) {
            for(int k=0; k<=n; k++){
                if(j + k <= n) {
                    dp[i][k] += dp[i-1][j + k]; 
                    dp[i][k] %= MMOD;
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=n; i++) {
        ans += dp[w][i];
        ans %= MMOD;
    }
    printf("%d", (ans - (n / w) - 1 + MMOD) % MMOD);

    return 0;
}