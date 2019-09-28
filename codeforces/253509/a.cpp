#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int MAXN = 2e3+7;
const int MAXG = 2e6+7;

typedef long long ll;

ll m, n;
int k;
ll px[MAXN], py[MAXN], pr[MAXN];

int gcnt = 0;
int efr[MAXG], et[MAXG], ef[MAXG], nxt[MAXG];
int v[MAXN];

queue<int> q;

void add_edge(int x, int y) {
    ++gcnt;
    // efr[gcnt] = x;
    et[gcnt] = y;
    nxt[gcnt] = ef[x];
    ef[x] = gcnt;
}

bool two_circle_intersect(int x, int y) {
    return (pr[x] + pr[y])*(pr[x] + pr[y]) >= ((px[x] - px[y])*(px[x] - px[y]) + (py[x] - py[y])*(py[x] - py[y]));
}

int main(){
    memset(v, 0, sizeof(v));
    memset(et, 0, sizeof(et));
    memset(ef, 0, sizeof(ef));
    // cin >> m >> n >> k;
    scanf("%lld%lld%d", &m, &n, &k);
    for(int i=1; i<=k; i++){
        // cin >> px[i] >> py[i] >> pr[i];
        scanf("%lld%lld%lld", &px[i], &py[i], &pr[i]);
    }

    for(int i=1; i<=k; i++){
        for(int j=1; j<=k; j++){
            if(i == j) continue;
            if(two_circle_intersect(i, j)){
                add_edge(i, j);
                add_edge(j, i);
            }
        }
    }

    for(int i=1; i<=k; i++){
        if(px[i] <= pr[i] || (py[i] + pr[i]) >= n) {
            add_edge(i, k+1);
            add_edge(k+1, i);
        }
        if(py[i] <= pr[i] || (px[i] + pr[i]) >= m) {
            add_edge(i, k+2);
            add_edge(k+2, i);
        }
    }

    q.push(k+1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(v[x]) continue;
        v[x] = 1;
        for(int e = ef[x]; e; e=nxt[e]){
            int y = et[e];
            if(!v[y]) q.push(y);
        }
    }

    if(v[k+2] == 0){
        printf("S");
    }else{
        printf("N");
    }

    // for(int i=1; i<=gcnt; i+=2) {
    //     cout << efr[i] << " " << et[i] << endl;
    // }


    return 0;
}