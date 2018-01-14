#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main(){
int a[10], temp;
bool flag;
for(int i=100; i<=333; i++){
flag = true;
memset(a, 0, sizeof(a));
for(int j=1; j<=3; j++){
temp = i*j;
a[temp%10]++;
temp /= 10;
a[temp%10]++;
temp /= 10;
a[temp]++;
}
for(int k=1; k<=9; k++){
if(a[k] == 0) flag = false;
}
if(flag == true){
cout << i << " " << i*2 << " " << i*3 << endl;
}
}

return 0;
}