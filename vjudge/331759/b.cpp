#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 1e5+7;

ll n;
int m;
char c;
int a, b;
int ecnt = 0;
int fi[MAXN], et[MAXN], ef[MAXN], nxt[MAXN];
int sta[MAXN];

void add_edge(int x, int y){
    ++ecnt;
    ef[ecnt] = x;
    et[ecnt] = y;
    nxt[ecnt] = fi[x];
    fi[x] = ecnt;
}

int main(){

    // cin >> n >> m;
    scanf("%lld %d\n", &n, &m);
    for(int i=1; i<=m; i++){
        scanf("%c %d %d\n", &c, &a, &b);
        if(c == 'L'){
            sta[i] = 1;
        }else {
            sta[i] = 0;
        }
        if(a != 0) add_edge(i, a);
        if(b != 0) add_edge(i, b);
    }
        // cout << c << endl;

    for(int i=1; i<=m; i++) cout << sta[i] << " ";

    return 0;
}