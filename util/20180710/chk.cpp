#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<ctime>

using namespace std;

const int MAXR = 100;

int main(){

  for(int i=1; i<=MAXR; i++){
    system("exhibit_rnd.exe");
    system("exhibit_std.exe");
    double st = clock();
    system("exhibit.exe");
    double ed = clock();
    if(system("fc exhibit.out exhibit.ans")){
      printf("Wrong Answer \n");
      return 0;
    }else{
      printf("Accepted on Test Case #%d, time elapsed %.0lf\n", i, ed - st);
    }
  }


  return 0;
}
