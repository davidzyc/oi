#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 1e7+7;

int n, pcnt = 0;
int mod;
int p[MAXN], pn[MAXN], v[MAXN];
int ans = 0;

void euler_prime(){
    for(int i=2; i<=n+1; i++){
        if(!v[i]){
            p[pcnt] = i;
            ++pcnt;
            for(int j=1; j*i <= n; j++){
                v[j*i] = 1;
            }
        }
    }
    return;
}

int main(){

    freopen("aiyouwei.in", "r", stdin);
    freopen("aiyouwei.out", "w", stdout);

    int t, tmul;
    int tans;
    ll gans = 1;
    scanf("%d%d", &n, &mod);
    euler_prime();
    for(int i=0; i<pcnt; i++){
        tans = 0;
        for(tmul = p[i], t = n / tmul; t > 0; tmul *= p[i], t = n / tmul){
            tans += t;
            tans %= mod;
        }
        ++ tans;
        // cout << tans << " "  << gans << " ";
        tans %= mod;
        cout << tans << endl;
        gans *= (ll) tans;
        gans %= (ll) mod;
    }
    printf("%lld\n", gans);

    return 0;
}
