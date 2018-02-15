#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAXN 30
#define MAXM 10
#define INF 2100000000
using namespace std;

int pos[MAXM+1], user[MAXN+1] = {0}, c[MAXM+1];

int main(){
  int n, m, id;
  double t, tmin, x, y;
  n= MAXN;
  m = MAXM;
  for(int i=0; i<n; i++){
    cin >> id >> x >> y >> c[i];
  }
  for(int i=0; i<n; i++){
    tmin = INF*1.0;
    for(int j=0; j<m; j++){
      cin >> t;
      if(t < tmin){
        tmin = t;
        pos[i] = j;
      }
    }
    user[pos[i]] += c[i];
  }
  for(int i=0; i<n; i++){
    cout << "Point " << i+1 << " select Charger " << pos[i]+1 << " User " << c[i] <<endl;
  }
  for(int i=0; i<m; i++){
    cout << "Charger " << i+1 << " has user " << user[i] << endl;
  }


  return 0;
}
