#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string s;
    char c;
    cin >> s;
    int ps = 1;
    int coe = 1, unk = 0, cons = 0, tempn = 0;
    double ans;
    for(int i=0; i<=s.length(); i++){
        // cout << s[i];
        if(s[i] >= '0' && s[i] <= '9'){
            tempn *= 10;
            tempn += s[i] - '0';
        }else if(s[i] == '+' || s[i] == '-' || s[i] == '=' || s[i] == '\0'){
            if(s[i-1] >= 'a' && s[i-1] <= 'z'){
                c = s[i-1];
                // if(tempn == 0) tempn = 1;
                unk += tempn * coe * ps;
            }else{
                cons += tempn * coe * ps;
            }
            // cout << tempn << endl;
            if(s[i] == '+'){
                ps = 1;
            }else{
                ps = -1;
            }
            tempn = 0;
            if(s[i] == '='){
                coe = -1;
                ps = 1;
            }
        }
    }
    cons *= -1;
    ans = cons * 1.0 / unk;
    // cout << unk << "x=" << cons;
    cout << c << "=";
    printf("%.3f", ans);
    return 0;
}