#include<cstdio>
#include<iostream>
#include<vector>
#define MAXN 500001
#define MAXM 1000001
using namespace std;

typedef long long ll;
int n, s;
int from[MAXM], to[MAXM], first[MAXN] = {0}, nxt[MAXM] = {0};
ll w[MAXN];
int v[MAXN] = {0};
ll tnode[MAXN] = {0};
ll gans = 0;

void dfs(int tnid){
    vector<ll> vec;
    ll tcnt = 0, tmax = 0, tsum = 0;
    if(v[tnid]) return;
    v[tnid] = 1;
    // cout << tnid << " ";
    for(int e=first[tnid]; e!=0; e=nxt[e]){
        if(v[to[e]]) continue;
        dfs(to[e]);
        vec.push_back(tnode[to[e]] + w[e]);
        tmax = max(tmax, tnode[to[e]] + w[e]);
    }
    for(int i=0; i<vec.size(); i++){
        gans += tmax - vec[i];
    }
    tnode[tnid] = tmax;
}

int main(){
    int tfrom, tto, tw, trev, t;
    cin >> n >> s;
    for(int i=1; i<n; i++){
        cin >> tfrom >> tto >> tw;
        trev = i+n-1;

        from[i] = tfrom;
        to[i] = tto;
        w[i] = tw;
        t = first[tfrom];
        first[tfrom] = i;
        nxt[i] = t;

        from[trev] = tto;
        to[trev] = tfrom;
        w[trev] = tw;
        t = first[tto];
        first[tto] = trev;
        nxt[trev] = t;
    }
    dfs(s);
    cout << gans << endl;

    return 0;
}