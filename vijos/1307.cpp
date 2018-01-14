#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    int n;
    long long tot = 0;
    cin >> n;
    for(int i=1; i<=n; i++){
        tot += i*i;
    }
    cout << tot;
    return 0;
}