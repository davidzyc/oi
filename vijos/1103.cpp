#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n, m, startp[105], endp[105], tree[10005], tot = 0;
    memset(tree, 0, sizeof(tree));
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> startp[i] >> endp[i];
        for(int pos = startp[i]; pos <= endp[i]; pos++){
            tree[pos] = 1;
        }
    }
    for(int i=0; i<=n; i++){
        if(tree[i] == 0) tot++;
    }

    cout << tot;
    return 0;
}