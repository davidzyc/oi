#include<cstdio>
#include<iostream>

using namespace std;

int cnt = 0;

bool chk(int x){
  bool flag = false;
  while(x > 0){
    if((x%10) == 6) flag = true;
    x /= 10;
  }
  return flag;
}

int main()
{
  for(int i=10002; i<=99999;i+=3){
    if(chk(i)) cnt++;
  }
  cout << cnt;
  return 0;
}
