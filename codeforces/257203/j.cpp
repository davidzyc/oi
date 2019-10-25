#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 2e5+7;

int n;
int a[MAXN];

int main(){
    int t;
    memset(a, 0, sizeof(a));
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> t;
        a[t] ++;
    }
    int gans = 0;
    for(int i=1; i<MAXN; i++){
        gans += (a[i] >> 1);
    }
    cout << (gans >> 1);

    return 0;
}