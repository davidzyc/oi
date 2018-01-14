// Longest Common Sequence
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

char s[1005], t[1005];
int dp[1005][1005];
int n, m;

int solve(int a, int b){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i] == t[j] && ((i-1 >= 0 && j-1 >= 0 && s[i-1] == t[j-1]) || (i+1 < n && j+1 < n && s[i+1] == t[j+1])) ){
                // cout << s[i] << " " << t[j] <<endl;
                dp[i+1][j+1] = dp[i][j]+1;
            }else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
}

int main(){
    memset(dp, 0, sizeof(dp));
    cin >> n >> m >> s >> t;

    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n][m];

    return 0;
}