#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 55;
const int MAXM = 50;

int primecnt = 15;
int prime[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int pointcnt[MAXN] = {0};
int prepoint[MAXN] = {0};

int main(){
    bool flag;
    int pos;
    int ti, tj, tk;
    // 3D
    for(int i=1; i<=MAXM; i++){
        for(int j=1; j<=MAXM; j++){
            for(int k=1; k<=MAXM; k++){
                flag = true;
                ti = i;
                tj = j;
                tk = k;
                for(int p=0; p<primecnt; p++){
                    if(ti%prime[p] == 0 && tj%prime[p] == 0 && tk%prime[p] == 0){
                        flag = false;
                    }
                }
                if(flag){
                    pos = max(i, max(j,k));
                    pointcnt[pos]++;
                }
            }
        }
    }
    // 2D
    for(int i=1; i<=MAXM; i++){
        for(int j=1; j<=MAXM; j++){
            flag = true;
                ti = i;
                tj = j;
                for(int p=0; p<primecnt; p++){
                    if(ti%prime[p] == 0 && tj%prime[p] == 0){
                        flag = false;
                    }
                }
                if(flag){
                    pos = max(i, j);
                    pointcnt[pos] += 3;
                }
        }
    }
    // 1D
    pointcnt[0] += 3;
    for(int i=1; i<=MAXM; i++){
        pointcnt[i] += pointcnt[i-1];
        //printf("%d -> %d\n", i, pointcnt[i]);
    }
    int gn, t;
    scanf("%d", &gn);
    while(gn--){
        scanf("%d", &t);
        printf("%d\n", pointcnt[t]);
    }


    return 0;
}
