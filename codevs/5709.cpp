#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int n, maxw;
int w[1000], k[1000], dp[1005][5005];

int main(){
    memset(dp, 0, sizeof(dp));
    cin >> maxw >> n;
    for(int i=0; i<n; i++){
        cin >> w[i] >> k[i];
    }
        for(int j=0; j<=maxw; j++){
    for(int i=0; i<n; i++){
            if(j - w[i] >= 0){
                dp[i+1][j] = dp[i][j] < dp[i][j-w[i]] + k[i] ? dp[i][j-w[i]] + k[i] : dp[i][j];
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    cout << dp[n][maxw];

    return 0;
}