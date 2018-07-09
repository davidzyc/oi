#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

const int MAXG = 5;
const int INF = 0x3f3f3f3f;

int inmat[MAXG][MAXG];
int switchmat[MAXG][MAXG] = {0};
int clkrec[MAXG][MAXG] = {0};
int cnt, ans = INF;
string s;

void swit(int i, int j){
  clkrec[i][j]++;
  switchmat[i][j]++;
  ++cnt;
  if(i-1 >= 0 && i-1 < MAXG && j >= 0 && j < MAXG) switchmat[i-1][j]++;
  if(i+1 >= 0 && i+1 < MAXG && j >= 0 && j < MAXG) switchmat[i+1][j]++;
  if(i >= 0 && i < MAXG && j-1 >= 0 && j-1 < MAXG) switchmat[i][j-1]++;
  if(i >= 0 && i < MAXG && j+1 >= 0 && j+1 < MAXG) switchmat[i][j+1]++;
  return;
}

bool need_swit(int i, int j){
  return (switchmat[i][j] ^ inmat[i][j]) & 1;
}

void print_mat(){
  for(int j=0; j<MAXG; j++){
    for(int k=0; k<MAXG; k++){
      // printf("%d ", (switchmat[j][k] ^ inmat[j][k]) & 1);
      printf("%d ", clkrec[j][k]);
    }
    printf("\n");
  }
  printf("\n");
}

void ginit(){
  // getchar();
  memset(switchmat, 0, sizeof(switchmat));
  memset(clkrec, 0, sizeof(clkrec));
  memset(inmat, 0, sizeof(inmat));
  cnt = 0, ans = INF;
}

int main(){

  int tgroup;
  scanf("%d", &tgroup);

  while(tgroup--){
    ginit();
    for(int i=0; i<MAXG; i++){
      cin >> s;
      for(int j=0; j<MAXG; j++){
        inmat[i][j] = s[j] == '1' ? 1 : 0;
      }
      // getchar();
    }

    for(int i=0; i<(1<<MAXG); i++){
      memset(switchmat, 0, sizeof(switchmat));
      memset(clkrec, 0, sizeof(clkrec));
      cnt = 0;
      for(int j=0; j<MAXG; j++){
        // switchmat[0][j] = (i >> j) & 1;
        if((i >> j) & 1){
          swit(0, j);
          // cnt++;
        }
      }
      for(int k=1; k<MAXG; k++){
        for(int h=0; h<MAXG; h++){
          if(!need_swit(k-1, h)){
            swit(k, h);
            // cnt++;
          }
        }
      }
      bool flag = true;
      for(int h=0; h<MAXG; h++){
        if(!need_swit(MAXG-1, h)){
          flag = false;
        }
      }
      if(flag){
        // print_mat();
        ans = min(ans, cnt);
      }
    }
    if(ans <= 6){
      printf("%d\n", ans);
    }else{
      printf("-1\n");
    }

  }

  return 0;
}
