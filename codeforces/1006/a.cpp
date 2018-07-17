#include<cstdio>
#include<iostream>

using namespace std;

int main(){
  int n, t;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &t);
    if((t&1) == 0){
      t --;
    }
    printf("%d ", t);
  }


  return 0;
}
