#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

const int MAXN = 2007;
const int MAXM = 1e5+7;

int n;
int am[MAXN][MAXN], bm[MAXN][MAXN], m[MAXN][MAXN];
int dm[MAXN][MAXN];
int ds[MAXN][2];
int b[MAXN];
char s[MAXN];
int v[MAXN][MAXN] = {0};
bool gflag = true;
queue<int> q;

void debug() {
    cout << "Status of BAR, row: " ;
    for(int i=1; i<=n; i++){
        cout << ds[i][0] << " ";
    }
    cout << endl;
    cout << "Status of BAR, col: " ;
    for(int i=1; i<=n; i++){
        cout << ds[i][1] << " ";
    }
    cout << endl;
}

void dfs(int x, int rc) {
    if (rc == 0) {
        for(int i=1; i<=n; i++){
            if (dm[x][i] != -1){
                if (ds[i][1] == -1){
                    ds[i][1] = ds[x][0] ^ dm[x][i];
                    // cout << "CUR " << x << " (Row:0, col:1) " << rc << endl;
                    // cout << "SET " << i << " (Row:0, col:1) " << (rc^1) << " : " << ds[i][rc^1] << endl;
                } else {
                    if (ds[i][rc^1] != (ds[x][rc] ^ dm[x][i])) {
                        gflag = false;
                        return;
                    } else {
                        if(v[x][i] == 0){
                            v[x][i] = 1;
                            dfs(i, rc^1);
                        }
                    }
                }
            }
        }
    } else {
        for(int i=1; i<=n; i++){
            if (dm[i][x] != -1){
                if (ds[i][rc^1] == -1){
                    ds[i][rc^1] = ds[x][rc] ^ dm[i][x];
                } else {
                    if (ds[i][rc^1] != (ds[x][rc] ^ dm[i][x])) {
                        gflag = false;
                        return;
                    } else {
                        if(v[i][x] == 0){
                            v[i][x] = 1;
                            dfs(i, rc^1);
                        }
                    }
                }
            }
        }
    }
}

int main(){

    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%s", s);
        for(int j=1; j<=n; j++){
            am[i][j] = s[j-1] - '0';
        }
    }
    for(int i=1; i<=n; i++){
        scanf("%s", s);
        for(int j=1; j<=n; j++){
            bm[i][j] = s[j-1] - '0';
        }
    }
    scanf("%s", s);
    for(int j=1; j<=n; j++){
        b[j] = s[j-1] - '0';
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            m[i][j] = am[i][j] ^ bm[i][j];
            // cout << m[i][j] << " ";
        }
        // cout << endl;
    }

    for(int i=1; i<=n; i++){
        ds[i][0] = -1;
        ds[i][1] = -1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dm[i][j] = -1;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(b[i] == 0 && b[j] == 0){
                if(m[i][j] == 1) {
                    printf("-1");
                    return 0;
                }
                // dm[i][j] = -1;
            } else if(b[i] == 1 && b[j] == 1){
                dm[i][j] = m[i][j];
            } else {
                if (b[i] == 1){
                    ds[j][1] = m[i][j];
                    q.push(n+j-1);
                }
                if (b[j] == 1) {
                    ds[i][0] = m[i][j];
                    q.push(i-1);
                }
            }
        }
    }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << dm[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << q.size();

    while(!q.empty()){
        int x = q.front();
        q.pop();
        int cx = (x % n) + 1;
        int rc = x / n;
        // printf("Checking %d ", cx);
        // rc ? printf("COL\n") : printf("ROW\n");
        dfs(cx, rc);
        if(gflag == false){
            printf("-1");
            return 0;
        }
    }

    for(int i=1; i<=n; i++){
        if(ds[i][0] == -1){
            ds[i][0] = 0;
            dfs(i, 0);
            if(gflag == false){
                printf("-1");
                return 0;
            }
        }
        if(ds[i][1] == -1){
            ds[i][1] = 0;
            dfs(i, 1);
            if(gflag == false){
                printf("-1");
                return 0;
            }
        }
    }
    int gcnt = 0;
    for(int i=1; i<=n; i++){
        if(ds[i][0] == 1) gcnt++;
        if(ds[i][1] == 1) gcnt++;
    }
    printf("%d\n", gcnt);
    for(int i=1; i<=n; i++){
        if(ds[i][0] == 1) printf("row %d\n", i-1);
        if(ds[i][1] == 1) printf("col %d\n", i-1);
    }



    return 0;
}