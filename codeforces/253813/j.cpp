#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
 
int total_num = 0;
char s[200];
 
int v[100];
 
bool f(int x, int y) {
//   cout << x << " " << y << endl;
    if(x > strlen(s)) {
        return false;
    }
    //   cout << "Hi";
    if(x == strlen(s)) {
        int flag = 1;
        for(int i=1; i<=total_num; i++){
            flag = min(flag, v[i]);
        }
        if(flag == 1) return true;
    }
    int cur;
    cur = s[x] - '0';
    if(cur > 0 && cur <= total_num && v[cur] == 0){
        v[cur] = y;
        if(f(x + 1, y + 1)) return true;
        v[cur] = 0;
    }
    if(x == strlen(s) - 1) return false;
    cur = (s[x] - '0') * 10 + s[x+1] - '0';
    if(cur > 0 && cur <= total_num && v[cur] == 0){
        v[cur] = y;
        if(f(x + 2, y + 1)) return true;
        v[cur] = 0;
    }
    return false;
}
 
int main(){
  // cout << "Hi";
  freopen("joke.in", "r", stdin);
freopen("joke.out", "w", stdout);
  scanf("%s", s);
  //cout << strlen(s);
    //cout << "Hi";
    if(strlen(s) <= 9)  {
      // cout << "Hi";
        for(int i=0; i<strlen(s); i++){
            printf("%d ", s[i] - '0');
        }
	return 0;
    }
    // cout << "Hello world" ;
    memset(v, 0, sizeof(v));
    total_num = (strlen(s) - 9) / 2 + 9;
    // cout << total_num;
    f(0, 1);
    for(int i=1; i<=total_num; i++){
        for(int j=1; j<=total_num; j++) {
            if(v[j] == i) printf("%d ", j);
        }
    }
    
    return 0;
}