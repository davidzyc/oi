#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){

  for(int i=1; i<=100; i++){
    system("compress_rnd.exe");
    system("compress_std.exe");
    double st = clock();
    system("compress.exe");
    double ed = clock();
    if(system("fc compress.ans compress.out")){
      printf("Wrong Answer!");
      return 0;
    }else{
      printf("Accepted on Test Case #%d, time elapsed %.0lfms\n", i, ed - st);
    }
  }

  return 0;
}
