#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define NEGINF -100000000

int n, m;
int p[100], prio[100], pa[100], vis[100], aff[100], pr[35000][100], pvis[35000][100];

int dp(int price, int layer){
    if(pvis[price][layer]){
        return pr[price][layer];
    }
    int temp, max = 0, maxi = -1;
    if(price > n){
        return NEGINF;
    }
    if(price == n){
        return 0;
    }
    for(int i=1; i<=m; i++){
        if(vis[i]){
            continue;
        }
        if(pa[i] != 0 && vis[pa[i]] == 0){
            continue;
        }
        if(pa[i] != 0 && aff[pa[i]] > 2){
            continue;
        }
        if(pa[i] != 0){
            aff[pa[i]]++;
        }
        vis[i]++;
        temp = dp(price + p[i], layer+1);
        vis[i]--;
        if(pa[i] != 0){
            aff[pa[i]]--;
        }
        temp += p[i] * prio[i];
        if(temp > max){
            max = temp;
            maxi = i;
        }
    }
    cout << layer << ": p:" << price << " maxi:" << maxi << " max:" << max << endl;
    pvis[price][layer] = 1;
    pr[price][layer] = max;
    return max;
}

int main(){
    cin >> n >> m ;
    memset(vis, 0, sizeof(vis));
    memset(aff, 0, sizeof(aff));
    memset(pr, 0, sizeof(pr));
    memset(pvis, 0, sizeof(pvis));
    for(int i=1; i<=m; i++){
        cin >> p[i] >> prio[i] >> pa[i];
    }

    cout << dp(0, 0);

    return 0;
}