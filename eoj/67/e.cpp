#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

typedef long long ll;

int gn;
string s;
int nlen;
ll dcnt[2];
ll typecnt[4];
ll ans;
ll tans;
int dig;

int main(){
    // freopen("e.txt", "r", stdin);
    scanf("%d", &gn);
    while(gn--){
        int ttype;
        ans = 0;
        memset(dcnt, 0, sizeof(dcnt));
        memset(typecnt, 0, sizeof(typecnt));
        cin >> s;
        nlen = s.length();
        typecnt[0]++;
        for(int i=0; i<nlen; i++){
            tans = 0;
            dig = s[i] - '0';
            dcnt[dig]++;
            ttype = 0;
            ttype = dcnt[0]%2;
            ttype *= 2;
            ttype += dcnt[1]%2;
            for(int j=0; j<4; j++){
                if((ttype^j) == 3) continue;
                tans += typecnt[j];
            }
            // cout << tans << " | ";
            typecnt[ttype] ++;
            ans += tans;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
