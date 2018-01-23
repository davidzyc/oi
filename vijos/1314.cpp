#include<cstdio>
#include<iostream>
#define MAXJOB 505
#define MAX_M 25
#define MAX_N 25
#define MAX_TIME 50005
using namespace std;

int mjob[MAX_M][MAX_TIME] = {0}, ntime[MAX_N] = {0}, njob[MAX_N] = {0}, globalmax = 0;

int main(){
    int m, n, qjob[MAXJOB], mno[MAX_N][MAX_M], mtime[MAX_N][MAX_M];
    cin >> m >> n;
    for(int i=1; i<=m*n; i++){
        cin >> qjob[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> mno[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> mtime[i][j];
        }
    }

    int tempn, tempm, startpos, templen, temppos;
    for(int i=1; i<=m*n; i++){
        tempn = qjob[i];
        njob[tempn] ++ ;
        tempm = njob[tempn];
        // cout << mno[tempn][tempm] << " " << mtime[tempn][tempm] << endl;
        temppos = ntime[tempn];
        templen = 0;
        while(templen < mtime[tempn][tempm]){
            if(mjob[mno[tempn][tempm]][temppos] == 0){
                templen++;
            }else{
                templen = 0;
            }
            temppos++;
        }
        ntime[tempn] = temppos;
        // cout << temppos << endl;
        globalmax = max(globalmax, temppos);
        for(int i=temppos - templen; i<temppos; i++){
            mjob[mno[tempn][tempm]][i] = 1;
        }
        
    // for(int i=1; i<=m; i++){
    //     for(int j=0; j<20; j++){
    //         cout << mjob[i][j];
    //     }
    //     cout << endl;
    // }
    // cout<<endl;

    }

    cout << globalmax;

    return 0;
}