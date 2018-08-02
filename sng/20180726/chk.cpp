#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

const int MAXROUND = 100;
int cnt = 0;

int main(){

  for(int i=0; i<MAXROUND; i++){
    system("diet_rnd.exe");
    // system("cd .\\luogu");
    system("diet_std.exe");
    double st = clock();
    system( "diet.exe");
    double ed = clock();
    if(system("fc diet.ans diet.out")){
      printf("Wrong Answer");
      return 0;
    }else{
      printf("Accepted on data %d, time %.0lf", ++cnt, ed - st);
    }
  }


}
