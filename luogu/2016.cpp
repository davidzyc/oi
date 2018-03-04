#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 1501
#define INF 2100000000
using namespace std;

int n, c[MAXN];
int from[MAXN], to[MAXN], first[MAXN], nxt[MAXN];
int indeg[MAXN] = {0};
int dp[MAXN][3] = {0};

// 0->son, 1->self, 2->pa

void dfs(int i){
    int e = first[i];
    int sonmin, selfmin, pamin, diffmin;
    diffmin = INF;
    while(e){
        dfs(to[e]);
        sonmin = selfmin = pamin = INF;
        selfmin = min(selfmin, dp[to[e]][0]);
        selfmin = min(selfmin, dp[to[e]][1]);
        selfmin = min(selfmin, dp[to[e]][2]);
        dp[i][1] += selfmin;
        sonmin = min(sonmin, dp[to[e]][0]);
        sonmin = min(sonmin, dp[to[e]][1]);
        diffmin = min(diffmin, dp[to[e]][1]-sonmin);
        dp[i][0] += sonmin;
        dp[i][2] += sonmin;
        e = nxt[e];
    }
    dp[i][0] += diffmin;
    dp[i][1] += c[i];
    // cout << endl << i << " : " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    return;
}

int main(){
    int ti, tn, tto, mcnt = 0, t;
    cin >> n;
    fill(c, c+MAXN, 1);
    for(int i=0; i<n; i++){
        cin >> ti;
        // cin >> c[ti];
        cin >> tn;
        for(int j=0; j<tn; j++){
            mcnt ++;
            cin >> tto;
            from[mcnt] = ti;
            to[mcnt] = tto;
            t = first[ti];
            first[ti] = mcnt;
            nxt[mcnt] = t;
            indeg[tto]++;
        }
    }
    int gans = 0;
    for(int i=1; i<=n; i++){
        if(!indeg[i]){
            memset(dp, 0, sizeof(dp));
            dfs(i);
            gans += min(dp[i][0], dp[i][1]);
        }
    }
    cout << gans << endl;

    return 0;
}
