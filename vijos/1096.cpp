#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int tot = 0, temp, deposit = 0;
    for(int i=0; i<12; i++){
        cin >> temp;
        tot = tot + 300 - temp;
        if(tot >= 0){
            deposit += tot - tot % 100;
            tot = tot % 100;
        }else{
            cout << "-" << i+1;
            return 0;
        }
    }
    cout << tot + deposit * 1.2;
    return 0;
}