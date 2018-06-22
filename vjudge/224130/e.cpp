#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;

const int MAXN = 1e6+7;
const int MAXDAT = (1 << 20) + 7;

int n, m, datn, targp;

char uname[MAXN][11];
int nxt[MAXN];

int num[50] = {1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720, 840, 1260, 1680, 2520, 5040, 7560, 10080, 15120, 20160, 25200, 27720, 45360, 50400, 55440, 83160, 110880, 166320, 221760, 277200, 332640, 498960, 210000000};
int numcnt[50] = {1, 2, 3, 4, 6, 8, 9, 10, 12, 16, 18, 20, 24, 30, 32, 36, 40, 48, 60, 64, 72, 80, 84, 90, 96, 100, 108, 120, 128, 144, 160, 168, 180, 192, 200, 2100000000};

int dat[MAXDAT] = {0};
int vis[MAXN] = {0};

int read(){
    char c;
    int ans = 0;
    bool neg = false;
    c = getchar();
    for(;(!isdigit(c))&&c != '-'; c=getchar());
    if(c == '-'){
        neg = true;
        c = getchar();
    }
    for(;isdigit(c); c=getchar()) ans = ans*10 + c - '0';
    return neg ? ans*-1 : ans;
}

void read_uname(int x){
    int pos = 0;
    char c;
    c = getchar();
    for(;(c==' ')||(c=='\n')||(c=='\r'); c=getchar());
    for(;(c!=' ')&&(c!='\n')&&(c!='\r'); c=getchar()) uname[x][pos++] = c;
    return;
}

int lowbit(int x){
    return x&(-x);
}

int query(int x){
    int ans = 0;
    while(x > 0){
        ans += dat[x];
        x -= lowbit(x);
    }
    return ans;
}

void update(int x, int val){
    if(x == 0) return;
    while(x <= datn){
        dat[x] += val;
        x += lowbit(x);
    }
    return;
}

void build(){
    for(datn=1; datn<n; datn<<=1);
    for(int i=1; i<=n; i++){
        update(i, 1);
    }
    return;
}

int main(){
    int curpos;
    while(scanf("%d%d", &n, &curpos) == 2){
        memset(dat, 0, sizeof(dat));
        memset(vis, 0, sizeof(vis));
        memset(uname, 0, sizeof(uname));
        memset(nxt, 0, sizeof(nxt));
        build();
        for(int i=0; i<37; i++){
            if(n >= num[i]){
                targp = i;
            }else{
                break;
            }
        }
        if(num[targp] > n) targp--;
        // cout << num[targp];
        for(int i=1; i<=n; i++){
            scanf("%s", uname[i]);
            // read_uname(i);
            nxt[i] = read();
        }
        int rem, lb, ub, tpos, curpro;
        for(int i=1; i<num[targp]; i++){
            tpos = 0;
            vis[curpos] = 1;
            update(curpos, -1);
            rem = n-i;
            if(nxt[curpos] < 0) ++nxt[curpos];
            curpro = (query(curpos) + ((nxt[curpos] % rem) + rem) % rem + rem - 1) % (rem) + 1;
            // cout << curpro << endl;
            lb = 1;
            ub = n;
            while(lb <= ub){
                int mid = (lb+ub)>>1;
                int tmpq = query(mid);
                if(tmpq >= curpro){
                    ub = mid - 1;
                    if(tmpq == curpro && !vis[mid]){
                        tpos = mid;
                    }
                }else if(tmpq < curpro){
                    lb = mid + 1;
                }
            }

            curpos = tpos;
            // cout << curpos << endl;
        }
        printf("%s %d\n", uname[curpos], numcnt[targp]);
    }

    return 0;
}
