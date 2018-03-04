#include<cstdio>
#include<iostream>
#define MAXN 201
#define MAXM 16003
#define ST 8001
using namespace std;

int n, gsum = 0;
int a[MAXN];
int dp[MAXN][MAXM] = {0};

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        gsum += a[i];
    }
    for(int i=0; i<MAXM; i++){
        dp[0][i] = -1;
    }
    dp[0][ST] = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<MAXM; j++){
            if(j-a[i]>=0 && dp[i][j-a[i]] == i){
                dp[i+1][j] = i+1;
            }
            if(j+a[i]<MAXM && dp[i][j+a[i]] == i){
                dp[i+1][j] = i+1;
            }
        }
    }
    for(int i=0; i<ST; i++){
        if((dp[n][ST-i] == n) || dp[n][ST+i] == n){
            // cout << i << endl;
            cout << (gsum-i)/2 << endl;
            cout << (gsum+i)/2 << endl;
            return 0;
        }
    }


    return 0;
}