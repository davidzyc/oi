#include<cstdio>
#include<iostream>
#define INF 2100000000
using namespace std;

const int maxn = 1 << 16;
int n, dat[2*maxn-1];

void init(int _n){
    n = 1;
    while(n < _n) n *= 2;
    for(int i=0; i<2*n-1; i++){
        dat[i] = INF;
    }
}

void update(int k, int a){
    int t = n-1+k;
    dat[t] = a;
    while(t>0){
        t=(t-1)/2;
        dat[t] = min(dat[t*2+1], dat[t*2+2]);
    }
}

int query(int a, int b, int k, int l, int r){
    if(r <= a || l >= b){
        return INF;
    }
    if(a <= l && b >= r){
        return dat[k];
    }
    int lt, rt, tmin;
    lt = query(a, b, k*2+1, l, (l+r)/2);
    rt = query(a, b, k*2+2, (l+r)/2, r);
    tmin = min(lt, rt);
    return tmin;
}

int main(){
    int tn, ts;
    cin >> tn;
    init(tn);
    for(int i=0; i<tn; i++){
        cin >> ts;
        update(i, ts);
    }
    int tl, tr;
    cin >> tn;
    for(int i=0; i<tn; i++){
        cin >> tl >> tr;
        cout << endl << query(tl, tr, 0, 0, n) << endl;
    }

    return 0;
}