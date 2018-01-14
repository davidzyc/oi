#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int n, a[100], numsum = 0, avg, tot;
    cin >> n;
    tot = n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        numsum += a[i];
    }
    avg = numsum / n;
    numsum = 0;
    for(int i=0; i<n; i++){
        numsum += a[i];
        if(numsum == avg * (i+1)){
            tot--;
        }
    }
    cout << tot << endl;
    return 0;
}