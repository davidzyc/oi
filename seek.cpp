#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int MAXN = 105;

int n, m;
int fa[MAXN] = {0};
int nodev[MAXN];
int dp[MAXN][MAXN] = {0};
vector<int> to[MAXN];

void dfs(int x){
    dp[x][1] = nodev[x];
    for(int i=0; i<to[x].size(); i++){
        int y = to[x][i];
        if(fa[x] == y) continue;
        fa[y] = x;
        dfs(y);
        for(int j=m-1; j>0; j--){
            for(int k=1; k<j; k++){
                dp[x][j+1] = max(dp[x][j+1], dp[x][k]+dp[y][j-k]);
            }
        }
    }
    for(int j=m-1; j>0; j--){
        dp[x][j+1] = dp[x][j] + nodev[x];
    }
    for(int i=0; i<to[x].size(); i++){
        int y = to[x][i];
        if(fa[x] == y) continue;
        for(int j=1; j<=m; j++){
            dp[x][j] = max(dp[x][j], dp[y][j]);
        }
    }
    return;
}

int main(){
    int tf, tt;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%d", &nodev[i]);
    }
    for(int i=1; i<n; i++){
        scanf("%d%d", &tf, &tt);
        to[tf].push_back(tt);
        to[tt].push_back(tf);
    }
    dfs(1);
    int gans = 0;
    /**
    for(int i=1; i<=n;i++){
            cout << i << "-> ";
        for(int j=1; j<=m; j++){
            cout << dp[i][j] << " ";
        }
    cout << endl;
    }
    **/
    for(int i=1; i<=m; i++){
        gans = max(gans, dp[1][i]);
    }
    printf("%d", gans);

    return 0;
}
