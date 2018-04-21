#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int MAXP = 1e6+5;

ll num[2];
ll gans = 1;
ll gpos = 1;
int pcnt = 0;
int eras[MAXP] = {0};
int ptable[MAXP] = {0};

int main(){
    for(int i=2; i<MAXP; i++){
        if(eras[i]) continue;
        for(int j=i*2; j<MAXP; j+=i){
            eras[j] ++;
        }
    }
    scanf("%lld%lld", &num[0], &num[1]);
    for(int nid=0; nid<2; nid++){
        for(int i=2; i<MAXP; i++){
            if(eras[i]) continue;
            while(num[nid] % (ll)i == 0){
                ptable[i]++;
                num[nid] /= (ll)i;
            }
        }
    }
    for(int i=2; i<MAXP; i++){
        if(eras[i] || !ptable[i]) continue;
        for(int j=0; j<(ptable[i]/2); j++){
            gans *= i;
        }
        // cout << i << " " << ptable[i] << endl;
        gpos *= (ptable[i] == (ptable[i] / 2) * 2) ? 1 : 2;
    }
    if(num[0] == num[1]){
        gans *= num[0];
    }
    printf("%lld %lld", gans, gpos);

    return 0;
}
