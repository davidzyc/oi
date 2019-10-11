#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN = 107;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

typedef pair<int, int> pii;

int h, w;
int mat[MAXN][MAXN], v[MAXN][MAXN];
char s[MAXN];
queue<pii> q;

int main(){

    while(scanf("%d%d", &h, &w) != EOF){
        memset(mat, 0, sizeof(mat));
        memset(v, 0, sizeof(v));
        while(!q.empty()){
            q.pop();
        }
        for(int i=0; i<h; i++){
            scanf("%s", s);
            for(int j=0; j<w; j++){
                if(s[j] == '/'){
                    mat[i][j] = 1;
                }else if(s[j] == '\\'){
                    mat[i][j] = 2;
                }
            }
        }
        // for(int i=0; i<h; i++){
        //     for(int j=0; j<w; j++){
        //         cout << mat[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int i=0; i<h; i++){
            q.push(make_pair(i, 0));
            q.push(make_pair(i, w-1));
        }
        for(int j=0; j<w; j++){
            q.push(make_pair(0, j));
            q.push(make_pair(h-1, j));
        }
        while(!q.empty()){
            pii t = q.front();
            q.pop();
            int y = t.first;
            int x = t.second;
            if(v[y][x] == 1 || mat[y][x] != 0) continue;
            v[y][x] = 1;
            for(int i=0; i<4; i++){
                int yy = y + dy[i];
                int xx = x + dx[i];
                if(yy >= 0 && xx >= 0 && yy < h && xx < w){
                    if(v[yy][xx] == 0 && mat[yy][xx] == 0 ){
                        q.push(make_pair(yy, xx));
                    }
                }
            }
        }
        int ccnt = 0, gcnt = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(mat[i][j] != 0){
                    ccnt ++;
                }else if(v[i][j] == 0){
                    gcnt++;
                }
            }
        }
        // cout << ccnt << " " << gcnt << endl;
        printf("%d\n", ccnt/2 + gcnt);
    }

    return 0;
}