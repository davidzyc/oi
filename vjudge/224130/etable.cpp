#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 500000;

int gcnt = 0;
int num[100], numcnt[100];

int main(){
    freopen("e.txt", "w", stdout);
    int last = 0, tmp;
    for(int i=1; i<MAXN; i++){
        tmp = 0;
        for(int j=1; j*j<=i; j++){
            if(j*j == i){
                tmp++;
                continue;
            }
            if(i % j == 0) tmp+=2;
        }
        if(tmp > last){
            num[gcnt] = i;
            numcnt[gcnt++] = tmp;
            last = tmp;
        }

    }

    for(int i=0; i<gcnt; i++){
        printf("%d, ", num[i]);
    }
    cout << endl;
for(int i=0; i<gcnt; i++){
        printf("%d, ", numcnt[i]);
    }
    cout << endl;
    cout << gcnt;
    return 0;
}
