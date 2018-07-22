#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
  freopen("garden.in", "w", stdout);
  srand((unsigned) time(0));
  // int n = rand()%100+1, m = rand()%100+1, k = rand()%10 + 1;
  int n = 100, m = 100, k = 10;
  cout << n<<" " << m << " " << k << endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      printf("%d", rand()%10);
    }
    printf("\n");
  }
  for(int i=0; i<k; i++){
    printf("%d %d\n", rand()%n, rand()%m);
  }

  return 0;
}
