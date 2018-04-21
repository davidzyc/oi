#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

const int MAXN = 2e5+7;

int n;
int dat[MAXN];

int lowbit(int x){
    return x&(-x);
}

int query(int t){
    int x = t;
    int ans = 0;
    while(x > 0){
        ans += dat[x];
        x -= lowbit(x);
    }
    return ans;
}

void update(int t, int p){
    int x = t;
    while(x <= n){
        dat[x] += p;
        x += lowbit(x);
    }
    return;
}

int main(){
    // freopen("a.txt", "r", stdin);
    bool flag;
    int datp;
    int a, b;
    int tmp;
    char s[6];
    scanf("%d", &datp);
    for(int pid=1; pid<=datp; pid++){
        printf("Case %d:\n", pid);
        flag = true;
        memset(dat, 0, sizeof(dat));
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%d", &tmp);
            update(i, tmp);
        }
        while(flag){
            scanf("%s", s);
            switch(s[0]){
                case 'Q':
                    scanf("%d%d", &a, &b);
                    printf("%d\n", query(b)-query(a-1));
                    break;
                case 'A':
                    scanf("%d%d", &a, &b);
                    update(a, b);
                    break;
                case 'S':
                    scanf("%d%d", &a, &b);
                    update(a, -b);
                    break;
                case 'E':
                    flag = false;
                    break;
            }
        }
    }

    return 0;
}
