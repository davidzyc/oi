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
    system("rand_num.exe");
    // system("cd .\\luogu");
    system("1134std.exe");
    double st = clock();
    system( "1134.exe");
    double ed = clock();
    if(system("fc 1134.ans 1134.out")){
      printf("Wrong Answer");
      return 0;
    }else{
      printf("Accepted on data %d, time %.0lf", ++cnt, ed - st);
    }
  }


}
