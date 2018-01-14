#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

// int a[500005], s[500005];
long long nc[100005];

int main(){
    long long n, k, temp, st = 0;
    long long tot = 0;
    cin >> n >> k;
    // memset(s, 0, sizeof(s));
    memset(nc, 0, sizeof(nc));
    for(int i=0; i<n; i++){
        cin >> temp;
        // temp = temp % k;
        st += temp;
        st = st % k;
        // s[i] = st;
        nc[st] ++;
    }
    // 天坑，nc溢出了，最大到100000，之前才设置了10000
    // 连续数之和最好设置常数，以免上面改了下面忘记改
    for(int i=0; i<=100000; i++){
        tot += (nc[i]-1) * nc[i] / 2;
        tot = tot % 1234567;
    }
    tot += nc[0];

    // for(int i=0; i<n; i++){
    //     if(s[i] == 0) tot++;
    //     for(int j=i+1; j<n; j++){
    //         if(s[i] == s[j]){
    //             tot++;
    //         }
    //     }
    // }

    cout << tot % 1234567;

    return 0;
}