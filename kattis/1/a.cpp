#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

const int MAXN = 1000;

int n;
int a[MAXN];
stack<int> s;
char c;
char ss[10000], si[10000];

int main(){

    scanf("%d", &n);
    scanf("%s", si);
    for(int i=0; i<2*n; i+=2){
        // scanf("%c", &c);
        c = si[i];
        if(c == 'T'){
            a[i] = 1;
        }else{
            a[i] = 0;
        }
    }
    for(int i=0; i<n; i++) cout << a[i];
    scanf("%s", ss);
    for(int i=0; i<strlen(ss); i+=2){
        c = ss[i];
        // if(c == ' ' || c == '\n') break;
        int t1, t2;
        if(c >= 'A' && c <= 'Z'){
            s.push(a[c - 'A']);
        }else{
            if(c == '*'){
                t1 = s.top();
                s.pop();
                t2 = s.top();
                s.pop();
                s.push(min(t1, t2));
            }else if(c == '+'){
                t1 = s.top();
                s.pop();
                t2 = s.top();
                s.pop();
                s.push(max(t1, t2));
            }else if(c == '-'){
                t1 = s.top();
                s.pop();
                s.push(1-t1);
            }
        }
    }
    cout << s.top();


    return 0;
}