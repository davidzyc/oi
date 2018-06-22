#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>

using namespace std;

const int MAXN = 1007;

int rn, cn, k, gmat = 0, gness, tness, gset = 0;
vector<int> to[MAXN];
int v[MAXN], m[MAXN];
int gf[MAXN], gt[MAXN];
int tf, tt, tmat;

void ginit(){
    for(int i=0; i<MAXN; i++){
        to[i].clear();
    }
    memset(m, 0, sizeof(m));
    gmat = 0;
    gness = tness = 0;
    return;
}

bool hungarian(int x){
    for(int i=0; i<to[x].size(); i++){
        int y = to[x][i];
        if((x == tf && y == tt) || (x == tt && y == tf)) continue;
        if(v[y]) continue;
        v[y] = 1;
        if(!m[y] || hungarian(m[y])){
            m[y] = x;
            m[x] = y;
            return true;
        }
    }
    return false;
}

int bipcnt(){
    int ans = 0;
    memset(m, 0, sizeof(m));
    for(int i=1; i<=rn; i++){
        memset(v, 0, sizeof(v));
        if(hungarian(i)) ans++;
    }
    return ans;
}

int main(){
    int r, c;
    while(scanf("%d%d%d", &rn, &cn, &k) == 3){
        ginit();
        for(int i=0; i<k; i++){
            scanf("%d%d",&r, &c);
            gf[i] = r;
            gt[i] = c+rn;
            to[r].push_back(c+rn);
            to[c+rn].push_back(r);
        }
        gness = 0;
        tf = tt = 0;
        gmat = bipcnt();
        for(int i=0; i<k; i++){
            tf = gf[i], tt = gt[i];
            tmat = bipcnt();
            if(tmat < gmat) gness++;
        }
        printf("Board %d have %d important blanks for %d chessmen.\n", ++gset, gness, gmat);
    }
    return 0;
}
