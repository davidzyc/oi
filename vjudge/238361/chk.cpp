#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){

  for(int i=1; i<=100; i++){
    system("c_rnd.exe");
    system("c_std.exe");
    double st = clock();
    system("c.exe");
    double ed = clock();
    if(system("fc c.ans c.out")){
      printf("Wrong Answer!");
      return 0;
    }else{
      printf("Accepted on Test Case #%d, time elapsed %.0lfms\n", i, ed - st);
    }
  }

  return 0;
}
