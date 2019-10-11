#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 2007;
const int MAXD = 27;
const int INF = 2100000000;

int n, d;
int dp[MAXN][MAXD];
int s[MAXN], cs[MAXN];

int main(){
    while(scanf("%d%d", &n, &d) == 2){
        memset(dp, 0, sizeof(dp));
        memset(s, 0, sizeof(s));
        memset(cs, 0, sizeof(cs));
        cs[0] = 0;
        for(int i=1; i<=n; i++){
            cin >> s[i];
            cs[i] = cs[i-1] + s[i];
        }
        for(int i=0; i<=d; i++){
            for(int j=0; j<=n; j++){
                dp[i][j] = -INF;
            }
        }
        for(int i=1; i<=n; i++){
            int tc = cs[i];
            tc = tc % 10;
            if(tc >= 5){
                tc = tc - 10;
            }
            dp[0][i] = tc;
        }
        // dp[0][0] = 0;
        for(int i=1; i<=d; i++){
            for(int j=1; j<=n; j++){
                for(int k=1; k<=j-1; k++){
                    int tc = cs[j] - cs[k];
                    tc = tc % 10;
                    if(tc >= 5){
                        tc = tc - 10;
                    }
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + tc);
                }
            }
        }
        int gans = -INF;
        for(int i=0; i<=d; i++){
            gans = max(gans, dp[i][n]);
        }

        for(int i=0; i<=d; i++){
            for(int j=0; j<=n; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        cout << cs[n] - gans << endl;
    }

    return 0;
}