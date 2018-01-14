#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int a[3], dp[10000000];

bool dfs(int remain){
    if(dp[remain] == 1) return true;
    if(remain == 0 || remain % a[0] == 0 || remain % a[1] == 0){
        dp[remain] = 1;
        return true;
    }
    //cout << remain << endl;
    for(int i=0; i<2; i++){
        if(remain - a[i] >=0 && dfs(remain - a[i])){
            dp[remain] = 1;
            return true;
        }
    }
    return false;
}

int min(int a, int b){
    return a<b ? a : b;
}

int main(){
    cin >> a[0] >> a[1];
    memset(dp, 0, sizeof(dp));
    int sep = min(a[0], a[1]), cnt = 0;
    for(int i=sep; ;i++){
        //cout << i << "------------" << endl;
        if(dfs(i)){
            cnt++;
            if(cnt == sep){
                cout << i-sep;
                break;
            }
        }else{
            cnt = 0;
        }
    }
    return 0;
}