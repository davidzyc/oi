#include<cstdio>
#include<iostream>

using namespace std;

const int MAXN = 1e3+7;

int n, m;
int a[MAXN], b[MAXN];

int main(){

    freopen("knockout.in", "r", stdin);
    freopen("knockout.out", "w", stdout);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i] >> b[i];
    }
    int ai, bi, ti;
    for(int i=1; i<=m; i++){
        int gcnt = 0;
        cin >> ai >> bi >> ti;
        for(int j=1; j<=n; j++){
            // cout << "Time " << ti << " Car " << a[j] << " -> " << b[j] << " is at ";
            int ofs, df, pos;
            if(a[j] > b[j]) {
                df = a[j] - b[j];
                ti += df;
            } else {
                df = b[j] - a[j];
            }
            ofs = ti % (df * 2);
            if(ofs > df){
                ofs = (df * 2) - ofs;
            }
            pos = min(a[j], b[j]) + ofs;
            // cout << pos << endl;
            if(ai <= pos && pos <= bi){
                gcnt ++ ;
            }
        }
        cout << gcnt << endl;
    }



    return 0;
}