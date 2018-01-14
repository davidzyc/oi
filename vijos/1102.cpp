#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int a[12], h, tot = 0;
    for(int i=0; i<10; i++){
        cin >> a[i];
    }
    cin >> h;
    for(int i=0; i<10; i++){
        if(a[i] <= h+30) tot++;
    }
    cout << tot;

    return 0;
}