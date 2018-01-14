#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

int n;
int perm[6][3] = {0,1,2,
                // 0,2,1,
                1,0,2,
                // 1,2,0,
                // 2,1,0,
                2,0,1};
char c[5][10005];
stack<char> cs;

void reverse_pass(int i){
    for(int j=0; j<n; j++){
        cs.push(c[i][j]);
    }
    for(int j=0; j<n; j++){
        c[4][j] = cs.top();
        cs.pop();
    }
    return ;
}

bool pass_diff(int x){
    char th, te, t2h, t2e, t3h, t3e;
    for(int i=0; i<n; i++){
        th = c[perm[x][0]][n-i-1];
        t2h = c[perm[x][1]][i];
        t3h = c[perm[x][2]][i];
        te = c[perm[x][0]][i];
        t2e = c[perm[x][1]][n-i-1];
        t3e = c[perm[x][2]][n-i-1];
                // cout << t2h - th <<" "<< th - t3h << " " << t2e - te <<" "<< te - t3e <<endl;
        if((t2h - th == th - t3h || t2h - th +26 == th - t3h || t2h - th - 26 == th - t3h) && (t2e - te == te - t3e || t2e - te +26 == te - t3e || t2e - te - 26 == te - t3e)){
            // cout << "true" << endl;
        }else{
            // cout << "false" << endl;
            return false;
        }
    }

    reverse_pass(perm[x][0]);
    for(int i=0; i<n; i++){
        cout << c[4][i];
    }
    return true;

}

int main(){
    
    cin >> n;
    for(int i=0; i<3; i++){
        for(int j=0; j<n; j++){
            cin >> c[i][j];
        }
    }
    for(int i=0; i<6; i++){
        if(pass_diff(i)) return 0;
    }
    // for(int i=0; i<4; i++){
    //     for(int j=0; j<n; j++){
    //         cout << c[i][j];
    //     }
    //     cout << endl;
    // }

    return 0;
}