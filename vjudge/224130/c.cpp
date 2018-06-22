#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 2e5+7;

int n, m = 1;
int odat[MAXN];
int dat[MAXN];

int lowbit(int x){
    return x&(-x);
}

int query(int x){
    int tx = x;
    int ans = 0;
    while(tx > 0){
        ans += dat[tx];
        tx -= lowbit(tx);
    }
    return ans;
}

void update(int x, int val){
    int tx = x;
    if(!tx) return;
    while(tx <= m){
        dat[tx] += val;
        tx += lowbit(tx);
    }
    return;
}

int main(){

    while(scanf("%d", &n) == 1){
        int tans = 0, gans = 0x3f3f3f3f;
        memset(dat, 0, sizeof(dat));
        memset(odat, 0, sizeof(odat));
        m = 1;
        for(m=1; m<n; m<<=1);
        for(int i=1; i<=n; i++){
            scanf("%d", &odat[i]);
            ++odat[i];
            // cout << query(n+2) - query(odat[i]) << " ";
            tans += (query(n+2) - query(odat[i]));
            update(odat[i], 1);
        }
        gans = min(gans, tans);
        // cout << tans << endl;
        for(int i=1; i<=n; i++){
            tans += n-odat[i]*2+1;
            // cout << tans << endl;
            gans = min(gans, tans);
        }
        printf("%d\n", gans);
    }

    return 0;
}
