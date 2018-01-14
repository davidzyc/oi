#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int n, maxw;
int w[105], k[105];
int dp[105][5005];

int main(){

    memset(dp, 0, sizeof(dp));
    cin >> maxw >> n;
    for(int i=0; i<n; i++){
        cin >> w[i] >> k[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=maxw; j++){
            if(j-w[i] >= 0){
                dp[i+1][j] = dp[i][j] > dp[i+1][j-w[i]]+k[i] ? dp[i][j] : dp[i+1][j-w[i]]+k[i];
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    cout << dp[n][maxw];
    return 0;
}