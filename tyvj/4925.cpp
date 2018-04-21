#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1e5+7;
const int MAXM = 4e5+7;

typedef long long ll;

int n, m;
int fa[MAXN];
ll ufsize[MAXN];
int ecnt = 0;
int from[MAXM], to[MAXM], id[MAXM];
ll ans[MAXN] = {0};

bool cmp(int a, int b){
    if(from[a] != from[b]){
        return from[a] < from[b];
    }else return to[a] < to[b];
}

void init(){
    for(int i=0; i<=n; i++){
        fa[i] = i;
        ufsize[i] = 1;
    }
    return;
}

int ufind(int x){
    int root = x, tx = x, t;
    while(fa[root] != root){
        root = fa[root];
    }
    while(tx != root){
        t = tx;
        fa[tx] = root;
        tx = fa[t];
        ufsize[tx] += ufsize[t];
        ufsize[t] = 0;
    }
    return root;
}

void unite(int x, int y){
    int rootx = ufind(x), rooty = ufind(y);
    fa[rooty] = rootx;
    return;
}

int main(){
    int tf, tt, tw;
    scanf("%d%d", &n, &m);
    init();
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &tf, &tt, &tw);
        if(tw == 0){
            unite(tf, tt);
        }else if(tw == 1){
            ecnt ++;
            from[ecnt] = tf;
            to[ecnt] = tt;
            id[ecnt] = ecnt;
            ecnt ++;
            from[ecnt] = tt;
            to[ecnt] = tf;
            id[ecnt] = ecnt;
        }
    }

    for(int i=1; i<=ecnt; i++){
        from[i] = ufind(from[i]);
        to[i] = ufind(to[i]);
    }
    for(int i=1; i<=n; i++){
        ufind(i);
    }
    sort(id+1, id+ecnt+1, cmp);
    for(int i=1; i<=ecnt; i++){
        int eid = id[i];
        int lasteid = id[i-1];
        if((from[eid] == from[lasteid] && to[eid] == to[lasteid]) || from[eid] == to[eid]) continue;
        ans[from[eid]] += ufsize[to[eid]];
    }
    for(int i=1; i<=n; i++){
        if(!ufsize[i]) continue;
        ans[i] += ufsize[i];
        ans[i] = (ans[i]-1) * (ans[i] - 2);
        ans[i] /= 2;
    }
    for(int i=1; i<=n; i++){
        int tfa = ufind(i);
        printf("%lld\n", ans[tfa]);
    }

    return 0;
}
