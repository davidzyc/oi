#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#define PERFECT_SEPERATION 0.6180339887498949
using namespace std;

int n, k[30005];
double totmin = 1.0;
int main(){
    int startpos, endpos, midpos, tempi, tempmid;
    double tempmin = 1.0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> k[i];
    }
    sort(k, k+n);
    for(int i=0; i<n; i++){
        startpos = i+1;
        endpos = n;
        while(startpos < endpos){
            midpos = (startpos + endpos) / 2;
            if(abs(k[i]*1.0/k[midpos]-PERFECT_SEPERATION) < tempmin){
                tempmin = abs(k[i]*1.0/k[midpos]-PERFECT_SEPERATION);
                tempi = i;
                tempmid = midpos;
            }
            if(k[i]*1.0/k[midpos] > PERFECT_SEPERATION){
                startpos = midpos + 1;
            }else{
                endpos = midpos;
            }
        }
        // cout << tempmin << endl;
    }
    cout << k[tempi] << endl << k[tempmid] << endl;

    return 0;
}