#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

typedef long long ll;

const int MAXN = (1 << 18) + 7;

int n, q, nn;
int qid[MAXN], qfrom[MAXN], qto[MAXN], qrfrom[MAXN], qrto[MAXN];
ll qans[MAXN];
vector<int> valto[MAXN];
int gval[MAXN], bval[MAXN];
// ZKW
int m;
ll dat[MAXN];
// TREE CUT
vector<int> to[MAXN];
int fa[MAXN], dep[MAXN];
int dfncnt = 0, dfn[MAXN], dfid[MAXN];
int sonsize[MAXN] = {0}, top[MAXN], hson[MAXN];

bool cmp(int a, int b){
    if(a != b){
        return qrfrom[a] < qrfrom[b];
    }else{
        return qrto[a] < qrto[b];
    }
}

void zkw_init(){
    for(m=1; m<n; m<<=1);
    for(int i=1; i<=n; i++){
        dat[m+i] = (ll) gval[dfid[i]];
    }
    for(int i=m-1; i>0; i--){
        dat[i] = dat[(i << 1)] + dat[(i << 1) ^ 1];
    }
    return;
}

void ginit(){
    for(int i=1; i<=n; i++){
        bval[i-1] = gval[i];
    }
    sort(b, b+n);
    nn = unique(b, b+n) - b;

    return;
}

void zkw_update(int x, int val){
    x = x + m;
    dat[x] += val;
    for(x >>= 1; x > 0 ; x >>= 1){
        dat[x] = dat[(x << 1)] + dat[(x << 1) ^ 1];
    }
    return;
}

ll zkw_query(int l, int r){
    ll ans = 0;
    for(l += m-1, r += m+1; l^r^1; l>>=1, r>>=1){
        if(~l&1) ans += dat[l^1];
        if(r&1) ans += dat[r^1];
    }
    return ans;
}

void predfs(int x){
    int maxson = 0, maxsonid = 0;
    for(int i=0; i<to[x].size(); i++){
        int y = to[x][i];
        if(fa[x] == y) continue;
        fa[y] = x;
        dep[y] = dep[x] + 1;
        predfs(y);
        if(maxson < sonsize[y]){
            maxson = sonsize[y];
            maxsonid = y;
        }
        sonsize[x] += sonsize[y];
    }
    hson[x] = maxsonid;
    sonsize[x] ++;
    return;
}

void tcutdfs(int x, int xtop){
    top[x] = xtop;
    dfn[x] = ++dfncnt;
    dfid[dfncnt] = x;
    if(!hson[x]) return;
    tcutdfs(hson[x], xtop);
    for(int i=0; i<to[x].size(); i++){
        int y = to[x][i];
        if(y == fa[x] || y == hson[x]) continue;
        tcutdfs(y, y);
    }
    return;
}

ll tcut_query(int x, int y){
    ll ans = 0;
    while(top[x] != top[y]){
        if(dep[top[y]] > dep[top[x]]) swap(x, y);
        // cout << x << " " << y <<endl;
        ans += zkw_query(dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    if(dep[y] > dep[x]) swap(x, y);
    ans += zkw_query(dfn[y], dfn[x]);
    // cout << endl;
    return ans;
}

int main(){
    int tf, tt;
    int tl, tr;
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; i++){
        scanf("%d", &gval[i]);
    }
    for(int i=1; i<n; i++){
        scanf("%d%d", &tf, &tt);
        to[tf].push_back(tt);
        to[tt].push_back(tf);
    }
    for(int i=0; i<q; i++){
        scanf("%d%d%d%d", &qfrom[i], &qto[i], &qrfrom[i], &qrto[i]);
        qid[i] = i;
    }
    dep[1] = 1;
    predfs(1);
    tcutdfs(1, 1);
    zkw_init();
    sort(qid, qid+q, cmp);
    for(int qi=0; qi<q; qi++){
        int i = qid[qi];

        qans[i] = tcut_query(qfrom[i], qto[i]);
    }

    for(int i=0; i<q; i++){
        printf("%d\n", qans[i]);
    }

    return 0;
}
