#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 1e5+7;
const int MAXM = 2e5+7;

int n;
int a[MAXN], b[MAXN], c[MAXN], id[MAXN];
int dat[2][MAXM] = {0};
int gans = 0;
int tnum[MAXM];

void discretify(){
    int tn;
    for(int i=0; i<n; i++){
        tnum[i*2] = a[i];
        tnum[i*2+1] = b[i];
    }
    sort(tnum, tnum+2*n);
    tn = unique(tnum, tnum+2*n) - tnum;
    for(int i=0; i<n; i++){
        a[i] = lower_bound(tnum, tnum+tn, a[i]) - tnum + 1;
        b[i] = lower_bound(tnum, tnum+tn, b[i]) - tnum + 1;
    }
    return;
}

int lowbit(int x){
    return x&(-x);
}

int tgetmax(int x, int tid){
    int tx = x;
    int ans = 0;
    while(tx > 0){
        ans = max(ans, dat[tid][tx]);
        tx -= lowbit(tx);
    }
    return ans;
}

void tsetmax(int x, int y, int tid){
    int tx = x;
    while(tx <= n){
        dat[tid][tx] = max(dat[tid][tx], y);
        tx += lowbit(tx);
    }
    return;
}

bool cmp(int x, int y){
    if(a[x] != a[y]){
        return a[x] < a[y];
    }else if(b[x] != b[y]){
        return b[x] < b[y];
    }else{
        return c[x] < c[y];
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        -- c[i];
        id[i] = i;
    }
    discretify();
    sort(id, id+n, cmp);
    for(int ti=0; ti<n; ti++){
        int tans = 0;
        int i = id[ti];
        for(int j=0; j<=c[i]; j++){
            tans = max(tans, tgetmax(b[i], j));
        }
        // cout << tans+1 << endl;
        gans = max(gans, tans+1);
        tsetmax(b[i], tans+1, c[i]);
    }
    // for(int i=0; i<n; i++){
    //    cout << a[i] << " " << b[i] << endl;
    // }
    printf("%d", gans);

    return 0;
}
