#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int numl[10];

bool sepint(int i){
    int tmp;
    while(i>0){
        tmp = i % 10;
        if(tmp == 0) return false;
        if(numl[tmp] == 0){
            numl[tmp]++;
        }else{
            return false;
        }
        i/=10;
    }
    return true;
}

int main(){
    int tmp1, tmp2, tmp, minv = 100;
    for(int i=100; i<1000; i++){
        memset(numl, 0, sizeof(numl));
        tmp1 = i;
        tmp2 = 2018-i;
        if(tmp2 % 10 == tmp1 % 10){
            // cout << tmp1 << " " << tmp2 << endl;
            if(sepint(tmp1/10) && sepint(tmp2/10)){
                minv = min(minv, (tmp1/10%10)*(tmp2/10%10));
                cout << tmp1 << " " << tmp2 << endl;
            }
        }
    }
    cout << minv;

    return 0;
}