#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, id[10005];
string name[10005], water[10005];

bool cmp(int n1, int n2){
    // > true, < false
    if(water[n1].length() > water[n2].length()){
        return true;
    }else if(water[n1].length() < water[n2].length()){
        return false;
    }else{
        for(int i=0; i<water[n1].length(); i++){
            if(water[n1][i] > water[n2][i]){
                return true;
            }else if(water[n1][i] < water[n2][i]){
                return false;
            }
        }
        int len = min(name[n1].length(), name[n2].length());
        for(int i=0; i<len; i++){
            if(name[n1][i] < name[n2][i]){
                return true;
            }else if(name[n1][i] > name[n2][i]){
                return false;
            }
        }
        return false;
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> name[i] >> water[i];
        id[i] = i;
    }
    sort(id, id+n, cmp);
    for(int i=0; i<n; i++){
        cout << name[id[i]] << endl;
    }

    return 0;
}