#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long ll;
const int MAXN = 2e6+7;

int n, m, k;
ll tans = 0;
int fa[MAXN];
ll imp[MAXN];
int id[MAXN], from[MAXN], to[MAXN], used[MAXN];

inline int read(){
    int ret = 0;
    char c;
    for(c = getchar();!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar()) ret = ret*10 + c - '0';
    return ret;
}

inline ll llread(){
    ll ret = 0;
    char c;
    for(c = getchar();!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar()) ret = ret*10 + c - '0';
    return ret;
}

inline void ginit(){
    n = m = k = tans = 0;
    memset(fa, 0, sizeof(fa));
    memset(imp, 0, sizeof(imp));
    memset(id, 0, sizeof(id));
    memset(from, 0, sizeof(from));
    memset(to, 0, sizeof(to));
    memset(used, 0, sizeof(used));
}

inline void init(int x){
    for(int i=0; i<=x; i++){
        fa[i] = i;
    }
}

inline bool cmp(int a, int b){
    return imp[from[a]] != imp[from[b]] ? imp[from[a]] > imp[from[b]] : imp[to[a]] < imp[to[b]];
}

inline int dsfind(int x){
    return x == fa[x] ? x : fa[x] = dsfind(fa[x]);
}

inline void dsunion(int x, int y){
    int fax = dsfind(x), fay = dsfind(y);
    fa[fax] = fay;
    return;
}

int main(){
    int gcase, tcase;
    scanf("%d", &tcase);
    gcase = tcase;
    while(tcase--){
        ginit();
        scanf("%d%d%d", &n, &m, &k);
        init(n);
        for(int i=1; i<=n; i++){
            //scanf("%d", &imp[i]);
            imp[i] = llread();
            tans += imp[i];
        }
        for(int i=0; i<m; i++){
            //scanf("%d%d", &from[i], &to[i]);
            from[i] = read();
            to[i] = read();
            id[i] = i;
            id[m+i] = m+i;
            to[m+i] = from[i];
            from[m+i] = to[i];
        }
        k = m - k;
        sort(id, id+2*m, cmp);
        for(int i=0; i<2*m; i++){
            int xf = from[id[i]], yt = to[id[i]];
            //cout << xf << " "<< yt << endl;
            if(xf != yt && !used[xf] && dsfind(xf) != dsfind(yt) && k > 0){
                dsunion(xf, yt);
                used[xf] = 1;
                k--;
                tans -= imp[xf];
            }
            if(k == 0) break;

        }
        printf("Case #%d: %lld\n", gcase-tcase, tans);
    }

    return 0;
}
