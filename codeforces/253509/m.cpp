#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1e5+7;

typedef long long ll;

ll n, c, t;
ll p[MAXN];
ll l = 0, r = 0;
// ll fa[MAXN], v[MAXN];

// ll find_fa(ll x){
//     return x == fa[x] ? x : fa[x] = find_fa(fa[x]);
// }

bool chk(ll x) {
    // ll used_cnt = 0;
    // for(ll i=1; i<=n; i++){
    //     fa[i] = i;
    //     v[i] = 0;
    // }
    ll cur = 1;
    for(int i=1; i<=c; i++){
        ll rem = x * t;
        while(rem > 0 && cur <= n) {
            // ll l = 0, r = n;
            // while(l < r) {
            //     ll mid = (l + r + 1) >> 1;
            //     if(p[mid] <= rem){
            //         l = mid;
            //     }else {
            //         r = mid - 1;
            //     }
            // }
            // l = find_fa(l);
            // if (l != 0) {
            //     rem -= p[l];
            //     v[l] = 1;
            //     fa[l] = l - 1;
            //     used_cnt ++;
            // } else {
            //     rem = 0;
            // }
            if(rem >= p[cur]){
                rem -= p[cur];
                cur++;
            } else {
                rem = 0;
                break;
            }
        }
    }
    return cur == n + 1;
}

int main(){

    scanf("%lld%lld%lld", &n, &c, &t);
    for(int i=1; i<=n; i++){
        scanf("%lld", &p[i]);
        // p[i] = (p[i] + t - 1) / t;
        r += p[i];
    }
    // r ++;
    // sort(p+1, p+1+n);
    // for(ll i=1; i<=n; i++) cout << p[i] << " ";
    while (l < r) {
        ll mid = (l + r) >> 1;
        if(chk(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    printf("%lld", l);


    return 0;
}