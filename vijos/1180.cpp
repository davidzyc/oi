#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 301
#define MAXM 301
using namespace std;

int n, m;
int pa[MAXN] = {0}, l[MAXN] = {0}, r[MAXN] = {0}, c[MAXN] = {0};
int dp[MAXN][MAXM] = {0};

void dfs(int i){
    if(i == 0) return;
    // cout << i << " ";
    dfs(r[i]);
    dfs(l[i]);
    int tm = m;
    if(i == n+1) tm++;
    for(int j=1; j<=tm; j++){
        dp[i][j] = dp[r[i]][j];
    }
    for(int j=1; j<=tm; j++){
        for(int k=0; k<j; k++){
            dp[i][j] = max(dp[i][j], dp[l[i]][k] + dp[r[i]][j-k-1] + c[i]);
        }
    }
    // cout << i << " : ";
    // for(int j=1; j<=tm; j++){
    //     cout << dp[i][j] << " ";
    // }
    // cout << endl;
    return;
}

int main(){
    cin >> n >> m;
    int tpa, tc, t;
    for(int i=1; i<=n; i++){
        cin >> tpa >> c[i];
        if(tpa == 0) tpa = n+1;
        t = l[tpa];
        l[tpa] = i;
        r[i] = t;
    }

    dfs(n+1);

    cout << dp[n+1][m+1];

    return 0;
}