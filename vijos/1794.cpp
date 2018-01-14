#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 105
#define INF 100000000

int n, k, m, s, t;
int c[MAXN], p[MAXN][MAXN], d[MAXN][MAXN], dij[MAXN], v[MAXN];
queue<int> q;

bool cmp(int i, int j){
    return dij[i] < dij[j];
}

int main(){
    int tu, tv; 
    cin >> n >> k >> m >> s >> t;
    for(int i=1; i<=n; i++){
        cin >> c[i];
    }
    for(int i=1; i<=k; i++){
        for(int j=0; j<k; j++){
            cin >> p[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    for(int i=1; i<=m; i++){
        cin >> tu >> tv;
        cin >> d[tu][tv];
    }
    //dijkstra
    memset(v, 0, sizeof(v));
    fill(dij, dij+MAXN, INF);
    dij[s] = 0;
    int m = INF, minx = s;
    while(v[minx] == 0){
        m = INF;
        v[minx] = 1;
        for(int i=1; i<=n; i++){
            if(d[minx][i] != -1){
                dij[i] = min(dij[i], dij[minx]+d[minx][i]);
                if(dij[i] < m && v[i] == 0){
                    m = dij[i];
                    minx = i;
                }
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for(int i=1; i<=n; i++){
    //     cout << dij[i];
    // }
    cout << dij[t];
    return 0;
}