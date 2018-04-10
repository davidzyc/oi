#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 55;
const int INF = 0x3f3f3f3f;

int n;
int gans = 0;
int adjm[MAXN][MAXN];

int main(){
  while(true){
    memset(adjm, 0, sizeof(adjm));
    gans = 0;
    scanf("%d", &n);
    if(n == 0) break;
    for(int i=1; i<n; i++){
      for(int j=i+1; j<=n; j++){
        scanf("%d", &adjm[i][j]);
        adjm[j][i] = adjm[i][j];
      }
    }
    gans += adjm[1][2];
    int tans;
    for(int i=3; i<=n; i++){
        tans = INF;
        for(int j=1; j<i; j++){
            for(int k=j+1; k<i; k++){
                tans = min(tans, (adjm[i][j] + adjm[i][k] - adjm[j][k])/2 );
            }
        }
        gans += tans;
    }

    printf("%d\n", gans);
    // for(int i=1; i<=n; i++){
    //   for(int j=1; j<=n; j++){
    //     cout << adjm[i][j] << " ";
    //   }
    //   cout << endl;
    // }
  }

  return 0;
}
