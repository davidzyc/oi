#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN = 105;
const double MINA = 0.1;

int n, maxs;
int x[MAXN], y[MAXN];
int gcnt = 0;

bool same_pos(int a, int b){
    return x[a] == x[b] && y[a] == y[b];
}

double get_edge(int a, int b){
    return sqrt(((x[a] - x[b])*(x[a] - x[b]) + (y[a] - y[b])*(y[a] - y[b]))*1.0);
}

double get_area(double ea, double eb, double ec){
    return sqrt(((ea+eb+ec)/2)*((ec+eb-ea)/2)*((ea-eb+ec)/2)*((ea+eb-ec)/2));
}

int main(){
    double ea, eb, ec;
    scanf("%d%d", &n, &maxs);
    for(int i=0; i<n; i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(same_pos(i, j) || same_pos(j, k) || same_pos(i, k)) continue;
                ea = get_edge(i, j);
                eb = get_edge(k, j);
                ec = get_edge(i, k);
                double ta = get_area(ea, eb, ec);
                // cout << i << " " << j << " " << k << " " << get_area(ea, eb, ec) << endl;
                if(ta > MINA && ta <= maxs*1.0){
                    ++gcnt;
                }
            }
        }
    }
    printf("%d", gcnt);
    return 0;
}
