#include<cstdio>
#include<iostream>
using namespace std;

char key[15];

int main(){
    char c;
    int keylen = 0, tot = 0;
    bool getkey = false;
    while(c=getchar()){
        if((c == '\n' || c == ' ')){
            if(getkey) break;
            else continue;
        }
        if(c >= 'A' && c <= 'Z'){
            c = c-'A'+'a';
        }
        getkey = true;
        key[keylen++] = c;
    }
    // bool flag = true, find = false, processed = false;
    // int firstpos = -1, pos = 0, cnt = 0;
    // while(true){
    //     c = getchar();
    //     if(!(c == ' ' || c == EOF || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) continue;
    //     if(c == ' ' || c == '\n' || c == EOF){
    //         if(!processed) continue;
    //         if(flag){
    //             tot++;
    //             if(!find){
    //                 find = true;
    //                 firstpos = cnt;
    //             }
    //         }
    //         cnt++;
    //         processed = false;
    //         flag = true;
    //         pos = 0;
    //         if(c == EOF) break;
    //         continue;
    //     }
    //     processed = true;
    //     if(c >= 'A' && c <= 'Z'){
    //         c = c-'A'+'a';
    //     }
    //     if(c != key[pos++]) flag = false;
    // }

    // cout << flag;
    // if(flag){
    //     tot++;
    //     if(!find){
    //         find = true;
    //         firstpos = cnt;
    //     }
    // }

    // for(int i=0; i<keylen; i++){
    //     cout << key[i];
    // }

    bool find = false, correct = true, first = true, processed = false;
    int firstpos = -1, pos = 0, cnt = 0, rollback;
    
    while(true){
        c = getchar();
        if(!(c == ' ' || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == EOF)) continue;
        if(c == ' ' || c == EOF){
            //initialize
            if(correct && processed && pos < keylen){
                tot--;
                correct = false;
            }
            if(processed && correct && !find){
                find = true;
                firstpos = cnt-1;
            }
            pos = 0;
            correct = true;
            first = true;
            processed = false;
            if(c == EOF) break;
            continue;
        }
        if(!correct) continue;
        if(c >= 'A' && c <= 'Z'){
            c = c-'A'+'a';
        }
        if(first){
            // cout << endl << cnt;
            // if(!find){
            //     rollback = firstpos;
            //     firstpos = cnt;
            //     find = true;
            // }
            tot++;
            cnt++;
            first = false;
        }
        processed = true;
        if(c != key[pos++]){
            // cout << " " << c << " Minus";
            // find = false;
            // firstpos = rollback;
            tot--;
            correct = false;
        }
    }

    if(tot != 0){
        cout << tot << " " << firstpos;
    }else{
        cout << "-1";
    }
    

    return 0;
}