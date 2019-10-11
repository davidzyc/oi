#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int MAXN = 1007;

typedef pair<int, int> pii;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

char s[MAXN];
int n, m;
int v[MAXN][MAXN];
int fl;
queue<pii> q;

int get_node_id(int y, int x){
    return y * (m + 1) + x;
}

void print_mat(){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    // freopen("a.in", "r", stdin);
    while(scanf("%d%d", &n, &m) == 2){
        while(!q.empty()){
            q.pop();
        }
        memset(v, 0, sizeof(v));
        for(int i=0; i<n; i++){
            scanf("%s", &s);
            for(int j=0; j<strlen(s); j++){
                if(s[j] == '/'){
                    fl = (i + j) % 2;
                    v[i+1][j] = 1;
                    v[i][j+1] = 1;
                }else if(s[j] == '\\'){
                    v[i][j] = 1;
                    v[i+1][j+1] = 1;
                }
            }
        }
        // print_mat();
        for(int i=0; i<=n; i++){
            q.push(make_pair(i, 0));
            q.push(make_pair(i, m));
        }
        for(int j=0; j<=m; j++){
            q.push(make_pair(0, j));
            q.push(make_pair(n, j));
        }
        while(!q.empty()){
            pii x = q.front();
            q.pop();
            int xx, yy;
            xx = x.second;
            yy = x.first;
            if(v[yy][xx]) continue;
            // cout << yy << " " << xx << endl;
            v[yy][xx] = 1;
            for(int i=0; i<4; i++){
                if((xx+dx[i] >= 0) && (xx+dx[i] <= m) && (yy+dy[i] >= 0) && (yy+dy[i] <= n)){
                    if(v[yy+dy[i]][xx+dx[i]] == 0){
                        q.push(make_pair(yy+dy[i], xx+dx[i]));
                    }
                }
            }
        }
        int gcnt = 0;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(v[i][j] == 0 && ((i+j)%2) == fl ) gcnt++;
                // cout << v[i][j] << " ";
            }
            // cout << endl;
        }
        // print_mat();
        printf("%d\n", gcnt * 2);
    }

    return 0;
}
