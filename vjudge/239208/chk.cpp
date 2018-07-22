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
    system("w_rnd.exe");
    // system("cd .\\luogu");
    system("w_std.exe");
    double st = clock();
    system( "w.exe");
    double ed = clock();
    if(system("fc w.ans w.out")){
      printf("Wrong Answer");
      return 0;
    }else{
      printf("Accepted on data %d, time %.0lf", ++cnt, ed - st);
    }
  }


}
