#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    int n;
    double temp = 1.0, nd;
    cin >> n;
    nd = n*1.0;
    for(int i=2;;i++){
        temp += 1.0 / i;
        if(temp > nd) {
            cout << i;
            return 0;
        }
    }
}