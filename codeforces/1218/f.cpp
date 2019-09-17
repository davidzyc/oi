#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

const int MAXN = 1e5+7;

typedef long long ll;

int n;
ll k, a;
ll x[MAXN];
ll c[MAXN];
ll cur_c = 0;
priority_queue<ll, vector<ll>, greater<ll> > pq;

int main(){
    scanf("%d%lld", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%lld", &x[i]);
    }
    scanf("%lld", &a);
    for(int i=1; i<=n; i++){
        scanf("%lld", &c[i]);
    }

    for(int i=1; i<=n; i++){
        pq.push(c[i]);
        while((!pq.empty()) && k < x[i] ){
            cur_c += pq.top();
            // cout << k << " " << x[i] << endl;
            // cout << "Take " << pq.top() << endl;
            k += a;
            pq.pop();
        }
        if(k < x[i]){
            printf("-1");
            return 0;
        }
    }
    printf("%lld", cur_c);

    return 0;
}