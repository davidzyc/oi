#include<cstdio>
#include<iostream>
#define MAXN 51
#define INF 2100000000
#define MAXT 100001
using namespace std;

int t, n;
int a[MAXN], b[MAXN], c[MAXN];
int dp[MAXT] = {0};

int main(){
    cin >> t >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    for(int i=0; i<MAXT; i++){
        dp[i] = -INF;
    }
    dp[0] = 0;
    for(int i=0; i<n; i++){
        cin >> c[i];
    }
    for(int i=0; i<n; i++){
        for(int j=MAXT-1; j>=c[i]; j--){
            dp[j] = max(dp[j], dp[j-c[i]]+a[i]-b[i]*j);
        }
    }
    int ans = 0;
    for(int i=0; i<MAXT; i++){
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}