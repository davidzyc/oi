#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    int n, m;
    int a[105];
    int dp[105][105];
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<=m; j++){
            if(j == 0){
                dp[i][j] = 1;
            }else{
                for(int k=0; k<=min(j, a[i]); k++){
                    dp[i+1][j] += dp[i][j-k];
                }
            }
        }
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << dp[n][m];

    return 0;
}