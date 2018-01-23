#include<cstdio>
#include<iostream>
#include<cmath>
#define UNC_DIS 0.00001
using namespace std;

int main(){
    double h, s, v, l, k;
    int n, tot = 0;
    cin >> h >> s >> v >> l >> k >> n;
    // int tot;
    // double carpos;
    // double tmin, tmax;

    // tmax = sqrt(2.0*(h - k + UNC_DIS)*1.0/10.0);
    // int maxpos = floor(s * 1.0 - tmax * v + l*1.0 + UNC_DIS);

    // tmin = sqrt(2.0*(h+UNC_DIS)*1.0/10.0);
    // int minpos = ceil(s * 1.0 - tmin * v - UNC_DIS);

    // if((minpos < 0 && maxpos < 0) || (minpos > n-1 && maxpos > n-1)){
    //     cout << 0;
    // }else if(minpos < 0 && maxpos >= 0){
    //     cout << maxpos + 1;
    // }else if(maxpos > n-1 && minpos <= n-1){
    //     cout << n - minpos;
    // }else{
    //     cout << maxpos - minpos + 1;
    // }

    // // tot = min(floor(carpos+l*1.0/2.0+UNC_DIS), n*1.0 - 1.0) - min(ceil(carpos-l*1.0/2.0-UNC_DIS), n*1.0 - 1.0);
    // cout << endl << maxpos << " " << minpos << endl;
    // // cout << endl << cpmax+l*1.0+UNC_DIS << " " << cpmin-UNC_DIS << endl;
    // // cout << floor()
    // // cout << tot;
    for(int i=0; i<n; i++){
        double tmin = (s-i*1.0)/v, tmax = (s+l-i*1.0)/v;
        double bpup = h - 5.0*tmin*tmin + UNC_DIS, bpdown = h - 5.0*tmax*tmax - UNC_DIS;
        if((bpup <= k && bpup >= 0.0) || (bpdown >= 0.0 && bpdown <= k) || (bpup >= k && bpdown <= 0.0)){
            tot++;
        }
    }
    cout << tot;
    return 0;
}