#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 1e9+7;

int n;
int a, b;
int l, r;

int main(){
    l = MAXN, r = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        l = min(l, b);
        r = max(r, a);
    }
    if(l <= r){
        cout << r-l+1 << endl;
        cout << l << " " << r;
    }else{
        cout << 1 << endl;
        cout << r << " " << r;
    }

    return 0;
}