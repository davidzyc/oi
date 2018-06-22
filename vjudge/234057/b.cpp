#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

const int MAXN = 1005;

int n, m, matcnt = 0;
vector<int> to[MAXN];
int match[MAXN], v[MAXN];

bool hungarian(int x){
    for(int i=0; i<to[x].size(); i++){
        int y = to[x][i];
        if(v[y]) continue;
        v[y] = 1;
        if(!match[y] || hungarian(match[y])){
            match[y] = x;
            match[x] = y;
            return true;
        }
    }
    return false;
}

int main(){
    memset(match, 0, sizeof(match));
    int tf, tt;
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d%d", &tf, &tt);
        to[tf].push_back(tt);
        to[tt].push_back(tf);
    }
    for(int i=1; i<=n; i++){
        memset(v, 0, sizeof(v));
        if(hungarian(i)) matcnt++;
    }
    for(int i=1; i<=n; i++){
        cout << i << " " << match[i] << endl;
    }
    printf("%d\n", matcnt / 2);

    return 0;
}
