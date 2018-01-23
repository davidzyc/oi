#include<cstdio>
#include<iostream>
#define MAX_T 300005
using namespace std;

int dps[MAX_T], dpm[MAX_T];

int main(){
  int m, s, t;
  cin >> m >> s >> t;
  dps[0] = 0;
  dpm[0] = m;
  for(int i=1; i<=t; i++){
    dps[i] = dps[i-1]+17;
    dpm[i] = dpm[i-1];
    // for(int j=0; j<i; j++){
    //   dps[j] + (dpm[j] + )
    // }
    if(dpm[i-1] >= 10){
      dpm[i] = dpm[i-1]-10;
      dps[i] = dps[i-1]+60;
    }else{
      if(i-2 >= 0 && dpm[i-2]+4 >= 10 && dps[i-2]+60 > dps[i]){
        dpm[i] = dpm[i-2]+4-10;
        dps[i] = dps[i-2]+60;
      }
      if(i-3 >= 0 && dpm[i-3]+8 >= 10 && dps[i-3]+60 > dps[i]){
        dpm[i] = dpm[i-3]+8-10;
        dps[i] = dps[i-3]+60;
      }
      if(i-7 >= 0 && dps[i-7]+120 > dps[i]){
        dpm[i] = dpm[i-7];
        dps[i] = dps[i-7]+120;
      }
    }

    if(dps[i] >= s){
      cout << "Yes" << endl;
      cout << i;
      return 0;
    }
  }

  cout << "No" << endl;
  cout << dps[t];

  // for(int i=0; i<=t; i++){
  //   cout << dps[i] << " ";
  // }
  // cout << endl;
  // for(int i=0; i<=t; i++){
  //   cout << dpm[i] << " ";
  // }

  return 0;
}
