#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    double x[10005], y[10005];
    double r, d = 0.0;
    cin >> n >> r;
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
        if(i!=0){
            d += sqrt(pow(x[i]-x[i-1], 2) + pow(y[i]-y[i-1], 2));
        }
    }
    d += sqrt(pow(x[n-1]-x[0], 2) + pow(y[n-1]-y[0], 2));
    d += M_PI * 2.0 * r;
    printf("%.2f", d);
    return 0;
}