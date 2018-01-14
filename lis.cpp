#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define DPMAX 100005

int n, temp, t1, t2;
vector<int> v;
vector<int>::iterator vi;
int dp[DPMAX], res = 0;

int solve(){
    t1 = 0;
    for(vector<int>::iterator i = v.begin(); i != v.end(); i++){
        t2 = 0;
        for(vector<int>::iterator j = v.begin(); j != i; j++){
            if(*j < *i){
                dp[t1] = max(dp[t1], dp[t2]+1);
            }
            t2++;
        }
        res = max(res, dp[t1]);
        t1++;
    }
    return res;
}

int main(){
    fill(dp, dp+DPMAX, 1);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> temp;
        vi = v.begin() + temp;
        v.insert(vi, i);
        cout << solve() << endl;
    }

    return 0;
}