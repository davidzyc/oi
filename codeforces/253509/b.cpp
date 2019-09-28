#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    int n;
    int a, b;
    scanf("%d%d", &n, &a);
    for(int i=2; i<=n; i++){
        scanf("%d", &b);
        if(b > a) {
            printf("N\n");
            return 0;
        }
    }
    printf("S\n");


    return 0;
}