#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, a[1005], b[1005], left[1005], right[1005];

bool cmp (const int i, const int j){
    return a[i] > a[j];
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        b[i] = i;
    }

    sort(b, b+n, cmp);

    return 0;
}