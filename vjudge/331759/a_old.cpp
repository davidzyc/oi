#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<map>
using namespace std;

const int SHFT = 40000;
const int MAXN = 1000;
int n, m;
char s[500];
// int mat[MAXN][MAXN];
map<int, int> mat;
int v[MAXN];
queue<int> q;
int gcnt = 0;

int get_node_id(int y, int x, int z){
    return (y*m + x)*4 + z;
}

void add_edge(int y1, int x1, int z1, int y2, int x2, int z2){
    mat[get_node_id(y1, x1, z1)*SHFT + get_node_id(y2, x2, z2)] = 1;
    mat[get_node_id(y2, x2, z2)*SHFT + get_node_id(y1, x1, z1)] = 1;
}

void remove_edge(int y1, int x1, int z1, int y2, int x2, int z2){
    mat[get_node_id(y1, x1, z1)*SHFT + get_node_id(y2, x2, z2)] = 0;
    mat[get_node_id(y2, x2, z2)*SHFT + get_node_id(y1, x1, z1)] = 0;
}

void debug_out_node_id(int t){
    int y, x, z;
    z = t % 4;
    t /= 4;
    x = t % m;
    y = t / m;
    cout << x << " " << y << " " << z << endl;
}

int main(){

    while(scanf("%d%d", &n, &m) != 0){
        gcnt = 0;
        while(!q.empty()){
            q.pop();
        }
        // memset(mat, 0, sizeof(mat));
        mat.clear();
        memset(v, 0, sizeof(v));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                add_edge(i, j, 0, i, j, 1);
                add_edge(i, j, 1, i, j, 2);
                add_edge(i, j, 2, i, j, 3);
                add_edge(i, j, 3, i, j, 0);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m-1; j++){
                add_edge(i, j, 2, i, j+1, 0);
            }
        }
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++){
                add_edge(i, j, 3, i+1, j, 1);
            }
        }
        for(int i=0; i<n; i++){
            scanf("%s", &s);
            for(int j=0; j<strlen(s); j++){
                if(s[j] == '/'){
                    remove_edge(i, j, 1, i, j, 2);
                    remove_edge(i, j, 0, i, j, 3);
                }else if(s[j] == '\\'){
                    remove_edge(i, j, 0, i, j, 1);
                    remove_edge(i, j, 2, i, j, 3);
                }
            }
        }
        for(int i=0; i<n; i++){
            q.push(get_node_id(i, 0, 0));
            q.push(get_node_id(i, m-1, 2));
        }
        for(int j=0; j<m; j++){
            q.push(get_node_id(0, j, 1));
            q.push(get_node_id(n-1, j, 3));
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(v[x] == 1) continue;
            // debug_out_node_id(x);
            v[x] = 1;
            gcnt ++;
            //
            int t, yy, xx, zz;
            t = x;
            zz = t % 4;
            t /= 4;
            xx = t % m;
            yy = t / m;
            // for(int i=0; i<m*n*4; i++){
            for(int i=-1; i<=1; i+=2){
                for(int j=-1; j<=1; j+=2){
                    if((xx + i >= 0) && (xx + i < m) && (yy + i >= 0) && (yy + i < n)){
                        for(int k=0; k<4; k++){
                            int y = get_node_id(yy+i, xx+i, k);
                            if(mat[x*SHFT + y] == 1 && v[y] == 0){
                                q.push(y);
                            }
                        }
                    }
                }
            }
            for(int k=0; k<4; k++){
                int y = get_node_id(yy, xx, k);
                if(mat[x*SHFT + y] == 1 && v[y] == 0){
                    q.push(y);
                }
            }
                
            // }
        }
        printf("%d\n", (n*m*4 - gcnt) / 4);
    }


    return 0;
}