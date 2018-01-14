#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int n, a[100], b[20005], temp, sum = 0;
    cin >> n;

    memset(b, 0, sizeof(b));
    for(int i=0; i<n; i++){
        cin >> a[i];
        b[a[i]] = 1;
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            temp = a[i]+a[j];
            if(b[temp] == 1){
                b[temp] ++;
                sum ++;
            }
        }
    }

    cout << sum;

    return 0;
}