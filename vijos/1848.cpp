#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    int n, m, suffix = 0, pot = 1, temp, sum = 0, temp_sum;
    cin >> n >> m;
    while(n >= 1){
        temp_sum = 0;
        temp = n % 10;
        n /= 10;
        temp_sum += n*pot;
        
        if(temp > m){
            temp_sum += pot;
        }else if(temp == m){
            temp_sum = temp_sum + suffix + 1;
        }
        if(m == 0){
            temp_sum -= pot;
        }
        sum += temp_sum;
        // cout << pot << " " << suffix << " " << temp_sum << endl;
        suffix = suffix + temp * pot;
        pot *= 10;
        
    }
    cout << sum;

    return 0;
}