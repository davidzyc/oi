#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


int main(){
  for(int i=0; i<100; i++){
    system("randgen.exe");
    system("4300std.exe");
    double st = clock();
    system("4300.exe");
    double ed = clock();
    if(system("fc 4300.out 4300.ans")){
      printf("Wrong Answer!\n\n");
      return 0;
    }else{
      printf("\nAccepted on Test %d time %.0lfms\n\n", i+1, ed-st);
    }
  }

  return 0;
}
