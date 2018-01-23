#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    int n, m, tot = 0;
    int temp, digit;
    cin >> n >> m;
    for(int i=n; i<=m; i++){
        temp = i;
        while(temp > 0){
            digit = temp % 10;
            if(digit == 2) tot ++;
            temp /= 10;
        }
    }
    cout << tot;

    return 0;
}