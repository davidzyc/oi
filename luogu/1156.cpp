#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 105;
const int MAXH = 205;

int d, g;
int t[MAXN], f[MAXN], h[MAXN], id[MAXN];
int dp[MAXH];
// int gans = 0x3f3f3f3f;

bool cmp(int a, int b){
    return t[a] < t[b];
}

int main(){
    // freopen("1156.txt", "r", stdin);
    scanf("%d%d", &d, &g);
    for(int i=0; i<g; i++){
        scanf("%d%d%d", &t[i], &f[i], &h[i]);
        id[i] = i;
    }
    sort(id, id+g, cmp);
    // memset(dp, 0x8f, sizeof(dp));

    dp[0] = 10;
    for(int ti = 0; ti<g; ti++){
        int i = id[ti];
        for(int j=d; j>=0; j--){
            if(dp[j] >= t[i]){
                if(j + h[i] >= d){
                    printf("%d", t[i]);
                    return 0;
                }
                dp[j+h[i]] = max(dp[j+h[i]], dp[j]);
                dp[j] += f[i];
            }

        }
    }
    printf("%d", dp[0]);
    return 0;
}
