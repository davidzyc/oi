#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
#include<cmath>
#include<sstream>
#include<algorithm>
using namespace std;
#define MAX_MUL 505
int ans[5000000], n;

string bign_add(string s1, string s2){
    memset(ans, 0, sizeof(ans));
    char s[1000005];
    stack<char> c1, c2;
    int n1, n2, ndigit = 0, p = 0;
    bool fore = false; // 进位
    for(int i=0; i<s1.length(); i++){
        c1.push(s1[i]);
    }
    for(int i=0; i<s2.length(); i++){
        c2.push(s2[i]);
    }
    while(!(c1.empty() && c2.empty())){
        n1 = 0;
        n2 = 0;
        if(!c1.empty()){
            n1 = c1.top();
            if(n1 >= '0' && n1 <= '9'){
                n1 -= '0';
            }else if(n1 >= 'A' && n1 <= 'F'){
                n1 = n1 - 'A'+10;
            }
            c1.pop();
        }
        if(!c2.empty()){
            n2 = c2.top();
            if(n2 >= '0' && n2 <= '9'){
                n2 -= '0';
            }else if(n2 >= 'A' && n2 <= 'F'){
                n2 = n2 - 'A'+10;
            }
            c2.pop();
        }
        // cout << n1 << " " << n2 << endl;
        ans[ndigit] += n1 + n2;
        ans[ndigit+1] += ans[ndigit] / n;
        ans[ndigit] %= n;
        if(ans[ndigit+1] != 0){
            fore = true;
        }else{
            fore = false;
        }
        ndigit ++ ;
    }
    if(!fore){
        ndigit --;
    }
    for(int i=ndigit; i>=0; i--){
        // cout << ans[i] << " ";
        if(ans[i] >= 0 && ans[i] <= 9){
            s[p++] = ans[i] + '0';
        }else if(ans[i] >= 10 && ans[i] <= 15){
            s[p++] = ans[i] + 'A' - 10;
        }
    }
    // cout << s;
    s[p] = '\0';
    return s;
}

int main(){
    int tot = 0;
    string s1, s2, st="";
    bool flag;
    // cin >> n >> s1 >> s2;
    cin >> n >> s1;
    for(int i=0; i<=30; i++){
        flag = true;
        st = s1;
        reverse(st.begin(), st.end());
        if(i!=0 && st == s1){
            cout << "STEP=" << i;
            return 0;
        }
        s1 = bign_add(s1, st);
        // cout << endl << s1 << endl;
    }
    cout << "Impossible!";
    // cout << bign_add(s1, s2);
    return 0;
}