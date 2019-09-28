#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1e5+7;
const double EPS = 0.000000001;

int n;
double aa, bb, at, bt, add_g[MAXN];
double g[MAXN], a[MAXN], b[MAXN];
int id[MAXN];

bool cmp(int x, int y){
    return a[x]*b[y] > a[y]*b[x];
}

int main(){
    freopen("burrito.in", "r", stdin);
    freopen("burrito.out", "w", stdout);
    cin >> n >> aa >> bb;
    for(int i=1; i<=n; i++){
        cin >> g[i] >> a[i] >> b[i];
        id[i] = i;
    }
    sort(id+1, id+1+n, cmp);
    for(int ii=1; ii<=n; ii++){
        int i = id[ii];
        add_g[i] = min(g[i], (bb - bt)/b[i]);
        // // cout << bb*1.0 - bt;

        bt += b[i] * add_g[i];
        at += a[i] * add_g[i];
        // double tot = b[i]*g[i];
        // if(bt + tot + EPS < bb) {
        //     bt += tot;
        //     at += a[i] * g[i];
        //     add_g[i] = g[i];
        // } else if(bt + EPS < bb){
        //     at += a[i] * (bb - bt) / b[i];
        //     add_g[i] = (bb - bt) / b[i];
        //     bt = bb;
        // }
        // cout << g[i] << " " << a[i] << " " << b[i] << endl;
        // cout << "at " << at << " | bt " << bt << endl;
    }

    if(at + EPS < aa){
        printf("-1 -1");
    }else{
        // cout << at << " " << bt << endl;
        printf("%.8lf %.8lf\n", at, bt);
        for(int i=1; i<=n; i++){
            // cout << add_g[i] << " ";
            printf("%.8lf ", add_g[i]);
        }
    }


    return 0;
}