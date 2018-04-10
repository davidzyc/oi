#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    int gn, nmax, nid, tn, t;
    scanf("%d", &gn);
    while(gn--){
        nmax = 0;
        scanf("%d", &tn);
        for(int i=1; i<=tn; i++){
            scanf("%d", &t);
            if(t > nmax){
                nmax = t;
                nid = i;
            }
        }
        printf("%d\n", nid);
    }
    return 0;
}
