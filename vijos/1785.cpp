#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int m, a, c = 0;
int p[200000];

bool is_p(int n){
    for(int i=0; i<c; i++){
        if(n % p[i] == 0) {
            return false;
        }
    }
    p[c++] = n;
    return true;
}

int main(){

    cin >> a;
    m = sqrt(a+0.5);
    memset(p, 0, sizeof(p));

    for(int i=2; i<=m; i++){
        if(a%i == 0){
            cout << a/i;
            return 0;
        }
    }

    return 0;
}