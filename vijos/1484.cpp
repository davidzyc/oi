#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    char c[20];
    int cnt = 0, tmp = 0;
    cin >> c;

    for(int i=0; i<12; i++){
        if(c[i] == '-') continue;
        tmp += (c[i]-'0')*(++cnt);
    }
    tmp = tmp % 11;

    if(c[12] == tmp + '0' || (tmp == 10 && c[12] == 'X')){
        cout << "Right";
    }else{
        if(tmp == 10){
            c[12] = 'X';
        }else{
            c[12] = tmp + '0';
        }
        cout << c;
    }

    return 0;
}