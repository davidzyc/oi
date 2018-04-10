#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

#define CUR 2
#define SON 1
#define GSON 0
#define FA 3
#define GFA 4

const int INF = 10000;
const int MAXN = 1005;

int n, t;
vector<int> to[MAXN];
int dp[MAXN][6] = {0};
int dfncnt = 0;
int dfn[MAXN] = {0};
int fa[MAXN] = {0};

int minthree(int a, int b, int c){
    return min(a, min(b, c));
}

int minfour(int a, int b, int c, int d){
    return min(a, min(b, min(c, d)));
}

int minfive(int a, int b, int c, int d, int e){
    return min(a, min(b, min(c, min(d, e))));
}

void dfs(int x){
    // cout << x << " ";
    int tadd = INF;
    int sonsize = to[x].size();
    for(int i=0; i<sonsize; i++){
        int y = to[x][i];
        if(fa[x] == y) continue;
        fa[y] = x;
        dfs(y);
        dp[x][CUR] += minfive(dp[y][GSON], dp[y][SON], dp[y][CUR], dp[y][FA], dp[y][GFA]);
        dp[x][GSON] += dp[y][SON];
        dp[x][FA] += minfour(dp[y][GFA], dp[y][CUR], dp[y][SON], dp[y][GSON]);
        dp[x][GFA] += minthree(dp[y][SON], dp[y][GSON], dp[y][CUR]);
        dp[x][SON] += minfour(dp[y][GSON], dp[y][SON], dp[y][CUR], dp[y][GFA]);
        tadd = min(tadd, dp[y][CUR] - minfour(dp[y][GSON], dp[y][SON], dp[y][CUR], dp[y][GFA]));
    }
    if(x != 1 && sonsize == 1){
        dp[x][SON] = dp[x][GSON] = INF;
    }
    dp[x][SON] += tadd;
    dp[x][CUR]++;
    // cout << x << ": SON " << dp[x][SON] << " | GrandSON " << dp[x][GSON] << " | CUR " << dp[x][CUR] << " | FA " << dp[x][FA] << " | GrandFA " << dp[x][GFA] << endl;
    return;
}

int main(){

    // freopen("2279.txt", "r", stdin);
    scanf("%d", &n);
    for(int i=2; i<=n; i++){
        scanf("%d", &t);
        to[i].push_back(t);
        to[t].push_back(i);
    }
    dfs(1);
    printf("%d", minthree(dp[1][SON], dp[1][GSON], dp[1][CUR]));

    return 0;
}
