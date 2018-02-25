#include<cstdio>
#include<iostream>
#define MAXN 101
#define INF 2100000000
using namespace std;

int n, m;
int mat[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];
int ans = -1;

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];
            dp[0][i][j] = mat[i][j];
            if(mat[i][j]) ans = 0;
        }
    }
    for(int k=1; k<min(n, m); k++){
        for(int i=0; i<n-k; i++){
            for(int j=0; j<m-k; j++){
                dp[k][i][j] = INF;
                dp[k][i][j] = min(dp[k][i][j], dp[k-1][i][j]);
                dp[k][i][j] = min(dp[k][i][j], dp[k-1][i+1][j]);
                dp[k][i][j] = min(dp[k][i][j], dp[k-1][i][j+1]);
                dp[k][i][j] = min(dp[k][i][j], dp[k-1][i+1][j+1]);
                if(dp[k][i][j] == 1){
                    ans = k;
                }
            }
        }
    }
    cout << ans+1;

    return 0;
}