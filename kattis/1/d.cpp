#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int n;
int a[1000];

int main(){
    memset(a, 0, sizeof(a));
    int t, tm = 0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        cin >> t;
        a[t] = 1;
        tm = max(tm, t);
    }
    int f = false;
    for(int i=1; i<=tm; i++){
        if(a[i] == 0){
            cout << i << endl;
            f = true;
        }
    }

    if(f == false){
        cout << "good job";
    }


    return 0;
}