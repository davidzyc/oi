#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int MAXN = 405;

int n;
vector<int> nth[MAXN];
int w[MAXN], p[MAXN], l[MAXN];
int dp[MAXN][MAXN];
int dps[MAXN][MAXN] = {0};
int nl = 0;
vector<int> ans;
int anscnt = 0;

void rec_print(int x, int h){
    ans.push_back(x+1);
    anscnt++;
    if(!dps[x][h]) return;
    rec_print(dps[x][h], h-w[dps[x][h]]);
    return;
}

int main(){
    int t;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d%d%d", &t, &w[i], &p[i], &l[i]);
        nth[t].push_back(i);
        nl = max(nl, t);
    }
    for(int i=nl-1; i>=0; i--){
        for(int j=0; j<nth[i].size(); j++){
            int x = nth[i][j];
            // dp[x][0] = l[x];
            for(int k=0; k<nth[i+1].size(); k++){
                int y = nth[i+1][k];
                for(int h=w[y]; h<=p[x]; h++){
                    if(dp[x][h] < dp[y][h-w[y]]+l[y]){
                        dp[x][h] = dp[y][h-w[y]]+l[y];
                        dps[x][h] = y;
                    }
                }
            }
        }
    }
    int gans = 0, gs;
    for(int i=0; i<=p[0]; i++){
        if(gans < dp[0][i]){
            gans = dp[0][i];
            gs = i;
        }
    }
    rec_print(0, gs);
    printf("%d %d\n", anscnt, gans+l[0]);
    for(int i=0; i<ans.size(); i++){
        printf("%d ", ans[i]);
    }
    return 0;
}
