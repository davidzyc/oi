#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int digit[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
bool psign = false, eqsign = false;
int n, tot = 0;
int num[2][15] = {0}, snum[15] = {0}, nlen[2] = {0}, slen = 0;

void bign_sum(){
    int tn1, tn2, maxlen;
    memset(snum, 0, sizeof(snum));
    maxlen = max(nlen[0], nlen[1]);
    for(int i=0; i<maxlen; i++){
        if(i<nlen[0]){
            tn1 = num[0][i];
        }else{
            tn1 = 0;
        }
        if(i<nlen[1]){
            tn2 = num[1][i];
        }else{
            tn2 = 0;
        }
        snum[i] += tn1 + tn2;
        snum[i+1] += snum[i] / 10;
        snum[i] %= 10;
    }
    if(snum[maxlen] != 0){
        slen = maxlen + 1;
    }else{
        slen = maxlen;
    }
}

void dfs(int remain, int stage){

    if(remain <= 0){
        return;
    }
    if(stage == 2){
        int tdigit = 0;
        bign_sum();
            // cout << endl <<  " " << nlen[0] << " " << nlen[1] << " " << slen << " ";
            // for(int i = nlen[0]-1; i>=0; i--) cout << num[0][i];
            // cout << "+";
            // for(int i = nlen[1]-1; i>=0; i--) cout << num[1][i];
            // cout << "=";
            // for(int i = slen-1; i>=0; i--) cout << snum[i];
        for(int i=0; i<slen; i++){
            tdigit += digit[snum[i]];
        }
        if(tdigit == remain){
            tot ++ ;
            // cout << endl << "Success: ";
            // for(int i = nlen[0]-1; i>=0; i--) cout << num[0][i];
            // cout << "+";
            // for(int i = nlen[1]-1; i>=0; i--) cout << num[1][i];
            // cout << "=";
            // for(int i = slen-1; i>=0; i--) cout << snum[i];
        }
        return;
    }
    // if(nlen[stage] > 0 && num[stage][0] == 0){
    //         dfs(remain, stage+1);
    // }else{
        for(int i=0; i<10; i++){
            num[stage][nlen[stage]] = i;
            nlen[stage] ++;
            dfs(remain - digit[i], stage);
            nlen[stage] --;
        }
        if(nlen[stage] == 1 || (nlen[stage] > 1 && num[stage][nlen[stage]-1] != 0)){
            dfs(remain, stage+1);
        }
    // } 
    
}

int main(){

    int n;
    // freopen("1496.txt", "w", stdout);
    // int p = 0;
    // char c;
    // int i = 0;
    // while(p < 2){
    //     c = getchar();
    //     if(c != ' ' && c != '\n'){
    //         num[p][i] = c - '0';
    //         i++;
    //     }else{
    //         nlen[p] = i;
    //         i = 0;
    //         p++;
    //     }
    // }
    // bign_sum();
    // cout << nlen[0] << " " << nlen[1] << " " << slen << endl;
    // for(int i=slen-1; i>=0; i--){
    //     cout <<  snum[i];
    // }

    cin >> n;
    dfs(n-4, 0);
    cout << tot;
    return 0;
}