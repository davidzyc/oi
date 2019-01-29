#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main(){
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);

  for(int i=1; i<=100; i++){
    for(int j=1; j<100-i; j++){
      if((i%10==a || i/10==a) && (j%10==b || j/10==b) && ((100-i-j)%10==c || (100-i-j)/10==c))
      cout << i << " " <<j << " " << 100-i-j << endl;
    }
  }

  return 0;
}
