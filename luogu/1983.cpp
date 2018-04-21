#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 1005;

int n, m;
int adjm[MAXN][MAXN] = {0};
int maxd[MAXN] = {0};
int v[MAXN] = {0};
int gans = 0;

void dfs(int x){
    v[x] = 1;
    for(int y=1; y<=n; y++){
        if(adjm[x][y]){
            if(!v[y] && !maxd[y]){
                dfs(y);
            }
            maxd[x] = max(maxd[x], maxd[y]);
        }
    }
    maxd[x] ++;
    gans = max(gans, maxd[x]);
    return;
}

int main(){
    int tn, t;
    int tm[MAXN], tv[MAXN];
    scanf("%d%d", &n, &m);
    for(int ii=0; ii<m; ii++){
        scanf("%d", &tn);
        memset(tv, 0, sizeof(tv));
        memset(tm, 0, sizeof(tm));
        for(int i=0; i<tn; i++){
            scanf("%d", &tm[i]);
            tv[tm[i]] = 1;
        }
        for(int i=tm[0]+1; i<tm[tn-1]; i++){
            if(!tv[i]){
                for(int j=0; j<tn; j++){
                    adjm[i][tm[j]] = 1;
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(!maxd[i]){
            dfs(i);
        }
    }
    /** for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    } **/
    printf("%d", gans);

    return 0;
}
