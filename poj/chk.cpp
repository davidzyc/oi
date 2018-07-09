#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;

const int MAXR = 1000;

int main(){

  for(int i=1; i<=MAXR; i++){
    system("rand_gen.exe");
    system("2018std2.exe");
    double st = clock();
    system("2018.exe");
    double ed = clock();
    if(system("fc 2018.out 2018.ans")){
      printf("Wrong Answer! \n");
      return 0;
    }else{
      printf("Accepted on Test Case #%d, time elapsed %.0lfms.\n\n", i, ed-st);
    }
  }

  return 0;
}
