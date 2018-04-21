#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 1e5+7;
const int MAXM = 1e5+7;

int n, m;
vector<int> to[MAXN];
int dfncnt = 0, dfn[MAXN], low[MAXN];
int scccnt = 0, sccmaxs = 0, sccmaxid;
int sccid[MAXN];
int sta[MAXN], stav[MAXN], stasize = 0;
vector<int> scc[MAXN];

void tarjan(int x){
    dfn[x] = low[x] = ++ dfncnt;
    sta[stasize++] = x;
    stav[x] = 1;
    for(int i=0; i<to[x].size(); i++){
        int y = to[x][i];
        if(!dfn[y]){
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }else if(stav[y]){
            low[x] = min(low[x], low[y]);
        }
    }
    if(low[x] == dfn[x]){
        int y = 0;
        scccnt++;
        do{
            y = sta[--stasize];
            sccid[y] = scccnt;
            scc[scccnt].push_back(y);
            stav[y] = 0;
        }while(x != y);
        sort(scc[scccnt].begin(), scc[scccnt].end());
        if(scc[scccnt].size() > sccmaxs){
            sccmaxs = scc[scccnt].size();
            sccmaxid = scccnt;
        }else if(scc[scccnt].size() == sccmaxs){
            for(int i=0; i<scc[scccnt].size(); i++){
                if(scc[scccnt][i] < scc[sccmaxid][i]){
                    sccmaxid = scccnt;
                    break;
                }
            }
        }
    }
    return;
}

int main(){
    int tf, tt, tl;
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &tf, &tt, &tl);
        to[tf].push_back(tt);
        if(tl == 2){
            to[tt].push_back(tf);
        }
    }
    for(int i=1; i<=n; i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    printf("%d\n", sccmaxs);
    for(int i=0; i<scc[sccmaxid].size(); i++){
        printf("%d ", scc[sccmaxid][i]);
    }

    return 0;
}
