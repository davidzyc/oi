#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n, m, a[30005], b[30005], tot = 0, tmpcnt = 0, processed = 0, tmpw = 0;
    cin >> m >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n, cmp);
    memset(b, 0, sizeof(b));
    while(processed < n){
        tmpcnt = 0;
        tmpw = 0;
        for(int i=0; i<n; i++){
            if(b[i] == 0){
                if(a[i] > m) return 0;
                if(tmpcnt >= 2){
                    break;
                }
                if(m-tmpw >= a[i]){
                    b[i] = 1;
                    // cout << a[i] << " ";
                    processed++;
                    tmpw += a[i];
                    tmpcnt++;
                }
            }
        }
        tot++;
        // cout << endl;
    }
    cout << tot;

    return 0;
}