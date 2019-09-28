#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    int a, b;
    scanf("%d%d", &a, &b);
    for(int i=1; i<=9; i++){
        printf("%d ", (a*b*i + 9) / 10);
    }


    return 0;
}