#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, temp, a, b, tot = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0; i<n; i++){
        cin >> temp;
        q.push(temp);
    }
    while(q.size()>1){
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        tot += a+b;
        // cout << tot;
        q.push(a+b);
    }
    cout << tot;

    return 0;
}