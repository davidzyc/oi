#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    char c[10000];
    int ww = 0, ll = 0, ww21 = 0, ll21 = 0;
    int n;
    for(int i=0;; i++){
        c[i] = getchar();
        if(c[i] == 'W'){
            ww ++;
        }else if(c[i] == 'L'){
            ll ++;
        }
        if((ww >= 11 || ll >= 11) && (ww - ll >= 2 || ll - ww >= 2)){
            cout << ww << ':' << ll << endl;
            ww = 0;
            ll = 0;
        }
        if(c[i] == 'E'){
            n = i;
            cout << ww << ':' << ll << endl;
            break;
        }
    }
    cout << endl;

    for(int i=0; i<n; i++){
        if(c[i] == 'W'){
            ww21 ++;
        }else if(c[i] == 'L'){
            ll21 ++;
        }
        if((ww21 >= 21 || ll21 >= 21) && (ww21 - ll21 >= 2 || ll21 - ww21 >= 2)){
            cout << ww21 << ':' << ll21 << endl;
            ww21 = 0;
            ll21 = 0;
        }
    }
    cout << ww21 << ':' << ll21 << endl;

    return 0;
}