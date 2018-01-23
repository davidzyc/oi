#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    int n;
    int ans = 0;
    bool neg = false;
    cin >> n;
    if(n < 0){
        neg = true;
        n *= -1;
    }
    while(n > 0){
        ans *= 10;
        ans += n%10;
        n /= 10;
    }
    if(neg) cout << "-";
    cout << ans;

    return 0;
}