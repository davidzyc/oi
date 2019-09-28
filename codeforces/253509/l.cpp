#include<cstdio>
#include<iostream>

using namespace std;

typedef unsigned long long ll;
ll n;

ll remove_left_digit(ll x){
    for(int i=63; i>=0; i--){
        if((x ^ (((ll)1) << i)) < x){
            return (x ^ (((ll)1) << i));
        }
    }
    return x;
}

ll f(ll x){
    return (remove_left_digit(x) == ((ll) 0)) ? x : ((ll) 2)*f(remove_left_digit(x));
}

int main(){
    int cnt = 0;
    scanf("%lld", &n);
    n++;
    // cout << n;
    // cout << remove_left_digit(5);
    printf("%lld", f(n));


    return 0;
}