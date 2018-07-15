#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 3e5+7;
const int INF = 2100000000;


int n, k;
int a[MAXN];
int ans = INF;

bool chk(int x){
    for(int i=1; i<=n; i++){
        if(a[i] % x > k) return false;
    }
    return true;
}

int main(){
    freopen("czl.in", "r", stdin);
    freopen("czl.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        ans = min(ans, a[i]);
    }
    for(int i=ans; i>=1; i--){
        if(chk(i)){
            printf("%d\n", i);
            return 0;
        }
    }


    printf("%d\n", 1);

    return 0;
}
