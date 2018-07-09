#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

const int MAXN = 4;

int chs[MAXN][MAXN] = {0};
int status[MAXN][MAXN] = {0};


int main(){

  for(int i=0; i<MAXN; i++){
    for(int j=0; j<MAXN; j++){
      chs[i][j] = getchar() == '+' ? 1 : 0;
    }
    getchar();
  }

  for(int i=0; i<MAXN; i++){
    for(int j=0; j<MAXN; j++){
      if(chs[i][j]){
        for(int k=0; k<MAXN; k++){
          status[i][k]++;
          status[k][j]++;
        }
        status[i][j]--;
      }
    }
  }

  int cnt = 0;

  //
  // for(int i=0; i<MAXN; i++){
  //   for(int j=0; j<MAXN; j++){
  //     printf("%d ", status[i][j]);
  //     status[i][j] %= 2;
  //   }
  //   printf("\n");
  // }


  for(int i=0; i<MAXN; i++){
    for(int j=0; j<MAXN; j++){
      status[i][j] %= 2;
      if(status[i][j] % 2 == 1){
        cnt++;
      }
    }
  }

  printf("%d\n", cnt);

  for(int i=0; i<MAXN; i++){
    for(int j=0; j<MAXN; j++){
      // status[i][j] %= 2;
      if(status[i][j] % 2 == 1){
        printf("%d %d\n", i+1, j+1);
      }
    }
  }

  return 0;
}
