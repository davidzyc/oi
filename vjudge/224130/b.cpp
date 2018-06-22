#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 4e5+7;

int n, m;
int a[MAXN];
int dat[MAXN];

void pushup(int node_id){
    dat[node_id] = max(dat[node_id << 1], dat[(node_id << 1)^1]);
    return;
}

void init(){
    for(m=1; m<n; m<<=1);
    for(int i=1; i<=n; i++){
        dat[m+i] = a[i];
    }
    for(int i=m-1; i>=1; i--){
        pushup(i);
    }
    return;
}

void update(int p, int val){
    p += m;
    dat[p] = val;
    for(p>>=1; p>0; p>>=1){
        pushup(p);
    }
    return;
}

int query(int l, int r){
    int ans = 0;
    for(l=l+m-1, r=r+m+1; l^r^1; l>>=1, r>>=1){
        if(~l&1){
            ans = max(ans, dat[l^1]);
        }
        if(r&1){
            ans = max(ans, dat[r^1]);
        }
    }
    return ans;
}

int main(){
    char c[3];
    int opx, opy;
    int q;
    while(scanf("%d%d", &n, &q) == 2){
        memset(dat, 0, sizeof(dat));
        memset(a, 0, sizeof(a));
        for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
        }
        init();
        for(int qi=0; qi<q; qi++){
            scanf("%s%d%d", c, &opx, &opy);
            if(c[0] == 'Q'){
                printf("%d\n", query(opx, opy));
            }else if(c[0] == 'U'){
                update(opx, opy);
            }
        }
    }

    return 0;
}
