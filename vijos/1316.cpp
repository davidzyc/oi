#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n, a[105], b[1005], temp, pos = 0;
    cin >> n;
    memset(b, 0, sizeof(b));
    for(int i=0; i<n; i++){
        cin >> temp;
        b[temp] = 1;
    }
    for(int i=1; i<=1000; i++){
        if(b[i] == 1){
            a[pos++] = i;
        }
    }
    cout << pos << endl;
    for(int i=0; i<pos; i++){
        if(i != 0) cout << " ";
        cout << a[i];
    }

    return 0;
}