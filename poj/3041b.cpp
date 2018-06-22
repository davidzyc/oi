#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>

using namespace std;

const int MAXN = 205;

int rn, cn, k, gmat = 0, gness, tness, gset = 0;
vector<int> to[MAXN];
int adjv[MAXN][MAXN];
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

bool ness(int x){
    for(int i=0; i<to[x].size(); i++){
        int y = to[x][i];
        if((x == tf && y == tt) || (x == tt && y == tf)) continue;
        if(v[y]) continue;
        v[y] = 1;
        if(adjv[x][y] || adjv[y][x] || adjv[y][m[y]] || adjv[m[y]][y]) continue;
        // cout << x << " -> " << y << endl;
        adjv[x][y] = adjv[y][x] = adjv[y][m[y]] = adjv[m[y]][y] = 1;
        if(ness(m[y])){
            return true;
        }
    }
    tness++;
    // cout << x << " Hi ";
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

        for(int i=1; i<=rn+cn; i++){
            // if(m[i]) continue;
            tness = -1;
            ness(i);
            gness += tness;
        }
        gness = gmat - gness;

        printf("Board %d have %d important blanks for %d chessmen.\n", ++gset, gness, gmat);
    }
    return 0;
}

