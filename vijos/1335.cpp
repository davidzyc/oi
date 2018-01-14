#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int num[10];

bool checknum(int i){
    if(num[i] == 0){
        num[i] ++;
        return true;
    }
    return false;
}

int main(){
    int n;
    int a[10][10];
    bool flag;
    cin >> n;
    for(int z=0; z<n; z++){
        flag = true;
        
        for(int i=0; i<9; i++){
            memset(num, 0, sizeof(num));
            for(int j=0; j<9; j++){
                cin >> a[i][j];
                if(!checknum(a[i][j])) flag = false;
            }
        }
        for(int j=0; j<9; j++){
            memset(num, 0, sizeof(num));
            for(int i=0; i<9; i++){
                if(!checknum(a[i][j])) flag = false;
            }
        }
        for(int p=0; p<3; p++){
            for(int q=0; q<3; q++){
                memset(num, 0, sizeof(num));
                for(int r=0; r<3; r++){
                    for(int s=0; s<3; s++){
                        if(!checknum(a[3*p+r][3*q+s])) flag = false;
                    }
                }
            }
        }

        if(flag) {
            cout << "Right" << endl;
        }else{
            cout << "Wrong" << endl;
        }
        // scanf("\n");
    }
    return 0;
}