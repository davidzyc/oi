#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int p_notation(int n, int k){
    int sum = 1, temp = n-k+1;
    for(int i=temp; i<=n; i++){
        sum *= i;
    }
    for(int i=2; i<=k; i++){
        sum /= i;
    }
    return sum;
}

int main(){

    int n = 1000, m, a, b, c = 0;
    cin >> a >> b;
    m = sqrt(n+0.5);
    int vis[1010], p[1000];
    memset(vis, 0, sizeof(vis));
    memset(p, 0, sizeof(p));

    for(int i=2; i<=n; i++){
        if(!vis[i]){
            p[c++] = i;
            for(int j=i*i; j<=n; j+=i){
                vis[j] = 1;
            }
        }
    }

    int temp = b / a, cnt = 0;

    for(int i=0; i<c; i++){
        if(temp % p[i] == 0){
            // cout << p[i] << " ";
            cnt++;
        }
    }

    int sum = 0;
    for(int i=0; i<=cnt; i++){
        sum += p_notation(cnt, i);
        // cout << sum << " ";
    }

    if(b % a){
        cout << 0;
    }else{

    cout << sum;
    }


    return 0;
}