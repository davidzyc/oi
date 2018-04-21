#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 13;
const int INF = 0x3f3f3f3f;
const int MAXDP = 1 << 12;

int n;
int mat[MAXN][MAXN];
int dp[MAXDP][MAXN];
int gans = INF;

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    for(int st=0; st<n; st++){
        memset(dp, 0x3f, sizeof(dp));
        dp[0][st] = 0;
        for(int i=1; i<(1<<n); i++){
            for(int v=0; v<n; v++){
                for(int u=0; u<n; u++){
                    if(!(i&(1 << u)) || u == v) continue;
                    dp[i][u] = min(dp[i][u], dp[(i&(~(1 << u)))][v] + mat[u][v]);
                }
            }
        }
        gans = min(gans, dp[(1<<n)-1][st]);
    }
    printf("%d", gans);

    return 0;
}
