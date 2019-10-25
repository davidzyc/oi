#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 2e5+7;

int s, g;
int a, b;

int main(){

    cin >> s >> g;
    if(s % g != 0){
        cout << "-1";
        return 0;
    }
    s /= g;
    if(s <= 1){
        cout << "-1";
        return 0;
    }
    if(s == 2){
        cout << g << " " << g;
        return 0;
    }
    if(s % 2 == 0){
        if(s % 4 == 0){
            cout << ((s/2) + 1)*g << " " << ((s/2) - 1)*g;
        }else{
            cout << ((s/2) + 2)*g << " " << ((s/2) - 2)*g;
        }
    }else{
        cout << (s/2)*g << " " << ((s/2) + 1)*g;
    }
    
    return 0;
}