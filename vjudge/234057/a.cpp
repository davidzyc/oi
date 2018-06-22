#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int MAXN = 500;

int tcase;
int p, n;
vector<int> to[MAXN];
int v[MAXN], m[MAXN];

void ginit(){
    for(int i=0; i<MAXN; i++){
        to[i].clear();
    }
    memset(v, 0, sizeof(v));
    memset(m, 0, sizeof(m));
}

bool hungarian(int x){
    for(int i=0; i<to[x].size(); i++){
        int y = to[x][i];
        if(v[y]) continue;
        v[y] = 1;
        if(!m[y] || hungarian(m[y])){
            m[y] = x;
            return true;
        }
    }
    return false;
}

int main(){
    scanf("%d", &tcase);
    while(tcase--){
        ginit();
        int tc, t;
        scanf("%d%d", &p, &n);
        for(int i=1; i<=p; i++){
            scanf("%d", &tc);
            for(int j=0; j<tc; j++){
                scanf("%d", &t);
                to[i].push_back(t+p);
                to[t+p].push_back(i);
            }
        }
        int gans = 0;
        for(int i=1; i<=p; i++){
            memset(v, 0, sizeof(v));
            if(hungarian(i)){
                ++gans;
            }
        }
        if(gans == p){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }


    return 0;
}
