#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
#include<cmath>
#include<sstream>
#include<algorithm>
using namespace std;
#define MAX_MUL 100005
int ans[5000000];

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
    for(int i=ansdigit-1; i>=0; i--){
        s[p++] = ans[i] + '0';
    }
    s[p] = '\0';
    return s;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    // cout << bign_add(s1, s2) << endl;
    cout << bign_mul(s1, s2) << endl;
    // cout << bign_sub(s1, s2);
    return 0;
}