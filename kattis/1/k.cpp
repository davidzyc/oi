#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int n;
char s[100007];
int v[100];

int main(){
    int gans = 0;
    memset(v, -1, sizeof(v));
    scanf("%s", s);
    n = strlen(s);
    for(int i=0; i<n; i++){
        int t = s[i] - 'a';
        for(int j=0; j<26; j++){
            if(v[j] != -1 && v[j] > v[t]){
                gans ++;
            }
        }
        v[t] = i;
    }

    cout << gans;


    return 0;
}