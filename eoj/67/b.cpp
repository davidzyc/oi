#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
    int digcnt[2] = {0};
    int gn;
    scanf("%d", &gn);
    while(gn--){
        memset(digcnt, 0, sizeof(digcnt));
        int stype = 2;
        string s;
        int nlen;
        int nd;
        cin >> s;
        nlen = s.length();
        for(int i=0; i<nlen; i++){
            if(s[i] != s[nlen-1-i]) stype = 1;
        }
        if(stype == 2){
            printf("Perfect!\n");
            continue;
        }
        for(int i=0; i<nlen; i++){
            nd = s[i] - '0';
            digcnt[nd]++;
        }
        if(nlen % 2 == 0){
            if(digcnt[0]%2 == 0 && digcnt[1]%2 == 0){
                printf("OK!\n");
            }else{
                printf("Pbo!\n");
            }
        }else{
            if((digcnt[0]%2 == 0 && digcnt[1]%2 == 1) || (digcnt[0]%2 == 1 && digcnt[1]%2 == 0)){
                printf("OK!\n");
            }else{
                printf("Pbo!\n");
            }
        }
    }

    return 0;
}
