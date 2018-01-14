#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

char c[1005][260];
int num[1005], id[1005];

int cmp(int i, int j){
    return num[i] < num[j];
}

int main(){
    char tc;
    int n = 0, tn = 1;
    id[0] = 0;
    while((tc=getchar())!='\n'){
        if(tc!=' '){
            // 字符串转数字，先在已有基础上乘10的n次方，再加数字
            num[n] *= tn;
            num[n] += (tc - '0');
            tn *= 10;
        }else{
            n ++;
            id[n] = n;
            tn = 1;
        }
    }
    // for(int i=0; i<n+1; i++){
    //     cout << num[i] << endl;
    // }
    sort(id, id+n+1, cmp);
    for(int i=0; i<n+1; i++){
        cin >> c[i];
    }
    for(int i=0; i<n+1; i++){
        cout << c[id[i]] << endl;
    }

    return 0;
}