#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int s, n;
int a[100], m[100];
int dp[100][1005];

int main(){
    cin >> s >> n;
    for(int i=0; i<n; i++) cin >> a[i] >> m[i];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=s; j++){
            if(dp[i][j]>=0){
                dp[i+1][j] = m[i];
            }else if(j >= a[i] && dp[i+1][j-a[i]] >= 0){
                dp[i+1][j] = max(dp[i][j], dp[i+1][j-a[i]]-1);
            }
        }
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=s; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    if(dp[n][s] >= 0) cout << "yes";
    else cout << "no";
    return 0;
}