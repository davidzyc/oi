#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 1e6+5;

int n, m;
vector<int> to[MAXN];
int d[MAXN] = {0}, c[MAXN] = {0}, v[MAXN] = {0};
priority_queue<pii, vector<pii>, greater<pii> > q;

void dijkstra(){
    pii tp;
    int curd, curi;
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    c[1] = 1;
    q.push(make_pair(0, 1));
    while(!q.empty()){
        tp = q.top();
        q.pop();
        curd = tp.first;
        curi = tp.second;
        if(v[curi]) continue;
        v[curi] = 1;
        for(int i=0; i<to[curi].size(); i++){
            if(d[curi] + 1 == d[to[curi][i]]){
                c[to[curi][i]] += c[curi];
                c[to[curi][i]] = c[to[curi][i]] % 100003;
            }else if(d[curi] + 1 < d[to[curi][i]]){
                d[to[curi][i]] = d[curi] + 1;
                c[to[curi][i]] = c[curi];
                c[to[curi][i]] = c[to[curi][i]] % 100003;
                q.push(make_pair(d[to[curi][i]], to[curi][i]));
            }
        }
    }
}

int main(){
    int tfrom, tto;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &tfrom, &tto);
        to[tfrom].push_back(tto);
        to[tto].push_back(tfrom);
    }
    dijkstra();
    for(int i=1; i<=n; i++){
        printf("%d\n", c[i] % 100003);
    }

    return 0;
}