#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int n, a[100][100];

void build_matrix(int k, int x, int y){
    int xx, yy;
    if(k == n * n){
        return;
    }
    if(y == 1 && x != n){
        yy = n;
        xx = x+1;
    }else if(x == n && y != 1){
        xx = 1;
        yy = y-1;
    }else if(x == n && y == 1){
        xx = x;
        yy = y+1;
    }else if(xx != n && yy != 1){
        if(x+1 <= n && y-1 > 0 && a[x+1][y-1] == 0){
            xx = x+1;
            yy = y-1;
        }else{
            xx = x;
            yy = y+1;
        }
    }
    a[xx][yy] = k+1;
    build_matrix(k+1, xx, yy);
}

int main(){
    cin >> n;
    memset(a, 0, sizeof(a));
    a[(n+1)/2][1] = 1;
    build_matrix(1, (n+1)/2, 1);
    for(int y=1; y<=n; y++){
        for(int x=1; x<=n; x++){
            cout << a[x][y] << " ";
        }
        cout << endl;
    }
    return 0;
}