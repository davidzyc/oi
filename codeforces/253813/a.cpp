#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 100;
// const int MAXM = 10000;


int n, m;
// int gcnt = 0;
// int x1[MAXM], y1[MAXM], x2[MAXM], y2[MAXM];
// int tp[MAXN];

// void add_r(int a, int b, int c, int d){
//     ++gcnt;
//     x1[gcnt] = a;
//     y1[gcnt] = b;
//     x2[gcnt] = c;
//     y2[gcnt] = d;
//     return;
// }

// void f(int x, int y, int p) {
//     add_r(2*x*tp[p-1], 2*y*tp[p-1], (2*x + 1)*tp[p-1], (2*y + 1)*tp[p-1]);
//     add_r((2*x + 1)*tp[p-1], (2*y + 1)*tp[p-1], (2*x + 2)*tp[p-1], (2*y + 2)*tp[p-1]);
//     if(p == 1){
//         return;
//     }
//     f(2*x, 2*y, p-1);
//     f(2*x+1, 2*y, p-1);
//     f(2*x, 2*y+1, p-1);
//     f(2*x+1, 2*y+1, p-1);
//     return;
// }

int main(){
    // tp[0] = 1;
    // for(int i=1; i<10; i++){
    //     tp[i] = tp[i-1] * 2;
    // }
    // // cin >> n >> m;
    // f(0,0,3);

    // for(int i=1; i<=gcnt; i++){
    //     printf("(%d, %d) (%d, %d)\n", x1[i] + 1, y1[i] + 1, x2[i], y2[i]);
    // }
    // cout << gcnt;
    // freopen("alter.in", "r", stdin);
    // freopen("alter.out", "w", stdout);
    cin >> n >> m;
    cout << (n / 2) + (m / 2) << endl;
    for(int i=2; i<=n; i+=2){
        printf("%d %d %d %d\n", i, 1, i, m);
    }
    for(int i=2; i<=m; i+=2){
        printf("%d %d %d %d\n", 1, i, n, i);
    }

    return 0;
}