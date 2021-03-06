#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
#include<cmath>
#include<sstream>
#include<algorithm>
using namespace std;
#define MAX_MUL 100000000
int ans[5000000];

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
            n1 = c1.top() - '0';
            c1.pop();
        }
        if(!c2.empty()){
            n2 = c2.top() - '0';
            c2.pop();
        }
        ans[ndigit] += (n1 + n2) % 10;
        ans[ndigit+1] += (n1 + n2) / 10;
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
        s[p++] = ans[i] + '0';
    }
    s[p] = '\0';
    return s;
}

string bign_mul(string s1, string s2){
    memset(ans, 0, sizeof(ans));
    char s[1000005];
    int p = 0;
    int n1, n2, ndigit1 = 0, ndigit2 = 0, ansdigit = 0;
    bool fore = false;
    int s2_stop_pos = 0;
    s2_stop_pos = max(0, (int)s2.length()-MAX_MUL-1);
    int s1_stop_pos = 0;
    s1_stop_pos = max(0, (int)s1.length()-MAX_MUL-1);
    for(int i=s2.length()-1; i>=s2_stop_pos; i--){
        ndigit2 = s2.length()-i-1;
        n2 = s2[i] - '0';
        for(int j=s1.length()-1; j>=s1_stop_pos; j--){
            ndigit1 = s1.length()-j-1;
            n1 = s1[j] - '0';
            // cout << n1 << " ("<< ndigit1 <<") ";
            ans[ndigit1+ndigit2] += n1 * n2;
            ans[ndigit1+ndigit2+1] += ans[ndigit1+ndigit2] / 10;
            ans[ndigit1+ndigit2] %= 10;
            if(ans[ndigit1+ndigit2+1] != 0){
                fore = true;
            }else{
                fore = false;
            }
        }
        // cout << ": " << n2 << " ("<< ndigit2 <<") " << endl;
    }
    ansdigit = s1.length()+s2.length();
    if(!fore){
        ansdigit --;
    }
    
    // ansdigit = 1000;
    // while(ans[ansdigit] != 0){
    //     ansdigit ++;
    // }
    for(int i=ansdigit-1; i>=0; i--){
        s[p++] = ans[i] + '0';
    }
    s[p] = '\0';
    return s;
}

int main(){
    int n;
    string ans = "1", pot = "1";
    // true -> 1, false -> 2
    bool ent = true;
    cin >> n;
    while(n > 1){
        int temp = n;
        if(ent){
            n = (n+1) / 2;
        }else{
            ans = bign_add(ans, pot);
            n /= 2;
        }
        if(temp % 2 == 1){
            ent = !ent;
        }
        pot = bign_mul(pot, "2");
    }
    cout << ans;

    return 0;
}