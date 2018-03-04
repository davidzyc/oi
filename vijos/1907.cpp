#include<cstdio>
#include<iostream>
#include<cmath>
#define MAXM 1001
#define MAXN 10001
#define INF 2000000000
using namespace std;

int n, m, k;
bool hastube[MAXN] = {false};
int tlow[MAXN] = {0}, thigh[MAXN] = {0};
int rise[MAXN] = {0}, down[MAXN] = {0};
int dp[2][MAXM] = {0};

int main(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        cin >> rise[i] >> down[i];
        thigh[i] = m;
        tlow[i] = 1;
    }
    int t;
    for(int i=0; i<k; i++){
        cin >> t;
        hastube[t] = true;
        cin >> tlow[t] >> thigh[t];
        tlow[t] ++;
        thigh[t] --;
    }
    int last, cur, tl, th, tmp, gans = INF;
    for(int i=1; i<n; i++){
        last = i % 2;
        cur  = (i+1) % 2;
        for(int j=0; j<=m; j++){
            dp[cur][j] = INF;
        }
        tmp = INF;
        for(int j=tlow[i]; j<=thigh[i]; j++){
            if(j == m){
                for(int tloc = tl; tloc < m; tloc++){
                    dp[cur][j] = min(dp[cur][j], dp[last][tloc]+(int)ceil((m-tloc)*1.0/rise[i-1]));
                }
                dp[cur][j] = min(dp[cur][j], dp[last][j]+1);
                tmp = min(tmp, dp[cur][j]);
                // cout << j << " " << dp[cur][j] << endl;
                continue;
            }
            if(thigh[i-1]-j>=down[i-1]){
                dp[cur][j] = min(dp[cur][j], dp[last][j+down[i-1]]);
            }
            for(int tloc=j-rise[i-1]; tloc>=max(1, tlow[i-1]); tloc -= rise[i-1]){
                dp[cur][j] = min(dp[cur][j], dp[last][tloc]+(j-tloc)/rise[i-1]);
            }
            tmp = min(tmp, dp[cur][j]);
            if(i == n-1){
                gans = min(gans, dp[cur][j]+(j>down[i]?0:1));
            }
            // cout << j << " " << dp[cur][j] << endl;
        }
        if(tmp >= INF){
            cout << 0 << endl;
            int tubecnt = 0;
            for(int tk=0; tk<i; tk++){
                if(hastube[tk]) tubecnt++;
            }
            cout << tubecnt << endl;
            return 0;
        }
    }
    cout << 1 << endl << gans;

    return 0;
}
