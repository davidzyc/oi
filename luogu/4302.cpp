#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;

int n;
string ss;
char s[MAXN];

int dp[MAXN][MAXN] = {0};
int dps[MAXN][MAXN] = {0};

bool csubstr(int l, int r, int sep){
    if((r+1-l)%sep != 0) return false;
    for(int i=1; i<(r+1-l)/sep; i++){
        for(int j=0; j<sep; j++){
            if(s[l+j] != s[l+i*sep+j]){
                return false;
            }
        }
    }
    return true;
}

void rec_print(int l, int r){
    if(l == r){
        printf("%c", s[l]);
        return;
    }
    if(dps[l][r] < 0){
        rec_print(l, -dps[l][r]);
        rec_print(-dps[l][r]+1, r);
    }else{
        printf("%d", (r+1-l)/dps[l][r]);
        printf("(");
        rec_print(l, l+dps[l][r]-1);
        printf(")");
    }
    return;
}

int main(){
    // freopen("4302.txt", "w", stdout);
    cin >> ss;
    n = ss.length();
    for(int i=1; i<=n; i++){
        s[i] = ss[i-1];
    }
    for(int i=1; i<=n; i++){
        dp[i][i] = 1;
    }
    for(int len=1; len<n; len++){
        for(int l=1, r; (r=l+len)<=n; l++){
            dp[l][r] = r+1-l;
            dps[l][r] = -l;
            for(int sep=1; sep <= (len+1)/2; sep++){
                if(csubstr(l, r, sep) && dp[l][r] >= dp[l][l+sep]+3+((r+1-l)/sep)/10){
                    dp[l][r] = dp[l][l+sep-1]+3+((r+1-l)/sep)/10;
                    dps[l][r] = sep;
                }
            }
            for(int k=l; k<r; k++){
                if(dp[l][r] > dp[l][k]+dp[k+1][r]){
                    dp[l][r] = dp[l][k]+dp[k+1][r];
                    dps[l][r] = -k;
                }
            }
            // cout << l << " " << r << " - > dp " << dp[l][r] << " sep " << dps[l][r] << endl;
        }
    }
    rec_print(1, n);
    // cout << endl;
    // printf("%d", dp[1][n]);

    return 0;
}
