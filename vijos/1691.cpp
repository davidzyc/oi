#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int n, tot = 0;
    int x[10005], y[10005];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    sort(y, y+n);

    for(int i=0; i<n/2; i++){
        tot += abs(y[n-i-1]-y[i]);
    }

    cout << tot;

    return 0;
}