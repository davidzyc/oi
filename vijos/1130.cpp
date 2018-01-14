#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n, tot = 0;
    int temp;
    queue<int> q;
    cin >> n;
    q.push(n);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(int i=1; i<=temp/2; i++){
            q.push(i);
        }
        tot++;
    }
    cout << tot;

    return 0;
}