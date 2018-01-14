#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
    int n, m, a[2005], b[2005], visb[2005], tot = 0;
    cin >> n >> m;
    memset(visb, 0, sizeof(visb));
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+m);
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(a[i] > b[j] && visb[j] == 0 && b[j] != 0){
                tot++;
                visb[j] = 1;
                break;
            }
        }
    }
    cout << m - tot;

    return 0;
}