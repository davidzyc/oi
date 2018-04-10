#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 55;
int n, st;
int p[MAXN], pos[MAXN];
int dpre[MAXN] = {0};
int dp[MAXN][MAXN][2];

int get_power(int l, int r){
    return dpre[l - 1] + dpre[n] - dpre[r];
}

int main(){
    memset(dp, 0x3f, sizeof(dp));
    scanf("%d%d", &n, &st);
    for(int i=1; i<=n; i++){
        scanf("%d%d", &pos[i], &p[i]);
    }
    for(int i=1; i<=n; i++){
        dpre[i] = dpre[i-1] + p[i];
        // cout << dpre[i] << " ";
    }
    dp[st][st][0] = dp[st][st][1] = 0;
    for(int len = 1; len<n; len++){
        for(int l = 1; l+len <= n; l++){
            int r = l + len;
            dp[l][r][0] = min(dp[l+1][r][0]+get_power(l+1, r)*(pos[l+1]-pos[l]), dp[l+1][r][1]+get_power(l+1, r)*(pos[r]-pos[l]));
            dp[l][r][1] = min(dp[l][r-1][1]+get_power(l, r-1)*(pos[r]-pos[r-1]), dp[l][r-1][0]+get_power(l, r-1)*(pos[r]-pos[l]));
            // cout << l << " " << r << " -> " << dp[l][r][0] << " " << dp[l][r][1] << endl;
        }
    }
    printf("%d", min(dp[1][n][0], dp[1][n][1]));

    return 0;
}
