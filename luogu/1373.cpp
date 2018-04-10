#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 805;
const int MAXMOD = 16;
const int GMOD = 1000000007;

int n, m, k;
int mat[MAXN][MAXN] = {0};
int dp[MAXN][MAXN][MAXMOD][2] = {0};
int gans = 0;

int main(){
    // freopen("1373.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    ++k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &mat[i][j]);
            mat[i][j] %= k;
            dp[i][j][mat[i][j]][1] = 1;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int h=0; h<k; h++){
                dp[i][j][h][1] += dp[i-1][j][(h+k-mat[i][j])%k][0];
                dp[i][j][h][1] += dp[i][j-1][(h+k-mat[i][j])%k][0];
                dp[i][j][h][1] %= GMOD;
                dp[i][j][h][0] += dp[i-1][j][(h+mat[i][j])%k][1];
                dp[i][j][h][0] += dp[i][j-1][(h+mat[i][j])%k][1];
                dp[i][j][h][0] %= GMOD;
            }
            gans += dp[i][j][0][0];
            gans %= GMOD;
        }
    }
    printf("%d", gans);

    return 0;
}
