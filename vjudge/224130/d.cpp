#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 8e5+7;
const int INF = 0x3f3f3f3f;

int q, n, m, w;
int dat[MAXN];

int read(){
    int t = 0;
    char c;
    c = getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar()) t = t*10 + c - '0';
    return t;
}

void build(){
    for(m=1; m<n; m<<=1);
    for(int i=1; i<=n; i++){
        dat[m+i] = w;
    }
    for(int i=m-1; i>=1; i--){
        dat[i] = max(dat[i<<1], dat[(i<<1)^1]);
    }
    return;
}

int query(int x, int tmax){
    if(x > m){
        return x - m;
    }
    if(x <= m && dat[x<<1] >= tmax){
        return query(x<<1, tmax);
    }else if(x <= m && dat[(x<<1)^1] >= tmax){
        return query((x<<1)^1, tmax);
    }else{
        return INF;
    }
}

void update(int x, int val){
    x = x + m;
    dat[x] -= val;
    for(x>>=1; x>0; x>>=1){
        dat[x] = max(dat[x<<1], dat[(x<<1)^1]);
    }
    return;
}

int main(){
    // freopen("d.txt", "r", stdin);
    int qlen, qpos;
    while(scanf("%d%d%d", &n, &w, &q) == 3){
        memset(dat, 0, sizeof(dat));
        n = min(n, q);
        m = 1;
        build();
        for(int i=0; i<q; i++){
            qlen = read();
            qpos = query(1, qlen);
            if(qpos < INF){
                update(qpos, qlen);
                printf("%d\n", qpos);
            }else{
                printf("%d\n", -1);
            }
        }
    }

    return 0;
}
