#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define MAXANS 20

int n, a[1005], tot = 0;
int dp[105][MAXANS+5];

int main(){
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<n; i++) cin >> a[i];
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=MAXANS; j++){
            // if(dp[i][j]){
                dp[i+1][j]+=dp[i][j];
            // }
            // if(dp[i][j-a[i]]){
                dp[i+1][j]+=dp[i][j-a[i]];
            // }
            if(i == n-1 && j % 2 == 0 && dp[i+1][j] >=1  && dp[i+1][j/2] >= 2){
                tot = j/2;
            }
        }
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=MAXANS; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    if(tot > 0){
        cout << tot;
    }else{
        cout << "Impossible";
    }

    return 0;
}