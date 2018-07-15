#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 3e5+7;

int n, m;
int l[MAXN], r[MAXN];

int main(){
    freopen("ohmygod.in", "r", stdin);
    freopen("ohmygod.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        l[i] = r[i] = i;
    }
    int tl, tr;
    for(int q=1; q<=m; q++){
        int ans = 0;
        scanf("%d%d", &tl, &tr);
        for(int i=tl; i<=tr; i++){
            ans += max(0, l[i] - tl);
            ans += max(0, tr - r[i]);
            l[i] = min(tl, l[i]);
            r[i] = max(tr, r[i]);
        }
        printf("%d\n", ans / 2);
    }

    return 0;
}
