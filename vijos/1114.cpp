#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

char c[1025];
int np, n;

void tree_walk(int s, int n){
    if(n > 1){
        tree_walk(s, n/2);
        tree_walk(s+n/2, n/2);
    }
    bool bs = false, is = false;
    for(int i=s; i<s+n; i++){
        if(c[i] == '0'){
            bs = true;
        }else{
            is = true;
        }
        // cout << c[i];
    }
    // cout << " 0:" << bs << " 1:" << is << endl;
    if(bs && is){
        cout << 'F';
    }else if(bs){
        cout << 'B';
    }else{
        cout << 'I';
    }
}

int main(){
    cin >> np;
    n = pow(2.0, np*1.0);
    // getchar会读到\n,所以要把\n读掉以后才能都数据，不然会少读
    getchar();
    for(int i=0; i<n; i++){
        c[i] = getchar();
    }
    tree_walk(0, n);
    return 0;
}