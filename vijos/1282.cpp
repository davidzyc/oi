#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k, id[50005], w[50005], e[15];

// Compare函数，多重排序代码，先考虑w[i]，再考虑id[i]
bool cmp(int i, int j){
    if(w[i] != w[j]){
        return w[i] > w[j];
    }else{
        return i<j;
    }
}

int main(){
    cin >> n >> k;
    for(int i=0; i<10; i++){
        cin >> e[i];
    }
    for(int i=0; i<n; i++){
        cin >> w[i];
        id[i] = i;
    }
    stable_sort(id, id+n, cmp);
    for(int i=0; i<n; i++){
        w[id[i]] += e[i%10];
    }
    stable_sort(id, id+n, cmp);
    for(int i=0; i<k; i++){
        cout << id[i]+1 << " ";
    }
    
    return 0;
}