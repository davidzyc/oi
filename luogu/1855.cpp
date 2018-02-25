#include<cstdio>
#include<iostream>
#define MAXN 101
#define MAXM 201
using namespace std;

int n, m, t;
int mi[MAXN], ti[MAXN];
int dp[MAXM][MAXM] = {0};

int main(){

    cin >> n >> m >> t;
    for(int i=0; i<n; i++){
        cin >> mi[i] >> ti[i];
    }
    for(int k=0; k<n; k++){
        for(int i=m; i>=mi[k]; i--){
            for(int j=t; j>=ti[k]; j--){
                dp[i][j] = max(dp[i][j], dp[i-mi[k]][j-ti[k]]+1);
            }
        }
    }
    cout << dp[m][t];

    return 0;
}