#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXLEN 500
#define M_X 7
#define M_Y 6
using namespace std;

int n, m, mpref[MAXLEN][MAXLEN];
int maxwidth = 0, minheight = MAXLEN;
int minwidth = MAXLEN, maxheight = 0;
char canvasm[MAXLEN][MAXLEN]; 
int visited[MAXLEN][MAXLEN];
char singlem[M_Y][M_X]={{'.','.','+','-','-','-','+'},
                        {'.','/',' ',' ',' ','/','|'},
                        {'+','-','-','-','+',' ','|'},
                        {'|',' ',' ',' ','|',' ','+'},
                        {'|',' ',' ',' ','|','/','.'},
                        {'+','-','-','-','+','.','.'}};

int paintm(int posx, int posy, bool cover){
    for(int i=0; i<M_Y; i++){
        for(int j=0; j<M_X; j++){
            if((!cover && !visited[posy+i][posx+j]) || cover || canvasm[posy+i][posx+j] == '.'){
                if(singlem[i][j] == '.' && visited[posy+i][posx+j]) continue;
                canvasm[posy+i][posx+j] = singlem[i][j];
                visited[posy+i][posx+j] = 1;
            }
            // if(canvasm[posy+i][posx+j] == '.'){
            //     visited[posy+i][posx+j] = 0;
            // }
        }
    }
}

int main(){
    // freopen("1497.in", "r", stdin);
    // freopen("1497.txt", "w", stdout);
    memset(visited, 0, sizeof(visited));
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mpref[i][j];
        }
    }
    for(int i=0; i<MAXLEN; i++){
        for(int j=0; j<MAXLEN; j++){
            canvasm[i][j] = '.';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int h=0; h<mpref[i][j]; h++){
                minwidth = min(minwidth, j*4+(n-i-1)*2);
                maxwidth = max(maxwidth, j*4+(n-i-1)*2);
                minheight = min(minheight, MAXLEN-h*3-6-(n-i-1)*2);
                maxheight = max(maxheight, MAXLEN-h*3-6-(n-i-1)*2);
                paintm(j*4+(n-i-1)*2, MAXLEN-h*3-6-(n-i-1)*2, true);
                // paintm(j*4, MAXLEN-h*3-30, true);
            }
        }
    }
    // paintm(0, 3, false);
    // paintm(0, 0, true);
    // paintm(4, 0, true);

    for(int i=minheight; i<maxheight+6; i++){
        for(int j=minwidth; j<=maxwidth+6; j++){
            cout << canvasm[i][j];
        }
        cout << endl;
    }

    return 0;
}