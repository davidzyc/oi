#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int MAXL = 20;
const int MAXN = 6e5+7;

typedef long long ll;

int n, m, nl;
// adjacent table
int ecnt = 0;
int first[MAXN], nxt[MAXN], to[MAXN];
ll l[MAXN];
// LCA 1 - Path Finding
int dfncnt, dfn[MAXN];
int fa[MAXN][MAXL], dep[MAXN];
ll fadis[MAXN] = {0};
ll dis[MAXN] = {0};
// LCA 2 - MAX Route Marking
ll fdismax[MAXN][MAXL] = {0};
ll gmax = 0;

int read_int(){
    char c;
    int ret = 0;
    c = getchar();
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar()){
        ret *= 10;
        ret += c - '0';
    }
    return ret;
}

ll read_ll(){
    char c;
    ll ret = 0;
    c = getchar();
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar()){
        ret *= 10;
        ret += c - '0';
    }
    return ret;
}

void add_edge(int tf, int tt, ll tl){
    ++ecnt;
    nxt[ecnt] = first[tf];
    first[tf] = ecnt;
    to[ecnt] = tt;
    l[ecnt] = tl;
    return;
}

void predfs(int x){
    dfn[x] = ++dfncnt;
    for(int i=1; i<=nl ;i++){
        fa[x][i] = fa[fa[x][i-1]][i-1];
    }
    for(int e=first[x]; e!=0; e=nxt[e]){
        int y = to[e];
        if(y == fa[x][0]) continue;
        dep[y] = dep[x] + 1;
        dis[y] = dis[x] + l[e];
        fadis[y] = l[e];
        fa[y][0] = x;
        predfs(y);
    }
    return;
}

int lca_query(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    for(int i=nl; i>=0; i--){
        if(dep[fa[x][i]] >= dep[y]){
            x = fa[x][i];
        }
    }
    if(x == y){
        return x;
    }
    for(int i=nl; i>=0; i--){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

void lca_mpath(int x, int y, ll lpath){
    if(dep[x] < dep[y]) swap(x, y);
    for(int i=nl; i>=0; i--){
        if(dep[fa[x][i]] >= dep[y]){
            maintain_max(x, i, lpath);
            x = fa[x][i];
        }
    }
    if(x == y){
        return;
    }
    for(int i=nl; i>=0; i--){
        if(fa[x][i] != fa[y][i]){
            maintain_max(x, i, lpath);
            maintain_max(y, i, lpath);
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    maintain_max(x, 0, lpath);
    maintain_max(y, 0, lpath);
    return;
}

int main(){
    freopen("2680.txt", "r", stdin);
    int tf, tt;
    ll tl;
    // scanf("%d%d", &n, &m);
    n = read_int();
    m = read_int();
    nl = (int) (log(n) / log(2)) + 1;
    for(int i=1; i<n; i++){
        // scanf("%d%d%lld", &tf, &tt, &tl);
        tf = read_int();
        tt = read_int();
        tl = read_ll();
        add_edge(tf, tt, tl);
        add_edge(tt, tf, tl);
    }
    dep[1] = 1;
    predfs(1);
    int opx, opy;
    ll tdis, tlca;
    for(int opi=0; opi<m; opi++){
        // scanf("%d%d", &opx, &opy);
        opx = read_int();
        opy = read_int();
        tlca = lca_query(opx, opy);
        tdis = dis[opx] + dis[opy] - 2*dis[tlca];
        gmax = max(gmax, tdis);
        lca_mpath(opx, opy, tdis);
        // printf("%lld\n", tdis);
    }
    for(int i=nl; i>0; i--){
        for(int j=1; j<=n; j++){


        }
    }


    return 0;
}
